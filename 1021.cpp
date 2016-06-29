#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

struct node {
	int height;
	vector<int> adj;
};

int N;
vector<node> graph;
vector<bool> visited;

void DFS(int v){
	int j;
	visited[v] = true;
	for (unsigned int i = 0; i < graph[v].adj.size(); i++) {
		j = graph[v].adj[i];
		if (visited[j] == false) {
			DFS(j);
		}
	}
}

int BFS(int v){
	queue<int> level;

	int height = 0;
	int size;
	level.push(v);
	visited[v] = true;
	size = 1;
	while (!level.empty()) {
		int len = size;
		size = 0;
		for (int i = 0; i < len; i++) {
			graph[level.front()].height = height;
			for (unsigned int j = 0; j < graph[level.front()].adj.size(); j++) {
				if (!visited[graph[level.front()].adj[j]]) {
                    level.push(graph[level.front()].adj[j]);
					visited[graph[level.front()].adj[j]] = true;
				    size++;
				}				
			}
			level.pop();
		}
		height++;
	}

	return --height;
}

int main() {

	cin >> N;
	graph.resize(N);
	visited.resize(N);

	int n1, n2;
	for (int i = 0; i < N-1; i++) {
		cin >> n1 >> n2;
 		graph[n1-1].adj.push_back(n2-1);
		graph[n2-1].adj.push_back(n1-1);
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			DFS(i);
			count++;
		}
	}

	if (count > 1) {
		printf("Error: %d components\n", count);
		system("pause");
		return 0;
	}

	set<int> res;
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	int max;
	int index;
	max = BFS(0);	
	for (int i = 0; i < N; i++) {
		if (graph[i].height == max) {
			index = i;
			res.insert(i);
		}
	}
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	max = BFS(index);
	for (int i = 0; i < N; i++) {
		if (graph[i].height == max) {
			res.insert(i);//elements in a set are unique, the insertion operation checks whether
			              //each inserted element is equivalent to an element already in the container
		}
	}
	for (set<int>::const_iterator iter = res.begin(); iter != res.end(); iter++) {//
		printf("%d\n", (*iter) + 1);
	}

	system("pause");
	return 0;
}