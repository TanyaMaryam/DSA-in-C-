/*
Implement Deletion in BST, 
Display the height of the BST, 
Search for an element x in the BST and change its value to y 
and then place the node with value y at its appropriate position in the BST
*/
#include <iostream>
using namespace std;

template <class L>
class BST;

template <class T>
class TNode
{
    TNode<T> *left;
    TNode<T> *right;
    T info;

public:
    TNode(T el)
    {
        left = 0;
        right = 0;
        info = el;
    }
    friend BST<T>;
};

template <class L>
class BST
{
    TNode<L> *root;

public:
    BST()
    {
        root = 0;
    }

    void insert(L el)
    {
        TNode<L> *p = root, *prev;
        
        if (root == 0)
        {
            root = new TNode<L>(el);
            return;
        }
        while (p != 0)
        {
            prev = p; // p is leading the way and stops one step before!
            if (el < p->info)
                p = p->left;
            else
                p = p->right;
        }
        
        if (el < prev->info)
            prev->left = new TNode<L>(el);
        else
            prev->right = new TNode<L>(el);
    }

    int Ht()
    {
        height(root); // since recursive so need to call once to pass root as its parameter
                      // as root is private cannot be accesed outside of function!
    }

    int height(TNode<L> *p)
    {
        if (p == 0)
            return 0;
        int a = height(p->right);
        int b = height(p->left);
        return a > b ? a + 1 : b + 1;
    }

    void findAndDelete(L el)
    { // finds the elements for deletion
        TNode<L> *node = root, *prev = 0;
        while (node != 0)
        {                         // finding the node
            if (node->info == el) // root
                break;

            prev = node; // updating prev
            if (el < node->info)
                node = node->left;
            else
                node = node->right;
        }

        if (node != 0 && el == node->info)
        {
            if (node == root)
            {
                deleteByMerging(root);
                //  deleteByCopying(root);
            }

            else if (prev->left == node)
            {
                deleteByMerging(prev->left);
                // deleteByCopying(prev->left);
            }

            else
            {
                deleteByMerging(prev->right);
                // deleteByCopying(prev->right);
            }
        }
        else if (root != 0)
            cout << "\n Element " << el << " is not Found\n";
        else
            cout << "Tree is Empty\n";
    }

    void deleteByCopying(TNode<L> *&node)
    {                                 // deletes the elements by copying then deleting
        TNode<L> *tmp = node, *prev1; // Note: maintaing two prev pointer
        if (node->right == 0)         // node has no right child
            node = node->left;
        else if (node->left == 0) // node has no left child
            node = node->right;
        else
        {                     // has both children
            tmp = node->left; // predecessor
            prev1 = node;
            while (tmp->right != 0)
            {
                prev1 = tmp;
                tmp = tmp->right; // reaching out for predecessor
            }
            node->info = tmp->info; // copying tmp data to nodes position
            if (prev1 == node)
                prev1->left = tmp->left;
            else
                prev1->right = tmp->left;
        }

        delete tmp;
    }

    void changePosition(L el, L elem)
    { // el- findNdelete, elem- merge
        findAndDelete(el);
        insert(elem);
    }

    void deleteByMerging(TNode<L> *&node)
    {
        TNode<L> *tmp = node; // node is to be deleted
        if (node != 0)
        {
            if (!node->right)
                node = node->left;
            else if (node->left == 0)
                node = node->right;
            else // two children are available
            {
                tmp = node->left;
                while (tmp->right != 0) // finding for predecessor
                    tmp = tmp->right;
                tmp->right = node->right;
                tmp = node;
                node = node->left; // making predecessor as new node
            }
            delete tmp;
        }
    }
};

int main()
{
    BST<int> b1;
    b1.insert(13);
    b1.insert(10);
    b1.insert(2);
    b1.insert(3);
    b1.insert(12);
    b1.insert(25);
    b1.insert(20);
    b1.insert(31);
    b1.insert(29);
    
    int h = b1.Ht();
    cout << "Before Deletion" << endl;
    cout << "Height of BST: " << h;
    
    b1.findAndDelete(31);
    cout << "\n\nAfter Deletion!" << endl;
    int h1 =  b1.Ht();
    cout<<"\n Height of BST: "<<h1;

    int e1, e2;
    cout << "\nEnter the element to be serched and changed : " << endl;
    cin >> e1;
    cout << "\nEnter the element to be replaced with :" << endl;
    cin >> e2;

   /* b1.changePosition(e1, e2);
    int h2 = b1.Ht();
    cout<<"Height of BST: "<<h2;
*/
    //b1.findAndDelete(96);
    //  int h3 = b1.height();
    //    cout<<"Height of BST: "<<h3;

    return 0;
}
