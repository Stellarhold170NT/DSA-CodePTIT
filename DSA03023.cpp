#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 200

#define MOD (ll) 1000000007
#define ld long double
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int main() {
	int n;
	string s;

	cin >> n >> s;

	map<char, int> mp;
	int res = 0;

	for (auto x : s) mp[x]++;

	for (int i = 0; i < mp['X']; i++) {
		if (s[i] == 'T') {
			for (int j = mp['X']; j < n; j++) {
				if (s[j] == 'X') {
					swap(s[j], s[i]);
					res++;
					break;
				}
			}
		}
		else if (s[i] == 'D') {
			for (int j = n - 1; j >= mp['X']; j--) {
				if (s[j] == 'X') {
					swap(s[j], s[i]);
					res++;
					break;
				}
			}
		}
	}

	for (int i = mp['X']; i < mp['X'] + mp['T']; i++) if (s[i] == 'D') {
		for (int j = mp['X'] + mp['T']; j < n; j++) {
			if (s[j] == 'T') {
				swap(s[j], s[i]);
				res++;
				break;
			}
		}
	}

	cout << res;

	return 0;
}