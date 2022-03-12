#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ve vector

bool solve(){
    int n; cin >> n;
    if (n == 0) return false;
    ve<string> deck(n,"");
    int curPos = 0;
    auto upd = [&](){ curPos = (curPos+1)%n; };
    for (int i = 0; i < n; ++i){
        string card,s; cin >> card >> s;
        auto skip = [&](){ while (deck[curPos]!="")upd(); };
        for (int j = 0; j < (int)s.length()-1; ++j){
            if (deck[curPos] != "") {
                skip(); upd();
            }
            else upd();
        }
        skip();
        deck[curPos] = card;
        if (i != n-1) skip();
    }
    for (int i = 0; i < n; ++i){
        if (i != 0) cout << " ";
        cout << deck[i];
    }
    cout << "\n";
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
