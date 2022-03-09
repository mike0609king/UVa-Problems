#include<bits/stdc++.h>

using namespace std;

using ll=long long;
#define ar array
#define ve vector

map<char,int> m; 
ar<char,27> run = {
    '0','A','2','3','4','5','6','7','8','9','T','J','Q','K',
    'A','2','3','4','5','6','7','8','9','T','J','Q','K'
};

// This function returns whether there is a run of <runOf> that starts at 
// the index <start> in the cards array.
bool runFrom(ar<char,5>& cards, int start ,int runOf){
    if (start >= 5) return false;
    int runIdx = m[cards[start]]; int offset = 0;
    set<int> s;
    for (int i = 0; i < runOf; ++i){
        int cardsIdx = (start+i+offset)%5;
        if (i != 0 && cardsIdx == start) return false;
        if (s.find(cards[cardsIdx]) != s.end()){offset++; i--; continue; }
        if (cards[cardsIdx] != run[runIdx + i]) return false;
        s.insert(run[runIdx+i]);
    }
    return true;
}

bool isStraight(ar<char,5>& cards){
    for (int i = 0; i < 5; ++i) if (runFrom(cards,i,5)) return true;
    return false;
}

bool isInvite(ar<char,5>& cards){
    for (int i = 0; i < 5; ++i) if (runFrom(cards,i,4)) return true;
    return false;
}

bool isBed(ar<char,5> cards){
    map<char,int> used;
    bool run3, run2; run3 = run2 = false;
    for (int i = 0; i < 5; ++i) used[cards[i]]++;
    for (int i = 0; i < 5; ++i) {
        int curCardIdx = m[cards[i]];
        int cur = run[curCardIdx];
        if (used[cur] == 0) continue;
        int next = run[curCardIdx+1];
        int afterNext = run[curCardIdx+2];

        if (used[next] > 0 && used[afterNext] > 0) {
            used[cur]--; used[next]--; used[afterNext]--;
            run3 = true; 
        }
    }
    for (int i = 0; i < 5; ++i) {
        int curCardIdx = m[cards[i]];
        int cur = run[curCardIdx];
        if (used[cur] == 0) continue;
        int next = run[curCardIdx+1];

        if (used[next] > 0){
            used[cur]--; used[next]--;
            run2 = true;
        }
    }
    return run2 && run3;
}
bool isMenage(ar<char,5>& cards){
    for (int i = 0; i < 5; ++i) if (runFrom(cards,i,3)) return true;
    return false;
}

bool isDouble(ar<char,5> cards){
    map<char,int> used;
    int cnt = 0;
    for (int i = 0; i < 5; ++i) used[cards[i]]++;
    for (int i = 0; i < 5; ++i) {
        int cur = run[m[cards[i]]];
        if (used[cur] == 0) continue;
        int next = run[m[cards[i]]+1];
        if (used[next] > 0) {
            used[next]--;
            used[cur]--;
            cnt++;
        }
    }
    return cnt == 2;
}

int paymentForCards(ar<char,5> cards){
    sort(cards.begin(),cards.end(),[](char a, char b){
            return m[a] < m[b];
            });
    if (isStraight(cards)) return 100;
    else if (isInvite(cards)) return 10;
    else if (isBed(cards)) return 5;
    else if (isMenage(cards)) return 3;
    else if (isDouble(cards)) return 1;
    return 0;
}

void solve(string s1){
    ve<int> poolOfCards = ve<int>(14,4);

    ar<string,5> cardsComplete = {s1,"","","",""};
    ar<char,5> cards = {s1[0],'x','x', 'x', 'x'};
    poolOfCards[m[s1[0]]]--;
    poolOfCards[m[s1[0]]];
    for (int i = 1; i < 5; ++i){
        string s; cin >> s;
        cardsComplete[i] = s;
        cards[i] = s[0];
        poolOfCards[m[cards[i]]]--;
    }
    
    double currentHand = (double)paymentForCards(cards) - 1; 
    double mxExpectedValue = -1;
    int bestReplacement = -1;
    for (int replace = 0; replace < 5; ++replace){
        double expectedValue = 0; // expectedValue if you replace card <replace>
        for (int i = 1; i <=13; ++i){
            ar<char,5> replaced = cards;
            replaced[replace] = run[i];
            expectedValue += (paymentForCards(replaced) * poolOfCards[m[run[i]]]);
        }
        expectedValue /= 47; // 52-5 = 47 
        expectedValue -= 2; // you will lose that amount if you exchange
        if (mxExpectedValue < expectedValue){ mxExpectedValue = expectedValue;
            bestReplacement = replace;
        }
    }
    if (currentHand < mxExpectedValue && bestReplacement != -1) cout << "Exchange " << cardsComplete[bestReplacement] << "\n";
    else cout << "Stay\n";
}

int main (){
    #ifdef DEBUG
        freopen("out","w", stdout);
        freopen("in","r", stdin);
    #endif

    m['A'] = 1; m['2'] = 2; m['3'] = 3; m['4'] = 4;
    m['5'] = 5; m['6'] = 6; m['7'] = 7; m['8'] = 8;
    m['9'] = 9; m['T'] = 10; m['J'] = 11; m['Q'] = 12; m['K'] = 13;

    while (true){
        string s; cin >> s;
        if (s == "#") break;
        solve(s);
    }
    return 0;
}
