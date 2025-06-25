#include <iostream>
#include "quadratic_probing.h"

int main() {
    // Create table with capacity 10
    QuadraticProbing table(10);

    std::cout << "=== Insert Test ===\n";
    table.insert(2);
    table.insert(3);
    table.insert(5);
    table.insert(7);
    table.insert(11);
    table.insert(13);
    table.insert(17);
    table.insert(19);
    table.insert(23);
    table.insert(29);
    table.insert(31);
    table.insert(37);
    table.print();

    std::cout << "\n=== Contains Test ===\n";
    int idx = table.findIndex(13);
    std::cout << "Contains 13? " << (idx != -1 ? "Yes" : "No") << ", on index No.: " << idx << "\n";
    // std::cout << "Contains 99? " << (table.contains(99) ? "Yes" : "No") << "\n";

    // std::cout << "\n=== Remove Test ===\n";
    // table.remove(25);
    // table.print();

    std::cout << "\n=== Stats ===\n";
    std::cout << "Comparisons: " << table.getComparisons() << "\n";
    std::cout << "Load factor: " << table.getAlpha() << "\n";

    return 0;
}
