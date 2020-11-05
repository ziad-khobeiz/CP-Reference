#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

const int N = 1e5 + 5;
const int M = 2000 + 5;
const int OO = 1e9;
const int mod = 1e9 + 7;

typedef valarray<ll> hashing;

int t, n, k;
hashing MOD = {(ll)1e9 + 7, (ll)1e9 + 9};
hashing B = {(ll)31, (ll)53};
hashing h[N], pw[N];
string s;
set<pair<ll, ll> > hashes;

hashing add(const hashing & a, const hashing & b) {

    return (a + b) % MOD;

}

hashing mul(const hashing & a, const hashing & b) {

    return (a * b) % MOD;

}

void init() {

    hashes.clear();

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #else
        #endif

    pw[0] = {1, 1};

    for (int i = 1; i < N; ++i) {
        pw[i] = mul(pw[i - 1], B);
    }

    cin >> t;

    while (t--) {

        cin >> n >> k >> s;

        init();

        h[0] = {0, 0};

        for (int i = 1; i <= n; ++i) {
            h[i] = add(h[i - 1], mul(hashing(s[i - 1] - 'a' + 1, 2), pw[i - 1]));
        }

        for (int i = 0; i <= n - k; ++i) {

            auto cur = mul(add(h[i + k], MOD - h[i]), pw[n - k - i]);
            hashes.emplace(cur[0], cur[1]);

        }

        cout << hashes.size() << '\n';

    }

    return 0;
}
