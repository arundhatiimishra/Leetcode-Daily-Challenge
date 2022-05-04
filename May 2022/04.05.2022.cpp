/*
   Question Link - https://leetcode.com/problems/max-number-of-k-sum-pairs/
   1679. Max Number of K-Sum Pairs
*/

/*
   Time Complexity - O(N*log N) where N is size of vector nums
   Space Complexity - O(1)
*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k){
        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums.size()-1;
        int count=0;
        while(start<end){
            if(nums[start]+nums[end]==k){
                count++;
                start++;
                end--;
            }else if(nums[start]+nums[end]<k){
                start++;
            }else{
                end--;
            }
        }
        return count;
    }
};