/*
   Question Link - https://leetcode.com/problems/backspace-string-compare/
   844. Backspace String Compare 
*/

/*
   APPROACH-1
   Time Complexity - O(N) where N is max of size of string s and size of string t
   Space Complexity - O(N) where N is size of stack
*/

class Solution {
public:
    bool backspaceCompare(string s,string t){
        stack<char> st;
        stack<char> tt;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(st.empty()==false){
                    st.pop();    
                }
            }else{
                st.push(s[i]);
            }
        }
        for(int i=0;i<t.size();i++){
            if(t[i]=='#'){
                if(tt.empty()==false){
                    tt.pop();    
                } 
            }else{
                tt.push(t[i]);
            }
        }
        if(st==tt){
            return true;
        }
        return false;
    }
};

/*
   APPROACH-2
   Time Complexity - O(N) where N is max of size of string s and size of string t
   Space Complexity - O(1)
*/

class Solution {
public:
    bool backspaceCompare(string s, string t){
        string s1="";
        string t1="";
        int count_hash=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='#'){
                count_hash++;
                continue;
            }else if(count_hash!=0){
                count_hash--;
                continue;
            }else{
                s1=s[i]+s1;
            }
        }
        count_hash=0;
        for(int i=t.size()-1;i>=0;i--){
            if(t[i]=='#'){
                count_hash++;
                continue;
            }else if(count_hash!=0){
                count_hash--;
                continue;
            }else{
                t1=t[i]+t1;
            }
        }
        if(s1==t1){
            return true;
        }
        return false; 
    }
};