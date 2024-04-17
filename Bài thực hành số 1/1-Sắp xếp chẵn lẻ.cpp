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
	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> chan;
	vector<int> le;
	int dd[1001] = { 0 };

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] % 2) le.push_back(v[i]);
		else chan.push_back(v[i]);
		dd[i] = v[i] % 2 == 1;
	}

	sort(chan.begin(), chan.end());
	sort(le.begin(), le.end(), greater<int>());

	int c = 0;
	int l = 0;

	for (int i = 0; i < n; i++) {
		if (dd[i]) {
			cout << le[l++] << " ";
		}
		else cout << chan[c++] << " ";
	}
	cout << endl;
	return 0;
}