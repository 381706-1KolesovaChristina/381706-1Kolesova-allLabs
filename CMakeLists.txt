cmake_minimum_required(VERSION 2.8) 

set(PROJECT_NAME 381706-1_Kolesova_labs) 

project(${PROJECT_NAME}) 

set (SortTabLib SortTabLib)
set (SortTab SortTab)
set (SortTabTest SortTabTest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) 
if(NOT CMAKE_BUILD_TYPE) 
   set(CMAKE_BUILD_TYPE Release) 
endif()

include_directories (
${CMAKE_CURRENT_SOURCE_DIR}/SortTabLib
${CMAKE_CURRENT_SOURCE_DIR}/gtest
) 

V

add_subdirectory(gtest)


