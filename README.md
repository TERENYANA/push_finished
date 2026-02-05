# Push_Swap by yyuskiv

*This project has been created as part of the 42 curriculum by yyuskiv.*

## Description

Push_swap is a sorting algorithm project that challenges students to sort data on a stack with a limited set of instructions, using the lowest possible number of actions. The project involves manipulating two stacks (stack A and stack B) using a specific set of operations to sort integers in ascending order.

### Goal

The main objective is to sort a random list of integers using two stacks and a limited set of operations, while minimizing the number of moves. The program must:

- Sort integers in ascending order on stack A
- Use stack B as an auxiliary stack
- Achieve optimal or near-optimal sorting efficiency
- Handle edge cases and errors gracefully

### Algorithm

This implementation uses the Turk Algorithm (also known as the push_swap algorithm), which is an efficient approach for sorting with two stacks:

1. Push all except 3 to stack B: Keeps the three smallest/largest elements in stack A
2. Sort three elements: Uses a simple algorithm to sort 3 numbers optimally (max 3 operations)
3. Push back with targets: For each element in B, calculates the optimal position in A
4. Cost calculation: Computes rotation costs for both stacks
5. Greedy selection: Always moves the element with the lowest total cost
6. Final rotation: Rotates stack A to have the minimum element at the top

### Performance

- 3 numbers: ≤3 operations
- 5 numbers: ≤12 operations
- 100 numbers: ~500-700 operations (good), <500 (excellent)
- 500 numbers: ~4500-5500 operations (good), <4500 (excellent)

---

## Instructions

### Prerequisites

- GCC compiler
- Make
- Unix-based system (Linux/macOS)

### Compilation

```bash
# Clone the repository
git clone <repository-url>
cd push_swap

# Compile the project
make

# Clean object files
make clean

# Clean everything (objects + executable)
make fclean

# Recompile from scratch
make re
```

### Usage

```bash
# Basic usage
./push_swap [list of integers]

# Examples
./push_swap 3 2 1
./push_swap 5 4 3 2 1
./push_swap 42 7 -3 0 15

# Test with random numbers (macOS)
./push_swap $(ruby -e "puts (1..100).to_a.shuffle.join(' ')")

# Count operations
./push_swap 3 2 1 | wc -l
```

### Input Rules

- Only integers within INT_MIN to INT_MAX range (-2147483648 to 2147483647)
- No duplicates allowed
- At least 2 arguments required

### Error Handling

The program outputs Error to stderr for:

- Non-numeric arguments
- Duplicate numbers
- Numbers outside INT range
- Invalid format (e.g., +, - alone)

### Available Operations

| Operation | Description |
|-----------|-------------|
| sa | Swap first 2 elements of stack A |
| sb | Swap first 2 elements of stack B |
| ss | sa and sb at the same time |
| pa | Push first element of B to top of A |
| pb | Push first element of A to top of B |
| ra | Rotate stack A up (first → last) |
| rb | Rotate stack B up (first → last) |
| rr | ra and rb at the same time |
| rra | Reverse rotate A (last → first) |
| rrb | Reverse rotate B (last → first) |
| rrr | rra and rrb at the same time |

---

## Resources

### Documentation & Tutorials

- Push_swap Subject (42 Intranet)
- Turk Algorithm Explanation
- Visualizer for Push_swap
- Algorithm Complexity Analysis

### AI Usage

AI assistance (Claude AI) was used for the following tasks:

#### Code Optimization

- Reducing function count in execute.c from 6 to 3 functions
- Reducing function count in parser.c from 6 to 1 function
- Creating utils.c to centralize helper functions
- Ensuring all functions stay under 25 lines (norminette compliance)

#### Bug Fixing

- Identifying and fixing duplicate includes
- Correcting header include syntax
- Memory leak detection and fixing

#### Documentation

- Structuring this README
- Explaining the Turk algorithm implementation
- Creating usage examples and troubleshooting guides

#### AI did NOT write

- The core sorting algorithm logic (turk.c, targets.c, costs.c)
- Stack operations (push.c, swap.c, rotate.c, reverse.c)
- The main algorithm flow and data structures

---

## Author

yyuskiv - 42 Student

---

## License

This project is part of the 42 School curriculum. Feel free to use it for learning purposes, but please don't copy it for your own 42 project evaluation.
