#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ve vector
#define pb push_back

ve<ve<int>>adj;
ve<bool> vis;

int dfs(int i){
  if (vis[i]) return 0;
  vis[i] = true;
  int ret = 1;
  for (int j : adj[i]) ret += dfs(j);
  return ret;
}

void solve(){
  adj = ve<ve<int>>(26);
  vis = ve<bool>(26, false);
  set<int> se; // existing nodes
  string s = "";
  while (true){
    cin >> s;
    if (s[0] == '*') break;
    int i = s[1]-'A'; int j = s[3]-'A'; 
    adj[i].pb(j); adj[j].pb(i);
  }
  cin >> s;
  for (int i = 0; i < (int)s.length(); i+=2) se.insert((int)s[i]-'A');


  int acorn = 0, tree = 0;
  for (int i : se){
    int size = dfs(i);
    if (size == 1) acorn++;
    else if (size > 1) tree++;
  }
  cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n";
}

int main (){
  #ifdef DEBUG
    //freopen("out","w", stdout);
    freopen("in","r", stdin);
  #endif
  int testCases; cin >> testCases;
  for(int t=1;t<=testCases;++t) solve();
  return 0;
}
