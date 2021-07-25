cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

# set the project name
project(UnderScoreGame VERSION 1.0)

if (WIN32)
  message("Use Windows")
endif (WIN32)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

# add the executable
add_executable(UnderScoreGame main.cpp)
target_link_libraries(UnderScoreGame glfw)
target_link_libraries(UnderScoreGame OpenGL::GL)

#target_include_directories(UnderScoreGame PUBLIC "${CMAKE_CURRENT_LIST_DIR}/thirdparty/include")

# if (UNIX)
#   message("Use MacOS")

#   file(GLOB LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/thirdparty/libs/macos/*.dylib")
#   message("LIBRARIES = ${LIBRARIES}")
  
#   target_link_libraries(UnderScoreGame PUBLIC ${LIBRARIES}})  

# endif (UNIX)
