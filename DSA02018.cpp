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
#define N 1003

#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int a[10], e, ax[10];
char x[100];
string operation = "+-*";
bool flag = false;

bool check() {
	int sum = a[1];
	for (int i = 1; i <= 4; i++) {
		if (x[i] == '*') {
			sum *= a[i + 1];
		}
		else if (x[i] == '+') {
			sum += a[i + 1];
		}
		else if (x[i] == '-') {
			sum -= a[i + 1];
		}
	}
	return sum == 23;
}

void Try(int i) {
	for (int j = 0; j < 3 && !flag; j++) {
		x[i] = operation[j];
		if (i < 4) Try(i + 1);
		else flag = check();
	}
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		flag = false;
		cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];

		sort(a + 1, a + 6);

		while (next_permutation(a + 1, a + 6) && !flag) {
			Try(1);
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}