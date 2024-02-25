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

int heso10(int x, int k) {
	int sum = 0;
	string s = to_string(x);
	for (int i = 0; i < s.length(); i++) {
		sum = sum * k + s[i] - '0';
	}
	return sum;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int k, a, b;
		cin >> k >> a >> b;

		int sum = heso10(a, k) + heso10(b, k);
		string ketqua = "";

		while (sum) {
			ketqua = to_string(sum % k) + ketqua;
			sum /= k;
		}

		cout << ketqua << endl;
	}

	return 0;
}