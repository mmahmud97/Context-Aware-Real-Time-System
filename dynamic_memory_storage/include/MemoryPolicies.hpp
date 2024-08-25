#pragma once
#include <cstddef>

template<typename T>
struct StandardAllocator {
    static T* allocate(size_t size) { return new T[size]; }
    static void deallocate(T* array) { delete[] array; }
};
