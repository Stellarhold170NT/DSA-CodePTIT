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
int arr[N];
int sum = 0;

bool check;

void Try(int i, int t) {
	if (check) return;
	if (t > sum) return;
	if (t == sum) {
		check = true;
		return;
	}
	for (int j = i; j <= n; j++) Try(j + 1, t + arr[j]);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		sum = 0;
		check = false;

		for (int i = 1; i <= n; i++)
			cin >> arr[i], sum += arr[i];

		if (sum % 2 == 0) {
			sum /= 2;

			Try(1, 0);

			if (check) cout << "YES\n";
			else cout << "NO\n";
		}
		else cout << "NO\n";
	}

	return 0;
}