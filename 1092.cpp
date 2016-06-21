#include<cstdio>
#include<map>
using namespace std;

int main() {
	char c;
	map<char, int> beads;
	int extra, miss;

	for (int i = 0; i < 10; i++) {
		beads['0' + i] = 0;
	}
	for (int i = 0; i < 26; i++) {
		beads['A' + i] = 0;
	}
	for (int i = 0; i < 26; i++) {
		beads['a' + i] = 0;
	}

	while ((c = getchar()) != '\n') {
		beads[c]++;
	}
	while ((c = getchar()) != '\n') {
		beads[c]--;
	}

	extra = 0;
	miss = 0;
	for (map<char, int>::const_iterator it = beads.begin(); it != beads.end(); it++) {
		if (it->second >= 0) {
			extra += it->second;
		}
		else {
			miss -= it->second;
		}
	}

	if (miss == 0) {
		printf("Yes %d\n", extra);
	}
	else {
		printf("No %d\n", miss);
	}

	system("pause");
	return 0;
}