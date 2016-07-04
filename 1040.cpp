#include<cstdio>
#include<string>
using namespace std;

int main() {
	char str[1001];	
	int pre, post;
	int syme = 0;
	int symo = 1;
	int sym;

	int num = 0;
	str[0] = getchar();	
	while (str[num] != '\n') {
		num++;
		str[num] = getchar();
	}

	int tempsym;
	for (int i = 0; i < num; i++) {
		pre = i-1;
		post = i+1;
		tempsym = 1;
		while (pre >= 0 && post < num) {
			if (str[pre] == str[post]) {
				tempsym += 2;
			}
			else {
				break;
			}
			pre--;
			post++;
		}
		if (tempsym > symo) {
			symo = tempsym;
		}
		if (post == num - 1) {
			break;
		}
	}

	tempsym = 0;
	for (int i = 0; i < num; i++) {
		if (str[i] == str[i + 1]) {
			pre = i - 1;
		    post = i + 2;
		    tempsym = 2;
		    while (pre >= 0 && post < num) {
			    if (str[pre] == str[post]) {
				    tempsym += 2;
			    }
			    else {
				    break;
			    }
			    pre--;
			    post++;
		    }
		    if (tempsym > syme) {
			    syme = tempsym;
		    }
		    if (post == num - 1) {
			    break;
		    }
		}		
	}

	if (syme > symo) {
		sym = syme;
	}
	else {
		sym = symo;
	}

	printf("%d\n", sym);

	system("pause");
	return 0;
}