#pragma once
#include "../include/IStorageStrategy.hpp"
#include "../../libs/dynamic_memory_storage/dynamic_memory_storage/include/RealTimeDynamicStorage.hpp"
#include <mutex>

template<typename ContextType>
class TransactionalStorageStrategy : public IStorageStrategy<ContextType> {
private:
    RealTimeDynamicStorage<ContextType> storage;  // Underlying storage for transactional data
    std::mutex storageMutex;  // Mutex for thread safety

public:
    TransactionalStorageStrategy(size_t capacity) : storage(capacity) {}

    void addContext(const ContextType& data) override {
        std::lock_guard<std::mutex> lock(storageMutex);  // Lock for thread-safe operation
        storage.push_back(data);  // Add transactional data
    }

    ContextType getContext(size_t index) const override {
        std::lock_guard<std::mutex> lock(storageMutex);  // Lock for thread-safe access
        return storage[index];  // Access transactional data
    }

    void removeContext(size_t index) override {
        std::lock_guard<std::mutex> lock(storageMutex);  // Lock for thread-safe modification
        storage.remove(index);  // Remove transactional data
    }

    size_t getSize() const override {
        std::lock_guard<std::mutex> lock(storageMutex);  // Lock for consistent size retrieval
        return storage.getSize();  // Get size of transactional data
    }

    void clear() override {
        std::lock_guard<std::mutex> lock(storageMutex);  // Lock for thread-safe clearing
        storage.clear();  // Clear all transactional data
    }
};
