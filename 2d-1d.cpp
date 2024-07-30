//Store 2d array into 1d array
#include<iostream>
using namespace std;
template<class t>
class Matrix{
	private:
		int row, col;
		t v;
		bool flag; // 0 for row major and 1 for coloumn major
		t*element;// 1d array to store 2d arr
		public:
			Matrix(){
			cout<<"Enter the no. of Rows"<<endl;
			cin>>row;
			cout<<"Enter the no. of Coloumns"<<endl;
			cin>>col;
			cout<<"For Row Major-0 and Coloumn Major-1"<<endl;
			cin>>flag;
			
	}
			void execute(){
			element = new t[row*col ]; //no. of rows
			cout<<"Enter the Elements"<<endl;
			for(int i=0; i<row;i++){
				for(int j=0;j<col; j++){
				cin>>v;
				set(i,j,v);	
				}
				cout<<endl;
			}
		
	}
		
		void set(int i,int j , t v){   // For storing the arr
			if (flag == 0){
				element[i*col+j]=v;
			}
			else {
			   element[i+j*row]=v;
			}
		}
		void display(){ // Displaying the 2d arr
		cout<<" Displaying 2D arr matrix"<<endl;
			for(int i=0; i<row;i++){
				for(int j=0;j<col; j++){
			if (flag == 0){
				cout<<element[i*col+j]<<" ";
			}
			else {
			cout<<element[i+j*row]<<" ";
			}
		} 
		cout<<endl;
   }
 }
		
		void get(){ // displaying 2d arr in 1d form according to Row Major and Coloumn Major
				cout<<"For Row Major-0 and Coloumn Major-1"<<endl;
			cin>>flag;
			cout<<"2D arr store in 1D"<<endl;
				for(int i=0; i<row;i++){
				for(int j=0;j<col; j++){
			if (flag == 0){
				cout<<element[i*col+j]<<" ";
			}
			else {
			cout<<	element[i+j*row]<<" ";
			}
		}
	
	}
   }
};

int main(){
	Matrix<int>r;
	r.execute();
	r.display();
	r.get();
	return 0;
}
