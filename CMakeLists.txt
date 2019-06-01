cmake_minimum_required(VERSION 2.8) 

set(PROJECT_NAME 381706-1_Kolesova_labs) 

project(${PROJECT_NAME}) 

set (TreeTabLib TreeTabLib)
set (TreeTab TreeTab)
set (TreeTabTest TreeTabTest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) 
if(NOT CMAKE_BUILD_TYPE) 
   set(CMAKE_BUILD_TYPE Release) 
endif()

include_directories (
${CMAKE_CURRENT_SOURCE_DIR}/TreeTabLib
${CMAKE_CURRENT_SOURCE_DIR}/gtest
) 

add_subdirectory (TreeTabLib TreeTabLib)
add_subdirectory (TreeTab TreeTab)
add_subdirectory (TreeTabTest TreeTabTest)

add_subdirectory(gtest)


