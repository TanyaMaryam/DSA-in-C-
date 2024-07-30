//Queue LL
#include<iostream>
using namespace std;
template<class L>
class Queue;

template<class T> 
class Node{    
	T info;
	Node<T>* next;
		
	public:
	Node(T a,Node<T> *n=0){
		info = a;
		next = n;
	}
	
friend class Queue<T>;	
};

template<class L>
class Queue{  
    Node<L>* rear;                     
	
	public:
	Queue(){
	rear=0;
	}
	
	
	//enqueue add to tail
	void enqueue(L a){                    
	Node<L>* temp=new Node<L>(a);
	if(rear==0){
		temp->next=temp;
		rear=temp;
		return;
	  }
	temp->next=rear->next;
	rear->next=temp;
	rear=temp;	
   }
   
   
   //dequeue delete from tail
    L dequeue(){                  // deleting the 1st ,                                                         
	if(rear==0)                     // the element after the cursor
	{
		cout<<"QUEUE UNDERFLOW !!!\n";
		return 0  ;
	}
	L ele=rear->next->info;
	
	if(rear->next==rear)
	{
		Node<L> *temp=rear;
		rear=0;
		delete temp;
		return ele;
	}
    Node<L> *temp=rear->next;
    rear->next=temp->next;
    delete temp; 
    
    return ele;
    }

   
    bool empty(){
	if(rear==NULL)
	  return true;
	else 
	  return false;

	} 
	
	
	
    void display(){
   	Node<L> *current=rear->next;
	while(current!=rear){
		cout<<current->info<<"  ";
		current=current->next;
	}
	cout<<rear->info<<"  ";
	cout<<endl;
	}
		
};










/*int main()
{
    Queue<int> q1;
	q1.dequeue();
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	q1.enqueue(6);
	q1.enqueue(7);
	q1.enqueue(8);
	q1.enqueue(9);
	q1.dequeue();
	q1.dequeue();
	q1.dequeue();
	q1.dequeue();
	q1.enqueue(7);
	q1.enqueue(8);
	q1.enqueue(9);
	q1.enqueue(10);
	q1.enqueue(11);
	q1.display();
return 0;	
}*/

