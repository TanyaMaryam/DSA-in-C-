/* Singly Linked List 5104_Tanya Maryam
Implement foll. functions:
1. Add to front
2. Add to rear
3. Add to a particular position
4. Delete from the front, rear, and from a position
*/
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
	node<L>* front; // front pointer |  add no.of obj   |   collection of obj = 1 list
	node<L>* rear;
	public:
		list(){
			front =0;
			rear=0;
		}
		
		//add to front
		void addhead(L a){
			if(front==0){
				front=rear=new node<L>(a);
				return;
			}
			front= new node<L>(a,front);
		}
		
		
		//add to rear
		void addtail(L a){	
			if(rear==0){
				front=rear=new node<L>(a);   //when no nodes are in List...Boundary condition
				return;
			}
			rear->next = new node<L>(a,0);
			rear = rear->next;
		}
		
		//add to position
		void addpos(L a,int pos){
			if(pos==1){
        	addhead(a);
  	        return;
        }
            if(front==0){
  	        cout<<"ERROR !!!\n";
  	        return;
        }
       node<L> *current=front;
       int count=1;
       while(current!=0){
       	if(count==(pos-1)){	
  	        current->next=new node<L>(a,current->next);
	        return;	
       }
       current=current->next;
       count+=1;
       }
       if(count==pos){
  	      addtail(a);
  	      return;
       }
       cout<<"ERROR !!!\n";
    }

		
		
		//delete front
		void deletehead(){
			if(front==0){
				rear=0;
				return;
			}
			node<L>* tempt = front;
			/*tempt */ front = front-> next;
			delete tempt; /*front*/
		//	front=tempt;
		}
		
		
		// delete rear
		void deletetail(){
			if (rear==0){
				front=0;
				return;
			}
			node<L>* tempt= front;
			while(tempt->next->next!=0)
			tempt = tempt->next;
		    
		    node<L>* temptail= tempt->next;
		    rear = tempt;
		    tempt->next=0;
		    delete temptail;
		}
		
		//delete at position
	   void deletepos(int pos){
		if(front==0) {
        	cout<<"ERROR !!!\n";
    	    return;
	   }
       	if(pos==1)	{
	    	deletehead();
	    	return;
	   }
	   node<L> *current=front;
    	int count=1;
	    while(current!=0){
		if(count==(pos-1))
		{
			node<L> *temp=current->next;
			current->next=current->next->next;
			delete temp;
			return;
		}
		current=current->next;
		count+=1;
	}
	cout<<"ERROR !!!\n";
}

		
		//display
		void display(){
			node<L>* temp= front;
			while(temp!=0){
				cout<<temp->info<<" ";
				temp=temp->next;
			}
		}
};


int main(){
	list<int>l1;   //list 1 create 
	l1.addhead(10);
	l1.addhead(5);
	l1.addhead(1);
	l1.addtail(15);
	l1.addtail(20);
	l1.addtail(25);
//	l1.deletehead();
	l1.deletetail();
	l1.addpos(30,6);
    l1.addpos(3,2);
    l1.addpos(5,5);
    l1.deletepos(5);
	l1.display();
	
	
}   
