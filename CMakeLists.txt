cmake_minimum_required(VERSION 3.18)
project(source2toolkit-sdk CXX)

set(CMAKE_CXX_STANDARD 20)

# =========================
# HL2SDK
# =========================

set(SOURCESDK_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/hl2sdk)
set(CSGO_PROTO_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/Protobufs)

set(SOURCESDK ${SOURCESDK_DIR}/cs2)
set(SOURCESDK_LIB ${SOURCESDK}/lib)

# =========================
# PLATFORM
# =========================

if (UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

# =========================
# PROTOBUF GENERATION
# =========================

set(PROTO_TARGETS
        ${CSGO_PROTO_DIR}/network_connection.proto
        ${CSGO_PROTO_DIR}/networkbasetypes.proto
        ${CSGO_PROTO_DIR}/cs_gameevents.proto
        ${CSGO_PROTO_DIR}/cs_usercmd.proto
        ${CSGO_PROTO_DIR}/base_gcmessages.proto
        ${CSGO_PROTO_DIR}/econ_gcmessages.proto
        ${CSGO_PROTO_DIR}/engine_gcmessages.proto
        ${CSGO_PROTO_DIR}/gcsdk_gcmessages.proto
        ${CSGO_PROTO_DIR}/gcsystemmsgs.proto
        ${CSGO_PROTO_DIR}/cstrike15_gcmessages.proto
        ${CSGO_PROTO_DIR}/cstrike15_usermessages.proto
        ${CSGO_PROTO_DIR}/source2_steam_stats.proto
        ${CSGO_PROTO_DIR}/netmessages.proto
        ${CSGO_PROTO_DIR}/networksystem_protomessages
        ${CSGO_PROTO_DIR}/steammessages.proto
        ${CSGO_PROTO_DIR}/usercmd.proto
        ${CSGO_PROTO_DIR}/usermessages.proto
        ${CSGO_PROTO_DIR}/gameevents.proto
        ${CSGO_PROTO_DIR}/clientmessages.proto
        ${CSGO_PROTO_DIR}/te.proto
)

if(UNIX)
    set(PROTOC_EXECUTABLE ${SOURCESDK_DIR}/devtools/bin/linux/protoc)
else()
    set(PROTOC_EXECUTABLE ${SOURCESDK_DIR}/devtools/bin/protoc.exe)
endif()

foreach(PROTO ${PROTO_TARGETS})
    get_filename_component(NAME ${PROTO} NAME_WLE)
    list(APPEND PROTO_OUTPUT ${CMAKE_BINARY_DIR}/protobuf/${NAME}.pb.cc)
    list(APPEND PROTO_HEADERS ${CMAKE_BINARY_DIR}/protobuf/${NAME}.pb.h)
    list(APPEND PROTO_INPUT ${PROTO})
endforeach()

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/protobuf)

add_custom_command(
        OUTPUT ${PROTO_OUTPUT}
        COMMAND ${PROTOC_EXECUTABLE}
        --proto_path=${CSGO_PROTO_DIR}
        --cpp_out=${CMAKE_BINARY_DIR}/protobuf
        ${PROTO_INPUT}
        DEPENDS ${PROTO_INPUT}
)

add_library(Protobufs STATIC ${PROTO_OUTPUT})

target_include_directories(Protobufs PUBLIC
        ${CMAKE_BINARY_DIR}/protobuf
        ${SOURCESDK_DIR}/thirdparty/protobuf-3.21.8/src
)

if (LINUX)
    target_link_libraries(Protobufs PUBLIC
            ${SOURCESDK_DIR}/lib/linux64/release/libprotobuf.a
    )
else()
    target_link_libraries(Protobufs PUBLIC
            ${SOURCESDK_DIR}/lib/public/win64/2015/libprotobuf.lib
    )
endif()

# =========================
# SDK TARGET
# =========================

add_library(source2toolkit-sdk INTERFACE)

# includes
target_include_directories(source2toolkit-sdk INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include

        ${SOURCESDK}
        ${SOURCESDK}/public
        ${SOURCESDK}/public/tier0
        ${SOURCESDK}/public/tier1
        ${SOURCESDK}/public/entity2
        ${SOURCESDK}/public/mathlib
        ${SOURCESDK}/public/engine
        ${SOURCESDK}/game/server

        ${SOURCESDK}/thirdparty/protobuf-3.21.8/src
)

# defines
target_compile_definitions(source2toolkit-sdk INTERFACE
        META_IS_SOURCE2
        _ITERATOR_DEBUG_LEVEL=0
)

# linux flags
if (LINUX)
    target_compile_definitions(source2toolkit-sdk INTERFACE
            _LINUX POSIX LINUX GNUC COMPILER_GCC PLATFORM_64BITS
            _FILE_OFFSET_BITS=64
            _GLIBCXX_USE_CXX11_ABI=0
    )

    target_compile_options(source2toolkit-sdk INTERFACE
            -fPIC
            -fno-strict-aliasing
            -fno-threadsafe-statics
    )

    target_link_libraries(source2toolkit-sdk INTERFACE
            ${SOURCESDK_LIB}/linux64/libtier0.so
            ${SOURCESDK_LIB}/linux64/tier1.a
            ${SOURCESDK_LIB}/linux64/interfaces.a
            ${SOURCESDK_LIB}/linux64/mathlib.a
            Protobufs
    )
endif()

# windows flags
if (WIN32)
    target_compile_definitions(source2toolkit-sdk INTERFACE
            _WIN32 _WINDOWS COMPILER_MSVC COMPILER_MSVC64
            _CRT_SECURE_NO_WARNINGS
    )

    target_link_libraries(source2toolkit-sdk INTERFACE
            ${SOURCESDK_LIB}/public/win64/tier0.lib
            ${SOURCESDK_LIB}/public/win64/tier1.lib
            ${SOURCESDK_LIB}/public/win64/interfaces.lib
            ${SOURCESDK_LIB}/public/win64/mathlib.lib
            Protobufs
    )
endif()

# =========================
# HELPER FUNCTION
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