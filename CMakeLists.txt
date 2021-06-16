cmake_minimum_required(VERSION 3.19.0)
project(cube-rotation VERSION 0.0.1)

# Use more warnings
if(MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Werror)
endif()

add_executable("${PROJECT_NAME}" "src/Program.cpp")
