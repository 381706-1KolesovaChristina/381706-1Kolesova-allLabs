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

set (TextLib TextLib)
set (Text Text)
set (TextTest TextTest)


#set (PlexLib PlexLib)
#set (Plex Plex)
#set (PlexTest PlexTest)

#set (TabLib TabLib)
#set (Tab Tab)
#set (TabTest TabTest)

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
${CMAKE_CURRENT_SOURCE_DIR}/TextLib
#${CMAKE_CURRENT_SOURCE_DIR}/PlexLib
#${CMAKE_CURRENT_SOURCE_DIR}/TabLib
#${CMAKE_CURRENT_SOURCE_DIR}/SortTabLib
#${CMAKE_CURRENT_SOURCE_DIR}/TreeTabLib
${CMAKE_CURRENT_SOURCE_DIR}/gtest
) 

#add_subdirectory (Vector Vector) 
#add_subdirectory (VectorLib VectorLib)

#add_subdirectory (Test Test)

#add_subdirectory (MatrixLib MatrixLib)
#add_subdirectory (Matrix Matrix)

#add_subdirectory (StackLib StackLib)
#add_subdirectory (Stack Stack)

#add_subdirectory (MStackLib MStackLib)
#add_subdirectory (MStack MStack)

#add_subdirectory (QueueLib QueueLib)
#add_subdirectory (Queue Queue)

#add_subdirectory (ListLib ListLib)
#add_subdirectory (List List)

#add_subdirectory (ListMasLib ListMasLib)
#add_subdirectory (ListMas ListMas)

#add_subdirectory (PolyLib PolyLib)
#add_subdirectory (Poly Poly)

#add_subdirectory (StackListLib StackListLib)
#add_subdirectory (StackList StackList)

#add_subdirectory (ObrPolLib ObrPolLib)
#add_subdirectory (ObrPol ObrPol)

add_subdirectory (TextLib TextLib)
add_subdirectory (Text Text)
add_subdirectory (TextTest TextTest)


#add_subdirectory (PlexLib PlexLib)
#add_subdirectory (Plex Plex)
#add_subdirectory (PlexTest PlexTest)

#add_subdirectory (TabLib TabLib)
#add_subdirectory (Tab Tab)
#add_subdirectory (TabTest TabTest)

#add_subdirectory (SortTabLib SortTabLib)
#add_subdirectory (SortTab SortTab)
#add_subdirectory (SortTabTest SortTabTest)

#add_subdirectory (TreeTabLib TreeTabLib)
#add_subdirectory (TreeTab TreeTab)
#add_subdirectory (TreeTabTest TreeTabTest)

add_subdirectory(gtest)

