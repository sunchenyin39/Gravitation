cmake_minimum_required (VERSION 3.8)

project ("Gravitation")

include_directories("${PROJECT_SOURCE_DIR}/include")

link_directories("${PROJECT_SOURCE_DIR}/lib")

aux_source_directory ( ${PROJECT_SOURCE_DIR}/src DIR_SRCS)

add_executable (Gravitation ${DIR_SRCS})

target_link_libraries(Gravitation EasyXa)
target_link_libraries(Gravitation EasyXw)

