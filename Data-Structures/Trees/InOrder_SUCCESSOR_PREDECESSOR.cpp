/**
In Order successor and Predecessor

Solution 1: Visit all the nodes in inorder traversal and store in an array and find the successor/Predecessor.
Find the node in the array - immediate high value is the successor and immediate low value is the predecessor.

Time complexity for Inorder traversal is O(n) - n is the number of nodes.
-------------------------------------------------------------------------------
Any query operation in a BST can be done in O(h) - h is the height of the tree
-------------------------------------------------------------------------------


Solution 2: Finding the Successor in O(h)
CASE1: Given node has a right Subtree - then left most value or the minimum value in the right subtree is the Successor.

CASE2: Given node has no right Subtree
        The Nearest ancestor for which given node would be in left subtree is the successor
        in other words - deepest ancestor node for which the left turn is taken is the successor.

vice versa for predecessor node.
**/



/******************* InOrder Successor of a Node **************************/

Node* GetSuccessor(Node* root, int data)
{
    //Search the data Node
    Node* current = Find(root,data);
    
    //CASE1: node has right subtree - find the minimum Element
    if(current->right!=NULL)
        return FindMin(current->right);
    
    //CASE2: Node has no right sub Tree
    else
    {
        Node* successor = NULL;
        Node* ancestor = root;
        
        while(current != ancestor)
        {
            if(current->data < ancestor->data)
            {   //So it is the deepest ancestor is the successor
                // the node where the last left turn is taken is the successor
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}

/**************** Inorder Predecessor of a node ***************/

Node* GetPredecessor(Node* root, int data)
{
    //Search for the node
    Node* current = Find(root,data);
    
    //CASE1: Node has a left tree - Right most node or Max Node is the Predecessor
    if(current->left!=NULL)
            return FindMax(current->left);
            
    //CASE2: Node has no left tree - deepest ancestor for which given node in right subtree
    //the node where the last right turn is taken is the Predecessor
    else{
        Node* predecessor = NULL;
        Node* ancestor = root;
        while (current != ancestor)
        {
            if(current->data > ancestor->data)
            {
                predecessor = ancestor;
                ancestor = ancestor->right;
            }
            else
                ancestor = ancestor->left;
        }
        return predecessor;
    }
    
}


