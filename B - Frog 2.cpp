/**
 *    author:  _Berlin_
 *    created: 06.04.2024 10:38:23 AM
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

int n, k, h[N], dp[N];

// from 1 ... n
int frog(int i) {
  if(i > n) return inf;
  if(i == n) return 0;
  int &ans = dp[i];
  if(ans != -1) return ans;
  ans = inf;
  for(int j = i + 1; j <= i + k; j++) {
    ans = min(ans, abs(h[i] - h[j]) + frog(j));
  }
  return ans;
}

// form n ... 1
int ffrog(int i) {
  if(i <= 0) return inf;
  if(i == 1) return 0;
  int &ans = dp[i];
  if(ans != -1) return ans;
  ans = inf;
  for(int j = i; j >= i - k; j--) {
    ans = min(ans, abs(h[i] - h[j]) + ffrog(j));
  }
  return ans;
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  memset(dp, -1, sizeof dp);

  // recursive
  cout << frog(1) << endl;
  cout << ffrog(n) << endl;

  //iterative
  dp[0] = 0;
  dp[1] = 0;
  for(int i = 2; i <= n; i++){
    int ans = inf;
    for(int j = 1; j <= k; j++) {
      if(j < i){
        ans = min(ans, abs(h[i] - h[i - j]) + dp[i - j]);
      }
    }
    dp[i] = ans;
  }
  cout << dp[n] << endl;

  return 0;
}