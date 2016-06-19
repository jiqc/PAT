#include<cstdio>
#include<vector>
#include<set>
using namespace std;

vector<set<int> > sets;

int main() {
	int N, M;

	int setnum;
	int num;
	scanf_s("%d", &N);
	sets.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &setnum);
		for (int j = 0; j < setnum; j++) {
			scanf_s("%d", &num);
			sets[i].insert(num);
		}
	}

	int s1,s2;
	float NC, NT;
	scanf_s("%d", &M);
	for (int i = 0; i < M; i++) {
		NC = NT = 0;
		scanf_s("%d %d", &s1, &s2);
		set<int>::const_iterator it1, it2;
		it1 = sets[s1 - 1].begin();
		it2 = sets[s2 - 1].begin();
		while (it1 != sets[s1 - 1].end() && it2 != sets[s2 - 1].end()) {
			if (*it1 > *it2) {
				it2++;
			}
			else {
				if (*it1 < *it2) {
					it1++;
				}
				else {
					NC++;
					it1++;
					it2++;
				}
			}
		}
		NT = sets[s1 - 1].size() + sets[s2 - 1].size() - NC;
		printf("%.1f%%\n", (NC / NT) *100);
	}

	system("pause");
	return 0;
}