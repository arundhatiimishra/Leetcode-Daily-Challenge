/*
   Question Link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/
   230. Kth Smallest Element in a BST 
*/

/*
   APPROACH-1
   Time Complexity - O(N) where N is number of Nodes 
   Space Complexity - O(N+h) where N is number of Nodes and h is height of tree
*/

class Solution {
public:
    vector<int> v;
    
    void inorderPrint(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorderPrint(root->left);
        v.push_back(root->val);
        inorderPrint(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k){
        inorderPrint(root);
        return v[k-1];
    }
};

/*
   APPROACH-2
   Time Complexity - O(N) where N is number of Nodes 
   Space Complexity - O(h) where h is height of tree
*/

class Solution {
public:
    int answer=-1;
    
    void findKthSmallest(TreeNode* root,int &k){
        if(root==NULL){
            return;
        }
        findKthSmallest(root->left,k);
        k=k-1;
        if(k==0){
            answer=root->val;
        }
        findKthSmallest(root->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        findKthSmallest(root,k);
        return answer;   
    }
};
