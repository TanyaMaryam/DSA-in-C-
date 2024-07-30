//Matrix Multiplcation addition using operator overloading
#include<iostream>
using namespace std;
template<class T>
class matrix{
	private:
		int therows;
		int thecolumns;
		T *element;
	public:
		
		matrix(int r,int c){
			
			
		therows=r;
		thecolumns=c;
		
			element=new T[therows*thecolumns];
		
			
			}
		
		void input(){
			cout << " enter values of array" << endl;
			for(int i=0;i<therows*thecolumns;i++){
				
					cin>> element[i];
				}
				
			
		}
			
		~matrix(){
			delete [] element;
		}
		int rows()const{
		return therows;
		}
		int columns()const
		{
		return thecolumns;
		}
		
		void display()
		{
			cout << "the matrix is" << endl;
			for(int i=0;i<therows*thecolumns;i++)
			{
				cout << element[i] <<" ";
			}
			cout << endl;
		}
				
	
	matrix<T> operator+(const matrix<T> & m)const { 
	if(therows!=m.therows&&thecolumns!=m.thecolumns){
		cout << " error as mismatched";
	}
		
		
			matrix<T> w(therows,thecolumns);
			for(int i=0;i<therows*thecolumns;i++){
				w.element[i]=element[i]+m.element[i];
			}
		
		return w;
	}
	matrix<T> operator *(const matrix<T> &m)const
	{
	if(thecolumns!=m.therows)
	{
		cout << " mismatched error" << endl;
	}
	matrix<T> w (therows,m.thecolumns);
	int ct,cm,cw=0;
	for(int i=0;i<therows;i++)
	{
		for(int j=0;j<m.thecolumns;j++)
		{
			T sum=element[ct]*m.element[cm];
			
			for(int k=1;k<thecolumns;k++)
			{
				ct++;
				cm=cm+m.thecolumns;
				sum=sum+element[ct]*m.element[cm];
			}
			w.element[cw++]=sum;
			ct=ct-(thecolumns-1);
			cm=j+1;
		}
		ct+=thecolumns;
		cm=0;
	}
	return w;
	}

};
int main(){
	
	matrix<int> m(2,3);
	m.input();
	m.display();
	
	matrix<int>m1(3,2);
	m1.input();
	m1.display();

	matrix<int> m2=m+m1;
	 m2.display();
	 cout<<" \n multiploication is : ";
	 matrix<int> m3=m*m1;
	 m3.display();
	 
	 return 0;
}
