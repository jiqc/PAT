#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string days[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

int main() {
	string str1, str2, str3, str4;
	char D, H, M;
	int d, h, m;

	cin >> str1 >> str2 >> str3 >> str4;

	int i;
	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
		if (str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G') {
			D = str1[i];
			break;
		}
	}
	i++;

	d = D - 'A';

	for (; str1[i] != '\0' && str2[i] != '\0'; i++) {
		if (str1[i] == str2[i]) {
			if ((str1[i] >= '0' && str1[i] <= '9') || (str1[i] >= 'A' && str1[i] <= 'N')) {
				H = str1[i];
			    break;
			}			
		}
	}

	h = H > '9' ? H - 'A' + 10 : H - '0';

	for (i = 0; str3[i] != '\0' && str4[i] != '\0'; i++) {
		if (str3[i] == str4[i]) {
			if ((str3[i] >= 'a' && str4[i] <= 'z') || (str3[i] >= 'A' && str4[i] <= 'Z')) {
				M = i;
				break;
			}
		}
	}

	m = M;

	cout << days[d];
	printf(" %02d:%02d\n", h, m);

	system("pause");
	return 0;
}