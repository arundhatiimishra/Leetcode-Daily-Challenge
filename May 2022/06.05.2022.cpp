/*
   Question Link - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
   1209. Remove All Adjacent Duplicates in String II  
*/

/*
   APPROACH-1
   Time Complexity - O(N*log N) where N size of string s 
   Space Complexity - O(N) where N is size of string s
*/

class Solution {
public:
    string removeDuplicates(string s, int k){
        stack<pair<char,int>> st;
        for(int i=0;i<s.size();i++){
            if(st.empty()==false && st.top().first==s[i]){
                st.top().second=st.top().second+1;
                if(st.top().second==k){
                    st.pop();
                }
            }else{
                st.push(make_pair(s[i],1));
            }
        }
        string answer="";
        while(st.empty()==false){
            for(int i=1;i<=st.top().second;i++){
                answer+=st.top().first;
            }
            st.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};

/*
   APPROACH-2
   Time Complexity - O(N) where N is size of string s 
   Space Complexity - O(N) where N is size of string s
*/

class Solution {
public:
    string removeDuplicates(string s, int k){
        vector<pair<char,int>> st;
        for(int i=0;i<s.size();i++){
            if(st.empty()==false && st[st.size()-1].first==s[i]){
                st[st.size()-1].second=st[st.size()-1].second+1;
                if(st[st.size()-1].second==k){
                    st.pop_back();
                }
            }else{
                st.push_back(make_pair(s[i],1));
            }
        }
        string answer="";
        for(int i=0;i<st.size();i++){
            for(int j=1;j<=st[i].second;j++){
                answer+=st[i].first;
            }
        }
        return answer;
    }
};