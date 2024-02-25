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

int dd[N] = { 0 };
int n;
string s;
string tmp = "";
map<string, bool> mp;

void Try(int i) {
	for (int j = 0; j < n; j++) if (!dd[j]) {
		dd[j] = 1;

		tmp = tmp + s[j];

		if (i == n && !mp[tmp]) {
			cout << tmp << " ";
			mp[tmp] = true;
		}
		else Try(i + 1);

		tmp.pop_back();

		dd[j] = 0;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> s;

		n = s.length();

		Try(1);

		cout << endl;
	}

	return 0;
}