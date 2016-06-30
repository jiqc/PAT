#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

struct customer {
	int time_arrive;
	int time_serve;
	int timeforwait;
	int timeforplay;	
	bool vip;
	bool played;
};

struct table {
	int time_end;
	int num_serve;
	bool freed;
	bool vip;
};

bool less_then_arrive(const customer &A, const customer &B) {
	return A.time_arrive < B.time_arrive;
}

bool less_then_serve(const customer &A, const customer &B) {
	if (A.played && B.played) {
		return A.time_serve < B.time_serve;
	}
	else {
		if (A.played && !B.played) {
			return true;
		}
		else {
			if (!A.played && B.played) {
				return false;
			}
			else {
				return A.time_arrive < B.time_arrive;
			}
		}
	}
	
}

int main() {
	int N;
	int K, M;
	int h, m, s, l, v;

	scanf_s("%d", &N);
	customer * players = new customer[N];
	for (int i = 0; i < N; i++) {
		scanf_s("%d:%d:%d %d %d", &h, &m, &s, &l, &v);
		players[i].time_arrive = h * 3600 + m * 60 + s;
		if (l > 120) {
			players[i].timeforplay = 7200;
		}
		else {
            players[i].timeforplay = l * 60;
		}		
		if (v) {
			players[i].vip = true;
		}
		else {
			players[i].vip = false;
		}
		players[i].played = false;
	}

	scanf_s("%d %d", &K, &M);
	table * tables = new table[K];
	for (int i = 0; i < K; i++) {
		tables[i].time_end = 28800;
		tables[i].num_serve = 0;
		tables[i].freed = true;
		tables[i].vip = false;
	}
	int num;
	for (int i = 0; i < M; i++) {
		scanf_s("%d", &num);
		tables[num-1].vip = true;
	}

	sort(players, players + N, less_then_arrive);

	queue<int> normal;
	queue<int> vip;
	
	int pindex = 0;
	if (players[pindex].time_arrive < 75600) {
	    int index;
		int cur_time = 28800;
	    while (cur_time < 75600) {
			while (players[pindex].time_arrive <= cur_time) {
				if (pindex == N) {
					break;
				}
				if (players[pindex].vip) {
					vip.push(pindex);
				}
				else {
					normal.push(pindex);
				}
				pindex++;

			}
			if (normal.empty() && vip.empty()) {
				if (pindex == N) {
					break;
				}
				for (int i = 0; i < K; i++) {
					if (players[pindex].time_arrive > tables[i].time_end) {
						tables[i].time_end = players[pindex].time_arrive;
					}
				}
			/*	if (pindex == N) {
					break;
				}
				if (players[pindex].vip) {
					for (index = 0; index < K; index++) {
						if (tables[index].vip && tables[index].freed) {
							break;
						}
					}
					if (index == K) {
						for (index = 0; index < K; index++) {
							if (tables[index].freed) {
								break;
							}
						}
					}
				}
				else {
					for (index = 0; index < K; index++) {
			            if (tables[index].freed) {
				        break;
			            }
		            }
				}
				tables[index].freed = false;
				tables[index].num_serve++;
				tables[index].time_end = players[pindex].time_arrive + players[pindex].timeforplay;
				players[pindex].played = true;
				players[pindex].time_serve = players[pindex].time_arrive;
				players[pindex].timeforwait = 0;
				pindex++;*/
				
			}
			else{
				if (normal.empty() && !vip.empty()) {
					for (index = 0; index < K; index++) {
						if (tables[index].vip && tables[index].freed) {
							break;
						}
					}
					if (index == K) {
						for (index = 0; index < K; index++) {
							if (tables[index].freed) {
								break;
							}
						}
					}					
					tables[index].freed = false;
					tables[index].num_serve++;
					tables[index].time_end = cur_time + players[vip.front()].timeforplay;
					players[vip.front()].played = true;
					players[vip.front()].time_serve = cur_time;
					players[vip.front()].timeforwait = cur_time-players[vip.front()].time_arrive;
					vip.pop();
				}
				else {
					if (!normal.empty() && vip.empty()) {
						for (index = 0; index < K; index++) {
							if (tables[index].freed) {
								break;
							}
						}
						tables[index].freed = false;
						tables[index].num_serve++;
						tables[index].time_end = cur_time + players[normal.front()].timeforplay;
						players[normal.front()].played = true;
						players[normal.front()].time_serve = cur_time;
						players[normal.front()].timeforwait = cur_time - players[normal.front()].time_arrive;
						normal.pop();
					}
					else{
						int tindex;
						for (index = 0; index < K; index++) {
							if (tables[index].vip && tables[index].freed) {
								break;
							}
						}
						if (index < K) {
							tindex = vip.front();
							vip.pop();
						}
						else {
							for (index = 0; index < K; index++) {
								if (tables[index].freed) {
									break;
								}
							}
							if (players[normal.front()].time_arrive < players[vip.front()].time_arrive) {
								tindex = normal.front();
								normal.pop();
							}
							else {
								tindex = vip.front();
								vip.pop();
							}
						}
						tables[index].freed = false;
						tables[index].num_serve++;
						tables[index].time_end = cur_time + players[tindex].timeforplay;
						players[tindex].played = true;
						players[tindex].time_serve = cur_time;
						players[tindex].timeforwait = cur_time - players[tindex].time_arrive;
					}
				}
			}
			cur_time = 75600;
			for (int i = 0; i < K; i++) {
				if (cur_time > tables[i].time_end) {
					cur_time = tables[i].time_end;
				}
			}
			for (int i = 0; i < K; i++) {
				if (cur_time == tables[i].time_end) {
					tables[i].freed = true;
				}
			}
	    }
	}

	sort(players, players + N, less_then_serve);
	
	int temp;
	for (int i = 0; i < N; i++) {
		if (players[i].played) {
			s = players[i].time_arrive % 60;
			temp = players[i].time_arrive / 60;
			m = temp % 60;
			h = temp / 60;
			printf("%02d:%02d:%02d ", h, m, s);
			s = players[i].time_serve % 60;
			temp = players[i].time_serve / 60;
			m = temp % 60;
			h = temp / 60;
			printf("%02d:%02d:%02d ", h, m, s);
			s = players[i].timeforwait % 60;
			m = players[i].timeforwait / 60;
			if (s >= 30) {
				m++;
			}
			printf("%d\n", m);
		}
	}
	printf("%d", tables[0].num_serve);
	for (int i = 1; i < K; i++) {
		printf(" %d", tables[i].num_serve);
	}
	printf("\n");

	delete[] tables;
	delete[] players;

	system("pause");
	return 0;
}