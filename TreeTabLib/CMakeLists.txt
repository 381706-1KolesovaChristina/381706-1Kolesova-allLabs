file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${TreeTabLib} STATIC ${srcs} ${hdrs}) 

