#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <iostream>
#include "LinkedListOfInts.h"

using namespace std;


class TestSuite {
    public:

        // Constructor
        TestSuite();

        // Destructor
        ~TestSuite();

        // Test to check if the LinkedListOfInts function isEmpty() works properly
        bool testIsEmpty();

        // Test to check if the LinkedListOfInts function size() works properly
        bool testSize();

        // Test to check if the LinkedListOfInt function search() works properly
        bool testSearch();

        // Test to check if the LinkedListOfInt function addBack() works properly
        bool testAddBack();

        // Test to check if the LinkedListOfInt function addFront() works properly
        bool testAddFront();

        // Test to check if the LinkedListOfInt function removeBack() works properly
        bool testRemoveBack();

        // Test to check if the LinkedListOfInt function removeFront() works properly
        bool testRemoveFront();

        // Runs all of the tests. Called in main().
        bool runTests();

    private:

        LinkedListOfInts *linkedList;

};


#endif