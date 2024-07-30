// Stacks using LL
#include<iostream>
using namespace std;
template<class L>
class Stack;
template <class T>
class node{
	T info;
     node<T>* next;
     public:
      node(T a, node<T>* n=0 ){
     		info=a;
     		next = n;
		 }
friend class Stack<T>; //  class ke private memebers i.e info and next koh acess krskey in Stack class

};

template<class L>
class Stack {
	node<L>* front; // front pointer |  add no.of obj   |   collection of obj = 1 Stack
	node<L>* rear;
	public:
		Stack(){
			front =0;
			rear=0;
		}
		
		
		//push = elements added to rear
		void push(L a){	
			if(rear==0){
				front=rear=new node<L>(a);   //when no nodes are in Stack...Boundary condition
				return;
			}
		/*	rear->next = new node<L>(a,0);
			rear = rear->next;*/
			rear = new node<L>(a,rear);
		}
		
	
		
		// pop = element delete at rear
	   L	pop(){
	     if(rear==0){
		cout<<"STACK UNDERFLOW !!!\n";
		return 0;
	    }
	   L ele=rear->info;
	
       node<L> *temp=rear;
       rear=temp->next;
       delete temp;
       return ele;
      }
		/*L pop(){
			if (rear==0){
				front=0;
				return 0;
			}
			node<L>* tempt= front;
			while(tempt->next->next!=0)
			tempt = tempt->next;
		    
		    node<L>* temptail= tempt->next;
		    rear = tempt;
		    tempt->next=0;
		    delete temptail;
		}*/
		
		
		
		//Empty
	bool empty(){
	if(rear==NULL)
	  return true;
	else 
	  return false;
     }
		
		//display
		void display(){
			node<L>* temp= front;
			while(temp!=0){
				cout<<temp->info<<" ";
				temp=temp->next;
			}
			cout<<endl;
		}
};

/*
int main(){
	Stack<int>s1;   //Stack 1 create 
	
	cout<<"Push"<<endl;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.display();
	
	cout<<"Pop"<<endl;
	s1.pop();
	s1.display();
	return 0;
	
}*/
