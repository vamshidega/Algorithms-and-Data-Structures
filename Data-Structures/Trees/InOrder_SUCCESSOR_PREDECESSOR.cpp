






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


