#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, p;
	vector<long long int> s;
	int max;
	long long int product;
	int pre, post, mid;

	scanf_s("%d %d", &N, &p);
	s.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%lld", &s[i]);
	}

	sort(s.begin(), s.end());

	
	if (p >= s[N - 1]) {
		max = N;
	}
	else {
		max = 1;
		for (int i = 0; i < N; i++) {
		    if (i + max >= N) {
			    break;
		    }
		    product = s[i] * p;
		    if (product < s[i + max - 1]) {
			    continue;
		    }
	    	else {
			    pre = i + max - 1;
		    	post = N - 1;
			    while (post - pre > 5) {
				    mid = (pre + post) / 2;
				    if (s[mid] <= product) {
			    		pre = mid;
			    	}
		    		else {
			    		post = mid - 1;
		    		}
		    	}
			    for (; pre <= post; pre++) {
		     		if (s[pre] > product) {
			    		break;
			    	}
		    	}
	    		pre--;
	    		max = pre - i + 1;
     		}
    	}
	}
	

	printf("%d\n", max);

	system("pause");
	return 0;
}
/* a very smart solution from tiny656

int main() {
    int N, p;
	vector<long long int> s;
	int max;
	
	scanf_s("%d %d", &N, &p);
	s.resize(N);
	for (int i = 0; i < N; i++) {
	    scanf_s("%lld", &s[i]);
	}

	sort(s.begin(), s.end());

    max = 1;									
    for (int i = 0; i + max < N; i++) {	
        while (i + max < N) {
            if (1.0 * s[i + max] / s[i] > p){
			    break;
			}
            max++;
        }
    }

    printf("%d\n", max);

	system("pause");
    return 0;
}
*/