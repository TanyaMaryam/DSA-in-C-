//Revered DLL
#include<iostream>
using namespace std;
template<class L>
class list;
template <class T>
class node{
	T info;
     node<T>* next;
     node<T>* prev;
     public:
     	node(T a, node<T>* n=0, node<T>* p=0 ){
     		info=a;
     		next = n;
     		prev = p;
		 }
friend class list<T>; // node class ke private memebers i.e info and next or previous koh acess krskey in list class

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
			tail->next = new node<L>(a,0,tail);
			tail = tail->next;
		}
		
		
		//Reverse address
		void reverse(){
			node<L>*tempt = 0;
			node<L>*current = head;
			
			while(current!=0){
				tempt = current->prev;
				current->prev = current->next;
				current->next = tempt;
				current = current->prev;
			}
			
			// Before changing the head, check for the cases like empty list and list with only one node 
			if(tempt!=0){
				head = tempt->prev;
			}		
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
	list<int>l1;
	l1.addtail(10);
	l1.addtail(20);
	l1.addtail(30);
	cout<<"Doubly Linked List:-"<<endl;
	l1.display();
	cout<<"Reversed DLL:-"<<endl;
	l1.reverse();
	l1.display();
	return 0;
}
		
