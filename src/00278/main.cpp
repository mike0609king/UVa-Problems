// Works, but not accepted (checked with an accepted solution and didn't work either?)
#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ar array
#define ve vector
#define pb push_back

const int MOD=1e9+7;
const int INF=1e9;
const ll LLINF=1e18;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1}; // grid problems (UP,RIGHT,DOWN,LEFT)

char piece;
int m, n, sol;

void solve(){
    sol = 0;
    cin >> piece >> m >> n;

    if (piece == 'r') sol = min(m,n); // Optimal Sol: Place the pieces on diagonal
    else if (piece == 'k'){
        // Optimal Sol: Knight on white square can only attack black squares
        // -> occupy all white squares or all black squares
        int knightPerRowEven = (n & 1) ? ((n-1)/2)+1 : n/2;
        int knightPerRowOdd = (n & 1) ? ((n-1)/2) : n/2;
        for (int i = 0; i < m; ++i){
            if (i & 1) sol += knightPerRowOdd;
            else sol += knightPerRowEven;
        }
    }
    else if (piece == 'K'){
        // you can only occupy every second row
        int kingPerRow = (n & 1) ? ((n-1)/2)+1 : n/2;
        for (int i = 0; i < m; i += 2) sol += kingPerRow;
    }
    else if (piece == 'Q') sol = min(m,n);
    printf("%d\n", sol);
}

int main (){
    #ifdef DEBUG
        freopen("out","w", stdout);
        freopen("in","r", stdin);
    #endif
    int testCases=1;
    cin >> testCases;
    for(int t=1;t<=testCases;++t) solve();
    return 0;
}
