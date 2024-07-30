//Oredred Linked List

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
		
		//add node by add to tail
		void addnode(L a){
				if(tail==0){
				head=tail=new node<L>(a);   //when no nodes are in List...Boundary condition
				return;
			}
			tail->next = new node<L>(a,0);
			tail = tail->next;
		}
		
		// Sorting List
		void sortList(){
			node<L>* current = head;
			node<L>* index = 0;
			int tempt;
		
			if(head==0){
				return;
			}
			while(current!=0){
				index = current->next;
				while(index!=0){
					if(current->info > index->info){
					tempt = current->info ;
					current->info = index->info;
					index->info = tempt;
				}
				 index= index->next;
				}
			
				current= current->next;
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
	l1.addnode(5);
	l1.addnode(4);
	l1.addnode(1);
	l1.addnode(2);
	l1.addnode(3);
	cout<<"The list without sorted:"<<endl;
	l1.display();
	cout<<"The list with sorted:"<<endl;
	l1.sortList();
	l1.display();
	return 0;
}
