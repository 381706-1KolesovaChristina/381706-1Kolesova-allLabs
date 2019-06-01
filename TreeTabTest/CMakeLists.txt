
file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 


add_executable(${TreeTabTest} ${srcs} ${hdrs}) 
target_link_libraries(${TreeTabTest} ${TreeTabLib} gtest )
