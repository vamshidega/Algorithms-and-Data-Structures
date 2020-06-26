/* Problems on the Print root to all leaf nodes
*
* Program to Print all paths from root to leaf nodes.
* 
*/


#include<iostream>
#include<stdio.h>
#include<queue>
#include<stack>
using namespace std;

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}Node;

Node* Create_Node(Node** root,int data)
{
	(*root) = new Node;
	(*root)->left = NULL;
	(*root)->right = NULL;
	(*root)->data = data;
	return *root;
}


/****************Insert the Node in to BST********************/
Node* Insert(Node* root, int data)
{
	if(root == NULL)
	{
		root = Create_Node(&root,data);
		return root;
	}
	else if(data < root->data)
		root->left = Insert(root->left,data);
	
	else if(data > root->data)
		root->right = Insert(root->right,data);
	
	return root;
}



/*************** Print root to leaf nodes *********************/

std::stack<int> node_data;

/** Printing the stack in the bottom up fashion by using the recursion**/
void print_stack(std::stack<int> node)
{
    if(node.empty()) return;
    //access the top 
    int data = node.top();
    //pop top 
    node.pop();
    //keep poping until reaches the bottom element
    print_stack(node);
    //now print the element then push it back.
    std::cout<<data<<" ";
    // preserve the stack by pushing back
    node.push(data);   
}

/*This is same as the Inorder traversal.
* LDR -  go left - then root - then right
*/
void print_path(Node* root)
{
    if(root == NULL) return;
    //first visit the node and push to the stack
    node_data.push(root->data);
    //then go left until the leaf node
    print_path(root->left);
    //if it is the leaf node print the stack - other function does the printing
    if(root->left == NULL && root->right==NULL){
    print_stack(node_data);
    std::cout<<endl;
    }
    //then go right side
    print_path(root->right);
    //to back trace pop the last leaf element from the stack
    node_data.pop();
}

int main()
{
	Node* root = NULL;
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,13);
	root = Insert(root,17);
	root = Insert(root,29);
	root = Insert(root,23);
	root = Insert(root,24);
	root = Insert(root,22);
	PrintTree(root);
	std::cout<<endl;
	PrintTree(root);
	std::cout<<endl;
	print_path(root);

	return 0;
}
