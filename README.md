# Source2Toolkit SDK

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](LICENSE)
[![Website](https://img.shields.io/badge/Website-source2toolkit.net-blue)](https://www.source2toolkit.net)
[![Discord](https://img.shields.io/discord/1178027657594687608?color=7289da&logo=discord&logoColor=white)](https://source2toolkit.dev/discord)

**Source2Toolkit SDK** is the core development kit required for building plugins for Source2Toolkit.

It bundles everything you need — headers, SDK, hooking system and build helpers — so you can focus purely on writing your plugin.

👉 **Docs & guides:** https://www.source2toolkit.net

---

## What is this?

Source2Toolkit SDK is a lightweight development layer that provides:

- Preconfigured **HL2SDK (CS2)**  
- Integrated **SourceHook** hooking library (virtual, DVP, manual and inline)  
- Ready-to-use **Source 2 headers & interfaces**  
- Cross-platform build configuration  
- Simple plugin build system  

No setup. No hunting dependencies. Just build.

---

## Why use it?

- **Zero setup** – everything included (SDK, hooks, protobufs)  
- **Fast builds** – optimized CMake configuration  
- **Clean integration** – designed specifically for Source2Toolkit  
- **Cross-platform** – Windows & Linux support out of the box  
- **Minimal boilerplate** – create plugins in seconds  

---

## Quick Start

👉 Full docs: https://www.source2toolkit.net

### 1. Add SDK to your project

```bash
git submodule add https://github.com/SlynxCZ/source2toolkit-sdk.git
git submodule update --init --recursive
```

---

### 2. Minimal plugin setup (4 lines)

```cmake
cmake_minimum_required(VERSION 3.18)
project(my-plugin CXX)

add_subdirectory(source2toolkit-sdk)
add_s2toolkit_plugin(my_plugin plugin.cpp)
```

---

## Building

```bash
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

Output:
```
my_plugin.stx
```

---

## What's Included

- **HL2SDK-CS2** (as submodule)  
- **SourceHook** (virtual, DVP, manual & inline hooks)  
- **Protobuf definitions**  
- **Tier0 / Tier1 / Mathlib**  
- **Schema system headers**  
- **Preconfigured compiler flags & linking**  

---

## Hooking

The SDK bundles **SourceHook** and the toolkit core runs its own engine
instance, separate from Metamod's. Your plugin does not create or include one —
`TOOLKIT_EXPOSE` declares `g_SHPtr` and `g_PLID`, and `TOOLKIT_SAVEVARS` fills
them from `ToolkitFactory(TOOLKIT_SOURCEHOOK_INTERFACE)`. From there the stock
`SH_` macros work as they do under Metamod:

```cpp
TOOLKIT_EXPOSE(MyPlugin, g_MyPlugin);

bool MyPlugin::Load(IToolkitAPI* api, PluginId id, char* error, size_t maxlen)
{
    TOOLKIT_SAVEVARS();   // g_SHPtr and g_PLID are live from here on
    ...
}
```

### Virtual hooks

```cpp
SH_DECL_HOOK2_void(IServerGameClients, ClientCommand, SH_NOATTRIB, 0,
                   CPlayerSlot, const CCommand&);

m_iHookID = SH_ADD_HOOK(IServerGameClients, ClientCommand, g_pSource2GameClients,
                        SH_MEMBER(this, &MyPlugin::Hook_ClientCommand), false);
```

### DVP hooks

When you only have a vtable pointer and no interface, `SH_ADD_DVPHOOK` takes
that pointer *as* the vtable:

```cpp
m_iHookID = SH_ADD_DVPHOOK(CServerSideClient, SendNetMessage, pVTable,
                           SH_MEMBER(this, &MyPlugin::Hook_SendNetMessage), false);
```

### Inline hooks

Inline hooks patch a raw address, so anything a signature scan finds is
hookable — no vtable involved. Declare with the argument count *excluding*
`this`, and add `_void` when there is no return value:

```cpp
SH_DECL_INLINEHOOK2(FilterMessage, INetworkMessageProcessingPreFilterCustom,
                    bool, const CNetMessage*, INetChannel*);

m_iHookID = SH_ADD_INLINEHOOK(FilterMessage, pAddress,
                              SH_MEMBER(this, &MyPlugin::Hook_FilterMessage), false);
```

`SH_ADD_INLINEHOOK` accepts a `void*`, a `uintptr_t` or a typed function
pointer directly, so a `CMemory` from a signature scan can be passed as-is.

Every id — virtual, DVP, manual or inline — is removed with
`SH_REMOVE_HOOK_ID`; the two id ranges are disjoint.

### Return values

Handlers return `META_RES`:

| `META_RES` | meaning |
|---|---|
| `MRES_IGNORED` | did nothing |
| `MRES_HANDLED` | did something, original still runs |
| `MRES_OVERRIDE` | original runs, your return value wins |
| `MRES_SUPERCEDE` | original is skipped entirely |

Timing is a plain `bool post` everywhere — the toolkit's listener APIs
(`RegConListener`, `HookGameEvent`, `AddEntityIOListener`) take the same
`false` = pre / `true` = post argument SourceHook's own `SH_ADD_HOOK` does.

---

## Helper API

### add_s2toolkit_plugin

```cmake
add_s2toolkit_plugin(my_plugin plugin.cpp)
```

Automatically:
- Links SDK  
- Sets correct output (`.stx`)  
- Applies all required flags  

---

## Requirements

- CMake 3.18+  
- C++20 compiler  
- Source2Toolkit installed on server  

---

## Documentation

- Docs: https://www.source2toolkit.net  
- Getting Started: https://www.source2toolkit.net/docs
- API Reference: https://www.source2toolkit.net/docs

---

## License

This project is licensed under the GNU General Public License v3.0.

---

<div align="center">
  <strong>Everything you need to build Source2Toolkit plugins. Nothing more.</strong>
</div>
