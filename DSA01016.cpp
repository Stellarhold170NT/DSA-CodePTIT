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

#define MOD (ll) 1000000007
#define ld long double
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

vector<int> v;

void Try(int n, int lim) {
	if (n < 0) return;
	if (n == 0) {
		cout << '(';
		for (int i = 0; i < v.size() - 1; i++) cout << v[i] << " ";
		cout << v[v.size() - 1] << ')' << " ";
	}
	for (int j = lim; j >= 1; j--) {
		v.push_back(j);
		Try(n - j, j);
		v.pop_back();
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		Try(n, n);
		cout << endl;
	}

	return 0;
}