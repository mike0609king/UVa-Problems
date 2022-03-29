#include<bits/stdc++.h>

using namespace std;

using ll=long long;

void solve(){
  ll a,b,c; cin >> a >> b >> c;
  for (int x = -100; x <= 100; ++x){
    for (int y = -100; y <= 100; ++y){
      // now z is calculable
      int z = a-x-y; // formular 1
      if (x == y || x == z || y == z) continue;
      if (x*y*z == b && x*x+y*y+z*z == c){
        cout << x << " " << y << " " << z << "\n";
        return;
      }
    }
  }
  cout << "No solution.\n";
}

int main (){
  #ifdef DEBUG
    freopen("out","w", stdout);
    freopen("in","r", stdin);
  #endif
  int testCases=1;
  cin >> testCases;
  for(int t=1;t<=testCases;++t) solve();
  return 0;
}
