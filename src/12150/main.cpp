#include<bits/stdc++.h>

using namespace std;

#define ve vector

bool solve(){
    int n; cin >> n;
    if (n == 0) return false;
    
    ve<int>sol(n+1,-1); 
    bool isPossible = true;
    for (int i = 1; i <= n; ++i){
        int id_car,p,starting_pos; cin >> id_car >> p;
        if (!isPossible) continue;
        starting_pos = i + p;
        if (starting_pos <= 0 || starting_pos > n || sol[starting_pos] != -1) isPossible = false;
        else sol[starting_pos] = id_car;
    }
    if (isPossible){
        for (int i = 1; i <=n; ++i) {
            if (i != 1) cout << " ";
            cout << sol[i];
        }
        cout << "\n";
    }
    else cout << -1 << "\n";
    return true;
}

int main (){
    #ifdef DEBUG
        freopen("out","w", stdout);
        freopen("in","r", stdin);
    #endif
    while (solve()){}
    return 0;
}
