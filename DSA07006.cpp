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

string s;
vector<pair<int, int>> v;
vector<string> res;
int f[100001] = { 0 };
int x[100001] = { 0 };
int n = 0;
map<string, bool> isChecked;

void getString() {
	string tmp = "";
	for (int i = 0; i < s.length(); i++) {
		if (x[f[i]]) continue;
		tmp += s[i];
	};
	if (tmp.length() != s.length() && !isChecked[tmp]) {
		res.push_back(tmp);
		isChecked[tmp] = true;
	}
}

void Try(int k) {
	for (int i = 0; i <= 1; i++) {
		x[k] = i;
		if (k == n) {
			getString();
		}
		else
			Try(k + 1);
	}
}

int main() {
	cin >> s;

	stack<int> st;

	memset(f, 0, sizeof f);
	memset(x, 0, sizeof x);

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') st.push(i);
		else if (s[i] == ')') {
			int right = i;
			int left = st.top();
			n++;
			f[left] = n;
			f[right] = n;
			st.pop();
		}
	}

	/*for (int i = 0; i < s.length(); i++) {
		cout << f[i] << " ";
	}
	cout << endl;*/

	Try(1);
	sort(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << "\n";
	}


	return 0;
}