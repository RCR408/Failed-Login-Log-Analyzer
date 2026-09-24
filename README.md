# Failed-Login Log Analyzer

A C++ program that parses a server log of failed login attempts and filters records by date range, using sorting and searching algorithms implemented from scratch.

## Features
- Parses a log file (`bitacora.txt`) containing failed login attempts, each with an IP address and timestamp
- Sorts records using a custom **QuickSort** implementation (no built-in sort function)
- Filters records by date range using **binary search** over the sorted data
- Uses a hash map for fast month lookup during parsing
- Writes the matching records to an output file

## Tech Stack
- **Language:** C++
- **Data structures:** custom QuickSort, binary search, `unordered_map`

## Why It's Interesting
The log used for testing has over 16,800 lines. Implementing sorting and searching manually (instead of using `std::sort`) was a deliberate choice to practice algorithm design and Big-O tradeoffs on a realistic dataset size.

## Running It
1. Compile: `g++ -o log_analyzer 1.3.cpp SortingA.cpp bitacora.cpp`
2. Run: `./log_analyzer`
3. Provide a date range when prompted; matching records are written to the output file

## Status
Coursework project focused on algorithms and data structures.
