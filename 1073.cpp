#include<cstdio>
#include<vector>
using namespace std;

int main() {
	bool sign;
	bool pos;
	char c;
	int exp;
	vector<char> numchar;

	c = getchar();
	if (c == '+') {
		sign = true;
	}
	else {
		sign = false;
	}

	c = getchar();
	numchar.push_back(c);
	c = getchar();
	while ((c = getchar()) != 'E') {
		numchar.push_back(c);
	}

	c = getchar();
	if (c == '+') {
		pos = true;
	}
	else {
		pos = false;
	}

	scanf_s("%d", &exp);

	int i;
	if (pos) {
		if (!sign) {
			putchar('-');
		}
		putchar(numchar[0]);
		for (i = 0; i < exp; i++) {
			if (i + 1 < (int)numchar.size()) {
				putchar(numchar[i+1]);
			}
			else {
				putchar('0');
			}
		}
		if (i + 1 < (int)numchar.size()) {
			putchar('.');
			for (; i + 1 < (int)numchar.size(); i++) {
				putchar(numchar[i + 1]);
			}
		}
	}
	else {
		if (!sign) {
			putchar('-');
		}
		printf("0.");
		for (i = 0; i < exp-1; i++) {
			putchar('0');
		}
		for (i = 0; i < (int)numchar.size(); i++) {
			putchar(numchar[i]);
		}
	}
	putchar('\n');

	system("pause");
	return 0;
}