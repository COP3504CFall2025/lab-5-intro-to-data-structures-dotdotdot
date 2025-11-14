#include "ABDQ.hpp"
#include <iostream>
#include <exception>

int main() {
    try {
        std::cout << "Testing ABDQ..." << std::endl;
        
        // Test 1: Basic construction and size
        ABDQ<int> dq;
        std::cout << "Initial size: " << dq.getSize() << std::endl;
        
        // Test 2: Push operations
        std::cout << "Pushing elements..." << std::endl;
        dq.pushBack(1);
        dq.pushBack(2);
        dq.pushFront(0);
        std::cout << "Size after pushes: " << dq.getSize() << std::endl;
        
        // Test 3: Access operations
        std::cout << "Front: " << dq.front() << std::endl;
        std::cout << "Back: " << dq.back() << std::endl;
        
        // Test 4: Print operations
        std::cout << "Forward: ";
        dq.PrintForward();
        std::cout << "Reverse: ";
        dq.PrintReverse();
        
        // Test 5: Pop operations
        std::cout << "Popping front: " << dq.popFront() << std::endl;
        std::cout << "Popping back: " << dq.popBack() << std::endl;
        std::cout << "Size after pops: " << dq.getSize() << std::endl;
        
        // Test 6: Capacity expansion (push more than initial capacity of 4)
        std::cout << "Testing capacity expansion..." << std::endl;
        for (int i = 3; i <= 10; ++i) {
            dq.pushBack(i);
        }
        std::cout << "Size after expansion: " << dq.getSize() << std::endl;
        std::cout << "Forward after expansion: ";
        dq.PrintForward();
        
        // Test 7: Empty all elements
        std::cout << "Emptying deque..." << std::endl;
        while (dq.getSize() > 0) {
            std::cout << "Popped: " << dq.popFront() << " ";
        }
        std::cout << std::endl << "Final size: " << dq.getSize() << std::endl;
        
        // Test 8: Error handling (should throw runtime_error)
        std::cout << "Testing error handling..." << std::endl;
        try {
            dq.popFront(); // Should throw
            std::cout << "ERROR: Should have thrown exception!" << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "Correctly caught runtime_error for popFront on empty deque" << std::endl;
        }
        
        try {
            dq.front(); // Should throw
            std::cout << "ERROR: Should have thrown exception!" << std::endl;
        } catch (const std::runtime_error& e) {
            std::cout << "Correctly caught runtime_error for front on empty deque" << std::endl;
        }
        
        std::cout << "All tests passed!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}