//Special Matrix - Uppertriangular Matrix
#include<iostream>
using namespace std;
template<class t>
class uppertriangular{
    private:
	int row;
	t*element;
	public:
		uppertriangular(){
			cout<<"Enter the no. of Rows"<<endl;
			cin>>row;
			element = new t[row*(row+1)/2 ]; //no. of non zero elements (n(n+1)/2)
		}
		
		void set(){
				cout<<"Enter the Elements"<<endl;
				for(int i=0; i<row;i++){
		 		for (int j=0;j<row;j++){
		 			if(i<=j){
		 				cin>>element[((j*(j+1)/2)+i)];
		}
	}
 }
}
 
		
		void get(){
				cout<<"Display the Element"<<endl;
		 	for(int i= 0; i<row;i++){
		 		for(int j=0;j<row;j++){
		 		if(i<=j){
		 					cout<<element[((j*(j+1)/2)+i)]<<" ";
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
	uppertriangular	<int>r;
	r.set();
	r.get();
	return 0;
}
