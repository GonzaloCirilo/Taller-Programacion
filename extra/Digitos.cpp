#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	char c;
	int res = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		int num = c - '0';
		if (num >= 0 && num <= 9) {
			res++;
		}
	}
	cout << res;
	return 0;
}