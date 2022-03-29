#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ar array
#define ve vector
#define pb push_back

void solve(int n){
    ve<ll> weights(1<<n);
    ve<ll> calcWeights(1<<n,0);
    ll mx = -1;
    for (int i = 0; i < 1<<n; ++i) cin >> weights[i];
    for (int i = 0; i < 1<<n; ++i){
        for (int j = 0; j < n; ++j){
            calcWeights[i] += weights[i^(1<<j)];
        }
    }
    for (int i = 0; i < 1<<n; ++i){
        for (int j = 0; j < n; ++j){
            mx = max(mx,calcWeights[i^(1<<j)]+calcWeights[i]);
        }
    }
    cout << mx << "\n";
}

int main (){
    #ifdef DEBUG
        //freopen("out","w", stdout);
        freopen("in","r", stdin);
    #endif
    int n;
    while (cin>>n){solve(n);}
    return 0;
}
