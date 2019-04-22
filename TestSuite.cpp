#include "TestSuite.h"
#include <stdlib.h> // for rand() function that will be used to test search()

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
    linkedList = new LinkedListOfInts;
    vector<int> linkedListVector;
    linkedListVector = linkedList->toVector();
    bool emptyCheck = false;
    bool filledCheck = false; 

    if (linkedListVector.empty()) {
        emptyCheck = linkedList->isEmpty(); 
        if (!emptyCheck) {
            cout << "testIsEmpty() FAILED: List is empty but isEmpty() returned false." << endl;
        }
    }

    int maxSize = 5;
    for (int i = 0; i < maxSize; i++) {
        linkedList->addBack(i);
        linkedList->addFront(i);
    }

    linkedListVector = linkedList->toVector(); 
    if(!(linkedListVector.empty())){
        filledCheck = !(linkedList->isEmpty());
        if (!filledCheck) {
            cout << "testIsEmpty() FAILED: List isn't empty, but isEmpty returned false." << endl;
        }
    }

    LinkedListOfInts *temp = linkedList;
    linkedList = nullptr;
    delete temp;

    return ((emptyCheck) && (filledCheck));
}

// Test to check if the LinkedListOfInts method size() works properly
bool TestSuite::testSize() {
    linkedList = new LinkedListOfInts;
    vector<int> linkedListVector;
    linkedListVector = linkedList->toVector();
    bool checkSizeEmpty = false;
    bool checkSizeNotEmpty = false;

    if (0 == linkedListVector.size()) {
        int linkedListSize = linkedList->size(); 
        if (linkedListVector.size() != linkedListSize) {
            cout << "testSize() FAILED: vector size was 0, but linked list size was: " << linkedListSize << endl;
            checkSizeEmpty = false;
        } else {
            checkSizeEmpty = true;
        }
    }

    int maxSize = 5;
    for (int i = 0; i < maxSize; i++) {
        linkedList->addFront(i);
        linkedList->addBack(i);
    }
    
    linkedListVector = linkedList->toVector();
    if ((maxSize * 2) == linkedListVector.size()) {
        int linkedListSize = linkedList->size(); 
        if (linkedListVector.size() != linkedListSize) {
            cout << "testSize() FAILED: size() function for linked list did not equal the output of the size(): "<<linkedListSize<< endl;
            checkSizeNotEmpty = false;
        } else {
            checkSizeNotEmpty = true;
        }
    }
    
    LinkedListOfInts *temp = linkedList;
    linkedList = nullptr;
    delete temp;

    return ((checkSizeEmpty) && (checkSizeNotEmpty));
}

// Test to check if the LinkedListOfInt method search() works properly
bool TestSuite::testSearch() {
    linkedList = new LinkedListOfInts;
    vector<int> linkedListVector;
    linkedListVector = linkedList->toVector();

    for (int i = 0; i < 100; i++) {
        linkedList->addFront(i);
    }
    linkedListVector = linkedList->toVector();

    int randomSearch = linkedListVector[rand() % 100];

    return (linkedList->search(randomSearch));
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
            cout << "testAddBack() FAILED: Added the value 0 to the back of an empty list, but 0 was not found." << endl;
            return false;
        }

        int maxSize = 10;
        for (int i = 1; i <= maxSize; i++) {
            linkedList->addBack(i);
            linkedListVector = linkedList->toVector();
            if (i != linkedListVector[linkedListVector.size() - 1]) {
                cout << "testAddBack() FAILED: Value entered at index " << linkedListVector.size() - 1 << " does not equal " << i << "." << endl;
                return false;
            }
        }

        cout << "testAddBack() PASSED" << endl;
        return true;
    }

    LinkedListOfInts *temp = linkedList;
    linkedList = nullptr;
    delete temp;
    return false;
}

// Test to check if the LinkedListOfInt method addFront() works properly
bool TestSuite::testAddFront() {
    linkedList = new LinkedListOfInts;
    vector<int> linkedListVector;
    linkedListVector = linkedList->toVector();

    if (linkedListVector.empty()) {
        linkedList->addFront(0);
        linkedListVector = linkedList->toVector();
        if (0 != linkedListVector[0]) {
            cout << "testAddFront() FAILED: Added the value 0 to the front of an empty list, but 0 was not found." << endl;
            return false;
        }

        int maxSize = 10;
        for (int i = 1; i <= maxSize; i++) {
            linkedList->addFront(i);
            linkedListVector = linkedList->toVector();
            if (i != linkedListVector[0]) {
                cout << "testAddFront() FAILED: Value entered at index " << linkedListVector.size() - 1 << " does not equal " << i << "." << endl;
                return false;
            }
        }

        cout << "testAddFront() PASSED" << endl;
        return true;
    }

    LinkedListOfInts *temp = linkedList;
    linkedList = nullptr;
    delete temp;
    return false;
}

// Test to check if the LinkedListOfInt method removeBack() works properly
bool TestSuite::testRemoveBack() {
    linkedList = new LinkedListOfInts;
    vector<int> linkedListVector;
    linkedListVector = linkedList->toVector();

    for (int i = 0; i < 5; i++) {
        linkedList->addBack(i);
    }
    
    linkedListVector = linkedList->toVector();
    int elementAtBack = linkedListVector[linkedListVector.size() - 1];
    linkedList->removeBack();
    linkedListVector = linkedList->toVector(); 

    if (linkedListVector[linkedListVector.size() - 1] == elementAtBack) {
        cout << "testRemoveBack() FAILED: last element of list should have been removed, but was still " << elementAtBack << "." << endl;
        return false;
    } else {
        cout << "testRemoveFront() PASSED" << endl;
        return true;
    }

    return false;
}

// Test to check if the LinkedListOfInt method removeFront() works properly
bool TestSuite::testRemoveFront() {
    linkedList = new LinkedListOfInts;
    vector<int> linkedListVector;
    linkedListVector = linkedList->toVector();

    for (int i = 0; i < 5; i++) {
        linkedList->addBack(i);
    }
    
    linkedListVector = linkedList->toVector();
    int elementAtFront = linkedListVector[0];
    linkedList->removeFront();
    linkedListVector = linkedList->toVector(); 

    if (linkedListVector[0] == elementAtFront) {
        cout << "testRemoveFront() FAILED: first element of list should have been removed, but was still " << elementAtFront << "." << endl;
        return false;
    } else {
        cout << "testRemoveFront() PASSED" << endl;
        return true;
    }

    return false;
}

void TestSuite::runTests() {
    bool emptyTest = false; 
    bool sizeTest = false; 
    bool searchTest = false; 
    bool addBackTest = false;
    bool addFrontTest = false; 
    bool removeBackTest = false;
    bool removeFrontTest = false; 


    emptyTest = testIsEmpty(); 
    cout << "Testing isEmpty(): ";
    if (emptyTest) {
        cout<< "TRUE" << endl; 
    } else {
        cout << "FALSE" << endl;
    }

    sizeTest = testSize(); 
    cout << "Testing size(): ";
    if (sizeTest) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }

    searchTest = testSearch(); 
    cout << "Testing search(): ";
    if (searchTest) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
    
    addBackTest = testAddBack(); 
    cout << "Testing addBack(): ";
    if (addBackTest) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
    
    addFrontTest = testAddFront();
    cout << "Testing addFront(): ";
    if (addFrontTest) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
    
    removeBackTest = testRemoveBack();
    cout << "Testing removeBack(): ";
    if (removeBackTest) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
    
    removeFrontTest = testRemoveFront();
    cout << "Testing removeBack(): ";
    if (removeFrontTest) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }

    cout << "TESTING DONE" << endl;
}