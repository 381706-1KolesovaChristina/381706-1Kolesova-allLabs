cmake_minimum_required(VERSION 2.8) 

set(PROJECT_NAME 381706-1_Kolesova_labs) 

project(${PROJECT_NAME}) 

set (TextLib TextLib)
set (Text Text)
set (TextTest TextTest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) 
if(NOT CMAKE_BUILD_TYPE) 
   set(CMAKE_BUILD_TYPE Release) 
endif()

include_directories (
${CMAKE_CURRENT_SOURCE_DIR}/TextLib
${CMAKE_CURRENT_SOURCE_DIR}/gtest
) 

add_subdirectory (TextLib TextLib)
add_subdirectory (Text Text)
add_subdirectory (TextTest TextTest)

add_subdirectory(gtest)


