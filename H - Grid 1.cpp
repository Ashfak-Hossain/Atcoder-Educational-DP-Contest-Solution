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

constexpr int MAX_N = 1e3 + 9;
constexpr int mod = 1e9 + 7;

int n, m, dp[MAX_N][MAX_N];
string a[MAX_N];

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
  cout << path(0, 0) << "\n";

  return 0;
} 

//* Bottom-Up Approach

int dp[MAX_N][MAX_N];
char a[MAX_N][MAX_N];

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  dp[0][0] = (a[0][0] != '#');

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') {
        dp[i][j] = 0;
      } else {
        if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod; 
        if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
      }
    }
  }

  cout << dp[n - 1][m - 1] << "\n";

  return 0;
} 