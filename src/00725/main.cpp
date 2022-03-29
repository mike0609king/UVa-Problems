#include<bits/stdc++.h>

using namespace std;
using ll=long long;

bool first = true;

bool check(ll i){
  ll checkNum = 0;
  for(; i != 0; i/=10) checkNum |= 1<<(i%10);
  return checkNum+1 == (1<<10);
}

bool solve(){
  ll n; cin >> n;
  if (n == 0) return false;
  if (first) first = false;
  else cout << "\n";

  bool used = false;
  ll x = 1;
  while (x*n < (ll)1e5){
    if (x*n >= 1e4 && check(x*n*(ll)1e5+x)){
      string p = (x < 1e4) ? "0" + to_string(x) : to_string(x);
      cout << x*n << " / " << p << " = " << n << "\n";
      used = true;
    }
    ++x;
  }
  if (!used) cout << "There are no solutions for " << n << ".\n";
  return true;
}

int main (){
  #ifdef DEBUG
    //freopen("out","w", stdout);
    freopen("in","r", stdin);
  #endif
  while (solve()){}
  return 0;
}
