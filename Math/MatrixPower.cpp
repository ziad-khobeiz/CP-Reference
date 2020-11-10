struct matrix {
    ll sz;
    vector<vector<int>> arr;
    matrix(int s) {
        sz = s;
        arr.resize(sz, vector<int>(sz, 0));
    }
    
    matrix operator*(matrix x) {
        matrix ans(sz);
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                for (int k = 0; k < sz; k++)
                    ans.arr[i][k] = add(ans.arr[i][k], mul(arr[i][j], x.arr[j][k]));
        return ans;
    }
    
    void print() {
        cout << "------------------------\n";
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
        cout << "------------------------\n";
    }
};

matrix matrix_I(ll s) {
    matrix ans(s);
    for (int i = 0; i < s; i++)
        ans.arr[i][i] = 1;
    return ans;
}

matrix fastpow(matrix b, ll p) {
    if (p == 0)
        return matrix_I(b.sz);
    matrix ans = fastpow(b, p / 2);
    ans = ans * ans;
    if (p % 2)ans = ans * b;
    return ans;
}
