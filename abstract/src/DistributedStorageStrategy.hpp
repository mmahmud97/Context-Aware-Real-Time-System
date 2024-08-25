#pragma once
#include "../include/IStorageStrategy.hpp"
#include "../../dynamic_memory_storage/include/RealTimeDynamicStorage.hpp"
#include <vector>
#include <functional>

template<typename ContextType>
class DistributedStorageStrategy : public IStorageStrategy<ContextType> {
private:
    std::vector<RealTimeDynamicStorage<ContextType>> nodes;  // Each node represents a storage for a different sensor

public:
    DistributedStorageStrategy(size_t nodeCount, size_t capacityPerNode) {
        for (size_t i = 0; i < nodeCount; ++i) {
            nodes.emplace_back(capacityPerNode);  // Initialize storage for each node
        }
    }

    void addContext(const ContextType& data) override {
        size_t nodeIndex = hashFunction(data) % nodes.size();
        nodes[nodeIndex].push_back(data);  // Add data to the appropriate node
    }

    ContextType getContext(size_t index) const override {
        size_t nodeIndex = determineNode(index);
        size_t localIndex = index % nodes[nodeIndex].getCapacity();
        return nodes[nodeIndex][localIndex];  // Get data from the appropriate node
    }

    void removeContext(size_t index) override {
        size_t nodeIndex = determineNode(index);
        nodes[nodeIndex].remove(index % nodes[nodeIndex].getCapacity());  // Remove data from the appropriate node
    }

    size_t getSize() const override {
        size_t totalSize = 0;
        for (const auto& node : nodes) {
            totalSize += node.getSize();  // Aggregate sizes from all nodes
        }
        return totalSize;
    }

    void clear() override {
        for (auto& node : nodes) {
            node.clear();  // Clear data in all nodes
        }
    }

private:
    size_t determineNode(size_t index) const {
        return index % nodes.size();  // Simple distribution based on index
    }

    size_t hashFunction(const ContextType& data) const {
        return std::hash<ContextType>{}(data);  // Simple hash function for demonstration
    }
};
