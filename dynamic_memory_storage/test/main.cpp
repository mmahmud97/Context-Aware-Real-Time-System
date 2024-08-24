#include <iostream>
#include <stdexcept>
#include "../include/RealTimeDynamicStorage.hpp"

int main() {
    // 1. Create an instance of the RealTimeDynamicStorage class for integers
    RealTimeDynamicStorage<int> storage;

    // 2. Attempt to access an element in the empty storage
    try {
        std::cout << "Trying to access element at index 0 in an empty storage: " << std::endl;
        std::cout << storage[0] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // 3. Add some elements to the storage
    storage.push_back(10);
    storage.push_back(20);
    storage.push_back(30);

    // 4. Output the elements stored
    std::cout << "Element at index 0: " << storage[0] << std::endl;
    std::cout << "Element at index 1: " << storage[1] << std::endl;
    std::cout << "Element at index 2: " << storage[2] << std::endl;

    // 5. Output the size and capacity of the storage
    std::cout << "Storage size: " << storage.getSize() << std::endl;
    std::cout << "Storage capacity: " << storage.getCapacity() << std::endl;

    // 6. Attempt to access an out-of-bounds index
    try {
        std::cout << "Trying to access element at out-of-bounds index 10: " << std::endl;
        std::cout << storage[10] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // 7. Large number of elements test
    std::cout << "Adding a large number of elements..." << std::endl;
    try {
        for (int i = 0; i < 100000; ++i) {
            storage.push_back(i);
        }
        std::cout << "Successfully added 100000 elements." << std::endl;
        std::cout << "Storage size after adding elements: " << storage.getSize() << std::endl;
        std::cout << "Storage capacity after adding elements: " << storage.getCapacity() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception during large element addition: " << e.what() << std::endl;
    }

    // 8. Memory limit test
    try {
        std::cout << "Attempting to add elements until memory limit is reached..." << std::endl;
        while (true) {
            storage.push_back(1);
        }
    } catch (const std::bad_alloc& e) {
        std::cout << "Caught memory allocation exception: " << e.what() << std::endl;
    }

    return 0;
}

