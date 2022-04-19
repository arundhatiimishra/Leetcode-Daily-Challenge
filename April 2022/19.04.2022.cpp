/*
   Question Link - https://leetcode.com/problems/recover-binary-search-tree/
   99. Recover Binary Search Tree
*/

/*
   APPROACH-1
   Time Complexity - O(N(log N)) where N is number of Nodes 
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
    
    void changeTree(TreeNode* root,vector<int> &v,int &idx){
        if(root==NULL){
            return;
        }
        changeTree(root->left,v,idx);
        if(v[idx]!=root->val){
            root->val=v[idx];
        }
        idx++;
        changeTree(root->right,v,idx);
    }
    
    void recoverTree(TreeNode* root){
        inorderPrint(root);
        vector<int> temp=v;
        sort(v.begin(),v.end());
        int idx=0;
        changeTree(root,v,idx);
        return;
    }
};

/*
   APPROACH-2
   Time Complexity - O(N+h) where N is number of Nodes 
   Space Complexity - O(h) where h is height of tree
*/

class Solution {
public:
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prevNode;
    
    void inorderPrint(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorderPrint(root->left);
        if(first!=NULL && second!=NULL){
            if(root->val<=second->val){
                second=root;
                long long firstVal=first->val;
                first->val=second->val;
                second->val=firstVal;
            }else{
                if(root->val>first->val && second->val<first->val){
                    long long firstVal=first->val;
                    first->val=second->val;
                    second->val=firstVal;
                }else if(root->val<first->val && second->val<first->val){
                    second=root;
                }
            }
        }
        if(prevNode->val>root->val){
            first=prevNode;
            second=root;
        }
        prevNode=root;
        inorderPrint(root->right);
    }
    
    void recoverTree(TreeNode* root){
        prevNode=new TreeNode(INT_MIN);
        inorderPrint(root);
        if(first->val>second->val){
            long long firstVal=first->val;
            first->val=second->val;
            second->val=firstVal; 
        }
        return;
    }
};