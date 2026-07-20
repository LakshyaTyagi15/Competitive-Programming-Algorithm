# Competitive Programming Algorithms

A practical collection of C++ templates for common competitive-programming data structures, graph algorithms, modular arithmetic, and combinatorics. Each file is intended to be copied into a contest solution and adapted to the problem at hand.

## Contents

| Topic | File | Highlights |
| --- | --- | --- |
| Binary lifting | [`Binary_Lifiting.cpp`](Binary_Lifiting.cpp) | `k`-th ancestor and lowest common ancestor (LCA) queries in `O(log n)` after `O(n log n)` preprocessing. |
| Disjoint-set union | [`DSU.cpp`](DSU.cpp) | Path compression and union by size. |
| Dijkstra — heap | [`Dijkstra - O(E*log(V)).cpp`](Dijkstra%20-%20O(E*log(V)).cpp) | Shortest paths on non-negative weighted graphs in `O(E log V)`. |
| Dijkstra — dense graph | [`Dijkstra - O(v^2).cpp`](Dijkstra%20-%20O(v%5E2).cpp) | Array-based Dijkstra for dense graphs, `O(V^2)`. |
| Fenwick tree | [`Fenwick_Tree.cpp`](Fenwick_Tree.cpp) | Point updates and prefix/range-sum queries in `O(log n)`. |
| Segment tree | [`Segment_Tree.cpp`](Segment_Tree.cpp) | Range sum queries, point assignment, and lazy range-add updates. |
| Flexible segment tree | [`Segment_Tree_Flexible.cpp`](Segment_Tree_Flexible.cpp) | Lazy segment tree parameterized with sum, minimum, maximum, or XOR nodes. |
| Matrix operations | [`Matrix.cpp`](Matrix.cpp) | Generic addition, multiplication, and fast matrix exponentiation. |
| Modular arithmetic | [`Modular.cpp`](Modular.cpp) | Type-safe modular integers and exponentiation; defaults to `1,000,000,007`. |
| Modular inverse | [`Mod_Inverse.cpp`](Mod_Inverse.cpp) | Fermat-based modular inverse for a prime modulus. |
| Combinations and permutations | [`PnC.cpp`](PnC.cpp) | Factorial precomputation with `nCr` and `nPr` modulo `1,000,000,007`. |
| Combinatorics helper | [`Combinatorics.cpp`](Combinatorics.cpp) | On-demand factorial/inverse-factorial helper; use together with `Modular.cpp`. |
| Starter template | [`Template.cpp`](Template.cpp) | Fast-I/O contest scaffold with PBDS support. |

## Using a snippet

1. Copy the relevant class, struct, or function into your solution.
2. Remove or replace the placeholder `main()`/`solve()` supplied in the snippet.
3. Match the input indexing expected by that implementation before calling it.

Most files use `#include <bits/stdc++.h>`; several also use GNU PBDS. Compile with GCC in GNU C++17 mode:

```bash
g++ -std=gnu++17 -O2 -pipe "DSU.cpp" -o solution
```

## Notes

- `Fenwick_Tree.cpp` exposes a **0-indexed** interface: `add(idx, value)`, `query(idx)`, and `query(left, right)`.
- `DSU.cpp` allocates elements from `1` through `n`.
- The segment-tree implementations use inclusive query ranges.
- Dijkstra's algorithm requires all edge weights to be non-negative.
- `Combinatorics.cpp` depends on the `Int` type declared by `Modular.cpp`; include the modular implementation first when combining them.
- The modular inverse and `nCr`/`nPr` helpers assume a prime modulus when using Fermat's little theorem.

## Contributing

Add new snippets as self-contained, readable `.cpp` files. Please include a short usage example or a minimal API, state index conventions clearly, and keep the time-complexity guarantees apparent from the implementation.
