/*when i use vector it surplus the time...
#include<cstdio>
#include<map>
using namespace std;

int main() {
	int M, N;
	int color;
	map<int, int> colorset;

	scanf_s("%d %d", &M, &N);
	int threshold = (M*N + 1) / 2;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &color);
			if (colorset.find(color) == colorset.end()) {
				colorset[color] = 0;
			}
			colorset[color]++;
			if (colorset[color] >= threshold) {
                printf("%d\n", color);
				break;
			}			
		}
	}	

	system("pause");
	return 0;
}
*/
/********************************************/
#include<cstdio>
using namespace std;

int main(){
	int M,N;
	int temp;
	int cnt;
	int dmt;
	scanf("%d %d",&M,&N);
	
	dmt=-1;
	cnt=0;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			scanf("%d", &temp);
			if(cnt==0){
				dmt=temp;
				cnt++;
			}else{
				if(dmt==temp){
					cnt++;
				}else{
					cnt--;
				}
			}
		}
	}
	printf("%d\n",dmt);
	return 0;
}
