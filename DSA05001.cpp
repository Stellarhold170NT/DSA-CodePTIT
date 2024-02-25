#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	string a;
	string b;

	getline(cin, a);
	getline(cin, b);

	int n = a.length();
	int m = b.length();

	int** f = new int* [n + 1];
	for (int i = 0; i < n + 1; i++) {
		f[i] = new int[m + 1] { 0 };
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1]) {
				f[i][j] = f[i - 1][j - 1] + 1;
			}
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		}
	}

	cout << f[n][m] << endl;

	string subStr = "";



	//	for (int i = 1; i <= n; i++) {
	//		for (int j = 1; j <= m; j++) {
	//			cout << f[i][j] << " ";
	//		}
	//		cout << endl;
	//	}
	//	
	//	int i = n;
	//	int j = m;
	//	
	//	while (f[i][j] != 0) {
	//		if (a[i - 1] == b[j - 1]) {
	//			subStr = a[i - 1] + subStr;
	//			i--;
	//			j--;
	//		}
	//		else {
	//			if (f[i - 1][j] >= f[i][j - 1]) {
	//				i--;
	//			}
	//			else j--;
	//		}
	//	}
	//	
	//	cout << subStr << endl;
	return 0;
}