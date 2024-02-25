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

char c;
char x[100];
int dd[100] = { 0 };
int k;

bool nguyen_am(char x) {
	if (x == 'A' || x == 'E') return true;
	return false;
}

void print() {
	string ans = "";
	for (int i = 1; i <= k; i++) {
		if (nguyen_am(x[i]) && i > 1 && i < k) {
			if (!nguyen_am(x[i - 1]) && !nguyen_am(x[i + 1])) return;
		}
		ans = ans + x[i];
	}
	cout << ans << endl;
}

void Try(int i) {

	for (char ch = 'A'; ch <= c; ch++)
		if (!dd[ch]) {
			x[i] = ch;
			dd[ch] = 1;
			if (i == k) print();
			else Try(i + 1);
			dd[ch] = 0;
		}
}

int main() {
	cin >> c;

	k = c - 'A' + 1;
	Try(1);

	return 0;
}