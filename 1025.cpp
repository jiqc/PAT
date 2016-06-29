#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct testee {
	string regnum;
	int score;
	int location;
	int rank_local;
	int rank_final;
};

bool higher_than_score(testee &A, testee &B) {
	if (A.score > B.score) {
		return true;
	}
	else {
		if (A.score == B.score) {
			if (A.regnum < B.regnum) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
}

int main() {
	int N;
	int K;
	int all;
	vector<testee> group;

	all = 0;

	testee temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> K;
		all = all + K;
		for (int j = 0; j < K;j++){
			cin >> temp.regnum;
			cin >> temp.score;
			temp.location = i + 1;
			group.push_back(temp);
		}
	}

	sort(group.begin(), group.end(), higher_than_score);

	vector<int> lrank,lsame,ltemp;
	lrank.resize(N, 1);
	lsame.resize(N, 1);
	ltemp.resize(N, 100);
	int ln;
	int rank = 1;
	int same = 1;
	int tempscore = 100;
	for (int i = 0; i < all; i++) {
		if (group[i].score == tempscore) {
			group[i].rank_final = same;
			rank++;
		}
		else {
			group[i].rank_final = rank;
			tempscore = group[i].score;
			same = rank;
			rank++;
		}
		ln = group[i].location - 1;
		if (group[i].score == ltemp[ln]) {
			group[i].rank_local = lsame[ln];
			lrank[ln]++;
		}
		else {
			group[i].rank_local = lrank[ln];
			ltemp[ln] = group[i].score;
			lsame[ln] = lrank[ln];
			lrank[ln]++;
		}
	}

	cout << all << '\n';
	for (int i = 0; i < all; i++) {
		cout << group[i].regnum << ' ' << group[i].rank_final << ' ' << group[i].location << ' ' << group[i].rank_local << '\n';
	}

	system("pause");
	return 0;
}