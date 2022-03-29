#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ve vector
#define pb push_back

bool first = true;
bool solve(){
  int k; cin >> k;
  if (k == 0) return false;
  if (first) first = false;
  else cout << "\n";

  ve<int> inp(k);
  for (int& i : inp) cin >> i;
  for (int a = 0; a < k-5; ++a){
    for (int b = a+1; b < k-4; ++b){
      for (int c = b+1; c < k-3; ++c){
        for (int d = c+1; d < k-2; ++d){
          for (int e = d+1; e < k-1; ++e){
            for (int f = e+1; f < k; ++f){
              cout << inp[a] << " "
                   << inp[b] << " "
                   << inp[c] << " "
                   << inp[d] << " "
                   << inp[e] << " "
                   << inp[f] << "\n";
            }
          }
        }
      }
    }
  }
  return true;
}

int main (){
  #ifdef DEBUG
    //freopen("out","w", stdout);
    freopen("in","r", stdin);
  #endif
  while(solve()){}
  return 0;
}
