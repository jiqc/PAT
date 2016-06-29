#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

struct book {
	int bookID;
	char booktitle[81];
	char author[81];	
	char keywords[5][11];
	char publisher[81];
	char year[5];
};

bool less_than_bookID(book &A, book &B) {
	return A.bookID < B.bookID;
}

int main() {
	int booknumber;
	int querynumber;

    char keybuffer[55];

	cin >> booknumber;
	book *booklib = new book[booknumber];
	for (int i = 0; i < booknumber; i++) {
		cin >> booklib[i].bookID;
		cin.get();
		cin.getline(booklib[i].booktitle, 81);
		cin.getline(booklib[i].author, 81);
		cin.getline(keybuffer, 55);
		int index = 0;
		int j = 0;
		int k = 0;
		while (keybuffer[index] != '\0') {
			if (keybuffer[index] == ' ') {
				booklib[i].keywords[k][j] = '\0';
				j = 0;
				k++;
				index++;
			}
			else {
				booklib[i].keywords[k][j] = keybuffer[index];
				j++;
				index++;
			}
		}
		booklib[i].keywords[k][j] = '\0';
		cin.getline(booklib[i].publisher, 81);
		cin >> booklib[i].year;
	}

	sort(booklib, booklib + booknumber, less_than_bookID);

	char query[84];
	bool find = false;

	cin >> querynumber;
	cin.get();
	for (int i = 0; i < querynumber; i++) {
		find = false;
		cin.getline(query, 84);
		cout << query << '\n';
		for (int j = 0; j < booknumber; j++) {			
            switch (query[0]){
		    case'1':
				if (strcmp(booklib[j].booktitle, query + 3) == 0) {
					printf("%07d\n", booklib[j].bookID);
					find = true;
				}
				break;
			case'3':
				for (int k = 0; k < 5; k++) {
					if (strcmp(booklib[j].keywords[k], query + 3) == 0) {
						printf("%07d\n", booklib[j].bookID);
					    find = true;
				    }
				}
				break;
			case'2':
				if (strcmp(booklib[j].author, query + 3) == 0) {
					printf("%07d\n", booklib[j].bookID);
					find = true;
				}
				break;
			case'4':
				if (strcmp(booklib[j].publisher, query + 3) == 0) {
					printf("%07d\n", booklib[j].bookID);
					find = true;
				}
				break;
			case'5':
				if (strcmp(booklib[j].year, query + 3) == 0) {
					printf("%07d\n", booklib[j].bookID);
					find = true;
				}
		    }
		}	
		if (!find) {
			cout << "Not Found\n";
		}
	}

	system("pause");
	return 0;
}