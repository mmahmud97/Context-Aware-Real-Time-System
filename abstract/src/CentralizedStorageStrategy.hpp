#pragma once
#include "../include/IStorageStrategy.hpp"
#include "../../libs/dynamic_memory_storage/dynamic_memory_storage/include/RealTimeDynamicStorage.hpp"
#include <mutex>  // Optional, for thread safety if needed
#include <vector> // Optional, for handling multiple data sources if needed

template<typename ContextType>
class CentralizedStorageStrategy : public IStorageStrategy<ContextType> {
private:
    RealTimeDynamicStorage<ContextType> centralStorage;  // Central storage for all data
    bool enableRedundancy;  // Flag to enable or disable redundancy
    RealTimeDynamicStorage<ContextType> backupStorage;  // Backup storage for redundancy, if needed

public:
    // Constructor with optional redundancy configuration
    CentralizedStorageStrategy(size_t capacity, bool enableRedundancy = false)
        : centralStorage(capacity), enableRedundancy(enableRedundancy), backupStorage(enableRedundancy ? capacity : 0) {}

    void addContext(const ContextType& data) override {
        centralStorage.push_back(data);  // Store data centrally
        if (enableRedundancy) {
            backupStorage.push_back(data);  // Store a redundant copy if redundancy is enabled
        }
    }

    ContextType getContext(size_t index) const override {
        return centralStorage[index];  // Access data from central storage
    }

    void removeContext(size_t index) override {
        centralStorage.remove(index);  // Remove data from central storage
        if (enableRedundancy) {
            backupStorage.remove(index);  // Remove redundant data if redundancy is enabled
        }
    }

    size_t getSize() const override {
        return centralStorage.getSize();  // Get size of central storage
    }

    void clear() override {
        centralStorage.clear();  // Clear central storage
        if (enableRedundancy) {
            backupStorage.clear();  // Clear backup storage if redundancy is enabled
        }
    }

    // Additional method to switch redundancy on or off
    void setRedundancy(bool enabled) {
        enableRedundancy = enabled;
        if (enabled && backupStorage.getCapacity() == 0) {
            backupStorage = RealTimeDynamicStorage<ContextType>(centralStorage.getCapacity());
        }
    }
};
