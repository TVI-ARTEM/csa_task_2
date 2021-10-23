cmake_minimum_required(VERSION 3.20)
project(Task-2)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")
set(SOURCE_FILES
        # Headers
        functions/streamManage.h
        functions/random.h
        functions/tryParse.h
        matrix/Matrix.h
        matrix/Square.h
        matrix/Diagonal.h
        matrix/LTriangle.h
        container/Container.h

        # Sources
        matrix/Matrix.cpp
        matrix/Square.cpp
        matrix/Diagonal.cpp
        matrix/LTriangle.cpp
        container/Container.cpp
        main.cpp
)
add_executable(Task-2 "${SOURCE_FILES}")
