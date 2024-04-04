/**
 *    author:  _Berlin_
 *    created: 03.04.2024 02:59:17 PM
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define endl '\n'
const int N = 1e5 + 9;
const int inf = 1e9;

int n, h[N], dp[N]; // n = number of stones, h = height of the stones, dp = dp array to store the cost

/**
 * @brief Function to calculate the minimum cost incurred by the frog to reach the last stone
 * @param i Current stone position
 * @return Minimum cost to reach the last stone from the current position
 */
int frog(int i) {
  if(i > n) return inf; // if the frog jumps beyond the last stone then the cost is infinite 
  if(i == n) return 0; // if the frog is at the last stone then the cost is 0
  if(dp[i] != -1) return dp[i]; // if the cost is already calculated then return the cost
  int ans = abs(h[i] - h[i + 1]) + frog(i + 1); // cost to jump to the next stone from the current stone 
  ans = min(ans, abs(h[i] - h[i + 2]) + frog(i + 2)); // cost to jump to the stone after the next stone from the current stone 
  return dp[i] = ans; // store the cost in the dp array
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp); // initialize the dp array with -1 
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> h[i]; // input the height of the stones
  cout << frog(1) << endl;
  
  return 0;
}