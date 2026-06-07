# 📊 Sorting Algorithm Visualizer

## Intern Details
| Field | Details |
|-------|---------|
| **Intern ID** | CITS3437 |
| **Full Name** | Aditya Singla |
| **No. of Weeks** | 4 Weeks (3rd June - 1st July) |
| **Project Name** | Sorting Algorithm Visualizer |
| **Company** | CodTech IT Solutions |

---

## 📌 Project Scope
A console-based Sorting Algorithm Visualizer built in C. It visually demonstrates how different sorting algorithms work using ASCII bar charts. Shows step-by-step sorting process and compares performance of all algorithms.

---

## ✅ Features
- Bubble Sort with step visualization
- Selection Sort with step visualization
- Insertion Sort with step visualization
- Merge Sort
- Quick Sort
- ASCII Bar Chart visualization
- Random array generator
- Manual array input
- Compare all algorithms (step count)

---

## 📊 Algorithms Included
| Algorithm | Best Case | Worst Case | Stable |
|-----------|-----------|------------|--------|
| Bubble Sort | O(n) | O(n²) | Yes |
| Selection Sort | O(n²) | O(n²) | No |
| Insertion Sort | O(n) | O(n²) | Yes |
| Merge Sort | O(n log n) | O(n log n) | Yes |
| Quick Sort | O(n log n) | O(n²) | No |

---

## 🛠️ Technologies Used
- Language: C
- Concepts: Arrays, Functions, Recursion, Sorting Algorithms

---

## ▶️ How to Run

### Compile
```bash
gcc sorting_visualizer.c -o sorting_visualizer
```

### Run
```bash
./sorting_visualizer
```
On Windows:
```bash
sorting_visualizer.exe
```

---

## 📋 Sample Output
```
==============================================
   SORTING ALGORITHM VISUALIZER             
   Aditya Singla | CITS3437                 
==============================================

Current Array: [ 5 3 8 1 9 2 7 4 6 10 ]

Visualization:
 10 |             ##
  9 |          ##  ##
  8 |    ##    ##  ##
  ...

========== MENU ==========
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
5. Quick Sort
6. Generate Random Array
7. Enter Array Manually
8. Compare All Algorithms
9. Exit
===========================
```

---

## 📁 Project Structure
```
Sorting-Algorithm-Visualizer/
├── sorting_visualizer.c    # Main source code
├── screenshots/            # Output screenshots
└── README.md               # Project documentation
```

---

## 📝 Notes
- Array size maximum 20 elements
- Random values between 1 and 20
- Step counter shows algorithm efficiency
- Compare option shows which algorithm uses fewer steps
