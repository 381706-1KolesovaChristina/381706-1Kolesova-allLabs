file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${VectorLib} STATIC ${srcs} ${hdrs}) 

