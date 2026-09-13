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

A hook is one line in your class, written with a `KHOOK_*` macro from
`IToolkitHooks.h`. The macro takes the hook's type from the handler it names
(so the handler is declared above it), the context is the enclosing object,
and the last two arguments are the Pre and Post callbacks -- `nullptr` for the
side you do not need. `KHOOK_INIT()` in `Load()` resolves and installs every
hook the plugin declared, `KHOOK_DESTRUCT()` in `Unload()` takes them down; a
hook that cannot be resolved is logged and skipped.

```cpp
class MyPlugin final : public IToolkitPlugin
{
    KHook::Return<void> Hook_ClientCommand(ISource2GameClients* pThis, CPlayerSlot slot, const CCommand& args);
    KHook::Return<int64_t> Hook_TakeDamageOld(CBaseEntity* pThis, CTakeDamageInfo* pInfo, CTakeDamageResult* pResult);

    KHOOK_VIRTUAL(m_hClientCommand, &ISource2GameClients::ClientCommand, &g_pSource2GameClients, &MyPlugin::Hook_ClientCommand, nullptr);
    KHOOK_MEMBER(m_hTakeDamageOld, ADDR_TAKE_DAMAGE_OLD(), &MyPlugin::Hook_TakeDamageOld, nullptr);
};

bool MyPlugin::Load(...)  { TOOLKIT_SAVEVARS(); ...; KHOOK_INIT(); return true; }
bool MyPlugin::Unload(...) { KHOOK_DESTRUCT(); return true; }
```

### Virtual hooks

`KHOOK_VIRTUAL(member, function, target, pre, post)`. The function is
`&Class::Method` (index read from the pointer), an integer index, or a
gamedata offset name; the target is `&pInstance` (read at `KHOOK_INIT()`, so
the global may still be null now), `KHOOK_VTABLE(module, class)` for a whole
vtable by RTTI name (module as a name or as `&pModule`), or `nullptr` to
attach it yourself with `m_hX.Init(pInstance)` / `m_hX.InitGlobal(vtable)`:

```cpp
KHOOK_VIRTUAL(m_hSendNetMessage, &CServerSideClientBase::SendNetMessage, KHOOK_VTABLE("engine2", "CServerSideClient"), &MyPlugin::Hook_SendNetMessage, nullptr);
KHOOK_VIRTUAL(m_hRespawn, "CCSPlayerController::Respawn", KHOOK_VTABLE("server", "CCSPlayerController"), &MyPlugin::Hook_Respawn, nullptr);
```

A missing gamedata offset (-1) is refused rather than installed one slot before
the vtable.

### Function hooks

Anything a signature scan finds is hookable -- `KHOOK_MEMBER` when the
function has a `this`, `KHOOK_FUNCTION` when it does not. The target is a
gamedata entry name (resolved through `IToolkitGameConfig::ResolveSignature`,
by symbol or by pattern), an `IToolkitMemory`, an `ADDR_*` getter (what the toolkit already
resolved, no second scan -- the target is evaluated at `KHOOK_INIT()`, not when
the object is constructed), or `nullptr` for `m_hX.Init(address)` later:

```cpp
KHOOK_MEMBER(m_hPostThink, "CCSPlayerPawn::PostThink", &MyPlugin::Hook_PostThink, nullptr);
KHOOK_MEMBER(m_hTakeDamageOld, ADDR_TAKE_DAMAGE_OLD(), &MyPlugin::Hook_TakeDamageOld, nullptr);
```

The member forwards `->` to the KHook object underneath, so
`m_hX->CallOriginal(pThis, ...)` and the rest of KHook are there as before. A
raw KHook object is still an option (`KHOOK_NEW` in `IToolkitTypes.h`), with
the attaching, detaching and deleting left to you.

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
