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


const ll MOD = 1000000000000007;

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

	return c % MOD;
}

struct matrix {
	ll arr[4][4];
	matrix() {
		memset(arr, 0, sizeof arr);
	}

	matrix operator * (const matrix& other) const {
		matrix res;

		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				(res.arr[i][j] += prod(this->arr[i][k], other.arr[k][j])) %= MOD;
			}
		}
		return res;
	}
};

matrix A;
matrix T0;
matrix I;

void init() {
	A.arr[0][0] = A.arr[0][1] = 1;
	A.arr[1][1] = A.arr[1][2] = A.arr[1][3] = 1;
	A.arr[2][1] = 1;
	A.arr[3][2] = 1;

	T0.arr[0][0] = 3;
	T0.arr[1][0] = 3;
	T0.arr[2][0] = 2;
	T0.arr[3][0] = 1;

	I.arr[0][0] = I.arr[1][1] = I.arr[2][2] = I.arr[3][3] = 1;
}

matrix LT(matrix X, ll n) {
	if (n == 0) return I;
	if (n == 1) return X;
	matrix tmp = LT(X, n / 2);
	if (n % 2 == 0) return tmp * tmp;
	else return tmp * tmp * X;
}

void showMatrix(matrix A) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << A.arr[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	init();

	int t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		if (n <= 3) {
			ll sum = 0;
			for (int i = 1; i <= n; i++) {
				sum = sum + i;
			}
			cout << sum << endl;
		}
		else {
			matrix res = LT(A, n - 2);
			res = res * T0;

			cout << res.arr[0][0] % MOD << endl;
		}
	}

	return 0;
}