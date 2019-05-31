file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp") 

add_executable(${Plex} ${srcs} ${hdrs}) 

target_link_libraries(${Plex} ${PlexLib})

