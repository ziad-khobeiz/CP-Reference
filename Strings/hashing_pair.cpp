typedef pair<int, int> hashing;
const hashing b = {31, 53};
const hashing mod = {1e9 + 9, 1e9 + 7};
hashing pw[N], h[N];

hashing mul(hashing a, hashing b) {
    return {1LL * a.first * b.first % mod.first, 1LL * a.second * b.second % mod.second};
}

hashing add(hashing a, hashing b) {
    return {(a.first + b.first) % mod.first, (a.second + b.second) % mod.second};
}


hashing hashOf(int x) {
    return {x, x};
}

auto zero = hashOf(0);

int main() {
    pw[0] = {1, 1};
    for (int i = 1; i < N; ++i) {
        pw[i] = mul(pw[i - 1], b);
    }
    for (int i = 0; i < n; ++i) {
        h[i] = add(i ? h[i - 1] : zero, mul(pw[i], hashOf(string[i]-'a'+1)));
    }
    return 0;
}
