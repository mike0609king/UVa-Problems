#include<bits/stdc++.h>

using namespace std;

int main (){
  #ifdef DEBUG
    //freopen("out","w", stdout);
    freopen("in","r", stdin);
  #endif
  string s;
  while (cin >> s){
    s = "]" + s;
    int n = (int)s.length();
    string tmp = "";
    for (int i = n-1; i >= 0; --i){
      char cur = s[i];
      if (cur == ']') tmp = "";
      else if (cur == '['){
        cout << tmp; tmp = "";
      }
      else tmp = cur + tmp;
    }
    bool print = false;
    for (int i = 0; i < n; ++i){
      char cur = s[i];
      if (cur == ']') print = true;
      else if (cur == '[') print = false;
      else if (print){
        cout << cur;
      }
    }
    cout << "\n";
  }
  return 0;
}
