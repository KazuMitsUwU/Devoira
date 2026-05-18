*This project has been created as part of the 42 curriculum by [sitrakaa],[manoaran].*

---

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 school curriculum. The goal is to sort a stack of integers using only two stacks (`a` and `b`) and a restricted set of operations, in as few moves as possible.

The program reads a list of integers from the command line, then outputs the sequence of operations that sorts them. The challenge lies in choosing an efficient strategy depending on the size and disorder of the input, since the number of operations is strictly evaluated.

### Allowed operations

| Operation | Effect |
|-----------|--------|
| `sa` / `sb` | Swap the top two elements of stack a / b |
| `ss` | `sa` and `sb` at the same time |
| `pa` / `pb` | Push top of b to a / top of a to b |
| `ra` / `rb` | Rotate stack a / b upward |
| `rr` | `ra` and `rb` at the same time |
| `rra` / `rrb` | Reverse rotate stack a / b |
| `rrr` | `rra` and `rrb` at the same time |

---

## Algorithms

This project implements an **adaptive strategy selector** that picks the best sorting algorithm based on input size and disorder level. Here is a detailed breakdown of each algorithm and the justification for its use.

### 1. Three/Five Sort — `three_five_sort.c`

For inputs of 2–5 elements, hardcoded optimal sequences are used. With so few elements, any general algorithm would waste operations. The optimal move count for 3 elements is at most 2 operations, and for 5 elements it stays under 12. This is the most operation-efficient path for small inputs.

### 2. Insertion Sort — `simple_sort.c`

For small inputs (roughly 6–20 elements) that are nearly sorted (disorder < 10%), insertion sort is used. It finds the minimum element, rotates it to the top of stack `a`, and pushes it to `b`, repeating until `a` is empty, then pushes everything back. This is O(n²) in move count but performs very well on nearly-sorted data where most elements are already close to their final position.

**Justification:** When the disorder metric (fraction of inverted pairs) is below 0.1, the stack is almost sorted. Insertion sort exploits this property; chunk or radix sort would waste moves on unnecessary grouping or bit passes.

### 3. Chunk Sort — `chunk_sort.c`, `chunk_process.c`

For medium inputs (roughly 20–100 elements) with moderate disorder (between 10% and 50%), the stack is divided into chunks based on the sorted rank (position) of each element. Chunks are processed one at a time: elements belonging to the current chunk are pushed to `b`, then pushed back to `a` in order. The number of chunks is approximately `√n / 2`.

**Justification:** Chunk sort reduces the problem into smaller, manageable subsets. It avoids the overhead of full radix passes for moderately disordered data and performs significantly better than insertion sort at this scale. The chunk size derived from `√n` keeps the number of rotations per chunk bounded, giving roughly O(n√n) total operations.

### 4. Radix Sort (binary) — `complex_sort.c`

For large inputs (100+ elements) or heavily disordered data (disorder ≥ 50%), binary radix sort is used. Elements are first ranked (assigned a position from 0 to n−1), then sorted bit by bit from LSB to MSB. On each pass, elements with a 0 in the current bit are pushed to `b`; elements with a 1 are rotated in `a`. After all bits are processed, the stack is sorted.

**Justification:** Radix sort is O(n × log n) in the number of operations (since log₂(n) bit passes are needed, each requiring n moves). For large n this dominates all other strategies. It does not depend on how disordered the input is — its cost is entirely determined by input size. The ranking step ensures it works on arbitrary integer values, not just indices.

### 5. Adaptive Selector — `adaptive_sort.c`

The `adaptive_sort` function ties everything together. It computes the disorder metric (ratio of inverted pairs over all pairs), then selects:

- `n ≤ 5` → three/five sort
- disorder = 0.0 → already sorted, exit
- disorder < 0.1 and n < 100 → insertion sort
- n ≥ 100 or disorder ≥ 0.5 → radix sort
- otherwise → chunk sort

**Justification:** No single algorithm is optimal across all cases. A 6-element nearly-sorted stack would be wasted on radix sort; a 500-element fully random stack would be killed by insertion sort. The disorder metric provides a data-driven signal to route each input to the best algorithm, keeping total operation counts within 42's grading thresholds (≤700 for n=100, ≤5500 for n=500).

---

## Instructions

### Requirements

- A C compiler (`cc`) with support for `-Wall -Wextra -Werror`
- `make`

### Compilation

The project contains two parts: the `ft_printf` library and the main `push_swap` program. Build from the root of the repository:

```bash
# Build ft_printf first (inside ft_printf/ subdirectory)
cd ft_printf
make
cd ..

# Build push_swap
make
```

This produces the `push_swap` executable.

### Execution

```bash
# Sort a list of integers
./push_swap 3 1 4 1 5 9 2 6

# With --bench flag to display operation statistics
./push_swap --bench 3 1 4 1 5 9 2 6

# Force a specific strategy
./push_swap --simple 5 3 1 2 4
./push_swap --medium 5 3 1 2 4
./push_swap --complex 5 3 1 2 4
./push_swap --adaptive 5 3 1 2 4   # default

# Integers can also be passed as a single quoted string
./push_swap "3 1 4 1 5"
```

### Flags

| Flag | Effect |
|------|--------|
| `--adaptive` | Default — auto-selects best algorithm |
| `--simple` | Forces insertion sort |
| `--medium` | Forces chunk sort |
| `--complex` | Forces radix sort |
| `--bench` | Prints operation statistics to stderr |

### Validation

You can pipe the output into a checker (if available):

```bash
ARG="3 1 4 1 5 9"; ./push_swap $ARG | ./checker $ARG
```

### Clean

```bash
make clean    # remove object files
make fclean   # remove objects + binary
make re       # full rebuild
```

---

## Resources

### Documentation & References

- [The original push_swap subject (42)](https://cdn.intra.42.fr/pdf/pdf/159806/en.subject.pdf) — official project specification
- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort) — overview of the LSD radix sort algorithm
- [Insertion Sort — Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort) — theory and complexity
- [Sorting Algorithms Visualized](https://visualgo.net/en/sorting) — interactive visualization of sorting algorithms
- [push_swap — A journey through sorting algorithms (Medium)](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) — community writeup on push_swap strategies
- [The disorder / inversions metric](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)) — mathematical background on counting inversions

### AI Usage

**Claude (Anthropic)** was used during this project for the following tasks:

- **Algorithm selection logic** (`adaptive_sort.c`): AI was consulted to reason about which disorder threshold values make sense as cutoffs between strategies, and to validate the O(n√n) claim for chunk sort.
- **Chunk size formula**: The `√n / 2` chunk count formula was explored with AI assistance to balance the number of chunks against rotation cost per chunk.
- **Debugging**: AI helped trace edge cases in `rra`/`rrb` (reverse rotate) and the `push_back_to_a` logic in chunk sort where elements were not being returned in the correct order.
- **README writing**: This README was drafted with AI assistance based on the full project source code.

AI was not used to write the core sorting logic wholesale — implementation was done by the authors, with AI serving as a sounding board and debugging tool.
