pair<int,int> crt(vector<pair<int,int> > Mds) {
  int A = Mds[0].first, B = Mds[0].second;
  for (int i = 1; i < sz; i++) {
    int cA = Mds[i].first,cB = Mds[i].second;
    int p, q;
    int g = gcd(cB, B, q, p);
    int l = B / g * cB;
    if (cA % g != A % g) return -1; // failed
    if (g == cB) continue;
    p %= l, q %= l;
    long long X = (A * (cB / g) * q + cA * (B / g) * p) % l;
    A = X, B = l;
  }
  return {A,B};
}
