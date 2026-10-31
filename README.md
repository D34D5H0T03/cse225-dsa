# CSE225: Data Structures and Algorithms (DSA)

Welcome to the repository for **CSE225: Data Structures and Algorithms**. This repository contains C++ implementations of various data structures, algorithmic paradigms, class lab notes, and practice problems organized throughout the semester.

## 📚 Topics Covered

This repository is divided into several modules corresponding to the course timeline (Quizzes, Midterm, Final, etc.). Here is a high-level overview of the concepts implemented:

### 1. Fundamentals & Pointers (`/class_1`, `/home/quiz_1`, `/home/regular`)
*   Pointers and memory management
*   Dynamic Arrays (`dynArr`, `dynArrSorted`)
*   Dimensional Vectors (`dimVector`)
*   Object-Oriented Programming Practice

### 2. Linear Data Structures (`/home/midterm`, `/online_class`)
*   **Unsorted Linked Lists**
*   **Sorted Linked Lists**
*   **Stacks** (Array and Linked List implementations)
    *   *Applications:* Infix to Postfix conversion, Postfix evaluation, Valid Parentheses checking.
*   **Queues** (Array and Linked List implementations)
    *   *Applications:* Prime sum calculations.

### 3. Non-Linear Data Structures (`/home/final/lab`)
*   **Binary Search Trees (BST)** 
*   **Heaps & Priority Queues** 

### 4. Algorithms & Theory (`/home/final/theory`)
*   **Recursion:** Basic recursion and Tower of Hanoi.
*   **Sorting Algorithms:**
    *   Bubble Sort
    *   Insertion Sort
    *   Selection Sort
    *   Merge Sort
*   **Graphs:**
    *   Graph representations (Adjacency Matrix/List)
    *   Breadth-First Search (BFS)
    *   Depth-First Search (DFS)
    *   Dijkstra's Algorithm (Shortest Path Via Priority Queue)
    *   Bellman-Ford Algorithm(Shortest path and negative Cycle Detection)

---

## 🗂️ Repository Structure

The files are structured around the timeline of the coursework:

```text
📦 cse225-dsa
 ┣ 📂 class_1               # Introductory labs and basic C++ tasks
 ┣ 📂 home
 ┃ ┣ 📂 final               # Final exam material (Trees, Graphs, Sorting, Heaps, Recursion)
 ┃ ┣ 📂 midterm             # Midterm material (Stacks, Queues, Linked Lists)
 ┃ ┣ 📂 quiz_1              # Quiz 1 practice (Dynamic Arrays, Pointers)
 ┃ ┗ 📂 regular             # Regular class practice (Vectors, OOP)
 ┗ 📂 online_class          # Additional unsorted linked list implementations
```

---

## 🚀 How to Compile and Run

To compile any of the C++ files in this repository, you will need a standard C++ compiler like `g++` (GCC) or `clang++`. 

Most modules consist of a header file (`.h`), an implementation file (`.cpp`), and a driver program (`main.cpp`). To compile them together, navigate to the specific directory and use:

```bash
# Example for compiling the Binary Search Tree
cd home/final/lab/bst/base/
g++ main.cpp binarysearchtree.cpp -o bst_program

# Run the compiled executable
./bst_program    # Linux/Mac
bst_program.exe  # Windows
```

## 🛠️ Prerequisites
*   A C++ compiler (e.g., GCC, Clang, MSVC)
*   Basic understanding of C++ syntax and Object-Oriented Programming (OOP) principles.