// Manacher's Algorithm ==>  cp_Algorithm
int manacher_algo(string &s) {
    int ans = 0;
    int n = s.size();
    vector<int> d1(n, 0);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        d1[i] = (i <= r) ? (min(d1[r - i + l], r - i + 1)) : 1;
        while (i + d1[i] < n && i - d1[i] >= 0 && s[i + d1[i]] == s[i - d1[i]])
            d1[i]++;
        ans = max(ans, 2 * d1[i] - 1);
        if (i + d1[i] - 1 > r) {
            r = i + d1[i] - 1;
            l = i - d1[i] + 1;
        }
    }
    vector<int> d0(n, 0);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        d0[i] = (i <= r) ? (min(d0[r - i + l + 1], r - i + 1)) : 0;
        while (i + d0[i] < n && i - d0[i] - 1 >= 0 && s[i + d0[i]] == s[i - d0[i] - 1])
            d0[i]++;
        ans = max(ans, 2 * d0[i]);
        if (i + d0[i] - 1 > r) {
            r = i + d0[i] - 1;
            l = i - d0[i];
        }
    }
    return ans; 
}
