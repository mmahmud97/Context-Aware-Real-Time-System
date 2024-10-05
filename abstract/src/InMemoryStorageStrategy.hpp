#pragma once
#include "../include/IStorageStrategy.hpp"
#include "../../dynamic_memory_storage/include/RealTimeDynamicStorage.hpp"
#include <stdexcept>  // For out_of_range exceptions

// In-memory storage strategy for high-speed access to context data.
template<typename ContextType>
class InMemoryStorageStrategy : public IStorageStrategy<ContextType> {
private:
    RealTimeDynamicStorage<ContextType> storage;  // Underlying dynamic memory storage

public:
    // Constructor to initialize the in-memory storage with a given capacity
    InMemoryStorageStrategy(size_t capacity) : storage(capacity) {}

    // Add context data to in-memory storage
    void addContext(const ContextType& data) override {
        storage.push_back(data);  // Push new context data into storage
    }

    // Retrieve context data by index
    ContextType getContext(size_t index) const override {
        if (index >= storage.getSize()) {
            throw std::out_of_range("Index out of range");
        }
        return storage[index];  // Return context from in-memory storage
    }

    // Remove context data by index
    void removeContext(size_t index) override {
        if (index >= storage.getSize()) {
            throw std::out_of_range("Index out of range");
        }
        storage.remove(index);  // Remove context data at the specified index
    }

    // Get the size of stored context data
    size_t getSize() const override {
        return storage.getSize();  // Return the number of elements in storage
    }

    // Clear all stored context data
    void clear() override {
        storage.clear();  // Clear the in-memory storage
    }
};
