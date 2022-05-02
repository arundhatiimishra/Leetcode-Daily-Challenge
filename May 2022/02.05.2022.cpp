/*
   Question Link - https://leetcode.com/problems/sort-array-by-parity/
   905. Sort Array By Parity
*/

/*
   APPROACH-1
   Time Complexity - O(N) where N is size of vector nums
   Space Complexity - O(N) where N is size of vector ans
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums){
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                ans.push_back(nums[i]);
            }  
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                ans.push_back(nums[i]);
            }  
        }
        return ans;
    }
};

/*
   APPROACH-2
   Time Complexity - O(N) where N is size of vector nums
   Space Complexity - O(1)
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums){
        int ptr1=0;
        int ptr2=0;
        while(true){
            if(ptr1==nums.size()||ptr2==nums.size()){
                break;
            }
            if(nums[ptr1]%2!=0 && nums[ptr2]%2==0){
                int temp=nums[ptr1];
                nums[ptr1]=nums[ptr2];
                nums[ptr2]=temp;
                ptr2++;
                ptr1++;
            }else if(nums[ptr1]%2!=0 && nums[ptr2]%2!=0){
                ptr2++;
            }else if(nums[ptr1]%2==0 && nums[ptr2]%2==0){
                ptr1++;
                ptr2++;
            }else{
                ptr1++;
            }
        }
        return nums;
    }
};