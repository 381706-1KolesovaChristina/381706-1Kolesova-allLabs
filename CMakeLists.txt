cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(Test1 381706-1Kolesova-allLabs) #Создаем обычную локальную переменную с именем проекта
project(${Test1}) # Название проекта

set(ExceptionLib ExceptionLib)

set(List List)
set(ListLib ListLib)
set(ListTest ListTest)

#set(MyLib1 MyLib1) #Переменная с именем библиотеки

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

#add_executable(${Vector} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ExceptionLib)
add_subdirectory(ExceptionLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
add_subdirectory(List) #Собираем проект в поддиректории lib1
add_subdirectory(ListLib) #Собираем проект в поддиректории lib1
add_subdirectory(ListTest)

#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}

