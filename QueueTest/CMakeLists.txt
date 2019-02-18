#set(target ${MP2_TESTS})
file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(${QueueTest} ${srcs} ${hdrs})

#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty")

target_link_libraries(${QueueTest} ${QueueLib} gtest)
