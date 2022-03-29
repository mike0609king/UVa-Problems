#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ve vector

void solve(){
  int n, p; cin >> n >> p;
  ve<int> bars(p);
  for (int& i : bars) cin >> i;
  
  for (int i = 0; i < (1 << p); ++i){
    int sum = 0;
    for (int j = 0; j < p; ++j){
      if (i&(1 << j)) sum += bars[j];
    }
    if (sum == n) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main (){
  #ifdef DEBUG
    //freopen("out","w", stdout);
    freopen("in","r", stdin);
  #endif
  int testCases=1;
  cin >> testCases;
  for(int t = 1;t <= testCases; ++t) solve();
  return 0;
}
