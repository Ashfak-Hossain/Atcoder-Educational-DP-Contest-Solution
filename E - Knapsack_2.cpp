/**
 *    author:  _Berlin_
 *    created: 07.04.2024 01:05:39 PM
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define endl '\n'
#define ll long long
const int N = 1e2 + 9;
const ll inf = 1e11;

int n, capacity, weight[N], value[N];
ll dp[N][N * 1000];

ll knapsack(int i, int total_value) {
  if(i == n + 1) {
    if(total_value == 0) {
      return 0;
    }
    return inf;
  }
  ll &ans = dp[i][total_value];
  if(ans != -1) return ans;
  ans = inf;
  ans = knapsack(i + 1, total_value);
  ans = min(ans, weight[i] + knapsack(i + 1, total_value - value[i]));
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> capacity;
  for(int i = 1; i <= n; i++){
    cin >> weight[i] >> value[i];
  }
  int ans = 0;
  memset(dp, -1, sizeof dp);
  for(int total_value = 1; total_value <= n * 1000; total_value++){
    if(knapsack(1, total_value) <= capacity) {
      ans = max(ans, total_value);
    }
  }
  cout << ans << endl;

  return 0;
} 