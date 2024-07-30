//Special Matrix - Lowertriangular Matrix
#include<iostream>
using namespace std;
template<class t>
class lowertriangular{
	private:
	int row;
	t*element;
	public:
		lowertriangular(){
			cout<<"Enter the no. of Rows"<<endl;
			cin>>row;
			element = new t[row*(row+1)/2 ]; //no. of non zero elements (n(n+1)/2)
		}
		
		void set(){
				cout<<"Enter the Elements"<<endl;
				for(int i=0; i<row;i++){
		 		for (int j=0;j<row;j++){
		 			if(i>=j){
		 				cin>>element[((i*(i+1)/2)+j)];
		}
	}
 }
}
 
		
		void get(){
				cout<<"Display the Element"<<endl;
		 	for(int i= 0; i<row;i++){
		 		for(int j=0;j<row;j++){
		 		if(i>=j){
		 					cout<<element[((i*(i+1)/2)+j)]<<" ";
						 }
				else{
				
						 	cout << "0"<<" ";
						 }
					 }
					 cout<<endl;
				 }
				 
		}
	
};

int main(){
	lowertriangular	<int>r;
	r.set();
	r.get();
	return 0;
}
