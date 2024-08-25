#pragma once

#include <cstddef>

// Abstract interface for different storage strategies
template<typename ContextType>
class IStorageStrategy {
public:
    virtual ~IStorageStrategy() = default;

    // Adds context data to the storage
    virtual void addContext(const ContextType& data) = 0;

    // Retrieves context data by index
    virtual ContextType getContext(size_t index) const = 0;

    // Removes context data by index
    virtual void removeContext(size_t index) = 0;

    // Returns the size of the stored data
    virtual size_t getSize() const = 0;

    // Clears all stored data
    virtual void clear() = 0;
};
