cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.


set(PROJECT_NAME 381706-1Kolesova-allLabs) #Создаем обычную локальную переменную с именем проекта

project(${PROJECT_NAME}) # Название проекта



set (MStack MStack)
set(MStackLib MStackLib) #Переменная с именем библиотеки
set (MStackTest MStackTest)



set(ExceptionLib ExceptionLib)


set(StackLib StackLib)


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



include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MStackLib)

add_subdirectory(MStack)

add_subdirectory(MStackLib)

add_subdirectory(MStackTest)



include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)

add_subdirectory(StackLib)
