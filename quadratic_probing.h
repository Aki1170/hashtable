/* --------------------------------------------------
 * Quardartic Probing HashTable
 * Author: Axel Klim
 * OOP Implementation of different Hashtables
 * Header file of hashing with quadratic probing
 * Inherits from base_class and implements quadratic probing
 * Version: 1.0.0 2025-06-21
 * Compiler: g++-14 (Homebrew GCC 14.2.0_1) 14.2.0
 * C++ Standard: C++17
 * -------------------------------------------------- */
#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include "base_class.h"
#include <vector>

class QuadraticProbing : public base_class {
private:
    std::vector<int> table;
    static const int EMPTY;
    static const int DELETED;

    int hash(int key) const;

public:
    QuadraticProbing(int capacity);

    void insert(int key) override;
    bool contains(int key) override;
    void remove(int key) override;
    void print() const override;
    int findIndex(int key);
};


#endif // QUADRATIC_PROBING_H
