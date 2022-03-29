#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ar array
#define ve vector
#define pb push_back

bool solve(){
    int n; cin >> n;
    if (n == 0) return false;
    int a=0,b=0; bool nowA = true;
    for (int i = 0; i < 32; ++i){
        if (n&(1<<i)){
            if (nowA) a |= (1<<i);
            else b |= (1<<i);
            nowA = !nowA;
        }
    }
    cout << a << " " << b << "\n";
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
