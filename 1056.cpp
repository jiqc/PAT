#include<cstdio>
#include<vector>
using namespace std;

struct programmer {
	int weight;
	int rank;
};

int main() {
	int NP, NG;

	vector<programmer> all;

	scanf_s("%d %d", &NP, &NG);
	all.resize(NP);
	for (int i = 0; i < NP; i++) {
		scanf_s("%d", &all[i].weight);
	}

	vector<vector<int> > winner;
	vector<int> temp;
	int num;
	for (int i = 0; i < NP; i++) {
		scanf_s("%d", &num);
		temp.push_back(num);
	}
	winner.push_back(temp);

	
	int k = 0;
	while (winner[k].size()>1) {		
	    temp.clear();
	    for (int i = 0; i < winner[k].size(); i = i + NG) {
		    int max = -1;
		    int j = i;
		    int tn;
		    while (j < winner[k].size() && j < i + NG) {
			    if (all[winner[k][j]].weight>max) {
				    tn = winner[k][j];
					max = all[winner[k][j]].weight;
			    }
			    j++;
		    }
			temp.push_back(tn);
	    }
		winner.push_back(temp);
		k++;
	}

	int rank = 1;
	for (; k >= 0; k--) {		
		for (unsigned int i = 0; i < winner[k].size(); i++) {
			if (all[winner[k][i]].rank == 0) {
				all[winner[k][i]].rank = rank;
			}
		}
		rank = winner[k].size() + 1;
	}

	printf("%d", all[0].rank);
	for (int i = 1; i < NP; i++) {
		printf(" %d", all[i].rank);
	}
	printf("\n");

	system("pause");
	return 0;	
}