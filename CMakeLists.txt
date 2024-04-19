cmake_minimum_required(VERSION 3.15)

project(hipass LANGUAGES C CXX)

add_executable(${PROJECT_NAME}
	src/hipass.c
	src/clipboard.c
	src/generator.c
	src/rand.cpp
)

set(WARNINGS -Wall -Wextra -Wshadow)
set(DEBUG_SANITIZERS "$<$<CONFIG:Debug>:-fsanitize=address,undefined>")

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE src/lib)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_options(${PROJECT_NAME}
	PRIVATE
	${DEBUG_SANITIZERS}
	${WARNINGS})
target_link_options(${PROJECT_NAME} PRIVATE ${DEBUG_SANITIZERS})

include(CTest)
add_test(
	NAME Prefix
	COMMAND ${PROJECT_NAME})
