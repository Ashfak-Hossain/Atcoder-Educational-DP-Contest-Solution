/**
 *    author:  _Berlin_
 *    created: 10.04.2024 02:40:50 PM
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

vector<int> g[N];
int dp[N];

int dist(int u) {
  int &ans = dp[u];
  if(ans != -1) return ans;
  ans = 0;
  for(auto v : g[u]) {
    ans = max(ans, 1 + dist(v));
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;
  while(m--) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  memset(dp, -1, sizeof dp);
  int ans = 0;
  for(int i = 1; i <= n; i++){
    ans = max(ans, dist(i));
  }
  cout << ans << endl;
  return 0;
} 