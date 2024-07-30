// Special Matrix - Tridiagnal Matrix

#include<iostream>
using namespace std;
template<class t>
class tridiagonal{
	private:
	int row;
	t*element;
	public:
		tridiagonal(){
			cout<<"Enter the no. of Rows"<<endl;
			cin>>row;
			element = new t[3*row-2]; //no. of non zero elements (3n -2)
		}
		
		 void set(){
		 	cout<<"Enter the Elements"<<endl;
		 	for(int i=0; i<row;i++){
		 		for (int j=0;j<row;j++){
		 			if(i==j+1){
		 				cin>>element[j]; // lower diagonal
					 }
					 else if (i==j){
					 		cin>>element[row-1+i]; // Middle diagonal
					 }
					 else if (i==j-1){
					 		cin>>element[2*row-1+i]; // Upper diagonal
					 }
				 }
			 }
		 }
		 
		 void get(){
		 	cout<<"Display the Element"<<endl;
		 	for(int i= 0; i<row;i++){
		 		for(int j=0;j<row;j++){
		 			switch(i-j){
		 				case 1: {
		 					cout<< element[j]<< " ";
							break;
						 }
						 case 0:{
						 	cout<< element[row-1+i]<< " ";
							break;
						 }
						 case -1:{
						 	cout<< element[2*row-1+i]<< " ";
							break;
						 }
		 				default:{
		 					cout<< "0"<< " ";
							break;
						 }
					 }
				//	 cout<<endl;
				 }
				  cout<<endl;
			 }
		 }
};

int main(){
	tridiagonal<int>r;
	r.set();
	r.get();
	return 0;
}
