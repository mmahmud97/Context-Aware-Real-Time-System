#pragma once
#include "../include/IStorageStrategy.hpp"
#include "../../dynamic_memory_storage/include/RealTimeDynamicStorage.hpp"
#include <vector>

template<typename ContextType>
class HierarchicalStorageStrategy : public IStorageStrategy<ContextType> {
private:
    RealTimeDynamicStorage<ContextType> localStorage;  // Local storage at the sensor level
    RealTimeDynamicStorage<ContextType> regionalStorage;  // Regional storage at an intermediate level
    RealTimeDynamicStorage<ContextType> centralStorage;  // Central storage at the highest level

public:
    HierarchicalStorageStrategy(size_t localCapacity, size_t regionalCapacity, size_t centralCapacity)
        : localStorage(localCapacity), regionalStorage(regionalCapacity), centralStorage(centralCapacity) {}

    void addContext(const ContextType& data) override {
        localStorage.push_back(data);  // Add data to local storage
        if (localStorage.getSize() > localStorage.getCapacity() / 2) {
            regionalStorage.push_back(data);  // Promote data to regional storage
        }
        if (regionalStorage.getSize() > regionalStorage.getCapacity() / 2) {
            centralStorage.push_back(data);  // Promote data to central storage
        }
    }

    ContextType getContext(size_t index) const override {
        if (index < localStorage.getSize()) {
            return localStorage[index];  // Retrieve from local storage
        } else if (index < localStorage.getSize() + regionalStorage.getSize()) {
            return regionalStorage[index - localStorage.getSize()];  // Retrieve from regional storage
        } else {
            return centralStorage[index - localStorage.getSize() - regionalStorage.getSize()];  // Retrieve from central storage
        }
    }

    void removeContext(size_t index) override {
        if (index < localStorage.getSize()) {
            localStorage.remove(index);  // Remove from local storage
        } else if (index < localStorage.getSize() + regionalStorage.getSize()) {
            regionalStorage.remove(index - localStorage.getSize());  // Remove from regional storage
        } else {
            centralStorage.remove(index - localStorage.getSize() - regionalStorage.getSize());  // Remove from central storage
        }
    }

    size_t getSize() const override {
        return localStorage.getSize() + regionalStorage.getSize() + centralStorage.getSize();  // Total size across all storage levels
    }

    void clear() override {
        localStorage.clear();
        regionalStorage.clear();
        centralStorage.clear();
    }
};
