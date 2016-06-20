#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct student {
	string name;
	string id;
	int grade;
};

bool camp(const student &A, const student &B) {
	return A.grade > B.grade;
}

int main() {
	int N;
	char str[12];
	vector<student> group;
	int g_up, g_down;

	scanf_s("%d",&N);
	group.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%s", str, 12);
		group[i].name = str;
		scanf_s("%s", str, 12);
		group[i].id = str;
		scanf_s("%d", &group[i].grade);
	}
	scanf_s("%d %d", &g_down, &g_up);

	sort(group.begin(), group.end(), camp);

	bool find = false;
	for (int i = 0; i < (int)group.size(); i++) {
		if (group[i].grade >= g_down && group[i].grade <= g_up) {
			printf("%s %s\n", group[i].name.c_str(), group[i].id.c_str());
			find = true;
		}
	}

	if (!find) {
		printf("NONE\n");
	}

	system("pause");
	return 0;
}