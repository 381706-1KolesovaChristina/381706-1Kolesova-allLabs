file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 
add_executable(${HashTab} ${srcs} ${hdrs}) 

target_link_libraries(${HashTab} ${HashTabLib})

