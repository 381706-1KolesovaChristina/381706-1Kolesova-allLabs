file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${SortTabLib} STATIC ${srcs} ${hdrs}) 

