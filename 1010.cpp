#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
/*
int input(int num[10]) {
	char numchar;
	int i = 0;
	int max = 0;

	while ((numchar = getchar()) != ' ') {
		if (numchar >= '0' || numchar <= '9') {
			num[i] = numchar - '0';
		}
		else {
			num[i] = numchar + 10 - 'a';
		}
		if (max < num[i]) {
			max = num[i];
		}
		i++;
	}
	if (i < 10) {
		num[i] = -1;
	}
	return max;
}

long long int getvalueinten(int num[10], long long int radix) {
	long long int value = 0;
	int i = 0;

	while (i < 10 && (num[i] != -1) ) {
		value = radix*value + num[i];
		if (value < 0) {
			return -1;
		}
		i++;
	}

	return value;
}

int main() {
	int num[2][10];
	int max[2];
	int choice;
	long long int value_known, value_cur;
	long long int radix_known, radix=0, radix_down=2, radix_up, radix_mid;

	max[0] = input(num[0]);
	max[1] = input(num[1]);
	scanf_s("%d %lld", &choice, &radix_known);
		
	value_known = getvalueinten(num[choice-1], radix_known);
	radix_up = value_known;
	if (choice == 2) {
		choice = 0;
	}
	radix_down = max[choice] + 1;
	value_cur = getvalueinten(num[choice], radix_down);
	if (value_cur == value_known) {
		printf("%lld\n", radix_down);
	}
	else {
		if (value_cur > value_known) {
			printf("Impossible\n");
		}
		else {
			radix_down++;
			while (radix_down <= radix_up) {
				radix_mid = (radix_down + radix_up) / 2;
				value_cur = getvalueinten(num[choice], radix_mid);
				if (value_cur==-1 || value_cur > value_known) {
				    radix_up = radix_mid - 1;
				}			
				else {
					if (value_cur < value_known) {
					    radix_down = radix_mid + 1;
				    }
					else {
						radix = radix_mid;
						break;
					}
				}
			}
			if (radix) {
				printf("%lld\n", radix);
			}
			else {
				printf("Impossible\n");
			}
		}
	}
	
	system("pause");
	return 0;
}*/

long long int getvalueinten(string str, long long int radix) {
	long long int value = 0;
	int i = 0;

	while (str[i]!='\0') {
		if (str[i] >= 'a') {
			value = radix*value + str[i] - 'a' + 10;
		}
		else {
			value = radix*value + str[i] - '0';
		}		
		if (value < 0) {
			return -1;
		}
		i++;
	}

	return value;
}

int main() {
	string stra, strb;
	int tag;
	long long int radix, radix_known, radix_down, radix_up, radix_mid;
	long long int value_known, value_cur;
	int max=0;

	cin >> stra >> strb >> tag >> radix_known;

	string temp;
	if (tag == 1) {
		temp = stra;
		stra = strb;
		strb = temp;
	}

	radix = 0;
	if (stra == strb) {
		if (strb.size() == 1) {
			if (strb[0] >= '0' || strb[0] <= '9') {
				radix = strb[0] - '0'+1;
			}
			else {
				radix = strb[0] + 11 - 'a';
			}
		}else{
			radix = radix_known;
		}
	}
	else {
		value_known = getvalueinten(strb, radix_known);
		for (int i = 0; stra[i] != '\0'; i++) {
			if (stra[i] > max) {
				max = stra[i];
			}
		}
		if (max >= 'a') {
			radix_down = max - 'a' + 11;
		}
		else {
			radix_down = max - '0' + 1;
		}
		radix_up = value_known + 1;
		while (radix_down <= radix_up) {
			radix_mid = (radix_down + radix_up) / 2;
			value_cur = getvalueinten(stra, radix_mid);
			if (value_cur <= 0 || value_cur > value_known) {
				radix_up = radix_mid - 1;
			}
			else {
				if (value_cur < value_known) {
					radix_down = radix_mid + 1;
				}
				else {
					radix = radix_mid;
					break;
				}
			}
		}
	}

	if (radix) {
		printf("%lld\n", radix);
	}
	else {
		printf("Impossible\n");
	}

	system("pause");
	return 0;
}

