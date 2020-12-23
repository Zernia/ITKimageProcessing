cmake_minimum_required(VERSION 3.17)
project(Project3)
find_package(VTK REQUIRED)
find_package( ITK REQUIRED )
include(${VTK_USE_FILE} )
INCLUDE( ${ITK_USE_FILE} )

add_executable(Project3 Project3.cxx)
target_link_libraries(Project3 ${VTK_LIBRARIES} ${ITK_LIBRARIES})



