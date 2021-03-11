bool is_prime[N];
int mu[N];

void build_mobius() {
    /*
      mu ==  0  ?  fih prime mtkrr
      mu ==  1  ?  # distinct primes even
      mu == -1  ?  # distinct primes odd
      */
    memset(is_prime, true, sizeof is_prime);
    fill(mu, mu + N, 1);
    for (int i = 2; i < N; i++) {
        if (is_prime[i] == 0) continue;
        for (int j = i; j < N; j += i) {
            mu[j] = -mu[j];
            is_prime[j] = 0;
            if ((j / i) % i == 0) mu[j] = 0;
        }
    }
}
 
