if (CMAKE_SIZEOF_VOID_P LESS 8)
    message(FATAL_ERROR "Node.js support requires a 64-bit build")
endif()

if ((NOT NODEJS_INCLUDE_DIR) OR (NOT NODEJS_LIB))
    if (NOT WIN32)
        # I don't know of anywhere to find this pre-built the way we need it to be.
        message(FATAL_ERROR "Must pass -DNODEJS_INCLUDE_DIR and -DNODEJS_LIB flags when building with mod_nodejs.")
    endif()

    message(STATUS "Using Node.js v26.7.0 from nodejs.org")

    include(FetchContent)
    FetchContent_Declare(
            nodejs_win32

            URL                        https://nodejs.org/dist/v26.7.0/node-v26.7.0-win-x64.7z
            URL_HASH                   SHA256=073be1a597ff9f0130b067fb35eb84225d3970fdd7a84ee898f4b6270aadec0f
            DOWNLOAD_EXTRACT_TIMESTAMP true
    )

    FetchContent_Declare(
            nodejs_headers

            URL                        https://nodejs.org/dist/v26.7.0/node-v26.7.0-headers.tar.xz
            URL_HASH                   SHA256=453153ebefe7999965211df9ad3029f99a3c57b89eded9862e17be7ee0aaf1ba
            DOWNLOAD_EXTRACT_TIMESTAMP true
    )

    FetchContent_MakeAvailable(nodejs_win32 nodejs_headers)

    set(NODEJS_INCLUDE_DIR "${nodejs_headers_SOURCE_DIR}/include/node")
    set(NODEJS_LIB "${nodejs_win32_SOURCE_DIR}/nodejs.lib")
    file(
            DOWNLOAD
            https://nodejs.org/dist/v26.7.0/win-x64/node.lib
            "${NODEJS_LIB}"
            EXPECTED_HASH SHA256=56f06350037085fce04930befd98327afc86ee46f52af6f6f8a68a03630e8380
    )
endif()

message(STATUS "Node.js include path: ${NODEJS_INCLUDE_DIR}")
message(STATUS "Node.js library: ${NODEJS_LIB}")

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
