cmake_minimum_required(VERSION 3.25.0)    # CMake version check
project("ManagementSystem")               # Create project 


# Add executable target 
add_executable("${PROJECT_NAME}" "main.cpp")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "main.cpp" DESTINATION src)
