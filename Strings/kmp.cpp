// Prefix function and KMP

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

// Counting the number of occurrences of each prefix

vector<int> ans(n + 1);
for (int i = 0; i < n; i++)
    ans[pi[i]]++;
for (int i = n-1; i > 0; i--)
    ans[pi[i-1]] += ans[i];
for (int i = 0; i <= n; i++)
    ans[i]++;
