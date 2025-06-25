/* --------------------------------------------------
 * Quadratic Probing HashTable
 * Author: Axel Klim
 * OOP implementation of a hash table using quadratic probing
 * Implements all required methods from base_class
 * Tracks comparisons and load factor
 * Version: 1.0.0 — 2025-06-21
 * Compiler: g++-14 (Homebrew GCC 14.2.0_1) 14.2.0
 * C++ Standard: C++17
 * -------------------------------------------------- */
#include "quadratic_probing.h"
#include <iostream>

const int QuadraticProbing::EMPTY = -1;
const int QuadraticProbing::DELETED = -2;

// Constructor: Initializes the base class and sets all slots to EMPTY
QuadraticProbing::QuadraticProbing(int capacity)
    : base_class(capacity), table(capacity, EMPTY) {}

// Hash function: Simple modulo operation
int QuadraticProbing::hash(int key) const {
    return key % table_capacity;
}

// Insert a key using quadratic probing
void QuadraticProbing::insert(int key) {
    int i = 0;

    while (i < table_capacity) {
        int s = (i / 2) + 1;                 // Step count for probing, increases with each iteration
        int offset = s * s;                 // Quadratic offset based on step count (s^2)
        if (i % 2 != 0) offset *= -1;       // Alternate direction: negative offset on odd steps

        int j = (hash(key) + offset + table_capacity) % table_capacity;

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

    std::cerr << "Error: Hash table overflow during insert(" << key << ")\n";
}

// Check if a key exists in the table using quadratic probing
bool QuadraticProbing::contains(int key) {
    int index = hash(key);

    for (int i = 0; i < table_capacity; ++i) {
        int s = (i / 2) + 1;
        int offset = s * s;
        if (i % 2 != 0) offset *= -1;
        int probeIndex = (index + offset + table_capacity) % table_capacity;

        comparisons++; // Each slot inspection counts as one comparison

        if (table[probeIndex] == EMPTY) return false;
        if (table[probeIndex] == key) return true;
    }

    return false;
}

// Find the index of a key (for debugging or tracking purposes)
int QuadraticProbing::findIndex(int key) {
    int index = hash(key);

    for (int i = 0; i < table_capacity; ++i) {
        int s = (i / 2) + 1;
        int offset = s * s;
        if (i % 2 != 0) offset *= -1;
        int probeIndex = (index + offset + table_capacity) % table_capacity;

        comparisons++;

        if (table[probeIndex] == EMPTY) return -1;
        if (table[probeIndex] == key) return probeIndex;
    }

    return -1;
}

// Remove a key from the table using quadratic probing
void QuadraticProbing::remove(int key) {
    int index = hash(key);

    for (int i = 0; i < table_capacity; ++i) {
        int s = (i + 1) / 2;
        int offset = s * s;
        if (i % 2 != 0) offset *= -1;
        int probeIndex = (index + offset + table_capacity) % table_capacity;

        if (table[probeIndex] == EMPTY) return;

        if (table[probeIndex] == key) {
            table[probeIndex] = DELETED;
            table_size--;
            return;
        }
    }
}

// Print the current state of the hash table
void QuadraticProbing::print() const {
    std::cout << "=== Quadratic Probing HashTable ===\n";
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
