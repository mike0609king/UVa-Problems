#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ar array
#define ve vector
#define pb push_back

ar<int,2> timeToNum(ar<string,2> t){
    ar<int,2> ret = {0,0};
    ret[0] = stoi(t[0].substr(0,2) + t[0].substr(3,2));
    ret[1] = stoi(t[1].substr(0,2) + t[1].substr(3,2));
    return ret;
}

void solve(){
    ar<string,2> t1,t2;
    cin >> t1[0] >> t1[1] >> t2[0] >> t2[1];
    ar<int,2> T1, T2;
    T1 = timeToNum(t1); T2 = timeToNum(t2);
    if ((T1[0] <= T2[0] && T1[1] >= T2[0])
        || (T2[0] <= T1[0] && T2[1] >= T1[0])) {
        cout << "Mrs Meeting\n";
    }
    else cout << "Hits Meeting\n";

}

int main (){
    #ifdef DEBUG
        freopen("out","w", stdout);
        freopen("in","r", stdin);
    #endif
    int testCases=1;
    cin >> testCases;
    for(int t=1;t<=testCases;++t) {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
