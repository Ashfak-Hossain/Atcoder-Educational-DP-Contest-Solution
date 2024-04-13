/**
 *    author:  _Berlin_
 *    created: 13.04.2024 10:52:35 PM
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
const int mod = 1e9 + 7;

int dp[N][2];
vector<int> g[N];

void dfs(int u, int p) {
  dp[u][0] = 1;
  dp[u][1] = 1;
  for(auto v : g[u]) {
    if(v != p) {
      dfs(v, u);
      dp[u][0] = 1LL * dp[u][0] * (dp[v][0] + dp[v][1]) % mod;
      dp[u][1] = 1LL * dp[u][1] * dp[v][0] % mod;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  cout << (dp[1][0] + dp[1][1]) % mod << endl;

  return 0;
} 