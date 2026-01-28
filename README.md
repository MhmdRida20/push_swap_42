# push_swap

A sorting algorithm project that sorts a stack of integers using a limited set of operations.

## Description

This project implements an efficient sorting algorithm for two stacks (A and B) using only specific operations.

## Operations

- `sa` : swap a - swap the first 2 elements at the top of stack a
- `sb` : swap b - swap the first 2 elements at the top of stack b
- `ss` : sa and sb at the same time
- `pa` : push a - take the first element at the top of b and put it at the top of a
- `pb` : push b - take the first element at the top of a and put it at the top of b
- `ra` : rotate a - shift up all elements of stack a by 1
- `rb` : rotate b - shift up all elements of stack b by 1
- `rr` : ra and rb at the same time
- `rra` : reverse rotate a - shift down all elements of stack a by 1
- `rrb` : reverse rotate b - shift down all elements of stack b by 1
- `rrr` : rra and rrb at the same time

## Compilation
```bash
make
```

## Usage
```bash
./push_swap [numbers]
```

Example:
```bash
./push_swap 3 2 1 0
```

## Performance

- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: < 700 operations
- 500 numbers: < 5500 operations

## Algorithm

The program uses different strategies based on input size:
- **2-3 elements**: Hardcoded optimal solution
- **4-5 elements**: Push smallest to B, sort, push back
- **100+ elements**: Chunk-based algorithm

## Author

aalkhati & mrida - 42 School
