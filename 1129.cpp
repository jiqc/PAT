#include<cstdio>
#include<set>
#include<unordered_map>

using namespace std;

struct query {
	int name;
	int cnt;
	query(int k, int n) {
		name = k;
		cnt = n;
	}
	~query() {};
	bool operator<(const query& A) const{
		if (A.cnt == cnt) {
			return name < A.name;
		}
		else {
			return cnt > A.cnt;
		}
	}
};

int main() {
	int N, K;
	scanf_s("%d %d", &N, &K);
	set<query> querys;
	unordered_map<int, int> count;

	for (int i = 0; i < N; i++) {
		int temp;
		scanf_s("%d", &temp);
		if (i) {
			printf("%d:", temp); 
			int j = 0;
			for (set<query>::iterator it = querys.begin(); it != querys.end()&& j < K;it++){
				printf(" %d", it->name);
				j++;
			}
			printf("\n");
		}
		auto it = querys.find(query(temp, count[temp]));
		if (it != querys.end()) {
			querys.erase(it);
		}
		querys.insert(query(temp, ++count[temp]));
	}
	system("pause");
	return 0;
}
