// Source: https://cp-algorithms.com/string/z-function.html#:~:text=The%20Z%2Dfunction%20for%20this,Note.
//String compression:
//A solution is: compute the Z-function of s, loop through all i such that i divides n. Stop at the first i such that i+z[i]=n. Then, the string s can be compressed to the length i.

vector<int> z_function(string s) {
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
