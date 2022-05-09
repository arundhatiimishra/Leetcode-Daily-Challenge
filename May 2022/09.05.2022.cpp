/*
   Question Link - https://leetcode.com/problems/letter-combinations-of-a-phone-number/
   17. Letter Combinations of a Phone Number
*/

/*
   APPROACH-1
   Time Complexity - O(N) where N is size of string digits
   Space Complexity - O(1)
*/

class Solution {
public:
    vector<string> mera_vector;
    
    void helper(vector<string> &temp,string otp,string digits,int idx){
        if(idx==digits.size()){
            if(otp!=""){
                mera_vector.push_back(otp);   
            }
            return;
        }
        string now=temp[(int)digits[idx]-48];
        for(int i=0;i<now.size();i++){
            helper(temp,otp+now[i],digits,idx+1);
        }  
    }

    vector<string> letterCombinations(string digits){
        vector<string> temp;
        temp.push_back("");
        temp.push_back("");
        temp.push_back("abc");
        temp.push_back("def");
        temp.push_back("ghi");
        temp.push_back("jkl");
        temp.push_back("mno");
        temp.push_back("pqrs");
        temp.push_back("tuv");
        temp.push_back("wxyz"); 
        helper(temp,"",digits,0);
        return mera_vector;
    }
};