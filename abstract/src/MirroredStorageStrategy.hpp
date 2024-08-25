#pragma once
#include "../include/IStorageStrategy.hpp"
#include "../../dynamic_memory_storage/include/RealTimeDynamicStorage.hpp"

template<typename ContextType>
class MirroredStorageStrategy : public IStorageStrategy<ContextType> {
private:
    RealTimeDynamicStorage<ContextType> primaryStorage;
    RealTimeDynamicStorage<ContextType> backupStorage;

public:
    MirroredStorageStrategy(size_t capacity)
        : primaryStorage(capacity), backupStorage(capacity) {}

    void addContext(const ContextType& data) override {
        primaryStorage.push_back(data);
        backupStorage.push_back(data);
    }

    ContextType getContext(size_t index) const override {
        return primaryStorage[index];
    }

    void removeContext(size_t index) override {
        primaryStorage.remove(index);
        backupStorage.remove(index);
    }

    size_t getSize() const override {
        return primaryStorage.getSize();
    }

    void clear() override {
        primaryStorage.clear();
        backupStorage.clear();
    }
};
