#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int main() {
	int  records;
	char lockID[16] = "none", unlockID[16] = "none", tempID[16] = "none";
	char opentime[10] = "24:00:00", shuttime[10] = "00:00:00", temptime[10];

	scanf_s("%d", &records);
	while (records != 0) {
		scanf_s("%s", tempID, 16);
		scanf_s("%s", temptime, 10);
		if (strcmp(temptime, opentime) < 0) {
			strcpy_s(opentime, temptime);
			strcpy_s(unlockID, tempID);
		}
		scanf_s("%s", temptime, 10);
		if (strcmp(temptime, shuttime) > 0) {
			strcpy_s(shuttime, temptime);
			strcpy_s(lockID, tempID);
		}
		records--;
	}
	printf("%s %s\n", unlockID, lockID);

	system("pause");
	return 0;
}