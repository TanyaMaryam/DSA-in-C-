//Circular Linked List
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
		
		
		//add to front 
		void addfront(L a){
	node<L>* temp=new node<L>(a);
	if(rear==0){
		temp->next=temp;
		rear=temp;
		return;
	  }
	temp->next=rear->next;
	rear->next=temp;
    }

    // add to back
    void addback(L a){
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
    
    // add after element
   void addelem(L a,L b){
	node<L> *current=rear->next;
	while(current->next!=rear->next){
		if(b==current->info){
			current->next=new node<L>(a,current->next);
			return;
		}
		if(b==rear->info){
			addback(a);
		}
		current=current->next;
    	}
   }

    // delete from front
    void deletefront(){
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
	
	//delete from back
	void deleteback(){
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
	
   node<L> *current=rear->next;
   while(current->next!=rear->next){
	  if(current->next==rear)	{
    	  node<L> *temp=rear;
		  current->next=rear->next;
		  rear=current;
		  delete temp;
		  return;
	    }
	  current=current->next;
     }   
		
	}
	
	//delete after element
	void deleteelem(int pos){
		 if(rear==0){
    	cout<<"ERROR !!!\n";
    	return;
	    }
	if(pos==1){
		deletefront();
		return;
	  }
	node<L> *current=rear->next;
	int count=1;
	while(current->next!=rear->next){
		if(count==(pos-1))	{
			node<L> *temp=current->next;
			current->next=temp->next;
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
		l1.addfront(30);
		l1.addfront(20);
		l1.addfront(10);
		l1.addback(40);
		l1.addback(50);
	//	l1.deleteback();
	//	l1.deletefront();
    //	l1.addelem(15,10);
    //   l1.deleteelem(3);
		l1.display();;
		return 0;
	}
	
	
	
    
    
    
    
    
    
