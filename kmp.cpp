#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const int N = 1e5 + 5;
const int M = 2000 + 5;
const int OO = 1e9;
const int mod = 1e9 + 7;

int n;
string s,t;

void init() {

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #else
        #endif

    bool firstTime = true;

    while (cin >> n) {

        if(firstTime) firstTime = false;
        else cout << '\n';

        cin >> s >> t;

        t = s + ' ' + t;
        int m = n + 1 + int(t.size());
        vector<int> pi(m);
        pi[0] = 0;

        for (int i = 1; i < m; ++i) {
            int & j = pi[i];
            j = pi[i - 1];
            while(j > 0 && t[i] != t[j]) {
                j = pi[j - 1];
            }
            if(t[i] == t[j]) ++j;
            if(j == n) cout << i - 2 * n << '\n';
        }

    }

    return 0;
}
