// R_BST insertion Recursive LL

//#include "Queue.h"
//#include "Stacks.h"
#include<iostream>
using namespace std;
template<class L>
class R_BST;

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
friend class R_BST<T>; //  class ke private memebers i.e info and left or right koh acess krskey in Stack class

};

template<class L>
class R_BST{
	TNode<L>* root; // root pointer 
	TNode<L> *p= root; 
	TNode<L> *prev = 0; 
	public:
		R_BST(){
			root = 0;
		}
		
		

	// Insertion 
      void R_insert(TNode<L> *p, TNode<L> *prev ,L el){
        while (p!=0){
        	if(el<p->info)
        	 return R_insert(p->left,p,el);
        	else
			 return R_insert(p->right,p,el);
		}
        
        if (root==0)
         root = new TNode<L>(el);
        else if(el<prev->info) // root ke element se small h.. root ke left me ayega
		    prev->left = new TNode<L>(el);
        else
		 prev->right = new TNode<L>(el); //root ke element se big h.. root ke right me 
}

     // Searching
		void R_search(TNode<L> *p ,L el){
		while(p!=0){
         	if(el==p->info){
         		cout<<"Element Found"<<endl;
         		return ;
			 }
			else if (el<p->info)
			  return R_search(p->left,el);
			else
			  return R_search(p->right,el);
		 }
		 cout<<"Element not Found"<<endl;
		 return;
         
		}
  



   //Preorder - NLR
   void R_Preorder(TNode<L> *p ){
   //	TNode<L> *p = root;
	if (p!=0){
	cout<<p->info<<" ";
	R_Preorder(p->left);
	R_Preorder(p->right);	
	}
   }   
    
 
 
 
  /*  // Inoreder - LNR
	void R_Inorder(){
	TNode<L>* p=root;
	if (p!=0){
	R_Inorder(p->left);
	cout<<p->info<<" ";
	R_Inorder(p->right);	
	}
  }
  
    //Postoreder - LRN
    void R_Postorder(){
    TNode<L>* p=root;
	if (p!=0){
	R_Postorder(p->left);
	R_Postorder(p->right);	
	cout<<p->info<<" ";
	}
	
}
    	
*/
};


int main(){
	R_BST<int>b1;
	b1.R_insert(13);
	b1.R_insert(10);
	b1.R_insert(25);
/*	b1.R_insert(20);
	b1.R_insert(31);
	b1.R_insert(12);
	b1.R_insert(2);
	b1.R_insert(3);
	b1.R_insert(29);
	b1.R_search(20);
*/	//b1.BreadthFirst();
	b1.R_Preorder();
//	b1.R_Inorder();
//	b1.R_Postorder();
	
return 0;
}
