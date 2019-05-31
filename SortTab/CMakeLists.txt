file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 

add_executable(${SortTab} ${srcs} ${hdrs}) 

target_link_libraries(${SortTab} ${SortTabLib})

