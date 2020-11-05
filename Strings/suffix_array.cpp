/// suffix_array ==> my code
void init_suffix_array(vector<int> &p, vector<int> &group, string &s) {
    int n = s.size();
    p.resize(n, 0);
    group.resize(n, 0);
    vector<int> co(256, 0);
    for (int i = 0; i < n; i++)
        co[s[i]]++;
    for (int i = 1; i < 256; i++)
        co[i] += co[i - 1];
    for (int i = 0; i < n; i++)
        p[--co[s[i]]] = i;
    group[p[0]] = 0;
    for (int i = 1; i < n; i++)
        group[p[i]] = group[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
}
 
bool update(vector<int> &p, vector<int> &group, int h, string &s) {
    int n = s.size();
    vector<int> np(n, 0), ngroup(n, 0), co(n, 0);
 
    for (int i = 0; i < n; i++) {
        np[i] = (p[i] - h + n) % n;
        co[group[np[i]]]++;
    }
    for (int i = 1; i < n; i++)
        co[i] += co[i - 1];
 
    for (int i = n - 1; i >= 0; i--)
        p[--co[group[np[i]]]] = np[i];
    ngroup[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        pair<int, int> cur = {group[p[i]], group[(p[i] + h) % n]};
        pair<int, int> prev = {group[p[i - 1]], group[(p[i - 1] + h) % n]};
        if (cur != prev)
            ++classes;
        ngroup[p[i]] = classes - 1;
    }
    group.swap(ngroup);
 
    return group[n - 1] != n - 1;
 
}
 
vector<int> suffix(string &s) {
    s += '$';
    vector<int> p, group;
    init_suffix_array(p, group, s);
    for (int h = 1; h < s.size() && update(p, group, h, s); h *= 2);
    return p;
}

/// LCP on Suffix Array
vector<int> LCP(vector<int> &p, string &s) {
    int n = p.size();
    vector<int> notp(n), lcp(n - 1, 0);
    for (int i = 0; i < n; i++)
        notp[p[i]] = i;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (notp[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[notp[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k])
            k++;
        lcp[notp[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}
 

// LCP in different strings in o(n^2) without suffix_array
// LCP between a.substr from i -> a.size()-1 and b.substr from j to b.size()-1
vector<vector<int>> LCP(string &a, string &b) {

    vector<vector<int>> lcpAB(a.size(), vector<int>(b.size(), 0));
    for (int i = a.size() - 1; i >= 0; i--) {
        for (int j = b.size() - 1; j >= 0; j--) {
            lcpAB[i][j] = (a[i] == b[j]) ? 1 + lcpAB[i + 1][j + 1] : 0;
        }
    }
    return lcpAB;
}
