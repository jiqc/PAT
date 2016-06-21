#include<cstdio>
#include<vector>
using namespace std;

struct rational {
	long long int intg;
	long long int num;
	long long int den;
};

long long int getgcd(long long a, long long b) {
	if (a < 0)a = -a;
	if (b != 0) while ((a = a%b) && (b = b%a));
	return a + b;
}

rational getstd(rational r) {
	long long int gcd;

	if (r.den != 0) {
		if (r.num == 0) {
			r.intg = 0;
		}
		else {
			gcd = getgcd(r.num, r.den);
			r.num /= gcd;
			r.den /= gcd;
			r.intg = r.num / r.den;
			r.num = r.num % r.den;
			if (r.intg<0 && r.num < 0) {
				r.num = -r.num;
			}
		}
	}
	return r;
}

void printr(rational r) {
	if (r.den == 0) {
		printf("Inf");
	}
	else {
		if (r.intg == 0 && r.num == 0) {
			printf("0");
			return;
		}
		if (r.intg != 0 && r.num == 0) {
			if (r.intg < 0) {
				printf("(%lld)", r.intg);
			}
			else {
				printf("%lld", r.intg);
			}
			return;
		}
		if (r.intg == 0 && r.num != 0) {
			if (r.num < 0) {
				printf("(%lld/%lld)", r.num,r.den);
			}
			else {
				printf("%lld/%lld", r.num, r.den);
			}
			return;
		}
		if (r.intg != 0 && r.num != 0) {
			if (r.intg < 0) {
				printf("(%lld %lld/%lld)", r.intg, r.num, r.den);
			}
			else {
				printf("%lld %lld/%lld", r.intg, r.num, r.den);
			}
			return;
		}
	}
}

int main() {
	rational r1, r2, rp, rmn, rmt, rd;

	scanf_s("%lld/%lld %lld/%lld", &r1.num, &r1.den, &r2.num, &r2.den);

	if (r2.num == 0) {
		rp = r1;
		rmn = r1;
		rmt.num = 0;
		rd.den = 0;
	}
	else {
		if (r1.num == 0) {
			rp = r2;
			rmn.num = -r2.num;
			rmn.den = r2.den;
			rmt.num = 0;
			rd.num = 0;
		}
		else {
			rp.num = r1.num*r2.den + r1.den*r2.num;
			rp.den = r1.den*r2.den;
			rmn.num = r1.num*r2.den - r1.den*r2.num;
			rmn.den = r1.den*r2.den;
			rmt.num = r1.num*r2.num;
			rmt.den = r1.den*r2.den;
			rd.num = r1.num*r2.den;
			rd.den = r1.den*r2.num;
			if (rd.den < 0) {
				rd.den = -rd.den;
				rd.num = -rd.num;
			}
		}
	}

	r1 = getstd(r1);
	r2 = getstd(r2);
	rp = getstd(rp);
	rmn = getstd(rmn);
	rmt = getstd(rmt);
	rd = getstd(rd);

	printr(r1); printf(" + "); printr(r2); printf(" = "); printr(rp); printf("\n");
	printr(r1); printf(" - "); printr(r2); printf(" = "); printr(rmn); printf("\n");
	printr(r1); printf(" * "); printr(r2); printf(" = "); printr(rmt); printf("\n");
	printr(r1); printf(" / "); printr(r2); printf(" = "); printr(rd); printf("\n");

	system("pause");
	return 0;
}