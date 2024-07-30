//AVL tree insertion and deletion 
#include<iostream>
#include<queue>
using namespace std;

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;	
}
template<class L>
class AVL;
template<class T>
class AVLnode
{
	public:
	AVLnode()  //constructor
	{
		left = right =parent= 0;
		height = 1;
	}
	AVLnode(const T& e) //parameterized constructor
 	{
 		el = e; left = 0; right = 0; height=1; parent=0;
 	}
	AVLnode *left,*right,*parent;
	int height;
	T el;
	friend class AVL<T>;
};

template<class L>
class AVL
{
	public:
		AVLnode<L>* root;
		AVL()
		{
			root=0;	
		}
		~AVL()
		{
			clear();	
		}
		void clear()
		{
			root=0;	
		}	
		bool isempty() const
		{
			return root==0;
		}
		
		AVLnode<L>* insert(AVLnode<L>* node,const L& data );
		void inorder(AVLnode<L> *p);
		void breadthFirst(); 
		AVLnode<L>* deleteNode(AVLnode<L>* node, int key);
		protected:
			int Height(AVLnode<L>*);
			AVLnode<L>* rightRotate(AVLnode<L>*);
			AVLnode<L>* leftRotate(AVLnode<L>*);
			AVLnode<L>* minValueNode(AVLnode<L>* node);
};


template<class L>
int AVL<L>::Height(AVLnode<L>* anode)
{
	if(anode==0)
		return 0;
	else
	{
		return anode->height;	
	}	
}

template<class L>
void AVL<L>::breadthFirst() 
{
 queue<AVLnode<L>*> Queue;
 AVLnode<L> *p = root;
 if (p != 0) 
 {
 //	cout<<"\npush in queue "<<p->el;
 	Queue.push(p);
 	while (!Queue.empty()) 
	{
 		p = Queue.front();
 	//	cout<<"\npop from queue "<<p->el;
 		Queue.pop();
 		cout<<p->el<<" ";
 		if (p->left != 0)
 		{	
 	//		cout<<"\npush in left of "<<p->el;
 			Queue.push(p->left);
 		}
 		if (p->right != 0)
 		{
 	//		cout<<"\npush in right of "<<p->el;
 			Queue.push(p->right);
 		}
 	}
 }
 else
 {
 	cout<<"\ntree is empty";
 }
}

template<class L>
AVLnode<L>* AVL<L>::rightRotate(AVLnode<L>* torotate)
{
	cout<<"\nright rotation";
	AVLnode<L>* node=torotate->left;
	if(torotate->left!=0)
	{
		torotate->left=node->right;
		if(node->right!=0)
		{
			node->right->parent=torotate;
		}
		node->parent=torotate->parent;
		if(torotate->parent==0) //torotate is root
			root=node;
		else if(torotate==torotate->parent->left) //left child
		{
			torotate->parent->left=node;
		}
		else //right child
		{
			torotate->parent->right=node;	
		}	
  		node->right=torotate;
  		torotate->parent=node;
  	
  		torotate->height=1+max(Height(torotate->left),Height(torotate->right));
  		node->height=1+max(Height(node->left),Height(node->right));
  	}
  	cout<<"\nroot: "<<root->el;
  	return node; 
}

template<class L>
AVLnode<L>* AVL<L>::leftRotate(AVLnode<L>* torotate)
{
	cout<<"\nleft rotation";
	AVLnode<L> *node=torotate->right;
	if(torotate->right!=0)
	{
		torotate->right=node->left;
		if(node->left!=0)
		{
			node->left->parent=torotate;
		}
		node->parent=torotate->parent;
		if(torotate->parent==0)  //torotate is root
  			root=node;
  		else if(torotate==torotate->parent->left) //torotate is left child
		  	torotate->parent->left=node;
		else   //torotate is right child
			torotate->parent->right=node;
		node->left=torotate;		  	
		torotate->parent=node;	
	
		torotate->height=1+max(Height(torotate->left),Height(torotate->right));
	  	node->height=1+max(Height(node->left),Height(node->right));
	}
	return node;		
}

template<class L>
AVLnode<L>* AVL<L>::insert(AVLnode<L>* node,const L& data)
{
	if(node==0)  
	{
		cout<<"\ninsert element "<<data;
		return new AVLnode<L>(data);
	}
	if(data<=node->el)  //insert in left subtree (find where to insert in left)
	{
		cout<<"\ninsert in left "<<data;
		node->left=insert(node->left,data);	
		node->left->parent=node;
	}
	else  //insert in right subtree(find where to insert in right)
	{
		cout<<"\ninsert in right "<<data;
		node->right=insert(node->right,data);
		node->right->parent=node;	
	}
	// balancing , balance factor= height at right - height at left
	node->height=1+max(Height(node->left),Height(node->right));
	
	int balance=Height(node->right)-Height(node->left);	
	cout<<"\nbalance of node "<<node->el<<" = "<<balance;
	cout<<"\nprint: ";
	inorder(root);
	AVLnode<L>* q;
	if(balance>1)  //height is larger at right side or insertion took place in right subtree of node having bal +2
	{
		//Fig 6.41 case
		q=node->right;
		if(Height(q->left)<=Height(q->right))//q balance factor is +1
		{
			cout<<"\nLeft rotate node(P)";
			return leftRotate(node);   
		}
		//fig 6.42 case
		else //q balance factor is -1
		{
			
			cout<<"\nRL rotate";
			node->right=rightRotate(q); 
			return leftRotate(node);
		}
	}
	if(balance<-1)  //height is larger at left side or P's balancing factor is -2
	{
		//symmetric to fig 6.41 right changed to left and left changed to right:case 3
		q=node->left;
		if(Height(q->left) >= Height(q->right))  //height in left node of left is larger so rotate to right
		{
			cout<<"\nRight rotate node(p)";
			return rightRotate(node);               
		}
		//symmetric to fig 6.42 right changed to left and left changed to right:case 4
		else
		{
			//LR rotation double rotation
			cout<<"\nLR rotate";
			node->left=leftRotate(q);  
			return rightRotate(node);      
		}
	}
	return node;
}
template<class L>
AVLnode<L>* AVL<L>:: minValueNode(AVLnode<L>* node)  
{  
    AVLnode<L>* current = node;  
  
    //loop down to find the leftmost leaf 
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}

template<class L>
AVLnode<L>* AVL<L>::deleteNode(AVLnode<L>* node, int key)  
{  
     AVLnode<L>* q;  
    if (node == NULL)  
        return node;   
    if ( key < node->el )  
        node->left = deleteNode(node->left, key);   
    else if( key > node->el )  
        node->right = deleteNode(node->right, key);   
    else
    {   //node with one or no child
        if( (node->left == NULL) || (node->right == NULL) )  
        { 
			AVLnode<L>* temp;
			if(node->left!=0) 
            	temp=node->left; 
            else	
                temp=node->right; 
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = node;  
                node = NULL;  
            }  
            else // One child case  
            *node = *temp; // Copy the contents of the non-empty child  
            delete temp;  
        }  
        else
        {  
            // node with two children: Get the inorder successor (smallest in the right subtree)  
            AVLnode<L>* temp = minValueNode(node->right);  
  
            // Copy the inorder successor's data to this node  
            node->el = temp->el;  
  
            // Delete the inorder successor  
            node->right = deleteNode(node->right,temp->el);  
        }  
    }  
  
    // If the tree had only one node then return  
    if (node == NULL)  
    	return node;  
  
 	// balancing , balance factor= height at right - height at left
	node->height = 1 + max (Height(node->left), Height(node->right));
	
	int balance = Height(node->right) - Height(node->left);	
	cout<<"\nbalance of node "<<node->el<<" = "<<balance;
	cout<<"\nprint: ";
	inorder(node);
	//Mansi: deletion from left subtree..so all 4 cases demonstrated in fig 6.45
	if(balance>1)  //height is larger at right side 
	{
		q=node->right;
		if(Height(q->left)<=Height(q->right))//Mansi: cases 6.45 a to c and 6.45 d to f left rotate at P
		{
			cout<<"\nRR rotate";
			return leftRotate(node);   
		}
		else	//Mansi: cases 6.45 g to i and 6.45 j to l Right rotate and then left rotate
		{
			
			cout<<"\nRL rotate";
			node->right=rightRotate(node->right); 
			return leftRotate(node);
		}
	}
	//Mansi: deletion from right subtree..so all 4 cases symmetric to fig 6.45
	if(balance<-1)  //height is larger at left side
	{
		//Mansi: cases symmetric to 6.45 a to c and 6.45 d to f right rotate at P
		q=node->left;
		if(Height(q->left)>=Height(q->right))  //height in left node of left is larger so rotate to right
		{
			cout<<"\nLL rotate";
			return rightRotate(node);               
		}
		else
		{
			//Mansi: cases symmetric to 6.45 g to i and 6.45 j to l - left exchanged with right 
			cout<<"\nLR rotate";
			node->left=leftRotate(node->left);  
			return rightRotate(node);      
		}
	}
	return node;
}



template<class L>
void AVL<L>::inorder(AVLnode<L> *p) //with recursion (left node right)
{
 if (p != 0) 
 {
 	inorder(p->left);
 	cout<<p->el<<" ";
 	inorder(p->right);
 }
} 

int main()
{
	AVL<int> t;
	//LL
/*	t.root=t.insert(t.root,20);
	t.insert(t.root,10);
	t.insert(t.root,30);
	t.insert(t.root,8);
	t.insert(t.root,12);
	t.insert(t.root,5);
	t.insert(t.root,9);
*/
	//RR	
/*	t.root=t.insert(t.root,50);
	t.insert(t.root,60);
	t.insert(t.root,40);
	t.insert(t.root,55);
	t.insert(t.root,65);
	t.insert(t.root,62);
	t.insert(t.root,69);
*/	
	//LR
/*	t.root=t.insert(t.root,20);
	t.insert(t.root,10);
	t.insert(t.root,15);
*/
	//RL
/*	t.root=t.insert(t.root,50);
	t.insert(t.root,30);
	t.insert(t.root,20);

	cout<<"\nprint: ";
	t.breadthFirst();
	cout<<"\n now deleting";
	t.deleteNode(t.root,20);
	cout<<"\nafter deleting 20 tree now is: ";
	t.breadthFirst();
*/	
	int ele;
	cout<<"\nEnter first element to be as root : ";
	cin>>ele;
	t.root=t.insert(t.root,ele);	
	int n;
	do
	{
		cout<<"\n\t\t..........menu..........";
		cout<<"\n\t\t1.insert";
		cout<<"\n\t\t2.delete";
		cout<<"\n\t\t3.breadth first print";
		cout<<"\n\t\t4.exit";
		cout<<"\nenter your choice(1-4): ";
		cin>>n;
		switch(n)
		{
			case 1:{	cout<<"\nenter element you want to enter: ";
						cin>>ele;
						t.insert(t.root,ele);	
						break;
					}
			case 2:{	cout<<"\nenter element you want to delete: ";
						cin>>ele;
						t.deleteNode(t.root,ele);
						break;
					}
			case 3:{	t.breadthFirst();
						break;
					}				
			case 4:{	cout<<"\nquiting...";
						break;
					}
			default:{	cout<<"wrong choice";
						break;
					}						
		}
	}while(n!=4);
		
	return 0;
}
