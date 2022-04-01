#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ar array
#define ve vector
#define pb push_back

void solve(int n, int m){
  map<int,ve<int>> store;
  for (int i = 1; i <= n; ++i){
    int in; cin >> in;
    store[in].pb(i);
  }
  for (int i = 0; i < m; ++i){
    int k, v; cin >> k >> v; 
    if ((int)store[v].size() >= k){
      cout << store[v][k-1] << "\n";
    }
    else cout << "0\n";
  }
}

int main (){
  #ifdef DEBUG
    //freopen("out","w", stdout);
    freopen("in","r", stdin);
  #endif
  int n,m;
  while (cin >> n >> m) solve(n,m);
  return 0;
}
