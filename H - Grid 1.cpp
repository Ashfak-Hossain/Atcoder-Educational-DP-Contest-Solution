/**
 *    author:  _Berlin_
 *    created: 10.04.2024 03:07:51 PM
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define endl '\n'
const int N = 1005;
const int mod = 1e9 + 7;

int n, m, dp[N][N];
string a[N];

int path(int i, int j) {
  if(i >= n or j >= m) return 0;
  if(a[i][j] == '#') return 0;
  if(i == n - 1 and j == m - 1) return 1;
  int &ans = dp[i][j];
  if(ans != -1) return ans;
  ans = path(i + 1, j);
  ans += path(i, j + 1);
  ans %= mod;
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  memset(dp, -1, sizeof dp);
  cout << path(0, 0) << endl;

  return 0;
} 