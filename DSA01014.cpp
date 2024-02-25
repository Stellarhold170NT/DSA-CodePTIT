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
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n, k, s;
int res = 0;
int x[100] = { 0 };
int sum = 0;

void Try(int i) {
	for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
		x[i] = j;
		sum += j;
		if (i == k) {
			if (sum == s) res++;
		}
		else Try(i + 1);
		sum -= j;
	}
}

int main() {

	while (true) {
		cin >> n >> k >> s;
		if (n == k && k == s && n == 0) return 0;
		sum = 0;
		res = 0;
		memset(x, 0, sizeof x);
		Try(1);
		cout << res << endl;
	}
}