#pragma once
#include "../include/IStorageStrategy.hpp"
#include "../../dynamic_memory_storage/include/RealTimeDynamicStorage.hpp"

template<typename ContextType>
class CircularBufferStorageStrategy : public IStorageStrategy<ContextType> {
private:
    RealTimeDynamicStorage<ContextType> storage;
    size_t head;  // Points to the oldest element
    size_t tail;  // Points to the newest element
    size_t maxSize;  // Max size of the buffer

public:
    CircularBufferStorageStrategy(size_t capacity)
        : storage(capacity), head(0), tail(0), maxSize(capacity) {}

    void addContext(const ContextType& data) override {
        storage[tail] = data;  // Use RealTimeDynamicStorage for direct memory management
        tail = (tail + 1) % maxSize;
        if (tail == head) {
            head = (head + 1) % maxSize;  // Overwrite oldest if full
        }
    }

    ContextType getContext(size_t index) const override {
        if (index >= getSize()) {
            throw std::out_of_range("Index out of range");
        }
        return storage[(head + index) % maxSize];
    }

    void removeContext(size_t index) override {
        // This method may not be meaningful for a circular buffer
        throw std::logic_error("Remove operation not supported in CircularBuffer");
    }

    size_t getSize() const override {
        return (tail + maxSize - head) % maxSize;
    }

    void clear() override {
        head = tail = 0;
    }
};
