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

int n, h[N], dp[N];

/**
 * @brief Function to calculate the minimum cost incurred by the frog to reach the last stone
 * @param i Current stone position
 * @return Minimum cost to reach the last stone from the current position
 */
int frog(int i) {
  if(i > n) return inf;
  if(i == n) return 0;
  if(dp[i] != -1) return dp[i];
  int ans = abs(h[i] - h[i + 1]) + frog(i + 1);
  ans = min(ans, abs(h[i] - h[i + 2]) + frog(i + 2));
  return dp[i] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof dp);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> h[i];
  cout << frog(1) << endl;
  
  return 0;
}