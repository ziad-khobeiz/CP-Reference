int main() {
        string s,t;
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
