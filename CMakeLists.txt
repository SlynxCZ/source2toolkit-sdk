cmake_minimum_required(VERSION 3.18)
project(source2toolkit-sdk CXX)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if (LINUX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static-libgcc -static-libstdc++")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--exclude-libs=libprotobuf.a")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        add_compile_definitions(_GLIBCXX_USE_CXX11_ABI=0)
    endif ()
endif ()

# =========================
# HL2SDK
# =========================

set(SOURCESDK ${CMAKE_CURRENT_SOURCE_DIR}/vendor/hl2sdk-cs2)
set(SOURCESDK_LIB ${SOURCESDK}/lib)
set(CSGO_PROTO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/Protobufs/csgo)

# =========================
# PLATFORM
# =========================

if (UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

if (WIN32 AND NOT MSVC)
    message(FATAL_ERROR "MSVC restricted.")
endif()

# =========================
# PROTOBUF
# =========================

include(protobuf.cmake)

# =========================
# GLOBAL CONFIG
# =========================

add_library(source2toolkit-config INTERFACE)

target_compile_definitions(source2toolkit-config INTERFACE
        META_IS_SOURCE2
        _ITERATOR_DEBUG_LEVEL=0

        $<$<PLATFORM_ID:Linux>:
        _LINUX POSIX LINUX GNUC COMPILER_GCC PLATFORM_64BITS
        _FILE_OFFSET_BITS=64
        _GLIBCXX_USE_CXX11_ABI=0

        stricmp=strcasecmp
        _stricmp=strcasecmp
        strnicmp=strncasecmp
        _strnicmp=strncasecmp
        _snprintf=snprintf
        _vsnprintf=vsnprintf
        _alloca=alloca
        strcmpi=strcasecmp
        >

        $<$<PLATFORM_ID:Windows>:
        COMPILER_MSVC COMPILER_MSVC64
        _WIN32 _WINDOWS
        _ALLOW_KEYWORD_MACROS
        __STDC_LIMIT_MACROS

        _CRT_SECURE_NO_WARNINGS=1
        _CRT_SECURE_NO_DEPRECATE=1
        _CRT_NONSTDC_NO_DEPRECATE=1
        >
)

target_compile_options(source2toolkit-config INTERFACE
        $<$<PLATFORM_ID:Linux>:
        -fPIC
        -fno-strict-aliasing
        -fno-threadsafe-statics

        -Wall
        -Wno-uninitialized
        -Wno-switch
        -Wno-unused
        -Wno-non-virtual-dtor
        -Wno-overloaded-virtual
        -Wno-conversion-null
        -Wno-write-strings
        -Wno-invalid-offsetof
        -Wno-reorder
        -Wno-error=stringop-overflow

        -mfpmath=sse
        -msse
        -fvisibility=default
        >

        $<$<PLATFORM_ID:Windows>:
        /wd4819
        /wd4828
        /wd5033
        /wd4005
        /permissive-
        /utf-8
        /MP
        >
)

target_link_options(source2toolkit-config INTERFACE
        $<$<PLATFORM_ID:Linux>:
        -Wl,--exclude-libs=libprotobuf.a
        >

        $<$<PLATFORM_ID:Windows>:
        $<$<CONFIG:RELEASE>:/OPT:REF>
        $<$<CONFIG:RELEASE>:/OPT:ICF>
        $<$<CONFIG:DEBUG>:/NODEFAULTLIB:libcmt>
        >
)

# =========================
# SDK LIB
# =========================

file(GLOB_RECURSE SOURCE_FILES
        public/*.cpp
        public/*.h
        public/*.hpp
)

list(APPEND SOURCE_FILES
        ${SOURCESDK}/public/tier0/memoverride.cpp
        ${SOURCESDK}/tier1/generichash.cpp
        ${SOURCESDK}/tier1/keyvalues3.cpp
        ${SOURCESDK}/tier1/convar.cpp
        ${SOURCESDK}/entity2/entityidentity.cpp
        ${SOURCESDK}/entity2/entitysystem.cpp
        ${SOURCESDK}/entity2/entitykeyvalues.cpp
)

add_library(source2toolkit-sdk STATIC ${SOURCE_FILES})

target_link_libraries(source2toolkit-sdk PUBLIC
        source2toolkit-config
)

target_include_directories(source2toolkit-sdk PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/public

        ${SOURCESDK}
        ${SOURCESDK}/thirdparty/protobuf-3.21.8/src
        ${SOURCESDK}/common
        ${SOURCESDK}/game/shared
        ${SOURCESDK}/game/server
        ${SOURCESDK}/public
        ${SOURCESDK}/public/engine
        ${SOURCESDK}/public/mathlib
        ${SOURCESDK}/public/tier0
        ${SOURCESDK}/public/tier1
        ${SOURCESDK}/public/entity2
        ${SOURCESDK}/public/game/server
        ${SOURCESDK}/public/schemasystem
)

# =========================
# LINK SDK DEPENDENCIES
# =========================

if (LINUX)
    target_link_libraries(source2toolkit-sdk PUBLIC
            ${SOURCESDK_LIB}/linux64/libtier0.so
            ${SOURCESDK_LIB}/linux64/tier1.a
            ${SOURCESDK_LIB}/linux64/interfaces.a
            ${SOURCESDK_LIB}/linux64/mathlib.a
            ${SOURCESDK}/lib/linux64/release/libprotobuf.a
            Protobufs
    )
endif()

if (WIN32)
    target_link_libraries(source2toolkit-sdk PUBLIC
            ${SOURCESDK_LIB}/public/win64/tier0.lib
            ${SOURCESDK_LIB}/public/win64/tier1.lib
            ${SOURCESDK_LIB}/public/win64/interfaces.lib
            ${SOURCESDK_LIB}/public/win64/mathlib.lib
            ${SOURCESDK_LIB}/public/win64/2015/libprotobuf.lib
            Protobufs
    )
endif()

# =========================
# HELPER
# =========================

function(add_s2toolkit_plugin name)
    add_library(${name} SHARED ${ARGN})

    target_link_libraries(${name}
            source2toolkit-sdk
    )

    set_target_properties(${name} PROPERTIES
            PREFIX ""
            SUFFIX ".stx"
    )
endfunction()
