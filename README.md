# Context-Aware-Real-Time-System
Independent research project performed under the supervision of Dr. Jonathan Shidal (WashU)

Project Structure and Files

Here’s an overview of the current project structure, including all the files, their purposes, and their locations:
1. Project Root: CONTEXT-AWARE-REAL-TIME-SYSTEM

    Folder: .vscode
        Purpose: Contains Visual Studio Code-specific settings and configurations (like launch settings, debugging configurations, etc.).

    File: .gitmodules
        Purpose: Defines submodules used in the repository, such as dynamic_memory_storage cloned into the libs folder.
        Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/.gitmodules

    File: README.md
        Purpose: Provides an overview of the project, usage instructions, and documentation.
        Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/README.md

2. Folder: abstract

    Subfolder: include
        Files:

            AbstractRealTimeSystem.hpp
                Purpose: Defines the abstract base class for all context-aware real-time systems, outlining core functionalities like initialization, context acquisition, decision making, etc.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/abstract/include/AbstractRealTimeSystem.hpp

            IStorageStrategy.hpp
                Purpose: Interface for different storage strategies. It defines the methods that any storage strategy must implement, such as addContext, getContext, removeContext, etc.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/abstract/include/IStorageStrategy.hpp

    Subfolder: src
        Files:
            CentralizedStorageStrategy.hpp
                Purpose: Unified storage strategy class that uses RealTimeDynamicStorage to manage centralized storage for both Air Control Systems and SCADA Systems, with optional redundancy for fault tolerance.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/abstract/src/CentralizedStorageStrategy.hpp

            InMemoryStorageStrategy.hpp
                Purpose: In-memory storage strategy for ADAS systems to provide ultra-fast data access and processing, leveraging RealTimeDynamicStorage.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/abstract/src/InMemoryStorageStrategy.hpp

            DistributedStorageStrategy.hpp
                Purpose: Distributed storage strategy for ADAS systems to manage data storage across multiple sensor nodes, ensuring quick local access and fault tolerance.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/abstract/src/DistributedStorageStrategy.hpp

            HierarchicalStorageStrategy.hpp
                Purpose: Hierarchical storage strategy for SCADA systems to manage data storage across multiple levels, from local sensors to a central server.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/abstract/src/HierarchicalStorageStrategy.hpp

            TransactionalStorageStrategy.hpp
                Purpose: Transactional storage strategy for financial trading systems to ensure data integrity, consistency, and durability, using RealTimeDynamicStorage with support for transactional operations.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/abstract/src/TransactionalStorageStrategy.hpp

            MirroredStorageStrategy.hpp
                Purpose: Mirrored storage strategy for systems requiring high reliability and fault tolerance, such as medical device systems. Ensures data integrity by storing redundant copies of data across two RealTimeDynamicStorage instances.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/abstract/src/MirroredStorageStrategy.hpp

            CircularBufferStorageStrategy.hpp
                Purpose: Circular buffer storage strategy for real-time systems, such as medical device systems, that require continuous data logging within a fixed memory footprint. Utilizes RealTimeDynamicStorage to manage a fixed-size buffer where new data overwrites the oldest data when full.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/abstract/src/CircularBufferStorageStrategy.hpp

3. Folder: dynamic_memory_storage

    Subfolder: include
        Files:

            IDynamicStorage.hpp
                Purpose: Defines the interface for a dynamic storage class, including methods like push_back, operator[], getSize, and getCapacity.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/dynamic_memory_storage/include/IDynamicStorage.hpp

            MemoryPolicies.hpp
                Purpose: Contains memory management policies like allocation and deallocation strategies used in dynamic storage classes.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/dynamic_memory_storage/include/MemoryPolicies.hpp

            RealTimeDynamicStorage.hpp
                Purpose: Implements the dynamic storage class that provides a flexible, dynamic array-like structure with functionalities to dynamically allocate, resize, and manage storage.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/dynamic_memory_storage/include/RealTimeDynamicStorage.hpp

    Subfolder: src
        Files:
            RealTimeDynamicStorage.cpp
                Purpose: Implements the methods defined in RealTimeDynamicStorage.hpp, such as constructors, destructors, resizing, adding, removing elements, etc.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/dynamic_memory_storage/src/RealTimeDynamicStorage.cpp

    Subfolder: examples
        Files:
            examplesUsage.cpp
                Purpose: Provides examples of how to use RealTimeDynamicStorage and other components of the dynamic memory storage module.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/dynamic_memory_storage/examples/examplesUsage.cpp

    Subfolder: test
        Files:

            main.cpp
                Purpose: Entry point for running unit tests for the dynamic memory storage and other components.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/dynamic_memory_storage/test/main.cpp

            TestDynamicStorage.cpp
                Purpose: Contains unit tests for RealTimeDynamicStorage to verify its functionality and performance under different conditions.
                Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/dynamic_memory_storage/test/TestDynamicStorage.cpp

    Files:

        CMakeLists.txt
            Purpose: Build configuration file for CMake, specifying how to build the dynamic memory storage module and its dependencies.
            Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/dynamic_memory_storage/CMakeLists.txt

        CMakeLists.txt.save
            Purpose: A backup or temporary file related to the CMake build configuration.
            Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/dynamic_memory_storage/CMakeLists.txt.save

        README.md
            Purpose: Provides documentation specific to the dynamic memory storage module, including usage instructions, configuration details, and examples.
            Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/dynamic_memory_storage/README.md

4. Folder: libs

    Subfolder: dynamic_memory_storage (cloned submodule)
        Purpose: Contains a cloned version of the dynamic_memory_storage module as a submodule. Used to share the dynamic storage logic across different parts of the project.
        Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/libs/dynamic_memory_storage/

5. Other Project Files

    File: .gitmodules
        Purpose: Configures Git submodules used in the repository (e.g., dynamic_memory_storage).
        Location: CONTEXT-AWARE-REAL-TIME-SYSTEM/.gitmodules

Summary of Key Files and Their Purposes

    Abstract System Files:
        AbstractRealTimeSystem.hpp and IStorageStrategy.hpp: Define the abstract base system and interface for storage strategies.
        CentralizedStorageStrategy.hpp: Unified strategy for centralized storage, used for both Air Control Systems and SCADA Systems.

    Dynamic Memory Storage Files:
        IDynamicStorage.hpp, MemoryPolicies.hpp, RealTimeDynamicStorage.hpp/cpp: Provide dynamic memory management and storage functionalities.
        Example and test files (examplesUsage.cpp, TestDynamicStorage.cpp): Demonstrate usage and verify functionality.

    Build and Configuration Files:
        CMakeLists.txt and .gitmodules: Configure the build system and manage submodules.
