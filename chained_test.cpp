// #include <iostream>
// #include "chained.h"

// int main() {
//     // Create table with capacity 10
//     Chained table(10);

//     std::cout << "=== Insert Test ===\n";
//     table.insert(2);
//     table.insert(3);
//     table.insert(5);
//     table.insert(7);
//     table.insert(11);
//     table.insert(13);
//     table.insert(17);
//     table.insert(19);
//     table.insert(23);
//     table.insert(29);
//     table.insert(31);
//     table.insert(37);
//     table.print();

//     std::cout << "\n=== Contains Test ===\n";
//     std::cout << "Contains 13? " << (table.contains(13) ? "Yes" : "No") << "\n";
//     // std::cout << "Contains 99? " << (table.contains(99) ? "Yes" : "No") << "\n";

//     // std::cout << "\n=== Remove Test ===\n";
//     // table.remove(25);
//     // table.print();

//     std::cout << "\n=== Stats ===\n";
//     std::cout << "Comparisons: " << table.getComparisons() << "\n";
//     std::cout << "Load factor: " << table.getAlpha() << "\n";

//     std::cout << "\n=== Average Comparisons Test ===\n";
//     std::vector<int> keys = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
//     int totalComparisons = 0;
//     for (int key : keys) {
//         table.resetStats();
//         table.contains(key);
//         totalComparisons += table.getComparisons();
//     }
//     double avg = static_cast<double>(totalComparisons) / keys.size();
//     std::cout << "Total comparisons: " << totalComparisons << "\n";
//     std::cout << "Average comparisons per search: " << avg << "\n";

//     return 0;
// }
