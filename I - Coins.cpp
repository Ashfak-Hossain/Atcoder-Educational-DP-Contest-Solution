/**
 *    author:  _Berlin_
 *    created: 17.04.2024 11:33:11 AM
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

int n;
double a[N];
double dp[N][N];
bool vis[N][N];

double fun(int i, int head, int tail) {
  if(i == n + 1) {
    if(head > tail) {
      return 1;
    } else {
      return 0;
    }
  }
  if(vis[i][head]) return dp[i][head];
  vis[i][head] = true;
  double ans = a[i] * fun(i + 1, head + 1, tail);
  ans += (1 - a[i]) * fun(i + 1, head, tail + 1);
  return dp[i][head] = ans;
}

// State optimization, we don't need tail here
// Time complexity O(n^2)

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  cout << fixed << setprecision(10) << fun(1, 0, 0) << endl;

  return 0;
}