cmake_minimum_required(VERSION 2.8)

project (online_judge)

set(CMAKE_C_FLAGS "-Wall -Werror -pedantic -std=c11 -O2")
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -std=c++11 -O2")

file(GLOB tasks RELATIVE 
     "${CMAKE_SOURCE_DIR}/tasks" "${CMAKE_SOURCE_DIR}/tasks/*")

add_custom_target(check)
file(MAKE_DIRECTORY bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

foreach(dir ${tasks})

  if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/tasks/${dir})

    file(GLOB c_files "${CMAKE_SOURCE_DIR}/tasks/${dir}/src/*.c")
    file(GLOB cxx_files "${CMAKE_SOURCE_DIR}/tasks/${dir}/src/*.cpp")

    add_executable(${dir} ${c_files} ${cxx_files})

    add_custom_target(check_${dir} 
        ${CMAKE_SOURCE_DIR}/test.pl 
	${CMAKE_BINARY_DIR}/${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${dir} 
	${CMAKE_SOURCE_DIR}/tasks/${dir}/test)

    add_dependencies(check_${dir} ${dir})

    add_dependencies(check check_${dir})

  endif()

endforeach()
