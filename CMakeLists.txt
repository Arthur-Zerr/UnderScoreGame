cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

# set the project name
project(UnderScoreGame VERSION 1.0)

#SDL

set(INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/thirdparty/include/")

if (WIN32)
  message("Use Windows")
  if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(LIBRARY "${CMAKE_CURRENT_LIST_DIR}/thirdparty/lib/win/x64/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/thirdparty/lib/win/x64/SDL2main.lib")
  else ()
    set(LIBRARY "${CMAKE_CURRENT_LIST_DIR}/thirdparty/lib/win/x86/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/thirdparty/lib/win/x86/SDL2main.lib")
  endif ()
endif (WIN32)

if (UNIX)
  find_package(glfw3 3.3 REQUIRED)
  find_package(OpenGL REQUIRED)
endif (UNIX)

# add the executable
add_executable(UnderScoreGame main.cpp )


#target_include_directories(UnderScoreGame PUBLIC "${CMAKE_CURRENT_LIST_DIR}/thirdparty/include")

# Windows uses SDL2
if (WIN32)
  message("Copy Windows DLLs")
  if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(DLLS "${CMAKE_CURRENT_LIST_DIR}/thirdparty/lib/win/x64/SDL2.dll")
  else ()
    set(DLLS "${CMAKE_CURRENT_LIST_DIR}/thirdparty/lib/win/x86/SDL2.dll")
  endif ()
                                
  add_custom_command(TARGET UnderScoreGame POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${DLLS} ${CMAKE_CURRENT_BINARY_DIR}) 
endif (WIN32)


# MACOS uses GLFW
if (UNIX)
  target_link_libraries(UnderScoreGame glfw)
  target_link_libraries(UnderScoreGame OpenGL::GL)
endif (UNIX)
