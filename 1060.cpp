#include<cstdio>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;

int main() {
	char A[100], B[100];
	char temp[100];
	int epa, epb;
	int N;

	scanf_s("%d", &N);
	
	scanf_s("%s", temp, 100);
	epa = 0;
	bool flag = true;	
	int j = 0;
	int i = 0;
	while (temp[i] != '\0' && temp[i] == '0') {
		i++;
	}
	if (temp[i] == '.') {
		i++;
		while (temp[i] != '\0' && temp[i] == '0') {
			epa--;
			i++;
		}
		if (temp[i] == '\0') {
			epa = 0;
		}
		while (temp[i] != '\0') {
			if (j < N) {
			    A[j] = temp[i];
				j++;
			}
			i++;
		}		
	}
	else {
		while (temp[i] != '\0') {
		    if (temp[i] != '.') {
			    if (j < N) {
				    A[j] = temp[i];
				    j++;
			    }
			    if (flag) {
				    epa++;
			    }
		    }
		    else {
			    flag = false;
		    }
		    i++;
	    }
	}	
	for (; j < N; j++) {
		A[j] = '0';
	}
	A[N] = '\0';

	scanf_s("%s", temp, 100);
	epb = 0;
	flag = true;
	j = 0;
	i = 0;
	while (temp[i] != '\0' && temp[i] == '0') {
		i++;
	}
	if (temp[i] == '.') {
		i++;
		while (temp[i] != '\0' && temp[i] == '0') {
			epb--;
			i++;
		}
		if (temp[i] == '\0') {
			epb = 0;
		}
		while (temp[i] != '\0') {
			if (j < N) {
				B[j] = temp[i];
				j++;
			}
			i++;
		}
	}
	else {
		while (temp[i] != '\0') {
			if (temp[i] != '.') {
				if (j < N) {
					B[j] = temp[i];
					j++;
				}
				if (flag) {
					epb++;
				}
			}
			else {
				flag = false;
			}
			i++;
		}
	}
	for (; j < N; j++) {
		B[j] = '0';
	}
	B[N] = '\0';

	if (strcmp(A, B) == 0 && epa==epb) {
		printf("YES 0.%s*10^%d\n", A, epa);
	}
	else {
		printf("NO 0.%s*10^%d 0.%s*10^%d\n", A, epa, B, epb);
	}

	system("pause");
	return 0;
}