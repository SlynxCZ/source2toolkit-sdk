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
- Integrated **KHook** hooking library  
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
- **KHook** (inline & virtual hooks)  
- **Protobuf definitions**  
- **Tier0 / Tier1 / Mathlib**  
- **Schema system headers**  
- **Preconfigured compiler flags & linking**  

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
