//Reverse SLL
#include<iostream>
using namespace std;
template<class L>
class list;
template <class T>
class node{
	T info;
     node<T>* next;
     public:
     	node(T a, node<T>* n=0 ){
     		info=a;
     		next = n;
		 }
friend class list<T>; // node class ke private memebers i.e info and next koh acess krskey in list class

};

template<class L>
class list {
	node<L>* head; // head pointer |  add no.of obj   |   collection of obj = 1 list
	node<L>* tail;
	public:
		list(){
			head =0;
			tail=0;
		}
		
			//add to tail
		void addtail(L a){	
			if(tail==0){
				head=tail=new node<L>(a);   //when no nodes are in List...Boundary condition
				return;
			}
			tail->next = new node<L>(a,0);
			tail = tail->next;
		}
		
		//reverse address
		void reverse(){
			node<L>*prev = 0;
			node<L>*tempt = 0;
			node<L>*current = head;
			
			while(current!=0){
				tempt = current->next;
				current->next = prev;
				prev = current;
				current = tempt;
			}		
			head = prev;
		}
		
			//display
		void display(){
			node<L>* temp= head;
			while(temp!=0){
				cout<<temp->info<<" ";
				temp=temp->next;
			}		
		   cout<<endl;
       }
};

int main(){
	list<int>l1;   //list 1 create 
	l1.addtail(10);
	l1.addtail(20);
	l1.addtail(30);
	cout<<"Singly linked list:-"<<endl;
	l1.display();
	cout<<"Reverse Singly Linked List:-"<<endl;
	l1.reverse();
	l1.display();
	return 0;
}
