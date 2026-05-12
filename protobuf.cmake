# Credit for this protobuf generation cmake file goes to Poggicek.
# Based on their work at https://github.com/Poggicek/StickerInspect

set(PROTO_TARGETS
        ${PROTOBUFS}/network_connection.proto
        ${PROTOBUFS}/networkbasetypes.proto
        ${PROTOBUFS}/cs_gameevents.proto
        ${PROTOBUFS}/cs_usercmd.proto
        ${PROTOBUFS}/base_gcmessages.proto
        ${PROTOBUFS}/econ_gcmessages.proto
        ${PROTOBUFS}/engine_gcmessages.proto
        ${PROTOBUFS}/gcsdk_gcmessages.proto
        ${PROTOBUFS}/gcsystemmsgs.proto
        ${PROTOBUFS}/cstrike15_gcmessages.proto
        ${PROTOBUFS}/cstrike15_usermessages.proto
        ${PROTOBUFS}/source2_steam_stats.proto
        ${PROTOBUFS}/netmessages.proto
        ${PROTOBUFS}/networksystem_protomessages
        ${PROTOBUFS}/steammessages.proto
        ${PROTOBUFS}/usercmd.proto
        ${PROTOBUFS}/usermessages.proto
        ${PROTOBUFS}/gameevents.proto
        ${PROTOBUFS}/clientmessages.proto
        ${PROTOBUFS}/te.proto
)

if(UNIX)
    set(PROTOC_EXECUTABLE ${SOURCESDK}/devtools/bin/linux/protoc)
elseif(WIN32)
    set(PROTOC_EXECUTABLE ${SOURCESDK}/devtools/bin/protoc.exe)
endif()

foreach(PROTO_TARGET ${PROTO_TARGETS})
    get_filename_component(PROTO_FILENAME ${PROTO_TARGET} NAME_WLE)
    list(APPEND PROTO_OUTPUT ${PROTO_FILENAME}.pb.cc ${PROTO_FILENAME}.pb.h)
    list(APPEND PROTO_INPUT ${PROTO_FILENAME}.proto)
    get_filename_component(PROTO_PATH ${PROTO_TARGET} DIRECTORY)
    list(APPEND PROTO_PATHS "--proto_path=${PROTO_PATH}")
endforeach()

list(REMOVE_DUPLICATES PROTO_PATHS)
list(TRANSFORM PROTO_OUTPUT PREPEND ${CMAKE_CURRENT_BINARY_DIR}/protobufcompiler/)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/protobufcompiler)

add_custom_command(
        OUTPUT ${PROTO_OUTPUT}
        COMMAND "${PROTOC_EXECUTABLE}" -I ${SOURCESDK}/thirdparty/protobuf-3.21.8/src --proto_path=${PROTOBUFS} ${PROTO_PATHS} --cpp_out=${CMAKE_CURRENT_BINARY_DIR}/protobufcompiler ${PROTO_INPUT}
        COMMENT "Generating protobuf file"
)

add_library(Protobufs STATIC
        ${PROTO_OUTPUT}
)

target_include_directories(Protobufs
        PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/protobufcompiler
        PUBLIC ${SOURCESDK}/thirdparty/protobuf-3.21.8/src
)

if(WIN32)
    target_link_libraries(Protobufs PUBLIC ${SOURCESDK}/lib/public/win64/2015/libprotobuf.lib)
elseif(UNIX)
    target_link_libraries(Protobufs PUBLIC ${SOURCESDK}/lib/linux64/release/libprotobuf.a)
endif()
set_target_properties(Protobufs PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(Protobufs PROPERTIES FOLDER SDK)
