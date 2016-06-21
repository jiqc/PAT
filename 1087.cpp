#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

#define DMAX 0x7fffffff

int N, K;
vector<bool> visited;
vector<int> shortest;
vector<int> prepath;
vector<int> maxpath;
vector<int> pathnode;
vector<vector<int> > road;
vector<int> happiness;
vector<int> allhappy;
map<string, int> city;

void initialization() {
	string cityname,cityname2;
	int happy, cost;

	cin >> N >> K >> cityname;
	city[cityname] = 0;

	happiness.resize(N);
	allhappy.resize(N);
	maxpath.resize(N);
	pathnode.resize(N);
	prepath.resize(N);
	shortest.resize(N);
	visited.resize(N);
	road.resize(N);
	for (int i = 0; i < N; i++) {
		road[i].resize(N, DMAX);
		road[i][i] = 0;
	}

	for (int i = 1; i < N; i++) {
		cin >> cityname >> happy;
		city[cityname] = i;
		happiness[i] = happy;
	}

	int a, b;
	for (int i = 0; i < K; i++) {
		cin >> cityname >> cityname2 >> cost;
		a = city[cityname];
		b = city[cityname2];
		road[a][b] = road[b][a] = cost;
	}

}

void dijkstra(int d) {
	int max, v;

	for (int i = 0; i < N; i++) {
		shortest[i] = road[0][i];
	}
	//visited[0] = true;
	maxpath[0] = 1;
	pathnode[0] = 0;

	for (int i = 0; i < N; i++) {
		max = DMAX;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && shortest[j] < max) {
				max = shortest[j];
				v = j;
			}
		}
		if (v == d) {
			break;
		}
		visited[v] = true;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && road[j][v] < DMAX) {
				if (max + road[j][v] < shortest[j]) {
					shortest[j] = max + road[j][v];
					allhappy[j] = allhappy[v] + happiness[j];
					maxpath[j] = maxpath[v];
					pathnode[j] = pathnode[v] + 1;
					prepath[j] = v;
				}
				else {
					if (max + road[j][v] == shortest[j]) {
						maxpath[j] = maxpath[v] + maxpath[j];
						if (allhappy[v] + happiness[j] > allhappy[j]) {
							allhappy[j] = allhappy[v] + happiness[j];						
							pathnode[j] = pathnode[v] + 1;
							prepath[j] = v;
						}
						else {
							if (allhappy[v] + happiness[j] == allhappy[j]) {
								if (pathnode[j] > pathnode[v] + 1) {
									pathnode[j] = pathnode[v] + 1;
									prepath[j] = v;
								}
							}
						}
					}
				}
			}
		}
	}

}

void printpath(int d) {
	int p;

	if (d) {	
		p = prepath[d];
	    printpath(p);	
		for (map<string, int>::const_iterator it = city.begin(); it != city.end(); it++) {
			if (p == it->second) {
				cout << it->first << "->";
				break;
			}
		}
	}
}

void printway(int d) {
	cout << maxpath[d] <<' '<< shortest[d] << ' ' << allhappy[d] << ' ' << allhappy[d] / pathnode[d] << endl;
	printpath(d);
	cout << "ROM" << endl;
}

int main() {
	int destination;

	initialization();

	destination = city["ROM"];

	dijkstra(destination);

	printway(destination);

	system("pause");
	return 0;
}