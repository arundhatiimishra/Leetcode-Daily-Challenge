/*
   Question Link - https://leetcode.com/problems/binary-search-tree-iterator/
   173. Binary Search Tree Iterator
*/

/*
   APPROACH-1
   Time Complexity - O(N) where N is number of Nodes 
   Space Complexity - O(N+h) where N is number of Nodes and h is height of tree
*/

class BSTIterator {
public:
    vector<int> v;
    int iterator=-1;
    
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    
    BSTIterator(TreeNode* root){
        inorder(root); 
    }
     
    int next(){
        iterator++;
        return v[iterator];  
    }
    
    bool hasNext(){
        if(iterator==v.size()-1){
            return false;
        }
        return true; 
    }
};

/*
   APPROACH-2
   Time Complexity - O(N) where N is number of Nodes 
   Space Complexity - O(h) where h is height of tree
*/

class BSTIterator {
public:
    stack<TreeNode*> st;
    
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        st.push(root);
        root=root->left;
        inorder(root);
    }
    
    BSTIterator(TreeNode* root){
        inorder(root); 
    }
     
    int next(){
        if(st.empty()==false){
            TreeNode* temp=st.top();
            st.pop();
            if(temp->right!=NULL){
                inorder(temp->right);
            } 
            return temp->val;
        }
        return -1;
    }
    
    bool hasNext(){
        if(st.empty()==true){
            return false;
        }
        return true;
    }
};