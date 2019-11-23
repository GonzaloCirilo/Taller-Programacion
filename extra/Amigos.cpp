#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, g, a, b, arrH[31] = {}, arrM[31] = {};
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> g >> a >> b;
		if (g == 1) {
			for (int i = a; i <= b; i++) {
				arrH[i]++;
			}
		}
		else {
			for (int i = a; i <= b; i++) {
				arrM[i]++;
			}
		}
	}

	int res = 0;

	for (int i = 0; i < 30; i++) {
		int mayor = min(arrH[i], arrM[i]);
		if (mayor > res)
			res = mayor;
		// res == max(res,mayor)
	}
	cout << res * 2;
	return 0;
}