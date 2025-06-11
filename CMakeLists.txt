/**
 * @file CMakeLists.txt
 *
 * @author Maksym Ostapenko <https://github.com/mak7ostapenko>
 */

cmake_minimum_required(VERSION 3.10.0)
project(firmware-math-lib VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wsign-conversion")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused -Wold-style-cast")

# Enable optimizations for embedded/firmware use
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g -DDEBUG")

# Main lib 
add_library(firmware-math-lib firmware-math-lib.cpp)
target_include_directories(firmware-math-lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    matrix/
    
)

# Tests
include(CTest)
enable_testing()

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

# test executables
add_executable(firmware-math-tests
    test/MatrixAssignmentTest.cpp
    test/MatrixHatveeTest.cpp          
    test/MatrixScalarMultiplicationTest.cpp  
    test/MatrixUpperRightTriangleTest.cpp  
    test/MatrixHelperTest.cpp          
    test/MatrixSetIdentityTest.cpp           
    test/MatrixVector2Test.cpp
    test/MatrixAttitudeTest.cpp    
    test/MatrixIntegralTest.cpp        
    test/MatrixSliceTest.cpp                 
    test/MatrixVector3Test.cpp
    test/MatrixCopyToTest.cpp      
    test/MatrixInverseTest.cpp         
    test/MatrixSparseVectorTest.cpp          
    test/MatrixVector4Test.cpp
    test/MatrixDcm2Test.cpp        
    test/MatrixLeastSquaresTest.cpp    
    test/MatrixSquareTest.cpp                
    test/MatrixVectorAssignmentTest.cpp
    test/MatrixDualTest.cpp        
    test/MatrixMultiplicationTest.cpp  
    test/MatrixTransposeTest.cpp             
    test/MatrixVectorTest.cpp
    test/MatrixFilterTest.cpp      
    test/MatrixPseudoInverseTest.cpp   
    test/MatrixUnwrapTest.cpp                
)

target_link_libraries(firmware-math-tests
    firmware-math-lib
    GTest::gtest
    GTest::gtest_main
    Threads::Threads
)

target_include_directories(firmware-math-tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    include/
)

include(GoogleTest)
gtest_discover_tests(firmware-math-tests)