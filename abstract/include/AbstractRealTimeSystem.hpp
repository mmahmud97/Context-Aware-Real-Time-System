#pragma once
#include <memory>
#include <string>
#include "IStorageStrategy.hpp"

// Abstract base class for context-aware real-time systems
template<typename ContextType>
class AbstractRealTimeSystem {
protected:
    std::unique_ptr<IStorageStrategy<ContextType>> storageStrategy;  // Pointer to the storage strategy

public:
    virtual ~AbstractRealTimeSystem() = default;

    // Allows setting a storage strategy at runtime
    void setStorageStrategy(std::unique_ptr<IStorageStrategy<ContextType>> strategy) {
        storageStrategy = std::move(strategy);
    }

    // Core system functions
    virtual void initializeSystem() = 0;   // System initialization
    virtual void acquireContext() = 0;     // Acquire context data
    virtual void processContext() = 0;     // Process context data
    virtual void makeDecision() = 0;       // Make decisions based on context
    virtual void executeAction() = 0;      // Execute actions based on decisions
    virtual void monitorHealth() = 0;      // Monitor system health
    virtual void handleFaults() = 0;       // Handle system faults
    virtual void shutdownSystem() = 0;     // Shutdown system gracefully

    // Logging and auditing
    virtual void logEvent(const std::string& event) = 0;

    // Run system cycle (default implementation that can be overridden)
    virtual void run() {
        acquireContext();
        processContext();
        makeDecision();
        executeAction();
        monitorHealth();
        handleFaults();
    }

    // Provide access to the storage strategy
    IStorageStrategy<ContextType>& getStorageStrategy() {
        return *storageStrategy;
    }
};
