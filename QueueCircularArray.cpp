//Circular Queue using array
#include<iostream>
using namespace std;
# define size 100
template <class Q>
class Queue{
	Q *arr;
   int front,rear,n; // n = no. of element
	
	public:
		Queue(){
		arr= new int[size];// arr created with size
		front = -1;
		rear = -1;
		n = 0;
		}
		
		//display the size of the queue
	int sz(){
			cout<<n;
			return n ;  // return no. of elements
		}
		
		//enqueue = adding element at the end
		void enqueue(Q e){
				if(n==size){
		cout<<"Queue is full"<<endl;
		return;
	   }
	  else if(front==-1){
		front=(front+1)%size;
		rear=(rear+1)%size;
		arr[rear]=e;
		n++;
    	}
	      else{
	    rear=(rear+1)%size;
		arr[rear]=e;
		n++;
	  }
	}
		
		//dequeue = deleting element from starting
		void dequeue(){
			if(n=0){ //front==rear
				cout<<"Queue is empty"<<endl;
				return;
			}
			
		arr[front]=0;
		front=(front+1)%size;
		n--;
		}
		
		
		//display
		void display(){
			if(front==-1 && rear==-1){
		cout<<"Queue is empty"<<endl;
		return;
    	}
	        else if(rear>=front){
		for(int i=front; i<=rear; i++){
			cout<<"Elements = "<<arr[i]<<endl;
		}
		cout<<endl;
     }
    }
};

int main(){
	Queue<int>q;
	cout<<"Enqueue the elemnt"<<endl;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.display();
	
	cout<<"Dequeue the element"<<endl;
    q.dequeue();
	q.display();
	
	cout<<"Size of Array"<<endl;
	q.sz();
	return 0 ;
}
 
