#include "iostream"
using namespace std;

class Rectangle{
	public:
		int height,width;
		Rectangle(int a, int b){
			height = a;
			width = b;		
		};
		
		int area(){ 
			return height*width; 
		};



};


int main(){
	Rectangle rect(5,10);
	Rectangle rect2 = new Rectangle(20,30);
	cout << rect.height;
	cout << rect.width;	
	cout << rect.area();

	cout << "this is the second area";
	cout << rect2.area();
	
	return 0;
}
