void kmp(vector<int> &fail, string &s, string &pat){
    int idx = 0;
    int n = s.size(), m = fail.size();
    for(int i = 0; i < n; i++){
        while(idx > 0 && s[i] != pat[idx]){
            idx = fail[idx - 1];
        }
        if(s[i] == pat[idx]) idx++;
        if(idx == m){
            cout << i - m + 1 << '\n';
        }
    }
    cout << endl;
}
 
vector<int> build_fail(string &s){
    int n = s.size();
    vector<int> fail(n, 0);
    int idx = 0;
    for(int i = 1; i < n; i++){
        while(idx > 0 && s[i] != s[idx]){
            idx = fail[idx - 1];
        }
        if(s[i] == s[idx]) idx++;
        fail[i] = idx;
    }
    return fail;
}
 
