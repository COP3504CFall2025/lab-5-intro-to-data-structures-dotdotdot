#include "ABQ.hpp"
#include <iostream>

int main() {
    std::cout << "Testing capacity shrinking..." << std::endl;
    
    ABQ<int> queue;
    
    // Start with capacity 1
    std::cout << "Initial capacity: " << queue.getMaxCapacity() << ", size: " << queue.getSize() << std::endl;
    
    // Add elements to trigger growth
    queue.enqueue(1);
    std::cout << "After 1 enqueue - capacity: " << queue.getMaxCapacity() << ", size: " << queue.getSize() << std::endl;
    
    queue.enqueue(2);  // Should grow to capacity 2
    std::cout << "After 2 enqueues - capacity: " << queue.getMaxCapacity() << ", size: " << queue.getSize() << std::endl;
    
    queue.enqueue(3);  // Should grow to capacity 4
    std::cout << "After 3 enqueues - capacity: " << queue.getMaxCapacity() << ", size: " << queue.getSize() << std::endl;
    
    queue.enqueue(4);
    std::cout << "After 4 enqueues - capacity: " << queue.getMaxCapacity() << ", size: " << queue.getSize() << std::endl;
    
    // Now dequeue to trigger shrinking
    queue.dequeue(); // size = 3, capacity should stay 4
    std::cout << "After 1 dequeue - capacity: " << queue.getMaxCapacity() << ", size: " << queue.getSize() << std::endl;
    
    queue.dequeue(); // size = 2, capacity should stay 4
    std::cout << "After 2 dequeues - capacity: " << queue.getMaxCapacity() << ", size: " << queue.getSize() << std::endl;
    
    queue.dequeue(); // size = 1, capacity should shrink to 2 (since 1 * 4 <= 4)
    std::cout << "After 3 dequeues - capacity: " << queue.getMaxCapacity() << ", size: " << queue.getSize() << std::endl;
    
    std::cout << "Test completed!" << std::endl;
    return 0;
}