/*
   Question Link - https://leetcode.com/problems/encode-and-decode-tinyurl/
   535. Encode and Decode TinyURL
*/

/*
   Time Complexity - O(1) for both the functions
   Space Complexity - O(N) 
*/

class Solution {
public:
    unordered_map<string,string> mp;
    int number=0;
    
    string encode(string longUrl){
        string temp="http://tinyurl.com/"+to_string(number);
        mp[temp]=longUrl;
        number++;
        return temp;
    }

    string decode(string shortUrl){
        return mp[shortUrl];
    }
};
