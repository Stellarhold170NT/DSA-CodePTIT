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

/*
	xoa di nhung xau ngoac dung, chi giu lai nhung xau ngoac sai
	truong hop 1: xau ngoac chua chan ngoac dong + chan ngoac mo -> st.size() / 2
	truong hop 2: xau ngoac chua le ngoac dong + le ngoac mo -> st.size() / 2 + 1
				(2 dau ngoac o ngoai cung ben phai va ngoai cung ben trai bi doi)
*/
int main() {
	int t;
	cin >> t;

	cin.ignore();

	while (t--) {
		string s;
		getline(cin, s);

		stack<char> st;

		for (auto x : s) {
			if (x == ')' && st.size() && st.top() == '(') st.pop();
			else st.push(x);
		}

		int cnt_open = 0;
		int cnt_close = 0;
		while (!st.empty()) {
			if (st.top() == ')') cnt_close++;
			else cnt_open++;
			st.pop();
		}

		if (cnt_open % 2 == 0) {
			cout << (cnt_open + cnt_close) / 2;
		}
		else cout << (cnt_open + cnt_close) / 2 + 1;

		cout << endl;
	}

	return 0;
}
