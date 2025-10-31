cmake_minimum_required(VERSION 3.16)
project(LearnOpenGL VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable folders in IDEs like VSCode or CLion
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Add subdirectories
add_subdirectory(Engine)
add_subdirectory(Sandbox)
