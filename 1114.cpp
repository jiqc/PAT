#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

struct person {
	int id;
	vector<int> adj;
	int sets;
	int areas;

	person() :id(-1), sets(0), areas(0) {}
	person(int id) :id(id) ,sets(0),areas(0){}
};

struct family {
	int id;
	int members;
	int sets;
	int areas;
	double avgset;
	double avgarea;
};

int N;
int k;
vector<person> people;
map<int, int> num2pos;
vector<bool> visited;
vector<family> group;

int findpos(int id) {
	if (num2pos.find(id) == num2pos.end()) {
		person temp(id);
		people.push_back(temp);
		visited.push_back(false);
		num2pos[id] = k;
		k++;
	}
	
	return num2pos[id];
}

bool campare(const family &A, const family &B) {
	if (A.avgarea != B.avgarea) {
		return A.avgarea > B.avgarea;
	}
	else {
		return A.id < B.id;
	}
}

void BFS(int pos) {
	queue<int> tqueue;
	family tempfamily;
	int tempid;
	int temppos;
	int tp;

	tqueue.push(pos);
	tempfamily.members = 0;
	tempfamily.sets = 0;
	tempfamily.areas = 0;
	tempfamily.id = people[pos].id;
	while (!tqueue.empty()) {
		temppos = tqueue.front();
		tqueue.pop();
		if (visited[temppos]) {
			continue;
		}
		if (people[temppos].id < tempfamily.id) {
			tempfamily.id = people[temppos].id;
		}
		visited[temppos] = true;
		tempfamily.members ++;
		tempfamily.sets +=people[temppos].sets;
		tempfamily.areas +=people[temppos].areas;
		for (int i = 0; i < (int)people[temppos].adj.size(); i++) {
			tp = findpos(people[temppos].adj[i]);
			if (!visited[tp]) {
                tqueue.push(tp);
			}			
		}
	}
	group.push_back(tempfamily);
}

int main() {
	int id;
	int id2;
	int num;
	int num2;
	int son;

	k = 0;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &id);
		num = findpos(id);
		scanf_s("%d", &id2);
		if (id2 != -1) {
			num2 = findpos(id2);
			people[num].adj.push_back(id2);
			people[num2].adj.push_back(id);
		}
		scanf_s("%d", &id2);
		if (id2 != -1) {
			num2 = findpos(id2);
			people[num].adj.push_back(id2);
			people[num2].adj.push_back(id);
		}
		scanf_s("%d", &son);
		for (int j = 0; j < son; j++) {
			scanf_s("%d", &id2);
			if (id2 != -1) {
				num2 = findpos(id2);
				people[num].adj.push_back(id2);
				people[num2].adj.push_back(id);
			}
		}
		scanf_s("%d", &people[num].sets);
		scanf_s("%d", &people[num].areas);
	}

	for (int i = 0; i < (int)people.size(); i++) {
		if (!visited[i]) {
			BFS(i);
		}
	}

	printf("%d\n", (int)group.size());
	for (int i = 0; i < (int)group.size(); i++) {
		group[i].avgset = (double)group[i].sets / group[i].members;
		group[i].avgarea = (double)group[i].areas / group[i].members;
	}
	sort(group.begin(), group.end(), campare);
	for (int i = 0; i < (int)group.size(); i++) {
		printf("%04d %d %.3f %.3f\n", group[i].id, group[i].members, group[i].avgset, group[i].avgarea);
	}

	system("pause");
	return 0;
}