#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

struct person {
	//string name;
	char name[9];
	int age;
	int wealth;
};

bool non_dec_age(const person &A, const person &B) {
	return A.age < B.age;
}

bool non_inc_wealth(const person &A, const person &B) {
	if (A.wealth != B.wealth) {
		return A.wealth > B.wealth;
	}
	else {
		if (A.age != B.age) {
			return A.age < B.age;
		}
		else {
			return strcmp(A.name, B.name) < 0;
		}
	}
}
/*----------------work better with smaller data and more queries--*/
int main() {
	int N, K;
	vector<person> people;

	scanf_s("%d %d", &N, &K);
	people.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%s", &people[i].name, 9);
		scanf_s("%d %d", &people[i].age, &people[i].wealth);
	}

	sort(people.begin(), people.end(), non_inc_wealth);

	int max, startage, endage;
	int count;
	for (int i = 0; i < K; i++) {
		scanf_s("%d %d %d", &max, &startage, &endage);
		printf("Case #%d:\n", i + 1);
		count = 0;
		for (int j = 0; j < N; j++) {
			if (people[j].age >= startage && people[j].age <= endage) {
				printf("%s %d %d\n", people[j].name, people[j].age, people[j].wealth);
				count++;
			}
			if (count == max) {
				break;
			}
		}
		if (count == 0) {
			printf("None\n");
		}
	}

	system("pause");
	return 0;
}


/*----------------work better with biger data and less queries

int main() {
	int N, K;
	vector<vector<person> > people;
	vector<person> part;
	people.resize(201);

	scanf_s("%d %d", &N, &K);
	person temp;
	for (int i = 0; i < N; i++) {
		scanf_s("%s", &temp.name, 9);
		scanf_s("%d %d", &temp.age, &temp.wealth);
		people[temp.age].push_back(temp);
	}

	int max, startage, endage;
	for (int i = 0; i < K; i++) {
		scanf_s("%d %d %d", &max, &startage, &endage);
		part.clear();
		for (int a = startage; a < endage + 1; a++) {
			if (!people[a].empty()) {
				part.insert(part.begin(), people[a].begin(), people[a].end());
			}			
		}
		printf("Case #%d:\n", i + 1);
		if (part.empty()) {
			printf("None\n");
		}
		else {
			sort(part.begin(), part.end(), non_inc_wealth);
			int min = max < part.size() ? max : part.size();
			for (int j = 0; j < min; j++) {
				printf("%s %d %d\n", part[j].name, part[j].age, part[j].wealth);
			}
		}
	}

	system("pause");
	return 0;
}

---------------------------------------------------------------------------

int N, K;
vector<person> people;

int findpre(const int age, int st, int ed) {
	int mid;
	while (ed - st > 5) {
		mid = (st + ed) / 2;
	    if (people[mid].age > age) {
		    ed = mid - 1;
	    }
	    else {
		    if (people[mid].age < age) {
			    st = mid +1;
		    }
		    else {			    
				ed = mid;
		    }
	    }
	}	
	while (ed >= st && people[st].age < age) {
		st++;
	}
	return st;
}

int findpost(const int age, int st, int ed) {
	int mid;
	while (ed - st > 5) {
		mid = (st + ed) / 2;
		if (people[mid].age > age) {
			ed = mid - 1;
		}
		else {
			if (people[mid].age < age) {
				st = mid + 1;
			}
			else {
				st = mid;
			}
		}
	}
	while (ed >= st && people[st].age <= age) {
		st++;
	}
	return st;
}

int main() {	

	//cin >> N >> K;
	scanf_s("%d %d", &N, &K);
	people.resize(N);
	for (int i = 0; i < N; i++) {
		//cin >> people[i].name >> people[i].age >> people[i].wealth;
		scanf_s("%s", &people[i].name, 9);
		scanf_s("%d %d", &people[i].age, &people[i].wealth);
	}

	sort(people.begin(), people.end(), non_dec_age);

	int max, startage, endage;
	int pre, post;
	for (int i = 0; i < K; i++) {
		cin >> max >> startage >> endage;
		pre = findpre(startage, 0, N-1);
		post = findpost(endage, 0, N-1);		
		//cout << "Case #" << i + 1 << ":" << endl;
		printf("Case #%d:\n", i + 1);
		if (pre == post) {
			//cout << "None" << endl;
			printf("None\n");
		}
		else {
			sort(people.begin() + pre, people.begin() + post, non_inc_wealth);
			for (int j = pre; j < post; j++) {
			    //cout << people[j].name << ' ' << people[j].age << ' ' << people[j].wealth << endl;
				printf("%s %d %d\n", people[j].name, people[j].age, people[j].wealth);
				max--;
				if (max == 0) {
					break;
				}
		    }
			sort(people.begin() + pre, people.begin() + post, non_dec_age);
		}		
	}

	system("pause");
	return 0;
}

*/