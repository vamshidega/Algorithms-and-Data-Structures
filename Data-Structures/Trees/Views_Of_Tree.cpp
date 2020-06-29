/* All Views of the binary Tree - Top view , Left Side view, Right side view, Bottom view 
*
*
*
*/









/********************** Top View Of the Binary Tree ********************/

   void topView(Node * root) {
        std::multimap<int,int> umap;
        std::multimap<int,int>::iterator it,itr;
        std::set<int> uset;
        
        std::queue<int> hdq;
        std::queue<Node*> ndq;

        int parent_hd = 0;
        int left_child_hd = 0, right_child_hd = 0;
        ndq.push(root);
        hdq.push(parent_hd);
        while(!ndq.empty())
        {
            parent_hd = hdq.front();
            umap.insert(std::make_pair(parent_hd,root->data));
            uset.insert(parent_hd);
                       
            if(root->left)
            {
                left_child_hd = hdq.front()-1; 
                ndq.push(root->left);
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
            root=ndq.front();
            
        } 
     
        std::set<int>::iterator str;
        for(str=uset.begin();str!=uset.end();str++)
        {
            itr = umap.lower_bound(*str);
            std::cout<<itr->second<<" ";
        }
    }
