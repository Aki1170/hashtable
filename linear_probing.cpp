/* --------------------------------------------------
 * Linear Probing HashTable
 * Author: Axel Klim
 * OOP implementation of a hash table using linear probing
 * Implements all required methods from base_class
 * Tracks comparisons and load factor
 * Version: 1.0.0 — 2025-06-21
 * Compiler: g++-14 (Homebrew GCC 14.2.0_1) 14.2.0
 * C++ Standard: C++17
 * -------------------------------------------------- */
#include "linear_probing.h"
#include <iostream>

const int LinearProbing::EMPTY = -1;
const int LinearProbing::DELETED = -2;

// Constructor: Initializes the base class and sets all slots to EMPTY
LinearProbing::LinearProbing(int capacity)
    : base_class(capacity), table(capacity, EMPTY) {}

// Hash function: Simple modulo operation
int LinearProbing::hash(int key) const {
    return key % table_capacity;
}

// Insert a key using linear probing, following the standard pseudocode from Cormen
void LinearProbing::insert(int key) {
    int i = 0;

    while (i < table_capacity) {
        int j = (hash(key) + i) % table_capacity;  // Probing index h(k, i)

        if (table[j] == EMPTY || table[j] == DELETED) {
            table[j] = key;
            table_size++;
            return;
        }

        if (table[j] == key) {
            // Key already present — do nothing
            return;
        }

        i++;
    }

    // If we reach here, the table is full
    std::cerr << "Error: Hash table overflow during insert(" << key << ")\n";
}

// Check if a key exists in the table
bool LinearProbing::contains(int key) {
    int index = hash(key);

    for (int i = 0; i < table_capacity; ++i) {
        int probeIndex = (index + i) % table_capacity;
         comparisons++;   // Each slot inspection counts as one comparison

        if (table[probeIndex] == EMPTY) {
            return false; // Key not found
        }

        if (table[probeIndex] == key) {

            return true; // Key found
        }

        // If DELETED → keep probing
    }

    return false; // Not found after full probing
}

// Remove a key from the table using linear probing
void LinearProbing::remove(int key) {
    int index = hash(key);

    for (int i = 0; i < table_capacity; ++i) {
        int probeIndex = (index + i) % table_capacity;

        if (table[probeIndex] == EMPTY) {
            // Key not found – stop search
            return;
        }

        if (table[probeIndex] == key) {
            table[probeIndex] = DELETED;
            table_size--;
            return;
        }
    }
}

// Print the current state of the hash table
void LinearProbing::print() const {
    std::cout << "=== Linear Probing HashTable ===\n";
    for (int i = 0; i < table_capacity; ++i) {
        std::cout << "[" << i << "]: ";
        if (table[i] == EMPTY) {
            std::cout << "(EMPTY)";
        } else if (table[i] == DELETED) {
            std::cout << "(DELETED)";
        } else {
            std::cout << table[i];
        }
        std::cout << "\n";
    }
    std::cout << "===============================\n";
}
