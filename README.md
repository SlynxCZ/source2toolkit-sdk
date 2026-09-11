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
- Integrated **KHook** hooking (virtual, vtable and function detours), shared with Metamod  
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
- **KHook** (virtual, vtable & function hooks) -- as the `vendor/khook` submodule, headers only    
- **Protobuf definitions**  
- **Tier0 / Tier1 / Mathlib**  
- **Schema system headers**  
- **Preconfigured compiler flags & linking**  

---

## Hooking

Hooks go through **KHook**, Metamod:Source's own detour library. The toolkit is
a Metamod plugin and gets the engine handed to it at load; `TOOLKIT_SAVEVARS()`
fetches that same engine for your plugin (`ToolkitFactory(TOOLKIT_KHOOK_INTERFACE)`),
so every hook on the server -- Metamod's, the toolkit's, every plugin's -- runs
on one instance.

The headers are the SDK's own `vendor/khook` submodule (`git submodule update
--init --recursive`); nothing of KHook is built and no metamod-source checkout
is needed. The SDK stamps the submodule's commit into your binary as
`TOOLKIT_KHOOK_COMMIT`, the core reports the commit it was built with
(`ToolkitFactory(TOOLKIT_KHOOK_VERSION_INTERFACE)`), and `TOOLKIT_SAVEVARS()`
refuses the load if the two differ -- a plugin built against one KHook never
hooks through another. Nothing to set up on your side:

```cpp
TOOLKIT_EXPOSE(MyPlugin, g_MyPlugin);

bool MyPlugin::Load(PluginId id, IToolkitAPI* api, char* error, size_t maxlen, bool late)
{
    TOOLKIT_SAVEVARS();   // KHook is live from here on
    ...
}
```

A hook is an object: the member function you want, the context (`this`) and
the callbacks that run before and after it -- `nullptr` for the side you do
not need. Keep it behind a plain pointer: KHook only takes a detour down in the
hook's destructor, so `new` it in your constructor and `delete` it in
`Unload()`.

### Virtual hooks

```cpp
KHook::Virtual<ISource2GameClients, void, CPlayerSlot, const CCommand&>* m_hClientCommand = nullptr;

m_hClientCommand = new KHook::Virtual(&ISource2GameClients::ClientCommand, this,
                                      &MyPlugin::Hook_ClientCommand, nullptr);
m_hClientCommand->Add(g_pSource2GameClients);
```

When you only have a vtable and no instance (an engine class found by RTTI
name), hand the hook something whose first pointer is that vtable and use
`AddGlobal` -- it then covers every object sharing it:

```cpp
void* m_pVTable = libengine.GetVirtualTableByName("CServerSideClient").GetPtr();
m_hSendNetMessage->AddGlobal(reinterpret_cast<CServerSideClientBase*>(&m_pVTable));
```

A vtable index instead of a member function pointer makes it a manual hook:
`new KHook::Virtual<CCSGameRules, void>(52u, this, &MyPlugin::Pre, &MyPlugin::Post)`.

### Function hooks

Anything a signature scan finds is hookable -- `KHook::Member` when the
function has a `this`, `KHook::Function` when it does not:

```cpp
KHook::Member<CBaseEntity, int64_t, CTakeDamageInfo*, CTakeDamageResult*>* m_hTakeDamageOld = nullptr;

m_hTakeDamageOld = new KHook::Member(this, &MyPlugin::Hook_TakeDamageOld, nullptr);
m_hTakeDamageOld->Configure(ADDR_TAKE_DAMAGE_OLD());
```

### Handlers

A handler takes the hooked object first, then the function's own parameters,
and returns `KHook::Return<T>` -- the action, plus the return value when the
function has one:

```cpp
KHook::Return<bool> MyPlugin::Hook_ClientConnect(ISource2GameClients* pThis, CPlayerSlot slot,
                                                 const char* pszName, uint64 xuid,
                                                 const char* pszNetworkID, bool unk1,
                                                 CBufferString* pRejectReason)
{
    if (!V_strcmp(pszName, "rejected"))
        return { KHook::Action::Override, false };

    return { KHook::Action::Ignore, true };
}
```

`CallOriginal(pThis, args...)` runs the original from inside a handler,
bypassing the chain; return `Supersede` afterwards so it does not run twice.

### Return values

| `KHook::Action` | meaning |
|---|---|
| `Ignore` | did nothing |
| `Override` | original runs, your return value wins |
| `Supersede` | original is skipped entirely |

The toolkit's own listener callbacks (`RegisterConListener`, `HookGameEvent`,
net message hooks, entity output listeners) return the same type: `Action`
(`IToolkitTypes.h`) is an alias of `KHook::Action`, so a KHook handler hands a
listener's answer straight through. Timing there is a plain `bool post`:
`false` runs before the original, `true` after.

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

This project is licensed under the GNU General Public License v3.0, with a
linking exception for Valve's engines and games and a dual-licensing exception
for derivative works. See [LICENSE_INFO.txt](LICENSE_INFO.txt) for the terms
and [LICENSE](LICENSE) for the full GPLv3 text.

---

<div align="center">
  <strong>Everything you need to build Source2Toolkit plugins. Nothing more.</strong>
</div>
