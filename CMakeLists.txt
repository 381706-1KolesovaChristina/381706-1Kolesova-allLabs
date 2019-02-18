cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME 381706-1Kolesova-allLabs) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set (ListLib ListLib)
set(Exception Exception)

set(StackList StackList)
set(StackListLib StackListLib) 
set (StackListTest StackListTest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .h


#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)

add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
add_subdirectory(ListLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Exception)
add_subdirectory(Exception)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
add_subdirectory(StackList)
add_subdirectory(StackListLib)
add_subdirectory(StackListTest)
