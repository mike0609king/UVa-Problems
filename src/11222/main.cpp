#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ar array
#define ve vector
#define pb push_back

int toCompare[3][2] = {{1,2},{0,2},{0,1}};
void solve(){
    ar<set<int>,3> inp;
    ar<ve<int>,3> noneOtherSolved;
    for (int i = 0; i < 3; ++i){
        int n; cin >> n;
        for (int j = 0; j < n; ++j){
            int a; cin >> a; inp[i].insert(a);
        }
    }
    for (int i = 0; i < 3; ++i){
        for (int j : inp[i]){
            if (inp[toCompare[i][0]].find(j) == inp[toCompare[i][0]].end()
             && inp[toCompare[i][1]].find(j) == inp[toCompare[i][1]].end()){
                noneOtherSolved[i].pb(j);
            }
        }
    }
    int mxSolved = -1;
    ve<ve<int>> sol;
    for (int i = 0; i < 3; ++i){
        if (mxSolved < (int)noneOtherSolved[i].size()){
            mxSolved = (int)noneOtherSolved[i].size();
            sol.clear();
        }
        if (mxSolved == (int)noneOtherSolved[i].size()){
            sort(noneOtherSolved[i].begin(),noneOtherSolved[i].end());
            noneOtherSolved[i].pb(i+1); // id of friend is appended (not very clean, but...)
            sol.pb(noneOtherSolved[i]);
        }
    }
    int cnt = 0;
    for (auto i : sol){
        if (cnt != 0) cout << "\n";
        cout << i.back() << " " << mxSolved;
        for (int j = 0; j < mxSolved; ++j) cout << " " << i[j];
        cnt++;
    }
    cout << "\n";
}

int main (){
    #ifdef DEBUG
        //freopen("out","w", stdout);
        freopen("in","r", stdin);
    #endif
    int testCases=1;
    cin >> testCases;
    for(int t=1;t<=testCases;++t) {
        cout << "Case #" << t << ":\n";
        solve();
    }
    return 0;
}
