cmake_minimum_required(VERSION 2.8)

project(Chapter_7)

set(PROJECTS_TO_CREATE "task_7_1_2"
                       "task_7_1_4")

##################### Definitions #################################

add_definitions(-std=c++1y)

################### Include #############################################

include_directories(${PROJECT_SOURCE_DIR}/src)

#################### Common files ###################################

file(GLOB COMMON_HEADER   		        src/*.h)
file(GLOB COMMON_SRC      		        src/*.cpp)

#########################  Create Project  ############################################

foreach(project_name ${PROJECTS_TO_CREATE})                       
    
    file(GLOB ${project_name}_HEADER  			src/${project_name}/*.h)
    file(GLOB ${project_name}_SRC      			src/${project_name}/*.cpp)
    
    add_executable(${project_name} ${COMMON_SRC} ${COMMON_HEADER} 
                                   ${${project_name}_SRC} ${${project_name}_HEADER} )
    
endforeach()
                        