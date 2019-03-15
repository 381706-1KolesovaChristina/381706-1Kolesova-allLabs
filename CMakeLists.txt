cmake_minimum_required(VERSION 2.8) 


set(PROJECT_NAME 381706-1Kolesova-allLabs) 

project(${PROJECT_NAME})
 

set(StackLib StackLib)
 
set(QueueLib QueueLib)

set(ExceptionLib ExceptionLib) 


set(PolishLib PolishLib)
set(Polish Polish)
set(PolishTest PolishTest)


set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)  

if(NOT CMAKE_BUILD_TYPE)
 
  set(CMAKE_BUILD_TYPE Release) 
endif()

file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 


#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) 


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)

add_subdirectory(gtest)



include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ExceptionLib)
add_subdirectory(ExceptionLib)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QueueLib)
add_subdirectory(QueueLib)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
add_subdirectory(StackLib) 


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolishLib)
add_subdirectory(PolishLib) 
add_subdirectory(Polish) 
add_subdirectory(PolishTest) 

