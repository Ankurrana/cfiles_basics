// defacing score. 

//i'll definitely use vectors to score the 
#include "iostream"
#include "vector"
#include "string"

using namespace std;
//First create a function convert
//this function either 

short int convert_equal_to(short int n1,short int limit){
	int i;
	short int forone[6] = {0,3,4,7,8,9};
	short int forseven[4] = {0,3,8,9};

	if(limit == 8)
		return 8;

	switch(n1){
		case 1:
			for(i=0;i<6;i++){
				if(forone[i] > limit)
					break;
			}
		return forone[i-1];
		break;
		case 2:
		case 6:
		case 9:
		 if(limit == 9)
		 	return 8;
		 break;
		case 3:
		case 4:
			if(limit == 9)
				return 9;
			break;
		case 5:
			if(limit < 8)
				return 6;
			if(limit == 9)
				return 9;
			break;
		case 7:
			for(i=0;i<4;i++){
				if(forseven[i] > limit)
					break;	
			}
			return forseven[i-1];
			break;

	}

	return n1;
}


short int convert_lesser_to(short int n1,short int limit){
	int i;
	short int forone[6] = {0,3,4,7,8,9};
	short int forseven[4] = {0,3,8,9};
	if(limit == 9)
		return 8;
	switch(n1){
		case 1:
			for(i=0;i<6;i++){
				if(forone[i] > limit)
					break;
			}
		if(forone[i-1] == limit);
			return forone[i-2];
		return forone[i-1];
			break;
		case 3:
		case 4:
			if(limit == 8)
				return n1;
			break;
		case 5:
			if(limit>6)
				return 6;
			break;
		case 7:
			for(i=0;i<4;i++){
				if(forone[i] > limit)
					break;
			}
		if(forone[i-1] == limit);
			return forone[i-2];
			break;
	}
	return n1;
}





bool can_convert(short int n1,short int limit){
	//Returns true if the number can be converted to a number 
	// smaller than the limit else , returns false;
	int a;
	a = convert_equal_to(n1,limit);
	if(a<=n1)
		return true;
	return false;
}









short int convert(short int *n1,short int *n2,short int *n3,short int *n4,short int offset){
	short int ori_n1 = *n2;
	if(offset > 0)
		*n1 = 9;
	*n2 = convert_equal_to(*n2,*n1);
	if((*n1 - *n2) > 0)
		*n3 = 9;

	if(can_convert(*n4,*n3))
		*n4 = convert_equal_to(*n4,*n3);
	else{

		*n2 = convert_lesser_to(*n2,ori_n1);
		*n3 = 9;
		*n4 = convert_equal_to(*n4,*n3);
	}

	return 0;
}


int main(){
	short int n1,n2,n3,n4;
	cin >> n1;
	cin >> n2;
	cin >> n3;
	cin >> n4;


	convert(&n1,&n2,&n3,&n4,0);

	cout << "\nn2:" << n2 << "\nn4:" << n4;



	return 0;
}	