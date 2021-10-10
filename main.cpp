/** cs124 project2 by Eyu on 6/7/21 */

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include "Course.h"
#include "AVLTREE.h"
#include "BINARYSEARCHTREE.h"
#include "SPLAYTREE.h"

/**
 * random generator function
 */
int ranNum(int i){
    return std::rand()%i;
}


/**
 * Main
 */
int main() {
    //generate a random sequence for testing
    //source code from http://www.cplusplus.com/reference/algorithm/random_shuffle/
    std::srand ( unsigned ( std::time(0) ) );
    std::vector<int> ranVector;
    std::vector<int> ranVector_course;

    // set some values:
    for (int i=1; i<=100; ++i) ranVector.push_back(i);
    for (int i=1; i<=1000; ++i) ranVector_course.push_back(i);

    // using built-in random generator:
    std::random_shuffle ( ranVector.begin(), ranVector.end() );
    // using myrandom:
    std::random_shuffle ( ranVector.begin(), ranVector.end(), ranNum);

    // for course object testing
    std::random_shuffle ( ranVector_course.begin(), ranVector_course.end() );
    std::random_shuffle ( ranVector_course.begin(), ranVector_course.end(), ranNum);



    /**
     * Binary Search Tree integer testing
     * testing with integers (in order and randomly), add it to the tree and print the depth to find it
     * */
    //binary search tree in order
    BinarySearchTree<int> binary1 = BinarySearchTree<int>();
    for (int i = 1; i <= 100; ++i) {
        binary1.add(i);
    }

    std::ofstream outFile;
    outFile.open("bst_int_orderly.csv");
    outFile << "depth" << std::endl;
    auto start1 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 100; ++i) {
        outFile << binary1.find(i) << std::endl;
    }
    auto stop1 = std::chrono::high_resolution_clock::now();
    outFile.close();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop1 - start1);

    std::cout << "BST Search function execution time: "
         << duration1.count() << " microseconds" << std::endl;

    std::cout << "Depth to find 0: " << binary1.find(0) << std::endl;
    std::cout << "Depth to find 101: " << binary1.find(101) << std::endl;
    std::cout << "Depth to find 102: " << binary1.find(102) << std::endl;
    std::cout << std::endl;


    //binary search tree in random
    BinarySearchTree<int> binary2 = BinarySearchTree<int>();
    for (std::vector<int>::iterator it=ranVector.begin(); it!=ranVector.end(); ++it) {
        binary2.add(*it);
    }

    std::ofstream outFile2;
    outFile2.open("bst_int_randomly.csv");
    outFile2 << "depth" << std::endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    for (std::vector<int>::iterator it=ranVector.begin(); it!=ranVector.end(); ++it) {
        outFile2 << binary2.find(*it) << std::endl;
    }
    outFile2.close();
    auto stop2 = std::chrono::high_resolution_clock::now();
    outFile.close();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2);

    std::cout << "BST Search function execution time: "
              << duration2.count() << " microseconds" << std::endl;

    std::cout << "Depth to find 0: " << binary2.find(0) << std::endl;
    std::cout << "Depth to find 101: " << binary2.find(101) << std::endl;
    std::cout << "Depth to find 102: " << binary2.find(102) << std::endl;
    std::cout << std::endl;

    /**
     * AVL Tree test with integers*/
    //AVL tree integer testing in order
    AVLTree<int> avl1 = AVLTree<int>();
    for (int i = 1; i <= 100; ++i) {
        avl1.add(i);
    }
    std::ofstream outFile4;
    outFile4.open("avl_int_orderly.csv");
    outFile4 << "depth" << std::endl;
    auto start3 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 100; ++i) {
        outFile4 << avl1.find(i) << std::endl;
    }
    outFile4.close();
    auto stop3 = std::chrono::high_resolution_clock::now();
    outFile.close();
    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(stop3 - start3);

    std::cout << "AVL Search function execution time: "
              << duration3.count() << " microseconds" << std::endl;

    std::cout << "Depth to find 0: " << avl1.find(0) << std::endl;
    std::cout << "Depth to find 101: " << avl1.find(101) << std::endl;
    std::cout << "Depth to find 102: " << avl1.find(102) << std::endl;

    std::cout << std::endl;

    //random int sequence
    AVLTree<int> avl2 = AVLTree<int>();
    for (std::vector<int>::iterator it=ranVector.begin(); it!=ranVector.end(); ++it) {
        avl2.add(*it);
    }

    std::ofstream outFile5;
    outFile5.open("avl_int_randomly.csv");
    outFile5 << "depth" << std::endl;
    auto start4 = std::chrono::high_resolution_clock::now();
    for (std::vector<int>::iterator it=ranVector.begin(); it!=ranVector.end(); ++it) {
        outFile5 << avl2.find(*it) << std::endl;
    }
    outFile5.close();
    auto stop4 = std::chrono::high_resolution_clock::now();
    outFile.close();
    auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(stop4 - start4);

    std::cout << "AVL Search function execution time: "
              << duration4.count() << " microseconds" << std::endl;

    std::cout << "Depth to find 0: " << avl2.find(0) << std::endl;
    std::cout << "Depth to find 101: " << avl2.find(101) << std::endl;
    std::cout << "Depth to find 102: " << avl2.find(102) << std::endl;
    std::cout << std::endl;



    /**
     * splay tree test with integers*/
    SplayTree<int> splay1 = SplayTree<int>();
    for (int i = 1; i <= 100; ++i) {
        splay1.add(i);
    }
    std::ofstream outFile7;
    outFile7.open("splay_int_orderly.csv");
    outFile7 << "depth" << std::endl;
    auto start5 = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= 100; ++i) {
        outFile7 << splay1.find(i) << std::endl;
    }
    outFile7.close();
    auto stop5 = std::chrono::high_resolution_clock::now();
    outFile.close();
    auto duration5 = std::chrono::duration_cast<std::chrono::microseconds>(stop5 - start5);

    std::cout << "Splay Search function execution time: "
              << duration5.count() << " microseconds" << std::endl;

    std::cout << "Depth to find 0: " << splay1.find(0) << std::endl;
    std::cout << "Depth to find 101: " << splay1.find(101) << std::endl;
    std::cout << "Depth to find 102: " << splay1.find(102) << std::endl;
    std::cout << std::endl;

    //random int sequence
    SplayTree<int> splay2 = SplayTree<int>();
    for (int i = 1; i <= 100; ++i) {
        splay2.add(i);
    }
    std::ofstream outFile8;
    outFile8.open("splay_int_randomly.csv");
    outFile8 << "depth" << std::endl;
    auto start6 = std::chrono::high_resolution_clock::now();
    for (std::vector<int>::iterator it=ranVector.begin(); it!=ranVector.end(); ++it) {
        outFile8 << splay2.find(*it) << std::endl;
    }
    outFile8.close();
    auto stop6 = std::chrono::high_resolution_clock::now();
    outFile.close();
    auto duration6 = std::chrono::duration_cast<std::chrono::microseconds>(stop6 - start6);

    std::cout << "Splay Search function execution time: "
              << duration6.count() << " microseconds" << std::endl;

    std::cout << "Depth to find 0: " << splay2.find(0) << std::endl;
    std::cout << "Depth to find 101: " << splay2.find(101) << std::endl;
    std::cout << "Depth to find 102: " << splay2.find(102) << std::endl;
    std::cout << std::endl;


    /**read the csv file and store in BST, AVL tree and Splay tree*/
    std::vector<Course> course;
    std::string fn = "../uvm_fall2021_courses.csv";

    if (loadFromFile(fn, course)) {
        std::cout << course.size()
                  << " records read from file" << std::endl;
    } else {
        std::cout << "Something went wrong." << std::endl;
    }

    // BST case
    BinarySearchTree<Course> binary3 = BinarySearchTree<Course>();
    for (int i = 0; i <= 1000; ++i) {
        binary3.add(course.at(i));
    }
    std::ofstream outFile3;
    outFile3.open("bst_courses.csv");
    outFile3 << "depth" << ", " << std::endl;
    for (int i = 0; i <= 1000; ++i) {
        outFile3 << binary3.find(course.at(i)) << std::endl;
    }
    outFile3.close();

    //AVL tree
    AVLTree<Course> avl3 = AVLTree<Course>();
    for (int i = 0; i <= 1000; ++i) {
        avl3.add(course.at(i));
    }
    std::ofstream outFile6;
    outFile6.open("avl_courses.csv");
    outFile6 << "depth" << std::endl;
    for (int i = 0; i <= 1000; ++i) {
        outFile6 << avl3.find(course.at(i)) << std::endl;
    }
    outFile6.close();

    // splay tree
    // addition: 2nd tree search objects randomly for 5 times
    SplayTree<Course> splay3 = SplayTree<Course>();
    SplayTree<Course> splay4 = SplayTree<Course>();
    for (int i = 0; i <= 1000; ++i) {
        splay3.add(course.at(i));
        splay4.add(course.at(i));
    }
    std::ofstream outFile9;
    outFile9.open("splay_courses.csv");
    outFile9 << "depth" << std::endl;
    for (int i = 0; i <= 1000; ++i) {
        outFile9 << splay3.find(course.at(i)) << std::endl;
    }
    outFile9.close();

    std::ofstream outFile10;
    outFile10.open("splay_course_random.csv");
    outFile10 << "depth" << ", " << "item" << std::endl;
    int depthSplayCourse = 0;
    for (std::vector<int>::iterator it=ranVector_course.begin(); it!=ranVector_course.end(); ++it) {
        for (int t=1; t<=5; ++t) {
            depthSplayCourse = splay4.find(course.at(*it));
        }
        outFile10 << depthSplayCourse << ", " << *it << std::endl;
    }
    outFile10.close();


    return 0;
}