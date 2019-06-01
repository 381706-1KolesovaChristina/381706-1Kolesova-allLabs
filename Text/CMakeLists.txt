file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 

add_executable(${Text} ${srcs} ${hdrs}) 

target_link_libraries(${Text} ${TextLib})

