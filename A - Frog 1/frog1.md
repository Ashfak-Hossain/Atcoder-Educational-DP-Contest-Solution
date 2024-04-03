## Problem Description
#### Problem Title: Frog 1

Time Limit: 2 sec

Memory Limit: 1024 MB

**Problem Statement**
You are given a sequence of stones numbered from `1 to N`. Each stone has a certain `height`. A frog is initially positioned on `Stone 1`. The frog's objective is to reach Stone `N`, by making jumps from Stone `i` to either Stone `i+1` or Stone `i+2`. However, with each jump, there is a cost incurred which is equal to the absolute difference in height between the stone the frog is currently on and the stone it is jumping to.

Your task is to determine the `minimum total cost` the frog incurs to reach Stone N.

#### Constraints
$2 ≤ N ≤ 10^5$
$1$ ≤ height of each stone ≤ $10^4$

**Input**
The input consists of:

The first line contains a single integer `N`, indicating the number of stones.
The second line `contains N integers` separated by space, representing the height of each stone from 1 to N.

**Output**
Print a single integer, denoting the minimum total cost incurred by the frog to reach Stone `N`.

#### Sample Input and Output
```cpp
Sample Input 1:
4
10 30 40 20

Sample Output 1:
30

Explanation 1:

If the frog follows the path 1 → 2 → 4, 
the total cost incurred would be |10-30| + |30-20| = 30.
```
```cpp
Sample Input 2:
2
10 10

Sample Output 2:
0

Explanation 2:

If the frog follows the path 1 → 2, the total cost incurred would be |10-10| = 0.
```
```cpp
Sample Input 3:

6
30 10 60 10 60 50

Sample Output 3:
40

Explanation 3:

If the frog follows the path 1 → 3 → 5 → 6, 
the total cost incurred would be |30-60| + |60-60| + |60-50| = 40.
```

**Key Insights**
The problem's constraints simplify our approach significantly. Notably:

* The frog's jumping options are limited to `one stone ahead (i+1)` or `two stones ahead (i+2)` from its current position __(i)__.
* We will create an array __dp__ of size __n__ (the total number of stones). **dp[i]** will store the minimum cost we can achieve till position **i**. An array __jumps of size n__ will store the height of each stone.
This restriction enables us to employ a dynamic programming approach efficiently.

Approach: __Recursive__

* If the frog reaches the last stone, return 0
* Base Cases: If the frog goes beyond the last stone, return infinity 
* Recursive step: Calculate the minimum cost to reach position i by considering two possible jumps `(i + 1) and (i + 2)`


#### Time Complexity: O(N)

#### Space Complexity: O(N)

Explanation:

##### Time Complexity:

* The frog function is called recursively for **each stone (i) from 1 to N**.
* In the worst case, each function call calculates the minimum cost for both the next jump **(i+1)** and the jump two stones ahead **(i+2)**.
* However, due to memoization (**dp[i]**), subsequent calls for the same position (i) avoid redundant calculations.
* Therefore, the total number of function calls is proportional to the number of stones (N), resulting in a **time complexity of O(N)**
  
##### Space Complexity:

* The **dp array** stores the minimum cost for reaching each stone (i).
* The **size of the dp array is N**, and it's used throughout the program.
* Hence, the **space complexity is O(N)**