if (CMAKE_SIZEOF_VOID_P LESS 8)
    message(FATAL_ERROR "Node.js support requires a 64-bit build")
endif()

if (LIBUV_LIB)
    message(STATUS "libuv library: ${LIBUV_LIB}")
else()
    # this needs to be passed in externally when Node.js was configured with --shared-libuv. Nix can
    # get away with this because it's Nix, but most builders will just link it statically, so just
    # using NODEJS_LIB for it is a fine fallback.
    set(LIBUV_LIB ${NODEJS_LIB})
    message(STATUS "libuv library: (use Node.js library)")
endif()

target_link_libraries(modules PUBLIC ${NODEJS_LIB} ${LIBUV_LIB})
target_include_directories(modules SYSTEM PUBLIC
        ${NODEJS_INCLUDE_DIR}
)

if (MSVC)
    target_compile_options(modules PRIVATE "/Zc:__cplusplus")
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
