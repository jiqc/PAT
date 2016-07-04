#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct card {
	string name;
	int position;
};

bool less_than_position(const card & A, const card & B) {
	return A.position < B.position;
}

int main() {
	int N; 
	vector<card> deck;
	vector<int> reposition;
	deck.resize(54);
	reposition.resize(54);

	deck[0].name = "S1";
	deck[1].name = "S2";
	deck[2].name = "S3";
	deck[3].name = "S4";
	deck[4].name = "S5";
	deck[5].name = "S6";
	deck[6].name = "S7";
	deck[7].name = "S8";
	deck[8].name = "S9";
	deck[9].name = "S10";
	deck[10].name = "S11";
	deck[11].name = "S12";
	deck[12].name = "S13";
	deck[13].name = "H1";
	deck[14].name = "H2";
	deck[15].name = "H3";
	deck[16].name = "H4";
	deck[17].name = "H5";
	deck[18].name = "H6";
	deck[19].name = "H7";
	deck[20].name = "H8";
	deck[21].name = "H9";
	deck[22].name = "H10";
	deck[23].name = "H11";
	deck[24].name = "H12";
	deck[25].name = "H13";
	deck[26].name = "C1";
	deck[27].name = "C2";
	deck[28].name = "C3";
	deck[29].name = "C4";
	deck[30].name = "C5";
	deck[31].name = "C6";
	deck[32].name = "C7";
	deck[33].name = "C8";
	deck[34].name = "C9";
	deck[35].name = "C10";
	deck[36].name = "C11";
	deck[37].name = "C12";
	deck[38].name = "C13";
	deck[39].name = "D1";
	deck[40].name = "D2";
	deck[41].name = "D3";
	deck[42].name = "D4";
	deck[43].name = "D5";
	deck[44].name = "D6";
	deck[45].name = "D7";
	deck[46].name = "D8";
	deck[47].name = "D9";
	deck[48].name = "D10";
	deck[49].name = "D11";
	deck[50].name = "D12";
	deck[51].name = "D13";
	deck[52].name = "J1";
	deck[53].name = "J2";

	cin >> N;

	for (int i = 0; i < 54; i++) {
		deck[i].position = i + 1;
	}

	for (int i = 0; i < 54; i++) {
		cin >> reposition[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 54; j++) {
			deck[j].position = reposition[j];
		}
		sort(deck.begin(), deck.end(), less_than_position);
	}

	for (int i = 0; i < 53; i++) {
		cout << deck[i].name << ' ';
	}
	cout << deck[53].name << endl;

	system("pause");
	return 0;
}