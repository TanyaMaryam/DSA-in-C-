//Double ended Queues LL
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
	
	node<L>* front; // front pointer |  add no.of obj   |   collection of obj = 1 list
	node<L>* rear;
	public:
		list(){
			front =0;
			rear=0;
		
		}
	   /* int sz(){
			return  ;
		}
		*/
			//enqueue = add to rear
		void enqueue(L a){	
			if(rear==0){
				front=rear=new node<L>(a);   //when no nodes are in List...Boundary condition
				return;
			}
			rear->next = new node<L>(a,0,rear);
			rear = rear->next;
			//N++;
		}
		
			
    	//dequeue = delete at front
		void dequeue(){
			if(front==0){
				rear=0;
				return;
			}
			node<L>* tempt = front;
			/*tempt */ front = front-> next;
			front->prev=0;
			delete tempt;
			//N--;
		    /*front*/
		//	front=tempt;
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

int main(){
		list<int>l1;
		
		cout<<"Enqueue"<<endl;
		l1.enqueue(10);
		l1.enqueue(20);
		l1.enqueue(30);
		l1.enqueue(40);
		l1.display();
		
		cout<<"Dequeue"<<endl;
		l1.dequeue();
		l1.display();
//		l1.sz();
		
		return 0;
		
		
		
}
