#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

    //Public Methods to avoid client user to think about
    //underlying design of each methods
    void insertNode(int data);
    //void deleteNode(int data);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    node* b_search(int data);
    void destroy_tree();
    node* minimumValueofBtree();

private:
    void insertNode(int data, node *leaf);
    //void deleteNode(int data, node * leaf);
    void inorderTraversal(node * leaf);
    void preorderTraversal(node * leaf);
    void postorderTraversal(node * leaf);
    node *b_search(int data, node * leaf);
    void destroy_tree(node *leaf);
    node* minimumValueofBtree(node *leaf);

    node *root;
};


BinaryTree::BinaryTree():root(nullptr){
}

BinaryTree::~BinaryTree(){
    destroy_tree();
}

void BinaryTree::insertNode(int data)
{
    if(root != NULL){
        insertNode(data,root);
    }
    else{
        root = new node;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    }
}

void BinaryTree::insertNode(int data , node* leaf)
{
    if(data < leaf->data){
        if(leaf->left != NULL)
        {
            insertNode(data,leaf->left);
        }
        else{
            leaf->left = new node;
            leaf->left->data = data;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    }else if( data >= leaf->data) {
        if(leaf->right != NULL){
            insertNode(data,leaf->right);
        }
        else{
            leaf->right = new node;
            leaf->right->data = data;
            leaf->right->right = nullptr;
            leaf->right->left = nullptr;
        }

    }
}


void BinaryTree::inorderTraversal()
{
    cout<<"\nInorder Traversal ";
    inorderTraversal(root);
}

void BinaryTree::inorderTraversal(node *leaf)
{

    if(leaf != NULL)
    {
        inorderTraversal(leaf->left);
        cout<<leaf->data<<" , ";
        inorderTraversal(leaf->right);
    }
}

void BinaryTree::preorderTraversal()
{
    cout<<"\nPre order Traversal ";
    preorderTraversal(root);
}

void BinaryTree::preorderTraversal(node *leaf)
{

    if(leaf != NULL)
    {
        cout<<leaf->data<<" , ";
        preorderTraversal(leaf->left);
        preorderTraversal(leaf->right);

    }
}

void BinaryTree::postorderTraversal()
{
    cout<<"\nPost order Traversal ";
    postorderTraversal(root);
}

void BinaryTree::postorderTraversal(node *leaf)
{
    if(leaf != NULL)
    {
        postorderTraversal(leaf->left);
        postorderTraversal(leaf->right);
        cout<<leaf->data<<" , ";
    }
}

node* BinaryTree::b_search(int data)
{
    return b_search(data , root);
}

node* BinaryTree::b_search(int data , node * leaf)
{
    if(leaf != NULL)
    {
        if(data == leaf->data)
        {
            return leaf;
        }
        if(data < leaf->data)
        {
            return b_search(data, leaf->left);
        }
        else{
            return b_search(data , leaf->right);
        }
    }
    else{
        return NULL;
    }
}

void BinaryTree::destroy_tree()
{
    destroy_tree(root);
}

void BinaryTree::destroy_tree(node *leaf)
{
    if(leaf != NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}
node* BinaryTree::minimumValueofBtree()
{
    minimumValueofBtree(root);
}

node* BinaryTree::minimumValueofBtree(node* leaf)
{
    if(leaf != NULL)
    {
        node* current = leaf;
        while(current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
}
int main()
{
    BinaryTree *btree = new BinaryTree();
    int data;
    char choice;
    while(choice != 'n')
    {
        cout<<"Provide Binary tree data value ";
        cin>>data;
        btree->insertNode(data);
        cout<<"\nDo you want to continue , if not press n ";
        cin>>choice;
    }

    btree->inorderTraversal();
    btree->preorderTraversal();
    btree->postorderTraversal();
    cout<<endl;
    int searching_var;
    cout<<"\nSearch Value in Binary tree , provide data ";
    cin>>searching_var;
    node* n1 = btree->b_search(searching_var);
    if(n1)
        cout<<"\nData is present in BST "<<endl;
    else
        cout<<"\nData is not present in BST "<<endl;

    node *n2 = btree->minimumValueofBtree();
    cout<<"\nMinimum value from Binary Tree is "<<n2->data;

    cout<<"\nDestroying Binary tree now ";
    btree->destroy_tree();
    if(!btree)
        cout<<"\nBinary Tree is cleaned up "<<endl;
}
