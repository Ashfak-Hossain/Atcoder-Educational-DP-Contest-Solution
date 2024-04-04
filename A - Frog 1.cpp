/**
 *    author:  _Berlin_
 *    created: 04.04.2024 10:31:51 AM
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

int frog(int i) {
  if(i > n) return inf;
  if(i == n) return 0;
  int &ans = dp[i];
  if(ans != -1) return ans;
  ans = abs(h[i] - h[i + 1]) + frog(i + 1);
  ans = min(ans, abs(h[i] - h[i + 2]) + frog(i + 2));
  return ans;
}

int ffrog(int i) {
  if(i < 0) return inf;
  if(i == 1) return 0;
  int &ans = dp[i];
  if(ans != -1) return ans;
  ans = abs(h[i] - h[i - 1]) + ffrog(i - 1);
  ans = min(ans, abs(h[i] - h[i - 2]) + ffrog(i - 2));
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> h[i];
  }
  memset(dp, -1, sizeof dp);

  // recursive
  cout << frog(1) << endl;
  cout << ffrog(n) << endl;

  // iterative
  for(int i = n; i >= 1; i--) {
    if(i == n) {
      dp[i] = 0;
    }else {
      int &ans = dp[i];
      ans = abs(h[i] - h[i + 1]) + dp[i + 1];
      if(i + 2 <= n) {
        ans = min(ans, abs(h[i] - h[i + 2]) + dp[i + 2]);
      }
    }
  }
  cout << dp[1] << endl;

  return 0;
}