/*
   Question Link - https://leetcode.com/problems/increasing-order-search-tree/
*/

/*
   APPROACH-1
   Time Complexity - O(N) where N is number of Nodes 
   Space Complexity - O(N+h) where N is number of Nodes and h is height of tree
*/

class Solution {
public:
    vector<TreeNode*> v;
    TreeNode* rootToReturn;
    
    void inorderPrint(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorderPrint(root->left);
        v.push_back(root);
        inorderPrint(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root){
        inorderPrint(root);
        rootToReturn=v[0];
        for(int i=0;i<v.size();i++){
            v[i]->left=NULL;
            if(i==v.size()-1){
                v[i]->right=NULL;
            }else{
                v[i]->right=v[i+1];
            }
        }
        return rootToReturn;
    }
};

/*
   APPROACH-2
   Time Complexity - O(N) where N is number of Nodes 
   Space Complexity - O(h) where h is height of tree
*/

class Solution {
public:
    TreeNode* curr=new TreeNode(0);
    
    void changeTree(TreeNode* root){
        if(root==NULL){
            return;
        }
        changeTree(root->left);
        root->left=NULL;
        curr->right=root;
        curr=root;
        changeTree(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy=curr;
        changeTree(root);
        return dummy->right; 
    }
};