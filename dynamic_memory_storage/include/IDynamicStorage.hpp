#pragma once
#include <cstddef>

template<typename T>
class IDynamicStorage {
public:
    virtual ~IDynamicStorage() = default;
    virtual void push_back(const T& value) = 0;
    virtual T& operator[](size_t index) = 0;
    virtual size_t getSize() const = 0;
    virtual size_t getCapacity() const = 0;
};
