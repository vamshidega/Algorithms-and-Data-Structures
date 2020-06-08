
/*************** BINARY SEARCH TREE OPERATIONS***************
* 1. Insert node
* 2. Delete a Node
* 3. Print tree in PreOrder
* 4. Print tree in Level Order
* 5. Find Min,Miax elements in the tree
*/

#include<iostream>
#include<stdio.h>
#include<queue>
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

/*****************Find Max Element In Tree***************/
Node* FindMax(Node* root)
{
	//Tree is empty
	if(root == NULL) return -1;
	
	while(root->right!=NULL)
        	root=root->right;
    	return root;
}

/*****************Find Min Element In Tree***************/
Node* FindMin(Node* root)
{
	//Tree is empty
	if(root == NULL) return -1;
	
	while(root->left!=NULL)
        	root=root->left;
    	return root;
}

/***************** Find a Node / Search for a node ********/
Node* Find(Node* root, int data)
{
    if(root==NULL) return 0;
    
    while(root->data!=data)
    {
        if(data < root->data) root = root->left;
        else root=root->right;
    }
    
    return root;
}

/****************** Delete a Node ************************/
Node* DeleteNode(Node* root, int data)
{
	if(root == NULL) return root;

	if(data < root->data)
		root->left = DeleteNode(root->left,data);
	else if(data > root->data)
		root->right = DeleteNode(root->right,data);

	else //Found the Node to be deleted
	{
		//Case 1: Node to be Deleted is a child node
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root=NULL;
		}

		//Case 2: Node to be Deleted has a right child node
		else if(root->left == NULL)
		{
			Node* temp = root;
			root = root->right;
			delete temp;

		}

		//Case 3: Node to be Deleted has a left child node
		else if(root->right == NULL)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}

		//Case 4: Node to be Deleted has a right and left child nodes / subtree
		else
		{
			Node* temp = FindMax(root->left); //Find Max value from left subtree / Min from right tree
			root->data = temp->data;
			root->left = DeleteNode(root->left,temp->data);
		}
	}
	return root;
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

/*****************Print Tree in PreOrder***********************/
void PrintTree(Node* root)
{
	if(root==NULL) return;
	std::cout<<root->data<<" ";
	PrintTree(root->left);
	PrintTree(root->right);
}
/********************* Print the Level Order Traversal of BST ************/
void LevelOrderTraversalBST(Node* root)
{
	std::queue<Node*> TreeQueue;
	TreeQueue.push(root);
	while(!TreeQueue.empty())
	{
		root = TreeQueue.front();
		std::cout<<TreeQueue.front()->data<<" ";
		if(root->left) TreeQueue.push(root->left);
		if(root->right) TreeQueue.push(root->right);
		TreeQueue.pop();
	}
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
	root = DeleteNode(root,23);
	std::cout<<endl;
	PrintTree(root);
	std::cout<<endl;

	return 0;
}

