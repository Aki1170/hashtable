// --------------------------------------------------
// stress_test.cpp
// Author: Axel Klim
// Test suite for stress testing various hash table implementations
// Includes:
// - Chained hashing
// - Linear probing
// - Quadratic probing
// --------------------------------------------------

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#include "chained.h"
#include "linear_probing.h"
#include "quadratic_probing.h"

// -------------------------------
// Chained Hashing Test
// -------------------------------
void runChainTest(Chained& table, int maxFactor) {
    // Insert keys from 2 to 1000
    for (int key = 2; key <= 1000; ++key) {
        table.insert(key);
    }

    // Remove all multiples of a fixed factor (e.g. 3)
    int factor = 3;
    for (int multiple = factor; multiple <= 1000; multiple += factor) {
        table.remove(multiple);
    }

    // Print table distribution for analysis
    table.print();
}

// -------------------------------
// Linear Probing – Successful Search
// -------------------------------
void runLinearSuccessfulTest() {
    std::cout << "\n=== L1: Linear Probing - Successful Search ===\n";
    const int tableSize = 1000;

    for (int percent = 10; percent <= 100; percent += 10) {
        LinearProbing table(tableSize);
        int n = tableSize * percent / 100;

        // Generate shuffled keys from 1 to n
        std::vector<int> keys(n);
        std::iota(keys.begin(), keys.end(), 1);
        std::shuffle(keys.begin(), keys.end(), std::mt19937{std::random_device{}()});

        // Insert all keys
        for (int i = 0; i < n; ++i) table.insert(keys[i]);

        // Reset comparison counter
        table.resetStats();

        // Perform successful searches for each inserted key
        for (int i = 0; i < n; ++i) table.contains(keys[i]);

        // Compute average number of comparisons
        double avgComparisons = static_cast<double>(table.getComparisons()) / n;
        std::cout << percent << "% full: avg. comparisons (successful): " << avgComparisons << '\n';
    }
}

// -------------------------------
// Linear Probing – Unsuccessful Search
// -------------------------------
void runLinearUnsuccessfullTest() {
    std::cout << "\n=== L3: Linear Probing - Unsuccessful Search ===\n";
    const int tableSize = 1000;

    for (int percent = 10; percent <= 100; percent += 10) {
        LinearProbing table(tableSize);
        int n = tableSize * percent / 100;

        // Insert keys from 1 to n
        for (int i = 1; i <= n; ++i) table.insert(i);

        // Reset comparison counter
        table.resetStats();

        // Perform unsuccessful searches (keys not in table)
        for (int i = n + 1; i <= 2 * n; ++i) table.contains(i);

        // Compute average number of comparisons
        double avgComparisons = static_cast<double>(table.getComparisons()) / n;
        std::cout << percent << "% full: avg. comparisons (unsuccessful): " << avgComparisons << '\n';
    }
}

// -------------------------------
// Quadratic Probing – Successful Search
// -------------------------------
void runQuadraticSuccessfulTest(){
    std::cout << "\n=== Q1: Quadratic Probing - Successful Search ===\n";
    const int tableSize = 100'000;

    for (int percent = 10; percent <= 100; percent += 10) {
        QuadraticProbing table(tableSize);
        int n = tableSize * percent / 100;

        // Generate shuffled keys from 1 to n
        std::vector<int> keys(n);
        std::iota(keys.begin(), keys.end(), 1);
        std::shuffle(keys.begin(), keys.end(), std::mt19937{std::random_device{}()});

        // Insert all keys
        for (int i = 0; i < n; ++i) table.insert(keys[i]);

        // Reset comparison counter
        table.resetStats();

        // Perform successful searches
        for (int i = 0; i < n; ++i) table.contains(keys[i]);

        // Compute average number of comparisons
        double avgComparisons = static_cast<double>(table.getComparisons()) / n;
        std::cout << percent << "% full: avg. comparisons (successful): " << avgComparisons << '\n';
    }
}

// -------------------------------
// Quadratic Probing – Unsuccessful Search
// -------------------------------
void runQuadraticUnseccessfulTest() {
    std::cout << "\n=== Q3: Quadratic Probing - Unsuccessful Search ===\n";
    const int tableSize = 1000;

    for (int percent = 10; percent <= 100; percent += 10) {
        QuadraticProbing table(tableSize);
        int n = tableSize * percent / 100;

        // Generate shuffled keys from 1 to n
        std::vector<int> keys(n);
        std::iota(keys.begin(), keys.end(), 1);
        std::shuffle(keys.begin(), keys.end(), std::mt19937{std::random_device{}()});

        // Insert all keys
        for (int i = 0; i < n; ++i) table.insert(keys[i]);

        // Reset comparison counter
        table.resetStats();

        // Perform unsuccessful searches
        for (int i = n + 1; i <= 2 * n; ++i) table.contains(i);

        // Compute average number of comparisons
        double avgComparisons = static_cast<double>(table.getComparisons()) / n;
        std::cout << percent << "% full: avg. comparisons (unsuccessful): " << avgComparisons << '\n';
    }
}

// -------------------------------
// Main Function
// -------------------------------
int main() {
    std::cout << "=== Stress Test Suite ===\n";

    // Run chained hashing tests with various table sizes
    Chained table1(97);  runChainTest(table1, 100000);
    Chained table2(100); runChainTest(table2, 100000);
    Chained table3(19);  runChainTest(table3, 100000);
    Chained table4(20);  runChainTest(table4, 100000);

    // Run linear probing tests
    runLinearSuccessfulTest();
    runLinearUnsuccessfullTest();

    // Run quadratic probing tests
    runQuadraticSuccessfulTest();
    runQuadraticUnseccessfulTest();

    return 0;
}
