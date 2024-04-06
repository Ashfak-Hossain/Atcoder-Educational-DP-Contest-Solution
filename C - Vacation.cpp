/**
 *    author:  _Berlin_
 *    created: 06.04.2024 11:49:26 PM
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

int n, dp[N][4], a[N][3];
int points(int i, int last) {
  if(i > n) return 0;
  int &ans = dp[i][last];
  if(ans != -1) return ans;
  ans = 0;
  for(int k = 0; k < 3; k++){
    if(k == last) continue;
    ans = max(ans, a[i][k] + points(i + 1, k));
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  } 
  // recursive
  cout << points(1, 3) << endl; // 3 because out state can be 0, 1, 2

  // iterative
  dp[n + 1][0] = dp[n + 1][1] = dp[n + 1][2] = dp[n + 1][3] = 0; // base case
  for(int i = n; i >= 1; i--){
    for(int last = 0; last < 4; last++){
      int &ans = dp[i][last];
      ans = 0;
      for(int k = 0; k < 3; k++){
        if(k == last) continue;
        ans = max(ans, a[i][k] + dp[i + 1][k]);
      }
    }
  }
  cout << dp[1][3] << endl;

  return 0;
} 