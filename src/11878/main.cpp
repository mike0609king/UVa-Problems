#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ar array
#define ve vector
#define pb push_back

void solve(){
    string s; int cnt = 0;
    while (cin >> s){
        if (s[(int)s.length()-1] == '?') continue;
        char st[100];
        bool minus = false;
        for (int i = 0; i < (int)s.length(); ++i){
            st[i]=s[i];
            if(st[i] == '-') minus = true;
        }
        st[(int)s.length()] = '\0';

        int a,b,c;
        if (!minus) {
            sscanf(st,"%d+%d=%d",&a,&b,&c);
            if (a+b==c) cnt++;
        }
        else {
            sscanf(st,"%d-%d=%d",&a,&b,&c);
            if (a-b==c) cnt++;
        }
    }
    cout << cnt << "\n";
}

int main (){
    #ifdef DEBUG
        //freopen("out","w", stdout);
        freopen("in","r", stdin);
    #endif
    int testCases=1;
    for(int t=1;t<=testCases;++t) solve();
    return 0;
}
