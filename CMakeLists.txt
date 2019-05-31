cmake_minimum_required(VERSION 2.8) 

set(PROJECT_NAME 381706-1_Soboleva_labs) 

project(${PROJECT_NAME}) 

#set (Vector Vector) 
#set (VectorLib VectorLib)

#set (Test Test)

#set (MatrixLib MatrixLib)
#set (Matrix Matrix)

#set (StackLib StackLib)
#set (Stack Stack)

#set (MStackLib MStackLib)
#set (MStack MStack)

#set (QueueLib QueueLib)
#set (Queue Queue)

#set (ListLib ListLib)
#set (List List)

#set (ListMasLib ListMasLib)
#set (ListMas ListMas)

#set (PolyLib PolyLib)
#set (Poly Poly)

#set (StackListLib StackListLib)
#set (StackList StackList)

#set (ObrPolLib ObrPolLib)
#set (ObrPol ObrPol)

set (TabLib TabLib)
set (Tab Tab)
set (TabTest TabTest)

#set (SortTabLib SortTabLib)
#set (SortTab SortTab)
#set (SortTabTest SortTabTest)

#set (TreeTabLib TreeTabLib)
#set (TreeTab TreeTab)
#set (TreeTabTest TreeTabTest)



set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) 
if(NOT CMAKE_BUILD_TYPE) 
   set(CMAKE_BUILD_TYPE Release) 
endif()

include_directories (
#${CMAKE_CURRENT_SOURCE_DIR}/VectorLib
#${CMAKE_CURRENT_SOURCE_DIR}/MatrixLib
#${CMAKE_CURRENT_SOURCE_DIR}/StackLib
#${CMAKE_CURRENT_SOURCE_DIR}/MStackLib
#${CMAKE_CURRENT_SOURCE_DIR}/QueueLib
#${CMAKE_CURRENT_SOURCE_DIR}/ListLib
#${CMAKE_CURRENT_SOURCE_DIR}/ListMasLib
#${CMAKE_CURRENT_SOURCE_DIR}/StackListLib
#${CMAKE_CURRENT_SOURCE_DIR}/PolyLib
#${CMAKE_CURRENT_SOURCE_DIR}/ObrPolLib
${CMAKE_CURRENT_SOURCE_DIR}/TabLib
#${CMAKE_CURRENT_SOURCE_DIR}/SortTabLib
#${CMAKE_CURRENT_SOURCE_DIR}/TreeTabLib
${CMAKE_CURRENT_SOURCE_DIR}/gtest
) 

#add_subdirectory(VectorLib)
#add_subdirectory(Vector)

#add_subdirectory(MatrixLib)
#add_subdirectory(Matrix)

#add_subdirectory(StackLib)
#add_subdirectory(Stack)

#add_subdirectory(MStackLib)
#add_subdirectory(MStack)

#add_subdirectory(QueueLib)
#add_subdirectory(Queue)

#add_subdirectory(ListLib)
#add_subdirectory(List)

#add_subdirectory(ListMasLib)
#add_subdirectory(ListMas)

#add_subdirectory(StackListLib)
#add_subdirectory(StackList)

#add_subdirectory(PolyLib)
#add_subdirectory(Poly)

#add_subdirectory(ObrPolLib)
#add_subdirectory(ObrPol)

add_subdirectory(TabLib)
add_subdirectory(Tab)
add_subdirectory(TabTest)

#add_subdirectory(SortTabLib)
#add_subdirectory(SortTab)
#add_subdirectory(SortTabTest)

#add_subdirectory(TreeTabLib)
#add_subdirectory(TreeTab)
#add_subdirectory(TreeTabTest)

#add_subdirectory(Test)

add_subdirectory(gtest)

