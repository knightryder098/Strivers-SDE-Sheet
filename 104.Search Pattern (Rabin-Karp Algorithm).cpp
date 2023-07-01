#include <bits/stdc++.h>
using namespace std;
const int prime = 31; // a prime number for hash calculation

vector<int> stringMatch(string &str, string &pat) {
    int n = str.length();
    int m = pat.length();

    const unsigned long long mod = 1e9 + 7; // a large prime number for hash calculation

    vector<unsigned long long> power(n); // array to store powers of prime
    power[0] = 1;
    for (int i = 1; i < n; i++) {
        power[i] = (power[i - 1] * prime) % mod;
    }

    // Calculate hash values for the pattern and the first segment of the string
    unsigned long long patHash = 0, strHash = 0;
    for (int i = 0; i < m; i++) {
        patHash = (patHash + (pat[i] - 'a' + 1) * power[m - i - 1]) % mod;
        strHash = (strHash + (str[i] - 'a' + 1) * power[m - i - 1]) % mod;
    }

    vector<int> matches;

    // Compare the hash values and check for matching substrings
    for (int i = 0; i <= n - m; i++) {
        if (patHash == strHash) {
            bool found = true;
            for (int j = 0; j < m; j++) {
                if (str[i + j] != pat[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                matches.push_back(i + 1); // Store the 1-based index where the pattern starts
            }
        }

        // Update the hash value for the next segment of the string
        if (i < n - m) {
            strHash = (prime * (strHash - (str[i] - 'a' + 1) * power[m - 1]) + (str[i + 1] - 'a' + 1) + mod) % mod;
			
		}
    }

    return matches;
}
