/*
   Question Link - https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
   581. Shortest Unsorted Continuous Subarray
*/

/*
   Time Complexity - O(N*log N) where N is size of vector nums
   Space Complexity - O(N) where N is size of vector nums
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums){
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        int start=-1;
        int end=-1;
        for(int i=0;i<nums.size();i++){
            if(start==-1 && nums[i]!=temp[i]){
                start=i;
            }
            if(nums[i]!=temp[i]){
                end=i;
            }
        }
        if(start==end){
            return 0;
        }
        return end+1-start;  
    }
};