file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${PlexLib} STATIC ${srcs} ${hdrs}) 

