#include "TestSuite.h"

using namespace std;

TestSuite::TestSuite() {
    linkedList = nullptr;
}

TestSuite::~TestSuite() {
    if (nullptr != linkedList) {
        delete linkedList;
    }
}

// Test to check if the LinkedListOfInts method isEmpty() works properly
bool TestSuite::testIsEmpty() {

}

// Test to check if the LinkedListOfInts method size() works properly
bool TestSuite::testSize() {

}

// Test to check if the LinkedListOfInt method search() works properly
bool TestSuite::testSearch() {

}

// Test to check if the LinkedListOfInt method addBack() works properly
bool TestSuite::testAddBack() {
    linkedList = new LinkedListOfInts;
    vector<int> linkedListVector;
    linkedListVector = linkedList->toVector();

    if (linkedListVector.empty()) {
        linkedList->addBack(0);
        linkedListVector = linkedList->toVector();
        if (0 != linkedListVector[0]) {
            cout << "FAILED: Added the value 0 to the back of an empty list, but 0 was not found." << endl;
            return false;
        }

        int maxSize = 10;
        for (int i = 1; i <= maxSize; i++) {
            linkedList->addBack(i);
            linkedListVector = linkedList->toVector();
            if (i != linkedListVector[linkedListVector.size() - 1]) {
                cout << "FAILED: Value entered at index " << linkedListVector.size() - 1 << " does not equal " << i << "." << endl;
                return false;
            }
        }
        cout << "PASSED" << endl;
        return true;
    }
    return false;
}

// Test to check if the LinkedListOfInt method addFront() works properly
bool TestSuite::testAddFront() {

}

// Test to check if the LinkedListOfInt method removeBack() works properly
bool TestSuite::testRemoveBack() {

}

// Test to check if the LinkedListOfInt method removeFront() works properly
bool TestSuite::testRemoveFront() {

}