cmake_minimum_required(VERSION 3.3)
project(AlgsStepic)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Intro/Fib/Fibonacci.hpp
                          Intro/GCD/GCD.hpp
                          Greedy/Intro/PointCover.hpp
                          Greedy/Intro/Bag.hpp
                          Greedy/Intro/SplitInteger.hpp
                          Greedy/Huffman/HuffmanTree.hpp
                          Greedy/PriorityQueue/PriorityQueue.hpp
                          DivideAndConquer/BinSearch/BinSearch.hpp
                          DivideAndConquer/Invertions/Invertions.hpp
                          DivideAndConquer/DotsOnLines/DotsOnLines.hpp
                          DivideAndConquer/CountSort/CountSort.hpp
                          Test6/First.hpp
                          Test6/Second.hpp
                          Test6/Third.hpp
                          Test6/Forth.hpp
                          DynamicProgramming/LIS/LDS.hpp
                          DynamicProgramming/LIS/LNIS.hpp
                          DynamicProgramming/EditingDistance/EditingDistance.hpp
                          DynamicProgramming/Bag/Bag.hpp DynamicProgramming/Overall/Stairs.hpp DynamicProgramming/Overall/Calculator.hpp Exam/First/MaxProd.hpp Exam/Second/Majority.hpp Exam/Forth/NumSum.hpp Exam/Fith/MaxSubset.hpp Exam/Third/LCS.hpp)

add_executable(AlgsStepic ${SOURCE_FILES})