#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ar array
#define ve vector
#define pb push_back

const int importantBits = (1<<9)-1;
void solve(){
    int n,q; cin >> n >> q;
    ve<bool> calculated(importantBits+1,false);
    ar<int,231> a; a.fill(0);
    for (int i = 0; i < n; ++i){
        int inp; cin >> inp;
        int mask = inp&importantBits;
        if (calculated[mask]) continue;
        calculated[mask] = true;
        for (int j = 0; j <= 230; ++j) a[j] = max(a[j], j & mask);
    }
    for (int i = 0; i < q; ++i){
        int inp; cin >> inp;
        cout << a[inp] << "\n";
    }
}

int main (){
    #ifdef DEBUG
        //freopen("out","w", stdout);
        freopen("in","r", stdin);
    #endif
    int testCases=1;
    cin >> testCases;
    for(int t=1;t<=testCases;++t) solve();
    return 0;
}
