/** cs124 project2 by Eyu on 10/9/21 */

#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include "Course.h"
#include "AVLTREE.h"
#include "BINARYSEARCHTREE.h"
#include "SPLAYTREE.h"

using namespace std;

/**
 * random generator function
 */
int ranNum(int i){
    return rand()%i;
}


/**
 * Main
 */
int main() {
    /**
     * generate a random sequence for testing
     * source code from http://www.cplusplus.com/reference/algorithm/random_shuffle/
     **/
    srand ( unsigned ( time(0) ) );
    vector<int> ranVector;
    vector<int> ranVector_course;

    // set some values:
    for (int i=1; i<=100; ++i) ranVector.push_back(i);
    for (int i=0; i<=1000; ++i) ranVector_course.push_back(i);

    // using built-in random generator:
    random_shuffle ( ranVector.begin(), ranVector.end() );
    // using myrandom:
    random_shuffle ( ranVector.begin(), ranVector.end(), ranNum);

    // for course object testing
    random_shuffle ( ranVector_course.begin(), ranVector_course.end() );
    random_shuffle ( ranVector_course.begin(), ranVector_course.end(), ranNum);



    /**
     * We start with testing trees of integers
     * Binary Search Tree integer testing
     * testing with integers (in order and randomly), add it to the tree and print the depth when find it
     * */
    //binary search tree in order
    BinarySearchTree<int> binary1 = BinarySearchTree<int>();
    for (int i = 1; i <= 100; ++i) {
        binary1.add(i);
    }
    // Array created for storing depth value
    vector<int> arr1;
    // Timer set
    auto start1 = chrono::high_resolution_clock::now();
    for (int i = 1; i <= 100; ++i) {
        arr1.push_back(binary1.find(i));
    }
    auto stop1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(stop1 - start1);
    cout << "BST Search function execution time: "
              << duration1.count() << " microseconds" << endl;

    cout << "Depth to find 0: " << binary1.find(0) << endl;
    cout << "Depth to find 101: " << binary1.find(101) << endl;
    cout << "Depth to find 102: " << binary1.find(102) << endl;
    cout << endl;

    //binary search tree in random
    BinarySearchTree<int> binary2 = BinarySearchTree<int>();
    for (vector<int>::iterator it=ranVector.begin(); it!=ranVector.end(); ++it) {
        binary2.add(*it);
    }

    vector<int> arr2;
    auto start2 = chrono::high_resolution_clock::now();
    for (int i=1; i<=100; ++i) {
        arr2.push_back(binary2.find(i));
    }
    auto stop2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(stop2 - start2);
    cout << "BST Search function execution time: "
              << duration2.count() << " microseconds" << endl;


    /**
     * AVL Tree test with integers*/
    //AVL tree integer testing in order
    AVLTree<int> avl1 = AVLTree<int>();
    for (int i = 1; i <= 100; ++i) {
        avl1.add(i);
    }

    vector<int> arr3;
    auto start3 = chrono::high_resolution_clock::now();
    for (int i = 1; i <= 100; ++i) {
        arr3.push_back(avl1.find(i));
    }
    auto stop3 = chrono::high_resolution_clock::now();
    auto duration3 = chrono::duration_cast<chrono::microseconds>(stop3 - start3);
    cout << "AVL Search function execution time: "
              << duration3.count() << " microseconds" << endl;


    //random int sequence
    AVLTree<int> avl2 = AVLTree<int>();
    for (vector<int>::iterator it=ranVector.begin(); it!=ranVector.end(); ++it) {
        avl2.add(*it);
    }

    vector<int> arr4;
    auto start4 = chrono::high_resolution_clock::now();
    for (int i=1; i<=100; ++i) {
        arr4.push_back(avl2.find(i));
    }
    auto stop4 = chrono::high_resolution_clock::now();
    auto duration4 = chrono::duration_cast<chrono::microseconds>(stop4 - start4);
    cout << "AVL Search function execution time: "
              << duration4.count() << " microseconds" << endl;



    /**
     * splay tree test with integers
     * */
    SplayTree<int> splay1 = SplayTree<int>();
    for (int i = 1; i <= 100; ++i) {
        splay1.add(i);
    }

    vector<int> arr5;
    auto start5 = chrono::high_resolution_clock::now();
    for (int i = 1; i <= 100; ++i) {
        arr5.push_back(splay1.find(i));
    }
    auto stop5 = chrono::high_resolution_clock::now();
    auto duration5 = chrono::duration_cast<chrono::microseconds>(stop5 - start5);

    cout << "Splay Search function execution time: "
              << duration5.count() << " microseconds" << endl;

    //random int sequence
    SplayTree<int> splay2 = SplayTree<int>();
    for (vector<int>::iterator it=ranVector.begin(); it!=ranVector.end(); ++it) {
        splay2.add(*it);
    }
    vector<int> arr6;
    auto start6 = chrono::high_resolution_clock::now();
    for (int i=1; i<=100; ++i) {
        arr6.push_back(splay2.find(i));
    }
    auto stop6 = chrono::high_resolution_clock::now();
    auto duration6 = chrono::duration_cast<chrono::microseconds>(stop6 - start6);
    cout << "Splay Search function execution time: "
              << duration6.count() << " microseconds" << endl;

    ofstream outFile;
    outFile.open("tree_stores_ints.csv");
    outFile << "BST_order" << ", "
                "BST_random" << ", "
                "AVL_order" << ", "
                "AVL_random" << ", "
                "S_order" << ", "
                "S_random" << endl;
    for (int i = 0; i < 100; ++i){
        outFile << arr1.at(i) << ", "
                << arr2.at(i) << ", "
                << arr3.at(i) << ", "
                << arr4.at(i) << ", "
                << arr5.at(i) << ", "
                << arr6.at(i) << endl;

    }
    outFile.close();

    /** Read the csv file and store in BST, AVL tree and Splay tree */
    vector<Course> course;
    string fn = "../uvm_fall2021_courses.csv";

    if (loadFromFile(fn, course)) {
        cout << course.size() << " records read from file" << endl;
    } else {
        cout << "Something went wrong." << endl;
    }

    /** Binary Search Tree */
    BinarySearchTree<Course> binary3 = BinarySearchTree<Course>();
    for (int i = 0; i <= 1000; ++i) {
        binary3.add(course.at(i));
    }

    vector<int> arr_bst;
    for (int i = 0; i <= 1000; ++i) {
        arr_bst.push_back(binary3.find(course.at(i)));
    }

    /** AVL Tree */
    AVLTree<Course> avl3 = AVLTree<Course>();
    for (int i = 0; i <= 1000; ++i) {
        avl3.add(course.at(i));
    }
    vector<int> arr_avl;
    for (int i = 0; i <= 1000; ++i) {
        arr_avl.push_back(avl3.find(course.at(i)));
    }

    /** Splay Tree*/
    // addition: 2nd tree search objects randomly for 5 times
    SplayTree<Course> splay3 = SplayTree<Course>();
    SplayTree<Course> splay4 = SplayTree<Course>();
    for (int i = 0; i <= 1000; ++i) {
        splay3.add(course.at(i));
        splay4.add(course.at(i));
    }
    // Search in order
    vector<int> arr_splay_order;
    for (int i = 0; i <= 1000; ++i) {
        arr_splay_order.push_back(splay3.find(course.at(i)));
    }

    // Search in random for 5 times
    vector<int> arr_splay_random;
    int depthSplayCourse = 0;
    for (vector<int>::iterator it=ranVector_course.begin(); it!=ranVector_course.end(); ++it) {
        for (int t=1; t<=5; ++t) {
            depthSplayCourse = splay4.find(course.at(*it));
            arr_splay_random.push_back(depthSplayCourse);
        }
    }

    ofstream outFileCourse;
    outFileCourse.open("tree_stores_courses.csv");
    outFileCourse << "bst" << ", " << "avl" << ", " << "splay_order" << ", " << "splay_random_1"
                  << ", " << "splay_random_2" << ", " << "splay_random_3" << ", " << "splay_random_4" << ", " << "splay_random_5" << endl;
    for(int i=0; i<=1000; ++i){
        outFileCourse << arr_bst.at(i) << ", "
                      << arr_avl.at(i) << ", "
                      << arr_splay_order.at(i) << ", "
                      << arr_splay_random.at(i*5) << ", "
                      << arr_splay_random.at(i*5 + 1) << ", "
                      << arr_splay_random.at(i*5 + 2) << ", "
                      << arr_splay_random.at(i*5 + 3) << ", "
                      << arr_splay_random.at(i*5 + 4) << ", "
                      << endl;
    }
    outFileCourse.close();


    return 0;
}