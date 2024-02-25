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
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

string turn5to6(string s) {
	for (auto& x : s) {
		if (x == '5') x = '6';
	}
	return s;
}

string turn6to5(string s) {
	for (auto& x : s) {
		if (x == '6') x = '5';
	}
	return s;
}

int main() {
	string a, b;
	cin >> a >> b;


	cout << stoi(turn6to5(a)) + stoi(turn6to5(b)) << " ";
	cout << stoi(turn5to6(a)) + stoi(turn5to6(b)) << endl;

	return 0;
}