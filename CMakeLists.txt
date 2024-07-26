cmake_minimum_required(VERSION 3.20)

#variables
set(MY_Project_Name EmployeeDatabase)

project(${MY_Project_Name})

#setting standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Set the base directory for the project
set(PROJECT_BASE_DIR "${CMAKE_SOURCE_DIR}")

# Add the base directory as a definition to the compiler
add_definitions(-DPROJECT_BASE_DIR="${PROJECT_BASE_DIR}")

# Add subdirectories
add_subdirectory(lib/logician)
add_subdirectory(src/controller)
add_subdirectory(src/view)
add_subdirectory(src/shared)

# Define the header-only Model library
add_library(Model INTERFACE)

# Specify the include directory for the Model library
target_include_directories(Model INTERFACE ${CMAKE_SOURCE_DIR}/include/model)

#include paths
include_directories(${CMAKE_SOURCE_DIR}/include)

#Generating Executable
add_executable(${MY_Project_Name} main.cpp)

#link paths
target_link_libraries(${MY_Project_Name} PUBLIC logician Controller View Model Shared)