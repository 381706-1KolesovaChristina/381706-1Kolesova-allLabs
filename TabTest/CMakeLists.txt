
file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 


add_executable(${TabTest} ${srcs} ${hdrs}) 
target_link_libraries(${TabTest} ${TabLib} gtest )
