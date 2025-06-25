/* --------------------------------------------------
 * Chained HashTable
 * Author: Axel Klim
 * OOP implementation of a hash table using separate chaining
 * Implements all required methods from base_class
 * Version: 1.0.0 — 2025-06-21
 * Compiler: g++-14 (Homebrew GCC 14.2.0_1) 14.2.0
 * C++ Standard: C++17
 * -------------------------------------------------- */

#include "chained.h"
#include <iostream>

const int Chained::EMPTY = -1;
const int Chained::DELETED = -2;

// Constructor: initialize table with empty buckets (empty lists)
Chained::Chained(int capacity)
    : base_class(capacity), table(capacity) {}

// Simple modulo hash function
int Chained::hash(int key) const {
    return key % table_capacity;
}

// Insert a key into the corresponding chain
void Chained::insert(int key) {
    int index = hash(key);

    // Check if key is already in the list (avoid duplicates)
    for (int existing : table[index]) {
        if (existing == key) return;
    }

    table[index].push_front(key);  // Add to the end of the chain
    table_size++;
}


// Check if a key exists in the hash table
bool Chained::contains(int key) {
    int index = hash(key);

    for (int existing : table[index]) {
        comparisons++; // increases comparisons for every iteration of a chained list
        if (existing == key) {
            return true;
        }
    }

    return false;
}

// Remove a key from the hash table using chaining
void Chained::remove(int key) {
    int index = hash(key);

    for (std::list<int>::iterator it = table[index].begin(); it != table[index].end(); ++it) {
        if (*it == key) {
            table[index].erase(it);
            table_size--;
            return;
        }
    }
}

// Print all chains
void Chained::print() const {
    std::cout << "=== Chained HashTable ===\n";
    for (int i = 0; i < table_capacity; ++i) {
        std::cout << "[" << i << "]: ";
        for (int val : table[i]) {
            std::cout << val << " -> ";
        }
        std::cout << "NULL\n";
    }
    std::cout << "=========================\n";
}
