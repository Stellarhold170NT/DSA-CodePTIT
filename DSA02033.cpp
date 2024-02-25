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
int dd[100] = { 0 };
int x[100] = { 0 };

void print() {
	for (int i = 1; i <= n; i++) {
		cout << x[i];
	}
	cout << endl;
}

void Try(int k) {
	for (int i = 1; i <= n; i++)
		if (!dd[i] && abs(i - x[k - 1]) > 1) {
			dd[i] = 1;
			x[k] = i;
			if (k == n) print();
			else Try(k + 1);
			dd[i] = 0;
		}
}
int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		x[0] = -1;
		Try(1);
		cout << endl;
	}

	return 0;
}