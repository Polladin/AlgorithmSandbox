cmake_minimum_required(VERSION 2.8)

project(Chapter6_sorting)


file(GLOB COMMON_HEADER   		        src/*.h)
file(GLOB COMMON_SRC      		        src/*.cpp)

file(GLOB MAX_HEAPIFY_HEADER  			src/max_heapify/*.h)
file(GLOB MAX_HEAPIFY_SRC      			src/max_heapify/*.cpp)

file(GLOB TASK_6_2_5_HEADER  			src/task_6_2_5/*.h)
file(GLOB TASK_6_2_5_SRC      			src/task_6_2_5/*.cpp)

file(GLOB HEAP_SORT_HEADER  			src/heap_sort/*.h)
file(GLOB HEAP_SORT_SRC      			src/heap_sort/*.cpp)

#################### Definitions #################################

add_definitions(-std=c++1y)

################## Include #############################################

include_directories(${PROJECT_SOURCE_DIR}/src)


################### Max-Heapify ##########################################

add_executable(MaxHeapify ${COMMON_SRC} ${COMMON_HEADER} 
                          ${MAX_HEAPIFY_SRC} ${MAX_HEAPIFY_HEADER})

################### Task 6.2.5 ##########################################

add_executable(Task_6_2_5 ${COMMON_SRC} ${COMMON_HEADER} 
                          ${TASK_6_2_5_SRC} ${TASK_6_2_5_HEADER})

################### Heap Sort ##########################################

add_executable(HeapSort   ${COMMON_SRC} ${COMMON_HEADER} 
                          ${HEAP_SORT_SRC} ${HEAP_SORT_HEADER})

                                