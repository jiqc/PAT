#include<cstdio>
#include<vector>
#include<set>
using namespace std;

struct node {
	int id;
	int value;
	int next;
};

node menlist[100000];

int main() {
	vector<node> newlist;
	vector<node> removed;
	set<int> numlist;
	int start;
	int id, num, next;
	int N;

	scanf_s("%d %d", &start, &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &id);
		menlist[id].id = id;
		scanf_s("%d %d", &menlist[id].value, &menlist[id].next);
	}

	while (start != -1) {
		num = menlist[start].value > 0 ? menlist[start].value : -menlist[start].value;
		if (numlist.find(num) == numlist.end()) {
			numlist.insert(num);
			newlist.push_back(menlist[start]);
			start = menlist[start].next;
		}
		else {
			removed.push_back(menlist[start]);
			start = menlist[start].next;
		}
	}

	int i;
	for (i = 0; i < (int)newlist.size(); i++) {
		if (i == 0) {
			printf("%05d %d ", newlist[i].id, newlist[i].value);
		}
		else {
			printf("%05d\n%05d %d ", newlist[i].id, newlist[i].id, newlist[i].value);
		}
	}
	printf("-1\n");
	if (!removed.empty()) {
		for (i = 0; i < (int)removed.size(); i++) {
		    if (i == 0) {
			    printf("%05d %d ", removed[i].id, removed[i].value);
		    }
		    else {
			    printf("%05d\n%05d %d ", removed[i].id, removed[i].id, removed[i].value);
		    }
	    }
	    printf("-1\n");
	}
	

	system("pause");
	return 0;
}