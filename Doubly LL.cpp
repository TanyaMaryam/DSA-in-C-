/* Doubly Linked List 5104_Tanya Maryam
Implement fowlloing. functions:
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
	
		//add to front
		void addhead(L a){
			if(front==0){
				front=rear=new node<L>(a);
				return;
			}
			front->prev = new node<L>(a,front,0);
			front=front->prev;
		}	
		
			//add to rear
		void addtail(L a){	
			if(rear==0){
				front=rear=new node<L>(a);   //when no nodes are in List...Boundary condition
				return;
			}
			rear->next = new node<L>(a,0,rear);
			rear = rear->next;
		}
		
			//add to position
		void addpos(L a,int pos){
			if(pos==1){
        	addhead(a);
  	        return;
        }
            if(pos==0){
  	        cout<<"ERROR !!!\n";
  	        return;
        }
       node<L> *current=front;
       int count=1;
       while(current!=0){
       	if(count==(pos-1)){	
  	        current->next = new node<L>(a,current->next,current);
	        return;	
       }
       current=current->next;
       count+=1;
       }
       if(pos==count){
  	      addtail(a);
  	      return;
       }
       //cout<<"ERROR !!!\n";
    }
    
    
    	//delete front
		void deletehead(){
			if(front==0){
				rear=0;
				return;
			}
			node<L>* tempt = front;
			/*tempt */ front = front-> next;
			front->prev=0;
			delete tempt;
		    /*front*/
		//	front=tempt;
		}
		
		// delete rear
		void deletetail(){
			if (rear==0){
				front=0;
				return;
			}
            node<L>* tempt= front;
			while(tempt->next->next!=0){
			tempt = tempt->next;
	     	}
		   node<L>* temptail= tempt->next;
		    rear = temptail->prev;
		    rear->next=0;
		    delete temptail;  
		    
		   /* node<L>* temptail= tempt->next;
		    rear = tempt;
		    tempt->next=0;
		    delete temptail;*/
		}
		
			//delete at position
	   void deletepos(int pos){
		if(pos==0) {
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
			node<L> *tempt=current->next;
		//	current->next = tempt->next;
		//	tempt->next= current->next;
			tempt->prev->next = tempt->next;
			tempt->next->prev = tempt->prev;
		//	current->next=current->next->next;
			delete tempt;
			return;
		}
		current=current->next;
		count+=1;
	}
//	cout<<"ERROR !!!\n";
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
		
		void concat(){
			node<L>* temp= front;
			while(temp!=0){
				cout<<temp->info<<" ";
				temp=temp->next;
			}
		}
};

int main(){
		list<int>l1;
		list<int>l2;
		l1.addhead(20);
		l1.addhead(10);
		l1.addpos(5,2);
		l1.addpos(4,4);
		l1.addpos(6,3);
		l1.addpos(7,4);
		l1.deletehead();
	//	l1.deletetail();
	    l1.deletepos(3);
		l1.display();
		
		l2.addhead(200);
		l2.addhead(100);
		l2.addtail(300);
		l2.display();
		cout<<"The Concatinate List is given below:-"<<endl;
		l1.concat();
		l2.concat();
	
}
