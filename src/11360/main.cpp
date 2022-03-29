#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ar array
#define ve vector
#define pb push_back

void solve(){
    int n,m; cin >> n;
    int cnt = 0;
    ve<string> mat(n);
    for (string& s : mat) cin >> s;
    cin >> m;
    for (int q = 0; q < m; ++q){
        string s; cin >> s;
        if (s == "row"){
            int a, b; cin >> a >> b; --a,--b;
            mat[a].swap(mat[b]);
        }
        else if (s == "col"){
            int a, b; cin >> a >> b; --a,--b;
            for (int i = 0; i < n; ++i) swap(mat[i][a],mat[i][b]);
        }
        else if (s == "inc") cnt++;
        else if (s == "dec") cnt--;
        else if (s == "transpose"){ 
            for (int i = 0; i < n; ++i){
                for (int j = i+1; j < n; ++j){
                    swap(mat[i][j],mat[j][i]);
                }
            }
        }
    }
    // sol
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            int toPrint = mat[i][j]+cnt-'0';
            while (toPrint < 0) toPrint += 10;
            cout << toPrint%10;
        }
        cout << "\n";
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
        cout << "Case #" << t << "\n";
        solve();
    }
    return 0;
}
