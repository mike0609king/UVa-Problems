#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ar array
#define ve vector
#define pb push_back

int main (){
    #ifdef DEBUG
        //freopen("out","w", stdout);
        freopen("in","r", stdin);
    #endif
    int n;
    while (cin >> n){
        ve<int> inp(n);
        ve<bool> in(n,false);
        bool jolly = true;
        for (int& i : inp) cin >> i;
        for (int i = 0; i < n-1; ++i){
            int num = abs(inp[i] - inp[i+1]);
            if (num < n) in[num] = true;
        }
        for (int i = 1; i < n; ++i){
            if (!in[i]) jolly = false;
        }
        if (jolly) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
    return 0;
}
