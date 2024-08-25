#include "../include/RealTimeDynamicStorage.hpp"
#include <cstddef> // for size_t
#include <stdexcept> // if you're using std::out_of_range
#include <algorithm> // if you use std::copy

template<typename T, typename MemoryPolicy>
RealTimeDynamicStorage<T, MemoryPolicy>::RealTimeDynamicStorage(size_t initial_capacity)
    : array(MemoryPolicy::allocate(initial_capacity)), capacity(initial_capacity), size(0) {}

template<typename T, typename MemoryPolicy>
RealTimeDynamicStorage<T, MemoryPolicy>::~RealTimeDynamicStorage() {
    MemoryPolicy::deallocate(array);
}

template<typename T, typename MemoryPolicy>
void RealTimeDynamicStorage<T, MemoryPolicy>::push_back(const T& value) {
    if (size == capacity) {
        resize();
    }
    array[size++] = value;
}

template<typename T, typename MemoryPolicy>
T& RealTimeDynamicStorage<T, MemoryPolicy>::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

template<typename T, typename MemoryPolicy>
size_t RealTimeDynamicStorage<T, MemoryPolicy>::getSize() const {
    return size;
}

template<typename T, typename MemoryPolicy>
size_t RealTimeDynamicStorage<T, MemoryPolicy>::getCapacity() const {
    return capacity;
}

template<typename T, typename MemoryPolicy>
void RealTimeDynamicStorage<T, MemoryPolicy>::resize() {
    size_t newCapacity = capacity * 2 + 1;
    T* newArray = MemoryPolicy::allocate(newCapacity);
    std::copy(array, array + size, newArray);
    MemoryPolicy::deallocate(array);
    array = newArray;
    capacity = newCapacity;
}

// Explicit template instantiation
template class RealTimeDynamicStorage<int, StandardAllocator<int>>;
// Add more instantiations as needed for other types
