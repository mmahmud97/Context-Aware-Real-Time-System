// RealTimeDynamicStorage.hpp
#pragma once

#include "IDynamicStorage.hpp"
#include "MemoryPolicies.hpp"
#include <cstddef>  // For size_t
#include <stdexcept> // For std::out_of_range
#include <algorithm> // For std::copy

template<typename T, typename MemoryPolicy = StandardAllocator<T>>
class RealTimeDynamicStorage : public IDynamicStorage<T> {
private:
    T* array;          // Pointer to dynamically allocated array
    size_t capacity;   // Maximum number of elements array can hold
    size_t size;       // Current number of elements in array

public:
    // Constructor with default capacity
    RealTimeDynamicStorage(size_t initial_capacity = 10);

    // Destructor
    virtual ~RealTimeDynamicStorage();

    // Override the pure virtual functions from IDynamicStorage
    virtual void push_back(const T& value) override;
    virtual T& operator[](size_t index) override;
    virtual size_t getSize() const override;
    virtual size_t getCapacity() const override;

private:
    // Function to resize the storage
    void resize();
};

