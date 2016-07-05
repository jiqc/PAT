//when you process the problem wiz memory and data list, you should first take the 
// useful datas out, and then handle them
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node {
	int location;
	int value;
	int next;
};

node memo[100000];

bool less_than_value(const node &A, const node &B) {
	return A.value < B.value;
}

int main() {
	int N;
	int start;
	bool find = false;

	vector<node> numlist;

	scanf_s("%d %d", &N, &start);

	int addr;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &addr);
		if (addr == start) {
			find = true;
		}
		memo[addr].location = addr;
		scanf_s("%d %d", &memo[addr].value, &memo[addr].next);
	}

	if (!find) {
		printf("0 -1\n");
	}
	else {
		addr = start;
		while (addr != -1) {
			numlist.push_back(memo[addr]);
			addr = memo[addr].next;
		}
		
		int L = numlist.size();

	    sort(numlist.begin(), numlist.end(), less_than_value);

	    start = numlist[0].location;
	    for (int i = 0; i < L-1; i++) {
		    numlist[i].next = numlist[i + 1].location;
	    }
	    numlist[L - 1].next = -1;

	    printf("%d %05d\n", L, start);
	    for (int i = 0; i < L - 1; i++) {
		    printf("%05d %d %05d\n", numlist[i].location, numlist[i].value, numlist[i].next);
	    }
	    printf("%05d %d -1\n", numlist[L - 1].location, numlist[L - 1].value);
	}

	system("pause");
	return 0;
}