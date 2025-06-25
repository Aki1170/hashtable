# HashTable Project

This project implements different types of hash tables in modern C++ for academic use in the "Grundlagen der Informatik 2" (GdI2) module. It includes various collision resolution strategies and comparison statistics for analysis and learning purposes.

## 📦 Contents

- **`base_class`** – Abstract base class for shared structure and statistics
- **`LinearProbing`** – Hash table with linear probing
- **`QuadraticProbing`** – Hash table with quadratic probing (Cormen-style)
- **`Chained`** – Hash table with separate chaining using STL lists
- **Test files** – Unit tests for each strategy (`*_test.cpp`)
- **Statistics** – Comparison counter, load factor, etc.

## 🔧 Build & Run

### Requirements

- C++17-compatible compiler (e.g., `g++-14`)
- CMake
- macOS or Linux

### Build

```bash
mkdir build
cd build
cmake ..
make
./hashtable  # or the specific test binary
```


📊 Features
	•	Tracks key comparisons in contains() and findIndex()
	•	Displays the current state of the hash table
	•	Error output on insertion failure (for open addressing)
	•	Clearly commented code for learning and debugging

🧠 Motivation

This project was created as a practical study tool to:
	•	Understand hash table behavior under different strategies
	•	Visualize clustering and probing sequences
	•	Compare theoretical vs. empirical performance
	•	Prepare for exam-level stress tests (up to 1,000,000 entries)

👨‍💻 Author
	•	Computer Science student at FH Südwestfalen (Germany)
	•	GitHub: Aki1170

⸻

Project Status: Active Development – Chaining implementation in progress.
