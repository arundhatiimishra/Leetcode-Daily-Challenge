/*
   Question Link - https://leetcode.com/problems/132-pattern/
   456. 132 Pattern
*/

/*
   APPROACH-1
   Time Complexity - O(N^3) where N is size of vector nums
   Space Complexity - O(1) 
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums){
        if(nums.size()<3){
            return false;
        }
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[j]>nums[i] && nums[j]>nums[k] && nums[k]>nums[i]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

/*
   APPROACH-2
   Time Complexity - O(N^2) where N is size of vector nums
   Space Complexity - O(1)
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums){
        if(nums.size()<3){
            return false;
        }
        int minTillNow=INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]>minTillNow && nums[i]>nums[j] && nums[j]>minTillNow){
                    return true;
                }    
            }
            minTillNow=min(minTillNow,nums[i]);
        }
        return false;
    }
};

/*
   APPROACH-3
   Time Complexity - O(N) where N is size of vector nums
   Space Complexity - O(N) where N is size of vector nums
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums){
        int num3=INT_MIN;
        vector<int> temp; //acting as a stack
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<num3){
                return true;
            }
            while(temp.empty()==false && nums[i]>temp[temp.size()-1]){
                num3=temp[temp.size()-1];
                temp.pop_back();
            }
            temp.push_back(nums[i]);
        }
        return false;
    }
};