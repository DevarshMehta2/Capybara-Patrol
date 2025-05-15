
# The Last of Us

## Problem Statement

One languid summer’s afternoon, the intrepid protagonists Alice and Bob elect to challenge one another in a protracted contest of chance and strategy, euphemistically entitled **“The Last of Us.”** Furnished with an urn containing exactly N identical, indivisible blocks, the two adversaries engage in an alternating sequence of moves governed by an index‑sensitive removal rule.

1. **Turn Indexing and Move Set.**  We label the successive turns by the positive integers x = 1,2,3,....  On the x-th turn, the active participant—Alice or Bob—must remove from the remaining pool of blocks one of the following permissible quantities, provided that quantity does not exceed the remaining count:
   - Exactly 1 block.
   - Exactly x blocks.
   - Exactly 2x blocks.
   - Exactly floor(x/2) blocks.

2. **Uniform Random Selection.**  At each juncture, the player whose turn it is selects *uniformly at random* from among all legal removal options. No strategic bias or preferential weighting is allowed; each admissible move is equally likely.

3. **Victory Condition.**  Play proceeds in strict alternation—Alice inaugurates the sequence at turn x=1, followed by Bob at x=2, and so on—culminating when the last block is extracted. The individual who removes the very final block is declared the winner.

4. Attempt this problem without dynamic programming.

5. **Probabilistic Objective.**  Given the initial block count N, determine the exact probability that **Alice** (the first mover) emerges victorious under this stochastic removal protocol.

## Input Format

- A single integer N on its own line, where 1 <= N <= 9.

## Output Format

- A single rational (floating-point) number: the probability that Alice wins the game.

## Constraints

- 1 <= N <= 9
- Time limit per test case: 1 ms
- Memory limit: 256 MB

## Example

**Input**  
3

**Output**  
.3333

**Explanation**  
Start (3)  
│  
├── Alice takes 1 → (2 blocks remain)  
│   │  
│   ├── Bob takes 1 → (1 block remain)  
│   │   └── Alice takes 1 → (0 blocks) ✅ Alice wins  
│   │  
│   └── Bob takes 2 → (0 blocks) ❌ Bob wins  
│  
└── Alice takes 2 → (1 block remain)  
    └── Bob takes 1 → (0 blocks) ❌ Bob wins
