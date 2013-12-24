cmake_minimum_required(VERSION 2.8)

project (SPOJ)

file(GLOB asdf RELATIVE 
     "${CMAKE_SOURCE_DIR}/tasks" "${CMAKE_SOURCE_DIR}/tasks/*")

add_custom_target(test)
add_custom_target(tags)

foreach(dir ${asdf})

  if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/tasks/${dir})

    file(GLOB c_files "${CMAKE_SOURCE_DIR}/tasks/${dir}/src/*.c")

    add_executable(${dir} ${c_files})

    add_custom_target(cscope_${dir} cd ${CMAKE_SOURCE_DIR}/tasks/${dir} && rm -f ctags.out && cscope -Rb)
    add_custom_target(ctags_${dir} cd ${CMAKE_SOURCE_DIR}/tasks/${dir} && rm -f tags && ctags -R)
    add_dependencies(tags cscope_${dir} ctags_${dir})
    add_dependencies(${dir} tags)

    add_custom_target(test_${dir} 
        ${CMAKE_SOURCE_DIR}/test.pl 
          ${CMAKE_BINARY_DIR}/${dir} 
          ${CMAKE_SOURCE_DIR}/tasks/${dir}/test)

    add_dependencies(test_${dir} ${dir})

    add_dependencies(test test_${dir})

  endif()

endforeach()
