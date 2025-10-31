# Engine/CMakeLists.txt
project(Engine LANGUAGES CXX)

# Collect all source files
file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE ENGINE_HEADERS CONFIGURE_DEPENDS src/*.h)

# Create shared library
add_library(${PROJECT_NAME} SHARED ${ENGINE_SOURCES} ${ENGINE_HEADERS})

# Enable position-independent code (needed for shared libs on Linux)
set_target_properties(${PROJECT_NAME} PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)

# --- Include directories ---
target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
)

# --- Platform-specific definitions ---
target_compile_definitions(${PROJECT_NAME} PUBLIC ENGINE_PLATFORM_LINUX)
