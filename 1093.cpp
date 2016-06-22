#include<cstdio>
#include<vector>
#include<string>
using namespace std;
/* out the time range
int main() {
	char str[100005];
	int count;

	scanf_s("%s", str, 100005);
	count = 0;
	for (int i = 0; i < 100005; i++) {
		if (str[i] != '\0') {
			if (str[i] == 'P') {
				for (int j = i + 1; j < 100005; j++) {
					if (str[j] != '\0') {
						if (str[j] == 'A') {
							for (int k = j + 1; k < 100005; k++) {
								if (str[k] != '\0') {
									if (str[k] == 'T') {
										count++;
										if (count == 1000000007) {
											count = 0;
										}
									}
								}
								else {
									break;
								}
							}
						}
					}
					else {
						break;
					}
				}
			}
		}
		else {
			break;
		}
	}
	printf("%d\n", count);

	system("pause");
	return 0;
}
*/
int main() {
	char c;
	int n_P;
	int n_PA;
	int n_PAT;

	n_P = 0;
	n_PA = 0;
	n_PAT = 0;
	
	while ((c = getchar()) != '\n') {
		switch (c) {
		case'P':
			n_P++;			
			break;
		case'A':
			n_PA += n_P;
			if (n_PA >= 1000000007) {
				n_PA %= 1000000007;
			}
			break;
		case'T':
			n_PAT += n_PA;
			if (n_PAT >= 1000000007) {
				n_PAT %= 1000000007;
			}
			break;
		}
	}

	printf("%d\n", n_PAT);

	system("pause");
	return 0;
}