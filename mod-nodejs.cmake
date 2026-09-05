if (CMAKE_SIZEOF_VOID_P LESS 8)
    message(FATAL_ERROR "Node.js support requires a 64-bit build")
endif()

# we set these before in CMakeLists.txt, just recover them here.
CU_GET_GLOBAL(NODEJS_INCLUDE_DIR)
CU_GET_GLOBAL(NODEJS_LIB)

message(STATUS "Node.js include path: ${NODEJS_INCLUDE_DIR}")
message(STATUS "Node.js library: ${NODEJS_LIB}")

target_link_libraries(modules PUBLIC ${NODEJS_LIB})
target_include_directories(modules SYSTEM PUBLIC
        ${NODEJS_INCLUDE_DIR}
)

# V8 headers require the compiler to report a real __cplusplus value.
# MSVC needs /Zc:__cplusplus for that, but the core compiles without it,
# so add it only on the modules target where mod-nodejs sources are built.
if (MSVC)
    target_compile_options(modules PRIVATE /Zc:__cplusplus)
endif()

# Embed a JS file as a constexpr char[] in a generated header.
# Included automatically by modules/CMakeLists.txt after the 'modules' target is created.

set(_INIT_SCRIPT_PATH ${CMAKE_SOURCE_DIR}/modules/mod-nodejs/src/init-script.js)
set(_HEADER_SOURCE_PATH ${CMAKE_SOURCE_DIR}/modules/mod-nodejs/src/NodeEmbeddedScriptFiles.h.in)
set(_GENERATED_HEADER ${CMAKE_BINARY_DIR}/mod-nodejs/NodeEmbeddedScriptFiles.h)

set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
        ${_INIT_SCRIPT_PATH}
)

file(READ ${_INIT_SCRIPT_PATH} _INIT_SCRIPT_CONTENT)

configure_file(${_HEADER_SOURCE_PATH} ${_GENERATED_HEADER} @ONLY)

target_include_directories(modules PRIVATE ${CMAKE_BINARY_DIR}/mod-nodejs)
