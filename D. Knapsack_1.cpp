/**
 *    author:  _Berlin_
 *    created: 07.04.2024 12:53:23 AM
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
const int N = 1e5 + 9;


int n, capacity, weight[N], value[N];
ll dp[105][N];

ll knapsack(int i, int curr_weight) {
  if(i == n + 1) return 0;
  ll &ans = dp[i][curr_weight];
  if(ans != -1) return ans;
  ans = knapsack(i + 1, curr_weight);
  if(curr_weight + weight[i] <= capacity) {
    ans = max(ans, value[i] + knapsack(i + 1, curr_weight + weight[i]));
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);
  cin >> n >> capacity;
  for(int i = 1; i <= n; i++){
    cin >> weight[i] >> value[i];
  }
  // recursive
  cout << knapsack(1, 0) << endl;

  // iterative
  for(int i = n; i >= 1; i--){
    for(int currentWeight = 0; currentWeight <= capacity; currentWeight++){
      ll &ans = dp[i][currentWeight];
      ans = 0;
      ans = dp[i + 1][currentWeight];
      if(currentWeight + weight[i] <= capacity) {
        ans = max(ans, value[i] + dp[i + 1][currentWeight] + weight[i]);
      }
    }
  }
  cout << dp[1][0] << endl;

  return 0;
}