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
//#define N 50000

//#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)


const int MOD = 1000000007;
ll n, k;

ll prod(ll a, ll b) {
	ll c = 0;

	while (b) {
		if (b & 1) {
			c = c + a;
			if (c >= MOD) c -= MOD;
		}
		a = a + a;
		if (a >= MOD) a -= MOD;
		b = b >> 1;
	}

	return c;
}

struct matrix {
	ll arr[10][10];
	matrix() {
		memset(arr, 0, sizeof arr);
	}

	matrix operator * (const matrix& other) const {
		matrix res;

		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				(res.arr[i][j] += prod(this->arr[i][k], other.arr[k][j])) %= MOD;
			}
		}
		return res;
	}
};

matrix I;

void init() {
	I.arr[0][0] = I.arr[1][1] = I.arr[2][2] = I.arr[3][3] = 1;
	I.arr[4][4] = I.arr[5][5] = I.arr[6][6] = I.arr[7][7] = 1;
	I.arr[8][8] = I.arr[9][9] = 1;
}

matrix LT(matrix X, ll n) {
	if (n == 0) return I;
	if (n == 1) return X;
	matrix tmp = LT(X, n / 2);
	if (n % 2 == 0) return tmp * tmp;
	else return tmp * tmp * X;
}

void showMatrix(matrix A) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		(sum += A.arr[i][n - 1]) %= MOD;
	}
	cout << sum << endl;
}
int main() {
	init();

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> k;

		matrix X;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> X.arr[i][j];
			}
		}

		matrix ANS = LT(X, k);
		showMatrix(ANS);
	}

	return 0;
}