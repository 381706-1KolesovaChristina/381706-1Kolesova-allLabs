
file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 


add_executable(${SortTabTest} ${srcs} ${hdrs}) 
target_link_libraries(${SortTabTest} ${SortTabLib} gtest )
