// Circular Queue using Singly Linked list
#include<iostream>
using namespace std;

template<class L>
class list;
template<class T> 
class node
{    
	T info;
	node<T>* next;
	public:
	node(T a, node<T> *n=0){
		info= a;
		next= n;
	}
	friend class list<T>;	
};

template<class L>
class list {
	node<L>* rear; // rear pointer
	
	public:
		list(){
		  rear= 0;
		}
		
		
    // enqueue = element add to back
    void enqueue(L a){
	node<L>* temp=new node<L>(a);
	if(rear==0){
		temp->next=temp;
		rear=temp;
		return;
	}
	temp->next=rear->next;
	rear->next=temp;
	rear=temp;	
    }
    

    //dequeue = element delete from front
    void dequeue(){
    	if(rear==0){
		cout<<"ERROR !!!\n";
		return;
	}
	if(rear->next==rear){
		node<L> *temp=rear;
		rear=0;
		delete temp;
		return;
	}
    node<L> *temp=rear->next;
    rear->next=temp->next;
    delete temp; 
	}
	
	//display
	void display(){
	 node<L> *current=rear->next;
	while(current->next!=rear->next){
		cout<<current->info<<"  ";
		current=current->next;
	}
	cout<<rear->info<<"  ";
	cout<<endl;
	}
};
	
	int main(){
		list<int>l1;
		cout<<"Enque"<<endl;
	    l1.enqueue(10);
	    l1.enqueue(20);
	    l1.enqueue(30);
	    l1.enqueue(40);
	    l1.display();
	    
	    cout<<"Dequeue"<<endl;
	    l1.dequeue();
	    l1.display();
	    
		return 0;
	}

