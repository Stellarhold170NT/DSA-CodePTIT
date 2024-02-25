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

// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 200

#define MOD (int) 1000000007
#define ld long double
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		priority_queue<int, vector<int>, greater<int>> p;

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			p.push(x);
		}

		int sum = 0;

		while (p.size() > 1) {
			int tmp = p.top();
			p.pop();
			tmp += p.top();
			p.pop();

			if (tmp >= MOD) tmp -= MOD;

			sum = (sum + tmp);
			if (sum >= MOD) sum -= MOD;
			p.push(tmp);
		}

		cout << sum << endl;
	}

	return 0;
}