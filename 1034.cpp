#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

struct person {
	string name;
	int weight;
	set<int> adj;
	bool visited;
};

struct group {
	string head;
	int member;
	int weight;
};


int N, K;
map<string,int> nametotag;
vector<person> namelist;
vector<group> gangs;
int tag = 0;

int gettag(string name) {
	person temp;
	map<string, int>::const_iterator it = nametotag.find(name);
	if (it == nametotag.end()) {
		temp.name = name;
		temp.visited = false;
		temp.weight = 0;
		namelist.push_back(temp);
		nametotag[name] = tag;
		tag++;
		return tag - 1;
	}
	else {
		return it->second;
	}
}

void bfs(int base) {
	group temp;
	queue<int> namequeue;
	int tindex;

    temp.weight = 0;
	temp.head = namelist[base].name;
	temp.member = 0;	

	namequeue.push(base);	
	namelist[base].visited = true;
	int twt = namelist[base].weight;
	while (!namequeue.empty()) {
		tindex = namequeue.front();
		namequeue.pop();	
		if (twt < namelist[tindex].weight) {
			temp.head = namelist[tindex].name;
			twt = namelist[tindex].weight;
		}
		temp.weight += namelist[tindex].weight;
		temp.member++;
		for (set<int>::const_iterator it = namelist[tindex].adj.begin(); it != namelist[tindex].adj.end(); it++) {
			if (!namelist[*it].visited) {
				namequeue.push(*it);
				namelist[*it].visited = true;
			}
		}
	}
	if (temp.weight>(2*K) && temp.member > 2) {
		gangs.push_back(temp);
	}
}

void findgang() {
	for (unsigned i = 0; i<namelist.size(); i++) {		
		if (!namelist[i].visited) {
			bfs(i);
		}
	}
}

bool less_than_name(group &A, group &B) {
	return A.head < B.head;
}

int main() {

	cin >> N >> K;

	string name1, name2;
	int wt;
	int t1,t2;
	for (int i = 0; i < N; i++) {
		cin >> name1 >> name2 >> wt;
		t1 = gettag(name1);
		t2 = gettag(name2);
		namelist[t1].weight += wt;
		namelist[t1].adj.insert(t2);
		namelist[t2].weight += wt;
		namelist[t2].adj.insert(t1);
	}

	findgang();

	if (gangs.empty()) {
		cout << '0' << endl;
	}
	else {
		sort(gangs.begin(), gangs.end(), less_than_name);
		cout << gangs.size() << endl;
		for (unsigned int i = 0; i < gangs.size(); i++) {
			cout << gangs[i].head << ' ' << gangs[i].member << endl;
		}
	}

	system("pause");
	return 0;
}