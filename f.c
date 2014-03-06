#include "stdio.h"
int main() {
	int n,i,j,z,a = 0,b,c,d,l = 0;
 
	scanf("%d", &n);
 
	if(n <=50 && n > 1){
	for (i = 0; i < n; ++i) {
		scanf("%d", &z);
 
		if (z > 2 && z <= 50) {
			a = 0;
			for (j = 0; j < (2*z); ++j) {
				scanf("%d", &b);
				if (b < 1 || b > 50) 
					++l;
				if (j < z)
					a = a + b;
				else
					a = a - b;
			}	
			a = 0 -  a;
 
			if (a % (z-2) == 0 && l==0)
				printf("%d\n", a/(z-2));
			else
				printf("-1\n");
		}
 
		else if(z == 2) {
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if ((c-a) == (b-d) && !((a < 1)||(b < 1)||(c < 1)||(d < 1)||(a > 50)||(b > 50)||(c > 50)||(d > 50))) {
				if ((c-a) > 0)
					printf("%d\n", (c-a));
				else
					printf("%d\n", (a-c));
			}
			else
				printf("-1\n");
		}
 
		else {
			scanf("%d%d", &a, &b);
			if((a-b) > 0 && !((a < 1) || (b < 1)|| (a > 50) || (b > 50)))
				printf("%d\n",(a-b));
			else
				printf("-1\n");
		}
	}
	}
	return 0;
}