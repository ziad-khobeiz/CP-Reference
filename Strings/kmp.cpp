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

// Applications:
// Source: https://cp-algorithms.com/string/prefix-function.html?fbclid=IwAR2TU5gSGYfSoATzakppT3Ovjc_HdvPwXpYAqnx1tuHb5DLtXDqKbVkqQxc#toc-tgt-8 

// Counting the number of occurrences of each prefix

vector<int> ans(n + 1);
for (int i = 0; i < n; i++)
    ans[pi[i]]++;
for (int i = n-1; i > 0; i--)
    ans[pi[i-1]] += ans[i];
for (int i = 0; i <= n; i++)
    ans[i]++;

// Building an Automaton

void compute_automaton(string s, vector<vector<int>>& aut) {
    s += '#';
    int n = s.size();
    vector<int> pi = prefix_function(s);
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    }
}

// Counting the number of distinct substring in a string

/*

Given a string s of length n. We want to compute the number of different substrings appearing in it.
We will solve this problem iteratively. Namely we will learn, knowing the current number of different substrings, how to recompute this count by adding a character to the end.
So let k be the current number of different substrings in s, and we add the character c to the end of s. Obviously some new substrings ending in c will appear. We want to count these new substrings that didn't appear before.
We take the string t=s+c and reverse it. Now the task is transformed into computing how many prefixes there are that don't appear anywhere else. If we compute the maximal value of the prefix function πmax of the reversed string t, then the longest prefix that appears in s is πmax long. Clearly also all prefixes of smaller length appear in it.
Therefore the number of new substrings appearing when we add a new character c is |s|+1−πmax.
So for each character appended we can compute the number of new substrings in O(n) times, which gives a time complexity of O(n2) in total.
It is worth noting, that we can also compute the number of different substrings by appending the characters at the beginning, or by deleting characters from the beginning or the end.

*/
