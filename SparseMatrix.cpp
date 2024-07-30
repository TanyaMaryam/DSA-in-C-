// Sparse Matrix
#include<iostream>
using namespace std;
class Tuple{
	public:
		int nzrow,nzcol,val; // nzrwo/nzcol - non zero row and coloumns

};
int main(){
	int row,col,nzele; //nzele= non zero element
	Tuple* T; //tuple of all non zero elements info
	cout<<"Enter the no. of rows";
	cin>>row;
	cout<<"Enter the no. coloumns";
	cin>>col;
	cout<<"Enter the no. of non zero elements";
	cin>>nzele;
	
	T=new Tuple[nzele];
	cout<<"Enter the non zero elements"<<endl;
	for(int i=0;i<nzele;i++){
		cout<<"Row no.";
		cin>>T[i].nzrow;
		cout<<"Coloumn no.";
		cin>>T[i].nzcol;
		cout<<"Value";
		cin>>T[i].val;
	}
	
	int curr=0; //displaying the sparse matix using the values stored in tuple 
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(i==T[curr].nzrow && j==T[curr].nzcol){ //checking for non zero elements
				cout<<T[curr].val<<" ";  //print when found
				curr++;  //updating the index of tuple
			}
			else{
				cout<<"0";
			}
		}
		cout<<endl;
	}
}
