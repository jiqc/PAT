#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct person {
	int id;
	int vg;
	int tg;
	int label;
};

bool campare(const person &A, const person &B) {
	if (A.label != B.label) {
		return A.label < B.label;
	}
	else {
		if (A.tg + A.vg != B.tg + B.vg) {
			return A.tg + A.vg > B.tg + B.vg;
		}
		else {
			if (A.vg != B.vg) {
				return A.vg > B.vg;
			}
			else {
				return A.id < B.id;
			}
		}
	}
}

int main() {
	int N, L, H;
	vector<person> people;

	scanf_s("%d %d %d", &N, &L, &H);
	person temp;
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d %d", &temp.id, &temp.vg, &temp.tg);
		if (temp.vg >= L && temp.tg >= L) {
			if (temp.vg >= H && temp.tg >= H) {
				temp.label = 1;
			}
			else {
				if (temp.vg >= H) {
					temp.label = 2;
				}
				else {
					if (temp.vg < H && temp.tg < H && temp.vg >= temp.tg) {
						temp.label = 3;
					}
					else {
						temp.label = 4;
					}
				}
			}
			people.push_back(temp);
		}
	}

	sort(people.begin(), people.end(), campare);

	printf("%d\n", people.size());
	for (unsigned int i = 0; i < people.size(); i++) {
		printf("%08d %d %d\n", people[i].id, people[i].vg, people[i].tg);
	}

	system("pause");
	return 0;
}