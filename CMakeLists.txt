cmake_minimum_required(VERSION 2.8) 

set(PROJECT_NAME 381706-1_Kolesova_labs) 

project(${PROJECT_NAME}) 

set (HashTabLib TabLib)
set (HashTab Tab)
set (HashTabTest HashTabTest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) 
if(NOT CMAKE_BUILD_TYPE) 
   set(CMAKE_BUILD_TYPE Release) 
endif()

add_subdirectory(HashTabLib)
add_subdirectory(HashTab)
add_subdirectory(HashTabTest)

add_subdirectory(gtest)


