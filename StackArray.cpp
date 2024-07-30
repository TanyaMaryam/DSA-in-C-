//Stack using array
#include<iostream>
//#include<stack>
using namespace std; 
#define n 100
template <class S>  
class Stack {
    S t;//t = index/range
    S arr[n]; // n = no.of elements
public:
     Stack(){
	 t = -1; // index set at -1
      }
    
    //Size of the array
  void size(){
   	cout<<"The no.of elements in stacks are = "<<t+1<<endl;
    	return ;
	}
	
	//adding the element in stacks i.e push
	void push(S e){
		if(t>= (n-1)){
			cout<<"Stack Overflow"<<endl;
			return;
		}
		arr[++t] = e;
		cout<<e<<" Pushed into stack"<<endl;
	}
	
	//deleting the top element from stack
	void pop(){
		if(t<0){
			cout<<"Stack Underflow"<<endl;
			return;
		}
	  t--;
	}
	
	//top element in stack
	int top(){
		if(t<0){
			cout<<"Stack is Empty"<<endl;
			return -1;
		}
		S e = arr[t];
//		cout<<arr[t];
		return arr[t];
	}
	
	//Check is stack empty or not 
	bool isEmpty(){
		return (t<0);
	}
		
		
	//display
	void display(){
		cout<<"The Stack is = ";
		 while(!isEmpty()){
        // print top element in stack
		cout<<top();
		cout<<" " ;
        // remove top element in stack
        pop();
    }
    return ;
	}
};

int main(){
	Stack<int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.pop();
	s.size();
	s.display();
	/* while(!s.isEmpty()){
        // print top element in stack
        cout<< s.top() <<" " ;
        // remove top element in stack
        s.pop();
    }*/
    
	return 0;
}
