/* --------------------------------------------------
 * Linear Probing HashTable
 * Author: Axel Klim
 * OOP Implementation of different Hashtables
 * Header file of hashing with linear probing
 * Inherits from base_class and implements linear probing
 * Version: 1.0.0 2025-06-21
 * Compiler: g++-14 (Homebrew GCC 14.2.0_1) 14.2.0
 * C++ Standard: C++17
 * -------------------------------------------------- */
#ifndef LINEAR_PROBING_H
#define LINEAR_PROBING_H

#include "base_class.h"
#include <vector>

class LinearProbing : public base_class {
private:
    std::vector<int> table;
    static const int EMPTY;
    static const int DELETED;

    int hash(int key) const;

public:
    LinearProbing(int capacity);

    void insert(int key) override;
    bool contains(int key) override;
    void remove(int key) override;
    void print() const override;
};

#endif // LINEAR_PROBING_H
