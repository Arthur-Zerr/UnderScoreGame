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

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_SOURCE_DIR}/src/*.cpp)
	
# Add header files
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_SOURCE_DIR}/src/*.hpp)

# add the executable
add_executable(UnderScoreGame main.cpp ${HEADER_FILES} ${SOURCE_FILES})

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

target_link_libraries(UnderScoreGame OpenGL::GL)

target_include_directories(UnderScoreGame PUBLIC ${INCLUDE_DIR})

# MACOS
if (UNIX)
  message("${SDL2_LIBRARIES}")
  target_link_libraries(UnderScoreGame ${SDL2_LIBRARIES})
endif (UNIX)

if (WIN32)
  target_link_libraries(UnderScoreGame ${LIBRARY})
endif (WIN32)
