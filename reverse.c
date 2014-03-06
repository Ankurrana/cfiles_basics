#include "stdio.h"
#include "string.h"

#define get getchar_unlocked

inline long int scan2(){
	long int n=0,s=1;
	char p=get();
	if(p=='-') s=-1;
	while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
	if(p=='-') s=-1,p=get();
	while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
	return n*s;
}

int main(){
	char strin[41][60],temp[10] = "Begin",right[10] = "Right",left[10] = "Left";
	long int rounds,turns = 0,i,j=0;
	rounds = scan2();
	
	while(rounds--){
		turns = scan2();
		for(i=0;i<turns;i++){
			scanf("%s",strin[i]);
		}
		i--;

		for(;i>=0;i--){
			if (strin[i][0] == 'L'){
				printf("%s",temp);
				for(j=4;strin[j]!=NULL;j++)
					printf("%c",strin[i][j]);
				strcpy(temp,right);
				printf("\n");
			}
			else{
				printf("%s",temp);
				for(j=5;strin[j]!=NULL;j++)
					printf("%c",strin[i][j]);
				strcpy(temp,left);
				printf("\n");
			}
				
		}
	}	
	return 0;
}