#include<iostream>
#include<string>
using namespace std;

int main() {
	string name_male, name_female;
	string ID_male, ID_female;
	int grade_male, grade_female;

	grade_male = 101;
	grade_female = -1;

	string tempname;
	char gander;
	string tempID;
	int tempgrade;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tempname >> gander >> tempID >> tempgrade;
		if (gander == 'M') {
			if (tempgrade < grade_male) {
				name_male = tempname;
				ID_male = tempID;
				grade_male = tempgrade;
			}
		}
		else {
			if (tempgrade > grade_female) {
				name_female = tempname;
				ID_female = tempID;
				grade_female = tempgrade;
			}
		}
	}

	if (grade_female == -1) {
		cout << "Absent" << endl;
	}
	else {
		cout << name_female << ' ' << ID_female << endl;
	}
	if (grade_male == 101) {
		cout << "Absent" << endl;
	}
	else {
		cout << name_male << ' ' << ID_male << endl;
	}
	if (grade_female != -1 && grade_male != 101) {
		cout << grade_female - grade_male << endl;
	}
	else {
		cout << "NA" << endl;
	}

	system("pause");
	return 0;
}