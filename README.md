# Push_swap

_This project has been created as part of the 42 curriculum by MhmdRida20._

## Description

Push_swap is an algorithmic project that sorts data on a stack with a limited set of instructions, using the lowest possible number of actions. The program implements four distinct sorting strategies (O(n²), O(n√n), O(n log n), and an adaptive algorithm) and selects the optimal approach based on the input's disorder metric.

## Instructions

### Compilation
```bash
make        # Compile push_swap
make bonus  # Compile checker (bonus)
make clean  # Remove object files
make fclean # Remove everything
make re     # Recompile
```

### Installation
```bash
git clone https://github.com/MhmdRida20/push_swap_42.git
cd push_swap_42
make
```

### Usage
```bash
# Basic usage
./push_swap 3 2 1 5 4

# With strategy selection
./push_swap --simple 4 3 2 1      # Force O(n²) algorithm
./push_swap --medium 5 4 3 2 1    # Force O(n√n) algorithm
./push_swap --complex 9 7 5 3 1   # Force O(n log n) algorithm
./push_swap --adaptive 2 1 4 3    # Adaptive (default)

# Benchmark mode
./push_swap --bench 4 67 3 87 23

# Count operations
./push_swap 3 2 1 | wc -l

# Test with checker (bonus)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

# Generate random test
ARG=$(shuf -i 0-9999 -n 100); ./push_swap $ARG | wc -l
```

## Algorithm Explanations

### 1. Simple Sort - O(n²)
**Strategy**: Insertion sort adaptation

Repeatedly finds the minimum element and moves it to the correct position using rotations and pushes.

**Complexity**: O(n²) operations in the worst case

### 2. Medium Sort - O(n√n)
**Strategy**: Chunk-based partitioning

Divides input into √n chunks, processes each chunk separately, then merges them back in sorted order.

**Complexity**: O(n√n) operations

### 3. Complex Sort - O(n log n)
**Strategy**: Radix sort (LSD)

Normalizes values to indices and sorts by processing each bit position from least to most significant.

**Implementation**:
- Normalize values to 0, 1, 2, ... n-1
- For each bit (starting from LSB):
  - Push to B if bit is 0, keep in A if bit is 1
  - Push all back from B to A
- Repeat for log₂(n) bits

**Complexity**: O(n log n) operations - optimal for large datasets

### 4. Adaptive Algorithm
**Strategy**: Dynamic selection based on disorder metric

Automatically selects the best algorithm based on how disordered the input is:
```
if disorder < 0.2:          Use O(n) optimizations
if 0.2 ≤ disorder < 0.5:    Use O(n√n) medium sort
if disorder ≥ 0.5:          Use O(n log n) complex sort
```

**Disorder Calculation**:
```
disorder = inversions / total_pairs
```
Where inversions are pairs where a larger element appears before a smaller one.

**Examples**:
- `[1, 2, 3, 4]` → disorder = 0.0 (0%)
- `[4, 3, 2, 1]` → disorder = 1.0 (100%)
- `[2, 1, 3, 4]` → disorder = 0.167 (16.7%)

**Justification**: The adaptive algorithm provides optimal performance across all input sizes and disorder levels by automatically selecting the most efficient strategy. Low disorder inputs benefit from simple optimizations, while highly disordered large inputs use the asymptotically optimal radix sort.

## Resources

### Classic References
- "Introduction to Algorithms" by Cormen et al. - Sorting algorithms fundamentals
- "The Art of Computer Programming Vol. 3" by Donald Knuth - Sorting and searching
- [Big-O Notation Guide](https://www.bigocheatsheet.com/)
- [Sorting Algorithms Visualization](https://www.toptal.com/developers/sorting-algorithms)
- [Push_swap Medium Tutorial](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

### AI Usage

AI tools (Claude AI) were used for:
- **Algorithm research**: Understanding sorting adaptations for two-stack constraints
- **Code structure**: Organizing modular components and best practices
- **Debugging**: Identifying memory leaks and logic errors
- **Documentation**: README structure and comprehensive comments
- **Optimization**: Exploring ways to reduce operation counts

**Important**: All submitted code is fully understood and implemented by the author. AI provided guidance and suggestions, but final decisions, implementations, and testing were performed independently. Every part of the code can be explained in detail during evaluation.

## Performance

### Target Benchmarks

#### 100 random numbers:
- ✅ Pass: < 2000 operations
- ⭐ Good: < 1500 operations
- 🏆 Excellent: < 700 operations

#### 500 random numbers:
- ✅ Pass: < 12000 operations
- ⭐ Good: < 8000 operations
- 🏆 Excellent: < 5500 operations

### Available Operations

- `sa`, `sb`, `ss` - Swap first two elements
- `pa`, `pb` - Push from one stack to another
- `ra`, `rb`, `rr` - Rotate (shift up)
- `rra`, `rrb`, `rrr` - Reverse rotate (shift down)

## Author

MhmdRida20 - 42 Beirut