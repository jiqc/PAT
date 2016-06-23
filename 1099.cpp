#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

vector<vector<int> > table;
vector<int> inorder;
vector<int> levelorder;
vector<int> datas;
map<int, int> p2d;
int N;

void initialization() {
	cin >> N;
	table.resize(N);
	for (int i = 0; i < N; i++) {
		table[i].resize(2);
		cin >> table[i][0] >> table[i][1];
	}
	//inorder.resize(N);
	//levelorder.resize(N);
	datas.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> datas[i];
	}
	sort(datas.begin(), datas.end());
}

void getinorder(int n) {
	if (table[n][0] != -1) {
		getinorder(table[n][0]);
	}
	inorder.push_back(n);
	if (table[n][1] != -1) {
		getinorder(table[n][1]);
	}
}

void getmap() {

	getinorder(0);

	for (int i = 0; i < N; i++) {
		p2d[inorder[i]] = i;
	}
}

void BFS() {
	queue<int> tqueue;
	int temp;

	tqueue.push(0);	
	while (!tqueue.empty()) {
		temp = tqueue.front();
		levelorder.push_back(temp);
		tqueue.pop();
		if (table[temp][0] != -1) {
			tqueue.push(table[temp][0]);
		}
		if (table[temp][1] != -1) {
			tqueue.push(table[temp][1]);
		}
	}
}

void printdata() {
	int m;

	m = p2d[levelorder[0]];
	cout << datas[m];
	for (int i = 1; i < N; i++) {
		m = p2d[levelorder[i]];
		cout <<' '<< datas[m];
	}
	cout << endl;
}

int main() {

	initialization();

	getmap();

	BFS();

	printdata();

	system("pause");
	return 0;
}