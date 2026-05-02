# Sudoku Solver

A command-line Sudoku solver written in C++ that uses a **backtracking algorithm** to find solutions to any valid 9×9 Sudoku puzzle. The program solves the puzzle, displays it in a formatted grid, and counts the total number of possible solutions.

---

## Features

- Accepts any 9×9 Sudoku puzzle as input (0 represents empty cells)
- Validates input to ensure all values are within the legal range (0–9)
- Solves the puzzle using recursive backtracking
- Displays the solved board in a clean, sectioned grid format
- Counts and reports the total number of distinct solutions

---

## Requirements

- A C++ compiler supporting **C++11 or later** (e.g., `g++`, `clang++`, MSVC)
- No external libraries required — uses only the C++ Standard Library

---

## Building

### Linux / macOS

```bash
g++ -std=c++11 -o sudoku_solver SudokuSolver.cpp
```

### Windows (MinGW)

```bash
g++ -std=c++11 -o sudoku_solver.exe SudokuSolver.cpp
```

---

## Usage

Run the compiled executable and enter the 81 numbers of your puzzle row by row, using `0` for empty cells. Numbers can be space-separated, newline-separated, or a mix of both.

```bash
./sudoku_solver
```

### Example Input

The following represents a standard Sudoku puzzle:

```
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

### Example Output

```
Solved Sudoku:
5 3 4 | 6 7 8 | 9 1 2
6 7 2 | 1 9 5 | 3 4 8
1 9 8 | 3 4 2 | 5 6 7
---------------------
8 5 9 | 7 6 1 | 4 2 3
4 2 6 | 8 5 3 | 7 9 1
7 1 3 | 9 2 4 | 8 5 6
---------------------
9 6 1 | 5 3 7 | 2 8 4
2 8 7 | 4 1 9 | 6 3 5
3 4 5 | 2 8 6 | 1 7 9

Number of solutions: 1
```

If no solution exists, the program prints:

```
No solution exists.
```

---

## How It Works

### Algorithm: Backtracking

The solver uses a classic **recursive backtracking** approach:

1. **Find** the next empty cell (value `0`) in the grid, scanning left-to-right, top-to-bottom.
2. **Try** placing each digit from 1–9 in that cell.
3. **Validate** the placement against Sudoku rules (no repeated digits in the same row, column, or 3×3 box).
4. **Recurse** — if the placement is valid, move to the next empty cell and repeat.
5. **Backtrack** — if no digit leads to a solution, reset the cell to `0` and return, allowing the previous call to try the next candidate.

This guarantees finding a solution if one exists.

### Solution Counting

After solving, the program runs a separate exhaustive search (`COUNT_SOLUTIONS`) that explores all possible valid completions of the **solved** board, counting every distinct arrangement. A well-formed Sudoku puzzle should report exactly `1`.

---

## Code Structure

| Function | Description |
|---|---|
| `INPUT_BOX` | Reads the 9×9 puzzle from standard input |
| `isValidInput` | Validates that all cell values are between 0 and 9 |
| `PRINT_BOX` | Prints the board with row and column dividers every 3 cells |
| `SEARCH` | Finds the next unassigned cell; returns `false` when the board is full |
| `PROJECT` | Checks whether placing a number in a cell violates Sudoku constraints |
| `SUDOKU_SOLUTION` | Recursive backtracking solver; returns `true` if a solution is found |
| `COUNT_SOLUTIONS` | Exhaustively counts all valid solutions via backtracking |
| `main` | Entry point — orchestrates input, validation, solving, and output |

---

## Limitations

- **Performance on ambiguous puzzles:** Puzzles with many empty cells and multiple solutions may cause `COUNT_SOLUTIONS` to run slowly, as it must explore the entire solution space.
- **No GUI:** This is a command-line tool only.
- **Single puzzle per run:** The program processes one puzzle per execution.
- **Input format:** Input must be exactly 81 integers. Invalid or incomplete input may cause undefined behaviour.

---

## Potential Improvements

- Add a puzzle generator to create random valid puzzles
- Implement constraint propagation (e.g., naked singles, hidden singles) for faster solving
- Add file input/output support to read puzzles from `.txt` files
- Implement a difficulty rating based on the solving techniques required
- Add a GUI or web interface

---

## License

This project is released under the [MIT License](https://opensource.org/licenses/MIT). You are free to use, modify, and distribute it for any purpose.
