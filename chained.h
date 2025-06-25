/* --------------------------------------------------
 * Chained HashTable with doubly linked list
 * Author: Axel Klim
 * OOP Implementation of different Hashtables
 * Header file of hashing with chaining by doubly linked list
 * Inherits from base_class and implements chaining
 * Version: 1.0.0 2025-06-21
 * Compiler: g++-14 (Homebrew GCC 14.2.0_1) 14.2.0
 * C++ Standard: C++17
 * -------------------------------------------------- */
#ifndef CHAINED_H
#define CHAINED_H

#include "base_class.h"
#include <list>    // Provides std::list: a doubly linked list used for chaining collisions
#include <vector>  // Provides std::vector: used to store the table of lists (buckets)

/*
 * Chained hashing implementation using std::list<int> for each bucket.
 * std::list is a standard doubly linked list, allowing efficient insert and delete operations.
 * Each bucket is a list, stored inside a std::vector for direct access via index.
 */
class Chained : public base_class {
private:
    std::vector<std::list<int>> table;  // Hash table: vector of linked lists (chains)
    static const int EMPTY;
    static const int DELETED;

    int hash(int key) const;  // Hash function: computes bucket index

public:
    Chained(int capacity);  // Constructor: initializes table with given capacity

    void insert(int key) override;     // Insert a key into the hash table
    bool contains(int key) override;   // Check if a key exists
    void remove(int key) override;     // Remove a key from the table
    void print() const override;       // Print table contents (all chains)
};

#endif // CHAINED_H
