#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ar array
#define ve vector
#define pb push_back

bool check(ve<int>& seatingArrangement, ve<ar<int,3>>& constrains){
  // precompute positions
  int n = (int)seatingArrangement.size();
  ve<int> pos(n);
  for (int i = 0; i < n; ++i) pos[seatingArrangement[i]] = i;

  for (ar<int,3> i : constrains){
    int apart = abs(pos[i[0]]-pos[i[1]]);
    // at most i[2] seats apart
    if (i[2] > 0 && apart > i[2]) return false;
    // at least -i[2] apart
    else if (i[2] < 0 && apart < -i[2]) return false;
    
  }
  return true;
}

bool solve(){
  int cnt = 0;
  int m,n; cin >> n >> m;
  if (m == 0 && n == 0) return false;

  ve<int> seatingArrangement;
  for (int i = 0; i < n; ++i) seatingArrangement.pb(i);

  ve<ar<int,3>> constrains(m);
  for (ar<int,3>& i : constrains) cin >> i[0] >> i[1] >> i[2];

  do {
    if (check(seatingArrangement,constrains)) cnt++;
  } while(next_permutation(seatingArrangement.begin(),seatingArrangement.end()));

  cout << cnt << "\n";
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
