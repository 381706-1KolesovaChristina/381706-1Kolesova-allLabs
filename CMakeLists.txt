cmake_minimum_required(VERSION 2.8) #�������� ������ CMake.

set(Test1 381706-1Kolesova-allLabs) #������� ������� ��������� ���������� � ������ �������
project(${Test1}) # �������� �������

set(Vector Vector)
set(VectorLib VectorLib)

#set(MyLib1 MyLib1) #���������� � ������ ����������

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #��������� ���������� CMAKE_CONFIGURATION_TYPES �� ��������� "Debug;Release" � ������/�������� Configs, ���������� ����������� � ����������� ����� ��������� �� ���� ������,
if(NOT CMAKE_BUILD_TYPE) # �������� ��������� � ����������� ��������� ������
  set(CMAKE_BUILD_TYPE Release) #���� ��� �� ������������� Release
endif()

#add_executable(${Vector} ${srcs} ${hdrs}) #������� ������ � ������ �� ���������� ${PROJECT_NAME}, � ���� ����������� ����� �� ���������� ${srcs} � ${hdrs}

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib)

add_subdirectory(Vector) #�������� ������ � ������������� lib1
add_subdirectory(VectorLib) #�������� ������ � ������������� lib1

#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #���������� � ������� � ������ ${PROJECT_NAME} ���������� � ������ ${MyLib1}

