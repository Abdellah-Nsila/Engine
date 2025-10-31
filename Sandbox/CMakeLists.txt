# Sandbox/CMakeLists.txt
project(Sandbox LANGUAGES CXX)

file(GLOB_RECURSE SANDBOX_SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(${PROJECT_NAME} ${SANDBOX_SOURCES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Engine
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/Engine/src
)
