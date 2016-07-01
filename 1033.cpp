#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct station {
	float price;
	float location;
	float gas_remain;
	float gas_fill;
};

float C_MAX, D, D_avg;
int N;
float range;
float maxdst;

vector<station> stops;

bool less_than_location(station &A, station &B) {
	return A.location < B.location;
}

void greedy(int aqui) {
	int next;
	next = -1;
	for (unsigned int i = aqui + 1; i < stops.size() && stops[i].location <= stops[aqui].location + range; i++) {
		if (stops[i].price < stops[aqui].price) {
			next = i;
			break;
		}
	}
	if (next != -1) {
		stops[aqui].gas_fill = (stops[next].location - stops[aqui].location) / D_avg-stops[aqui].gas_remain;
		stops[next].gas_remain = 0;
		greedy(next);
	}
	else {
		if (stops[aqui].location + range >= D) {
			stops[aqui].gas_fill = (D - stops[aqui].location) / D_avg - stops[aqui].gas_remain;
			maxdst = D;
		}
		else {
			float minprice = (float)0x7fffffff;
			for (unsigned int i = aqui + 1; i < stops.size() && stops[i].location <= stops[aqui].location + range; i++) {
				if (stops[i].price < minprice) {//here must be '<'
					next = i;
					minprice = stops[i].price;
				}
			}
			if (next == -1) {
				maxdst = stops[aqui].location + range;
			}
			else {
				stops[aqui].gas_fill = C_MAX - stops[aqui].gas_remain;
				stops[next].gas_remain = C_MAX - (stops[next].location - stops[aqui].location) / D_avg;
				greedy(next);
			}
		}
	}
}

float statis() {
	float sum = 0;
	for (int i = 0; i < N; i++) {
		if (stops[i].gas_fill != 0) {
			sum += stops[i].price*stops[i].gas_fill;
		}		
	}
	return sum;
}

int main() {
	float cost;

	cin >> C_MAX >> D >> D_avg >> N;
	range = C_MAX*D_avg;
	stops.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> stops[i].price >> stops[i].location;
		stops[i].gas_fill = 0;
		stops[i].gas_remain = 0;
	}

	sort(stops.begin(), stops.end(), less_than_location);

	if (stops[0].location != 0) {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}

	greedy(0);

	if (maxdst < D) {
		printf("The maximum travel distance = %.02f\n", maxdst);
	}
	else {
		cost = statis();
		printf("%.02f\n", cost);
	}

	system("pause");
	return 0;	
}