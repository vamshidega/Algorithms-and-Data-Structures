/* All Views of the binary Tree - Top view , Left Side view, Right side view, Bottom view 
*
*
*
*/


/********************** TOP VIEW ********************/
/*
Top View is Vertical Order Traversal + Level Order Traversal
- Mark the HD(Horizontal Distance) for each node - root is '0' , left = parent -1, right = parent +1
- same like level order traversal - Enqueue the root, also enqueue HD of the element. Also create a map with <HD,node->data>
- While poping root, Enqueue child HD and childs.

*/

   void topView(Node * root) {
        // map to store the <hd,data> pair
        std::multimap<int,int> umap;
        std::multimap<int,int>::iterator it,itr;
        std::set<int> uset;
        
        //Q to store the hd
        std::queue<int> hdq;
       //Q to store the node
        std::queue<Node*> ndq;

        int parent_hd = 0;
        int left_child_hd = 0, right_child_hd = 0;
         //Push root and its HD
        ndq.push(root);
        hdq.push(parent_hd);
      
        while(!ndq.empty())
        {
           //Access the front element HD - which 
            parent_hd = hdq.front();
           // Add hd, root_data to map
            umap.insert(std::make_pair(parent_hd,root->data));
           //Add the hd to set - since we have the same key with multiple values in the multimap.
           // So set will have the unique key values - later we will search the set key in the map to find the lowest/highest values
            uset.insert(parent_hd);
                       
            if(root->left)
            {
                left_child_hd = hdq.front()-1; 
                ndq.push(root->left); // Add child Hd , Child node
                hdq.push(left_child_hd);
            }
            if(root->right)
            {
                right_child_hd = hdq.front()+1; 
                ndq.push(root->right);
                hdq.push(right_child_hd);

            }
            ndq.pop();
            hdq.pop();
            root=ndq.front(); // Set root to front  
            
        } 
     
         //Traverse through the Set and find the lower element in the map
        std::set<int>::iterator str;
        for(str=uset.begin();str!=uset.end();str++)
        {
            itr = umap.lower_bound(*str);
            std::cout<<itr->second<<" ";
        }
    }
