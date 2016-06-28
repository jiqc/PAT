#include <iostream>
#include <vector>
using namespace std;

#define INT_MAX 0x7fffffff

vector<vector<int> > roads;
vector<bool> visited;
vector<int> bikes;
vector<vector<int> > previsit;
vector<int> shortestpath;

int C_MAX;
vector< vector<int> > ways;

void initialization(int size) {
	visited.resize(size);
	bikes.resize(size);
	roads.resize(size);
	for (int i = 0; i < size; i++) {
		roads[i].resize(size);
		for (int j = 0; j < size; j++) {
			roads[i][j] = INT_MAX;
		}
		roads[i][i] = 0;
	}
	previsit.resize(size);
	shortestpath.resize(size);
	for (int i = 0; i < size; i++) {
		shortestpath[i] = INT_MAX;
	}
}

void Dijkstra(int num, int outset, int destination) {
	int v;
	int min;
	shortestpath[outset] = 0;
	for (int i = 0; i < num; i++) {
		min = INT_MAX;
		for (int j = 0; j < num; j++) {
			if (visited[j] == 0 && shortestpath[j] < min) {
				v = j;
				min = shortestpath[j];
			}
		}
		if (v == destination) {
			break;
		}
		visited[v] = true;
		for (int k = 0; k < num; k++) {
			if (!visited[k] && roads[v][k]!=INT_MAX) {
				if (shortestpath[k] > (shortestpath[v] + roads[v][k])) {
					previsit[k].clear();
					previsit[k].push_back(v);
					shortestpath[k] = shortestpath[v] + roads[v][k];
				}
				else {
					if (shortestpath[k] == (shortestpath[v] + roads[v][k])) {
						previsit[k].push_back(v);
					}
				}
			}
		}		
	}
}

void Find_ways(int index, vector<int> part) {
	part.push_back(index);
	for (unsigned int i = 0; i < previsit[index].size(); i++) {
		if (previsit[index][i]==0) {
			ways.push_back(part);
		}
		else {
			Find_ways(previsit[index][i], part);
		}
	}
}

int main() {
	int  N, SP, M;

	cin >> C_MAX >> N >> SP >> M;
	N++;
	initialization(N);
	for (int i = 1; i < N; i++) {
		cin >> bikes[i];
	}
	int r, c, t;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> t;
		roads[r][c] = roads[c][r] = t;
	}

	Dijkstra(N, 0, SP);

	vector<int> temp;
	Find_ways(SP, temp);

	
	vector<pair<int, int>> result;
	result.resize(ways.size());
	for (unsigned int i = 0; i < ways.size(); i++) {
		for (unsigned int j = ways[i].size(); j >0 ; j--) {//attention in unsigned number it is positive when 0-1 
			result[i].second = result[i].second + bikes[ways[i][j-1]] - C_MAX / 2;
			if (result[i].second < 0) {
				result[i].first -= result[i].second;//for example, 2 8, send=3,back=3,not send=back=0
				result[i].second = 0;
			}
		}		
	}
    
	int find = 0;
	for (unsigned int i = 1; i < ways.size(); i++) {
		if (result[find].first > result[i].first) {//miner send then miner back
			find = i;
		}
		else {
			if (result[find].first == result[i].first) {
				if (result[find].second > result[i].second) {
					find = i;
				}
			}
		}
	}

	cout << result[find].first << " 0" ;
	for (unsigned int i = ways[find].size(); i > 0 ;i--) {
		cout << "->" << ways[find][i-1];
	}
	cout << ' ' << result[find].second << '\n';

	system("pause");
	return 0;
}