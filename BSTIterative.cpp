// BST insertion iterative LL

#include "Queue.h"
#include "Stacks.h"
//#include<iostream>
//using namespace std;
template<class L>
class BST;

template <class T>
class TNode {
	T info;
     TNode<T>* left;
     TNode<T>* right;
     public:
     TNode(T a, TNode<T>* l=0, TNode<T>*r=0 ){
     		info=a;
     		left = l;
     		right = r;
		 }
friend class BST<T>; //  class ke private memebers i.e info and left or right koh acess krskey in Stack class

};

template<class L>
class BST{
	TNode<L>* root; // root pointer 
	public:
		BST(){
			root = 0;
		}
		
		

	// Insertion 
        void insert(L el){
         if (root == 0){ // tree is empty;
        root = new TNode<L>(el);
        return ;
        }
        
		TNode<L> *p = root, *prev = 0;
        while (p != 0) { // find a place for inserting new ;
			prev = p;
            if (el < p->info)
             p = p->left;
            else p = p->right;
           }
        
         if (el < prev->info) // root ke element se small h root ke left me ayega
        prev->left = new TNode<L>(el);
        else
		 prev->right = new TNode<L>(el); //root ke element se big h root ke right me ayega
}

     // Searching
		void search(L el){
		TNode<L>*p = root;
			if (root==0){
				cout<<"Tree doesn't exist"<<endl;
			}
			while(p!=0){
				if (el==p->info){
					cout<<"Element found"<<endl;
					return;
				}
				else if (el<p->info){
					p=p->left;
				}
				else
				p= p->right;
			}
			cout<<"Element not found"<<endl;
		}
  
    // Breadth-First
    
	void BreadthFirst(){   
     if(root==NULL){
    	cout<<"Tree doesn't exist!!\n";
    	return;
	} 
	cout<<"BREADTH FIRST TRAVERSAL"<<endl;
    Queue<TNode<L>*> q;
 
   TNode<L>* p=root;
	q.enqueue(p);
	
	while(!q.empty())	
	{
		TNode<L>* temp = q.dequeue ();
		cout<<temp->info<<" ";
		
		if(temp->left)
		   q.enqueue(temp->left);
		if(temp->right)
		   q.enqueue(temp->right);
		   	     
	}	
	cout<<endl;
} 



   //Preorder
   void Preorder(){   
    if(root==NULL){
    	cout<<"Tree doesn't exist!!\n";
    	return;
	}
	
	cout<<"PREORDER TRAVERSAL"<<endl;
    Stack<TNode<L>*> s;
    
	TNode<L>* current=root;
	s.push(current);
	
	while(!s.empty()){
		TNode<L>* temp=s.pop();
		cout<<temp->info<<" ";
		
		if(temp->right)
		   s.push(temp->right);
		if(temp->left)
		   s.push(temp->left);
		   	     
	}
	cout<<endl;	
 }	
 
 
 
 
 
    // Inoreder
	void Inorder(){
	   if(root==NULL){
    	cout<<"Tree doesn't exist!!\n";
    	return;
	}
	
	cout<<"IN-ORDER TRAVERSAL"<<endl;
    Stack<TNode<L>*> s;
    
    TNode<L>* current=root;
    
     while(current!=NULL||!s.empty()){
    	while(current!=NULL){
    		s.push(current);
    		current=current->left;
		}
		current=s.pop();	
		cout<<current->info<<" ";
		current=current->right;
       }
    cout<<endl;
  }
  
    //Postoreder
    void Postorder(){
	if(root==NULL){
    	cout<<"Tree doesn't exist!!\n";
    	return;
	}
	
	cout<<"POST-ORDER TRAVERSAL"<<endl;
    Stack<TNode<L>*> s;
    
    TNode<L>* current=root;
    TNode<L>* displayed=root;
    
    while(current!=0){
    	for(  ; current->left!=0 ; current=current->left)
    	    s.push(current);
    	    
    	while(current->right==0||current->right==displayed){
			cout<<current->info<<" ";
			displayed=current;
			
			if(s.empty())
			  return;
			  
			current=s.pop();
	    }  
	    
	    s.push(current);
	    current=current->right;	 
	}
	cout<<endl;	
}
    	

};


int main(){
	BST<int>b1;
	b1.insert(13);               
	b1.insert(10);               
	b1.insert(25);              
	b1.insert(20);        
	b1.insert(31); 
	b1.insert(12);
	b1.insert(2);
	b1.insert(3);
	b1.insert(29);
	b1.BreadthFirst();
	b1.Preorder();
	b1.Inorder();
	b1.Postorder();
	
return 0;
}

/*
 insert
           13
        /     \
       10      25
      / \    /   \
    2   12   20  31
     \           /
     3          29
     
*/   
     
