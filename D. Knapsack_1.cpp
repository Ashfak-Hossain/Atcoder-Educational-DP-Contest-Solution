/**
 *    author:  _Berlin_
 *    created: 02.04.2024 10:36:16 AM
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define endl '\n'
#define int long long
const int N = 1e5 + 9;

int v[N], w[N], n, W, dp[105][N];

int knap(int i, int weight) {
  if(i == n + 1) return 0;
  if(dp[i][weight] != -1) return dp[i][weight];
  int ans = knap(i + 1, weight);
  if(weight + w[i] <= W) ans = max(ans, knap(i + 1, weight + w[i]) + v[i]);
  dp[i][weight] = ans;
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);
  cin >> n >> W;
  for(int i = 1; i <= n; i++){
    cin >> w[i] >> v[i];
  }
  cout << knap(1, 0) << endl;

  return 0;
}