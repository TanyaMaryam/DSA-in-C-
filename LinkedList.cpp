#include <iostream>
using namespace std;
template <class L> class list;
template <class T> class node
{
	T info;
	node<T>* next;
	public:
		node(T a,node<T>* n=0){
			info=a;
			next=n;
		}
	friend class list<T>;
};
template <class L> class list
{
	node<L>* head;             
	node<L>* tail;
	public:
	list(){
		head=0;
		tail=0;
	}
	L add_to_head(L a);
	L add_to_tail(L a);
	void del_head();
	void del_tail();
	L add_to_pos(L a,int pos);
	void del_from_pos(int pos);
	void display();
};
template <class L>L list<L>::add_to_head(L a)
{
	if(head==0)                            
	{
		head=tail=new node<L> (a);       
		//As there is only one node ,so head and tail will be same and will have only info part
	}
	else
	head= new node<L> (a,head);  //new head will point to previous node	
}
template <class L>L list<L>::add_to_tail(L a)
{
	if(tail==0)                            
	{
		tail=head=new node<L> (a);       
		//As there is only one node ,so head and tail will be same and will have only info part
	}
	else                                 //  _   _(t)
	tail -> next = new node<L> (a);      //  _   _(t) ->   _(new node)
	tail=tail -> next;  	             //  _   _   _(t)
}
template <class L>void list<L>::del_head()
{
	if (head==0)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		node<L>* temp=head;                        // _(temp)   _      _
		head = head -> next;                       // _         _(h)   _
		delete temp;                               //           _(h)   _	
	}                              
}
template <class L>void list<L>::del_tail()
{
	if (tail==0)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	if (tail==head)
	{
		tail=head=0;
		return;
	}
	node<L>* temp =head;                  // _(temp)    _         _(t)     
	node<L>* prevn;                       
	while(temp -> next!= 0)
	{
		prevn=temp;                       // _(prevn)   _(temp)   _(t)      
		temp= temp-> next;                // _          _(prevn)  _(temp & t)
	}
	delete temp;                          // _          _(prevn) 
	prevn -> next=0;                      // _          _(prevn)-> null
	tail = prevn;                         // _          _(t)
}
template <class L> L list<L>::add_to_pos(L a,int pos)
{   /*cout<<"Enter the info and position where you want to insert node : "<<endl;
	int pos,info;
    cin>>info>>pos;*/
	if (pos==1){
		add_to_head(a);
		return 0;
	}
	node<L>* temp=head;
	if (temp == 0){
		return 0;
	}
	int cur=1;
	while (cur<pos-1 && temp!= 0)
	{
		temp=temp -> next;
		cur++;
	}
	temp ->next = new node<L> (a,temp -> next);
}
template <class L>void list<L>::del_from_pos(int pos)
{
	if (pos==1)
	{
		del_head();
	}
	else
	{
		int cur=1;
		node<L>* temp=head;
		node<L>* prevn;
		while (cur<pos)
		{
			prevn=temp;
			temp=temp->next;
			cur++;
		}
		if (temp==tail)
		{
			del_tail();
		}
		prevn -> next = temp -> next;
		delete temp;
	}	
}
template <class L>void list<L>::display()
{
	node<L>* temp = head;
	cout<<"Info present in list is :"<<endl;
	while (temp!=0){
		cout<<temp -> info<<endl;
		temp=temp ->next;
	}
}
int main()
{
	list<int> m;
	cout<<"----------MENU-----------"<<endl;
	cout<<"1. Add to head."<<endl;
	cout<<"2. Add to tail."<<endl;
	cout<<"3. Add at position."<<endl;
	cout<<"4. Delete head."<<endl;
	cout<<"5. Delete tail."<<endl;
	cout<<"6. Delete at position."<<endl;
	int choice;
	
	char ch;
	do
	{
		cout<<"Enter Choice:"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:{
				int a;
				cout<<"Enter info you want to insert at head : "<<endl;
	            cin>>a;
            	m.add_to_head(a);
            	m.display();
				break;
			}
			case 2:{
				int b;
				cout<<"Enter info you want to insert at tail : "<<endl;
	            cin>>b;
             	m.add_to_tail(b);
             	m.display();
				break;
			}
			case 3:{
				int info,pos;
				cout<<"Enter the info and position where you want to insert node : "<<endl;
				cin>>info>>pos;
				m.add_to_pos(info,pos);
				m.display();
				break;
			}
			case 4:{
				cout<<"Deleting head :"<<endl;
				m.del_head();
				m.display();
				break;
			}
			case 5:{
				cout<<"Deleting tail :"<<endl;
				m.del_tail();
				m.display();
				break;
			}
			case 6:{
			    cout<<"Enter the position from where you want to delete node :"<<endl;
	            int pos;
	            cin>>pos;
	            m.del_from_pos(pos);
	            m.display();
				break;
			}
			default:
				cout<<"Wrong choice"<<endl;
		}
		cout<<"Do you want to continue (Y or N) "<<endl;
		cin>>ch;
	}
	while(ch =='Y' || ch =='y');

}
