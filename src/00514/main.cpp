#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ar array
#define ve vector
#define pb push_back

// solution is just lazily similating with stacks...
bool solve(){
  int n; cin >> n;
  if (n == 0) return false;

  while (true){
    ve<int> inp(1);
    cin >> inp[0];
    if (inp[0] == 0) {
      cout << "\n";
      return true;
    }
    for (int i = 1; i < n; ++i){
      int in; cin >> in; inp.pb(in);
    }

    // inp is the goal that has to be achieved
    stack<int> trackA, station;
    for (int i = n; i >= 1; --i) trackA.push(i);
    int curCompleted = 0;
    while (!trackA.empty() || !station.empty()){
      if (!trackA.empty() && inp[curCompleted] == trackA.top()){
        trackA.pop(); curCompleted++;
      }
      else if (!station.empty() && inp[curCompleted] == station.top()){
        station.pop(); curCompleted++;
      }
      else if (!trackA.empty()) {
        station.push(trackA.top()); trackA.pop();
      }
      else break;
    }
    if (curCompleted != n) cout << "No\n";
    else cout << "Yes\n";
  }
}

int main (){
  #ifdef DEBUG
    //freopen("out","w", stdout);
    freopen("in","r", stdin);
  #endif
  while(solve()){}
  return 0;
}
