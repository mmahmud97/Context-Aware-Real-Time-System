#ifndef MEMORY_STORAGE_H
#define MEMORY_STORAGE_h

#include <iostream>
#include <memory>

template<typename T>

class MemoryStorage {
    public:
        virtual ~MemoryStorage() {}
        virtual void print() const = 0;
        virtual std::unqiue_ptr<MemoryStorage<T>> clone() const = 0;
};

#endif

//Liskov Substitution Principle
//This principle states that objects of a super class should be replacable
//with objects of its subclasses without altering the desirable properties
//of the program

//Open/Close Principle
//Software entities should be open for extension, but closed for modification

//Interface Segregation Principle
//A class should only have one reason to change. It should have only one job
//or responsibility

//Dependency Inversion Principle
//High-Level modeules should not depend on low-level modules. Both should depend
//on abstractions (e.g. interfaces)

//Polymorphism
//Polymorphism allows methids to do different things based on the object it is acting
//upon, enabling the same method to perform different functionalities