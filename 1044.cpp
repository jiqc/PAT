#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int N, M;

	scanf_s("%d %d", &N, &M);
	vector<int> diamond;
	diamond.resize(N);
	vector<pair<int, int> > result;
	int pre, pos;
	int min, temp;

	pre = 0;
	pos = 0;
	min = 0x7fffffff;
	temp = 0;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &diamond[i]);
		temp += diamond[i];
		if (temp >= M) {
			if (temp < min) {
				min = temp;
				result.clear();
				result.push_back(pair<int,int>(pre,pos));
			}
			else {
				if (temp == min) {
					result.push_back(pair<int, int>(pre, pos));
				}
			}
            if (temp > M) {
			    while (temp >= M) {
		            temp -= diamond[pre];
					pre++;
					if (temp < M) {
						break;
					}
				    if (temp < min) {
				    	min = temp;
				        result.clear();
			    		result.push_back(pair<int, int>(pre, pos));
					}
					else {
                        if (temp == min) {
			    			result.push_back(pair<int, int>(pre, pos));
			 	    	}
					}				    	    					        
				}
		    }					    				
		}
		pos++;
	}

	for (unsigned int i = 0; i < result.size(); i++) {
		printf("%d-%d\n", result[i].first+1, result[i].second+1);
	}

	system("pause");
	return 0;
}