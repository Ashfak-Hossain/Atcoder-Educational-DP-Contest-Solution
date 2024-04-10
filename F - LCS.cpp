/**
 *    author:  _Berlin_
 *    created: 10.04.2024 11:22:46 PM
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef BERLIN
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define endl '\n'
const int N = 3005;

string s, t;
int dp[N][N];

int lcs(int i, int j) {
  if(i >= s.size() or j >= t.size()) return 0;
  int &ans = dp[i][j];
  if(ans != -1) return ans;
  ans = lcs(i + 1, j);
  ans = max(ans, lcs(i, j + 1));
  if(s[i] == t[j]) {
    ans = max(ans, lcs(i + 1, j + 1) + 1);
  }
  return dp[i][j] = ans;
}

void printLcs(int i, int j) {
  if (i >= s.size() or j >= t.size()) return;
  if (s[i] == t[j]) {
    cout << s[i];
    printLcs(i + 1, j + 1);
    return;
  }
  int x = lcs(i + 1, j);
  int y = lcs(i, j + 1);
  if (x >= y) {
    printLcs(i + 1, j);
  }
  else {
    printLcs(i, j + 1);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> t; 
  memset(dp, -1, sizeof dp);
  printLcs(0, 0);

  return 0;
}