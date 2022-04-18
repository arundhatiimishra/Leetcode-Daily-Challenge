/*
   Question Link - https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
   1038. Binary Search Tree to Greater Sum Tree
*/

/*
   Time Complexity - O(N) where N is number of Nodes 
   Space Complexity - O(N)
*/

class Solution {
public:
    void convert(TreeNode* root,int &sum){
        if(root==NULL){
            return;
        }
        convert(root->right,sum);
        sum=sum+root->val;
        root->val=sum;
        convert(root->left,sum);  
    }
    
    TreeNode* convertBST(TreeNode* root){
        int sum=0;
        convert(root,sum);
        return root;
    }
};
