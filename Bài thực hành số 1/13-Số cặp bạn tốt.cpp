#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
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

#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int main() {
	int n, k;
	cin >> n >> k;

	vector<string> s(n);
	for (auto& i : s) cin >> i;

	unordered_map<int, int> mp;
	for (int i = 0; i < k; i++) {
		mp[s[i].length()]++;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (i + k < n) mp[s[i + k].length()]++;
		ans += mp[s[i].length()] - 1;
		mp[s[i].length()]--;
	}

	cout << ans << endl;
	return 0;
}