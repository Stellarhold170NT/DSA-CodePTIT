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
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 200

//#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n;
string s;

void find(int id, string& res, int k) {
	if (k == n) return;
	char tmp = s[id];

	for (int i = id + 1; i < s.length(); i++)
		if (tmp < s[i]) tmp = s[i];

	if (tmp != s[id]) k++;

	for (int i = id; i < res.length(); i++) {
		if (s[i] == tmp) {
			swap(s[id], s[i]);
			if (s.compare(res) > 0) res = s;
			find(id + 1, res, k);
			swap(s[id], s[i]);
		}
	}
}
int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		cin >> s;

		string res = s;
		find(0, res, 0);
		cout << res << endl;
	}

	return 0;
}