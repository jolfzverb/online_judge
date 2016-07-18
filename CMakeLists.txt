cmake_minimum_required(VERSION 2.8)

project (online_judge)

set(CMAKE_C_FLAGS "-Wall -Werror -pedantic -std=c11 -O2")
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -std=c++11 -O2")

add_custom_target(check)

include_directories(${CMAKE_SOURCE_DIR})

file(GLOB lib_test RELATIVE
     "${CMAKE_SOURCE_DIR}/lib/test" "${CMAKE_SOURCE_DIR}/lib/test/*.cpp")
file(MAKE_DIRECTORY test)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY test)
foreach(dir ${lib_test})

  add_executable(test_${dir} ${CMAKE_SOURCE_DIR}/lib/test/${lib_test})

  add_custom_target(test_lib_${dir} ${CMAKE_BINARY_DIR}/${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test_${dir})

  add_custom_target(prepare_${dir} ${CMAKE_SOURCE_DIR}/scripts/prepare_lib.sh
	  ${CMAKE_SOURCE_DIR}/lib/${dir})

  add_dependencies(test_${dir} prepare_${dir})

  add_dependencies(test_lib_${dir} test_${dir})

  add_dependencies(check test_lib_${dir})

endforeach()

file(GLOB tasks RELATIVE
     "${CMAKE_SOURCE_DIR}/tasks" "${CMAKE_SOURCE_DIR}/tasks/*")
file(MAKE_DIRECTORY bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

foreach(dir ${tasks})

  if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/tasks/${dir})

    file(GLOB c_files "${CMAKE_SOURCE_DIR}/tasks/${dir}/src/*.c")
    file(GLOB cxx_files "${CMAKE_SOURCE_DIR}/tasks/${dir}/src/*.cpp")

    add_executable(${dir} ${c_files} ${cxx_files})

    add_custom_target(check_${dir}
        ${CMAKE_SOURCE_DIR}/scripts/test.pl
	${CMAKE_BINARY_DIR}/${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${dir}
	${CMAKE_SOURCE_DIR}/tasks/${dir}/test)

    add_custom_target(prepare_${dir}
	    ${CMAKE_SOURCE_DIR}/scripts/prepare_solution.sh ${CMAKE_SOURCE_DIR}
	    ${c_files}${cxx_files} --no-release)

    add_dependencies(${dir} prepare_${dir})

    add_dependencies(check_${dir} ${dir})

    add_dependencies(check check_${dir})

  endif()

endforeach()
