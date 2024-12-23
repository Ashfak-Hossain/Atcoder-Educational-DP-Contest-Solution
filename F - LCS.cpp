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


//* Bottom-Up Approach 

constexpr int MAX_N = 3e3 + 9;

int dp[MAX_N][MAX_N];

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;

  memset(dp, 0, sizeof dp);
  int m = s.size(), n = t.size();

  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if(s[i - 1] == t[j - 1]) {
        dp[i][j] =max(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }

  string lcs;
  int i = m, j = n;
  while (i && j) {
    if (s[i-1] == t[j-1]) {
      lcs += s[i-1];
      i--, j--;
    } else if (dp[i][j-1] >= dp[i-1][j]) {
      j--;
    } else {
      i--;
    }
  }

  reverse(begin(lcs), end(lcs));

  cout << lcs << "\n";

  return 0;
}