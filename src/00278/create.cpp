#include<bits/stdc++.h>

using namespace std;

// Debug Code (Debugging in C++)
void __print(int x){cerr<<x;}
void __print(long x){cerr<<x;}
void __print(long long x){cerr<<x;}
void __print(unsigned x){cerr<<x;}
void __print(unsigned long x){cerr<<x;}
void __print(unsigned long long x){cerr<<x;}
void __print(float x){cerr<<x;}
void __print(double x){cerr<<x;}
void __print(long double x){cerr<<x;}
void __print(char x) {cerr<<'\''<<x<<'\'';}
void __print(const char *x){cerr<<'\"'<< x<<'\"';}
void __print(const string &x){cerr << '\"' << x << '\"';}
void __print(bool x){cerr<<(x ? "true":"false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr<<"\n{"; __print(x.first); cerr<< ','; __print(x.second); cerr<< '}';}
template<typename T>
void __print(T const& x){int f = 0; cerr<<"\n{"; for(auto &i: x) cerr<<(f++ ? "," : ""), __print(i); cerr<<"}";}
void _print(){cerr<<"\n";}
template <typename T, typename... V>
void _print(T const& t, V const&... v){__print(t); if (sizeof...(v)) cerr<< ", "; _print(v...);}

#ifdef DEBUG
#define deb(x...) cerr<<#x<< "="; _print(x)
#define debL(x...) cerr<<__LINE__<<" >> "<<#x<<"=";_print(x)
#else
#define deb(x...)
#endif

using ll=long long;
#define ar array
#define ve vector
#define pb push_back

const int MOD=1e9+7;
const int INF=1e9;
const ll LLINF=1e18;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1}; // grid problems (UP,RIGHT,DOWN,LEFT)

void solve(){
    int cnt = 0;
    for (int i = 4; i <= 10; ++i){
        for (int j = 4; j <= 10; ++j){
            cnt++;
        }
    }
    printf("%d\n",cnt*4);
    for (int i = 4; i <= 10; ++i){
        for (int j = 4; j <= 10; ++j){
            printf("k %d %d\n",i, j);
            printf("K %d %d\n",i, j);
            printf("Q %d %d\n",i, j);
            printf("r %d %d\n",i, j);
        }
    }
}

int main (){
    #ifdef DEBUG
        freopen("in","w", stdout);
        //freopen("in","r", stdin);
    #endif
    int testCases=1;
    for(int t=1;t<=testCases;++t) solve();
    return 0;
}
