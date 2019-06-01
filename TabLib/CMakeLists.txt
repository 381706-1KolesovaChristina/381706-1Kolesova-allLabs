file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${TabLib} STATIC ${srcs} ${hdrs}) 

