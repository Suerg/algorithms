cmake_minimum_required(VERSION 3.7)
project(algorithms)

include_directories(data-structures/include)
include_directories(sorting/include)

# only use certain files for now since the
# project isn't done yet
set(SOURCES
    sorting/src/basicSorts.c
    data-structures/src/linked-list.c
    data-structures/src/queue.c
    data-structures/src/stack.c
    src/sorting-main.c)

add_executable(sorting-main ${SOURCES})
