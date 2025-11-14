#include "ABQ.hpp"
#include "ABS.hpp"
#include <iostream>

int main() {
    std::cout << "Testing capacity management for all array-based structures..." << std::endl;
    
    // Test ABQ
    std::cout << "\n=== Testing ABQ ===" << std::endl;
    ABQ<int> queue;
    
    // Grow
    for (int i = 1; i <= 8; ++i) {
        queue.enqueue(i);
        std::cout << "After enqueue " << i << " - capacity: " << queue.getMaxCapacity() << ", size: " << queue.getSize() << std::endl;
    }
    
    // Shrink
    for (int i = 0; i < 6; ++i) {
        queue.dequeue();
        std::cout << "After dequeue - capacity: " << queue.getMaxCapacity() << ", size: " << queue.getSize() << std::endl;
    }
    
    // Test ABS
    std::cout << "\n=== Testing ABS ===" << std::endl;
    ABS<int> stack;
    
    // Grow
    for (int i = 1; i <= 8; ++i) {
        stack.push(i);
        std::cout << "After push " << i << " - capacity: " << stack.getMaxCapacity() << ", size: " << stack.getSize() << std::endl;
    }
    
    // Shrink
    for (int i = 0; i < 6; ++i) {
        stack.pop();
        std::cout << "After pop - capacity: " << stack.getMaxCapacity() << ", size: " << stack.getSize() << std::endl;
    }
    
    std::cout << "\nAll tests completed successfully!" << std::endl;
    return 0;
}