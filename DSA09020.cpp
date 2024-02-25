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
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long
#define MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 5000000 + 11
#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int main() {
	int n;
	cin >> n;

	int ma_tran_ke[1001][1001];

	memset(ma_tran_ke, 0, sizeof ma_tran_ke);

	cin.ignore();

	FOR(i, 1, n) {
		string s;
		getline(cin, s);

		stringstream ss(s);
		string node;

		while (ss >> node) {
			ma_tran_ke[i][stoi(node)] = 1;
			ma_tran_ke[stoi(node)][i] = 1;
		}

	}

	FOR(i, 1, n) {
		FOR(j, 1, n) {
			cout << ma_tran_ke[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

