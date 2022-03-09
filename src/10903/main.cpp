#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ar array
#define ve vector

// 0: draw; 1: s1 wins; 2: s2 wins
int wins(string s1, string s2){
    if  (s1 == s2) return 0;
    else if((s1 == "rock" && s2 == "scissors")
            || (s1 == "scissors" && s2 == "paper")
            || (s1 == "paper" && s2 == "rock")){
        return 1;
    }
    else return 2;
}

void solve(int n){
    int k;
    cin >> k;
    ve<ar<int,2>> v = ve<ar<int,2>>(n,{0,0});
    for (int i = 0; i < k*n*(n-1)/2; ++i){
        int p1,p2; string s1,s2; cin >> p1 >> s1 >> p2 >> s2; --p1,--p2;
        int w = wins(s1,s2);
        if (w == 1) {
            v[p1][0]++;
            v[p2][1]++;
        }
        else if (w == 2){
            v[p1][1]++;
            v[p2][0]++;
        }
    }
    for (int i = 0; i < n; ++i){
        int div = v[i][0]+v[i][1];
        if (div == 0) printf("-\n");
        else printf("%.3f\n",(double)v[i][0]/div);
    }
}

int main (){
    int cnt = 0;
    while(true){
        int n; cin >> n;
        if (n == 0) break;
        if (cnt != 0) printf("\n");
        solve(n);
        cnt++;
    }
    return 0;
}
