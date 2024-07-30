//Special Matrix - Diagonal Matrix
#include<iostream>
using namespace std;
template<class t>
class diagonal{
	private:
	int row;
	t*element;
	public:
		diagonal(){
			cout<<"Enter the no. of Rows"<<endl;
			cin>>row;
			element = new t[row]; //no. of non zero elements (n(n+1)/2)
		}
		
		void set(){
				cout<<"Enter the Elements"<<endl;
				for(int i=0; i<row;i++){
		 		for (int j=0;j<row;j++){
		 			if(i==j){
		 				cin>>element[i];
		}
	}
 }
}
 
		
		void get(){
				cout<<"Display the Element"<<endl;
		 	for(int i= 0; i<row;i++){
		 		for(int j=0;j<row;j++){
		 		if(i==j){
		 					cout<<element[i]<<" ";
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
	diagonal<int>r;
	r.set();
	r.get();
	return 0;
}

