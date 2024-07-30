//Special Matrix - Symmetric Matrix
#include<iostream>
using namespace std;
template<class t>
class symmetric{
	int size;
	 t*arr;
	t val;
	int flag=1; 
	public:
	symmetric(int size){
		this->size=size;
		arr=new t[size*(size+1)/2];
	}
	void execute(){
		cout<<"Enter the elements"<<endl;
		for(int a=0;a<size;a++){
			for(int b=0;b<size;b++){
				cin>>val;
				set(a,b,val);
			}
		}
		if(flag==1){
		cout<<"the matrix is symmetric"<<endl;
    	for(int a=0;a<size;a++){
			for(int b=0;b<size;b++){
				get(a,b);
		
	       }
	       cout<<endl;
       }
   }
}
void set(int i,int j,t v){
	if(i<=j){
	  arr[(size*i)-(((i)*(i-1))/2)+(j-i)]=v;	
	}
	else{ 
	  if((v)!=arr[(size*j)-(((j)*(j-1))/2)+(i-j)]){
	  	cout<<"not a symmetric matrix";
	  	flag=0;
	  }
	}
}
void get(int i,int j){
	if(i<=j){
		cout<<arr[(size*i)-(((i)*(i-1))/2)+(j-i)]<<" ";
	}
	else{
		cout<<arr[(size*j)-(((j)*(j-1))/2)+(i-j)]<<" ";
	}
}
};
int main(){
symmetric<int> obj1(4);
	obj1.execute();
}
