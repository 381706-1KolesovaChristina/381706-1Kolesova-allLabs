file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 

add_executable(${TreeTab} ${srcs} ${hdrs}) 

target_link_libraries(${TreeTab} ${TreeTabLib})

