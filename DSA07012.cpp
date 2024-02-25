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
#define N 600000

#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int main() {
	int t;
	cin >> t;

	cin.ignore();

	while (t--) {
		string s;
		getline(cin, s);

		stack<string> st;

		string res = "";

		for (int i = 0; i < s.length(); i++) {
			if (isalpha(s[i])) st.push(string(1, s[i]));
			else {
				string a = st.top();
				st.pop();
				string b = st.top();
				st.pop();
				string c = "(" + b + s[i] + a + ")";
				st.push(c);
			}
		}

		cout << st.top() << endl;
	}
	return 0;
}