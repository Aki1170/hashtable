/* --------------------------------------------------
 * Hashtables
 * Author: Axel Klim
 * OOP Implementation of different Hashtables
 * Header file of abstract base class
 * Version: 1.0.0 2025-06-21
 * Compiler: g++-14 (Homebrew GCC 14.2.0_1) 14.2.0
 * C++ Standard: C++17
 * -------------------------------------------------- */
#ifndef BASE_CLASS_H
#define BASE_CLASS_H

class base_class
{
protected:
    int comparisons;       // Number of key comparisons made
    int table_capacity;    // Total capacity of the hash table
    int table_size;        // Number of currently stored elements

public:
    // Constructor
    base_class(int capacity)
        : comparisons(0), table_capacity(capacity), table_size(0) {}

    // Virtual destructor (required for abstract base classes)
    virtual ~base_class() = default;

    // Pure virtual methods (must be implemented by derived classes)
    virtual void insert(int key) = 0;
    virtual bool contains(int key) = 0;
    virtual void remove(int key) = 0;
    virtual void print() const = 0;

    // Reset probe and comparison counters
    virtual void resetStats() {
        comparisons = 0;
    }

    // Getters
    int getComparisons() const { return comparisons; }
    int getSize() const { return table_size; }
    int getCapacity() const { return table_capacity; }

    // Calculate load factor α = size / capacity
    double getAlpha() const {
        return static_cast<double>(table_size) / table_capacity;
    }
};

#endif // BASE_CLASS_H
