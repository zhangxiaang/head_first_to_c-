cmake_minimum_required(VERSION 3.6)
project(c___primer_plus)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp exam_3/exam_3.cpp exam_3/exam_3.3.cpp smartpointer/wildpointer.cpp smartpointer/smart_prt.h template/template_1.cpp smartpointer/smart_ptrs.cpp smartpointer/smart_ptrs.h exam_3/vector.cpp exam_3/exam3.1x.cpp exam_3/iterator.cpp shm/shmdemo.cpp shm/shm_normal.cpp shm/relativeshm.cpp pipe/w_pipedemo.cpp pipe/r_pipedemo.cpp pipe/atomic_pipedemo.cpp pipe/relative_process_pipedemo.cpp pipe/read_named_pipe.cpp pipe/write_named_pipe.cpp pipe/simple_duplex_pipe.cpp array/array.cpp exam_3/cstringdemo.cpp array/multiDarray.cpp)
add_executable(c___primer_plus ${SOURCE_FILES})