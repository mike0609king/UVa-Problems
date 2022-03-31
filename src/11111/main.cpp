#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ar array
#define ve vector
#define pb push_back

const string YES = ":-) Matrioshka!";
const string NO = ":-( Try again.";

void solve(string inp){
    ll maxN = (ll)inp.length();
    ll sum = 0;
    string tmp;
    istringstream gout(inp);
    // [<positive number (the other end)>, 
    //  <keeps track of the total toy value in the current number>]
    ve<ar<ll,2>> st; // vector is used for in place editing (Would stack be faster?)
    while (sum < maxN){
      gout >> tmp;
      sum += (ll)tmp.length()+1;
      ll num = (ll)stoi(tmp);
      if (num < 0) st.pb({-num,0});
      else {
        if (st.empty() || st.back()[0] != num){
          cout << NO << "\n"; return;
        }
        else {
          st.pop_back();
          if (!st.empty()){
            int lastIdx = (int)st.size()-1;
            st[lastIdx][1] += num;
            if (st[lastIdx][0] <= st[lastIdx][1]){
              cout << NO << "\n"; return;
            }
          }
        }
      }
    }
    if (!st.empty()) cout << NO << "\n";
    else cout << YES << "\n";
}

int main (){
  #ifdef DEBUG
    //freopen("out","w", stdout);
    freopen("in","r", stdin);
  #endif
  string inp;
  while (getline(cin, inp)) solve(inp);
  return 0;
}
