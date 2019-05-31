file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 
add_executable(${Tab} ${srcs} ${hdrs}) 

target_link_libraries(${Tab} ${TabLib})

