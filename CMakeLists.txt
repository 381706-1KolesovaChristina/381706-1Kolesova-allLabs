cmake_minimum_required(VERSION 2.8) 

set(PROJECT_NAME 381706-1_Kolesova_labs) 

project(${PROJECT_NAME}) 

set (PlexLib PlexLib)
set (Plex Plex)
set (PlexTest PlexTest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) 
if(NOT CMAKE_BUILD_TYPE) 
   set(CMAKE_BUILD_TYPE Release) 
endif()

include_directories (
${CMAKE_CURRENT_SOURCE_DIR}/PlexLib
${CMAKE_CURRENT_SOURCE_DIR}/gtest
) 

add_subdirectory (PlexLib PlexLib)
add_subdirectory (Plex Plex)
add_subdirectory (PlexTest PlexTest)

add_subdirectory(gtest)


