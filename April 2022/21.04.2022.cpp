/*
   Question Link - https://leetcode.com/problems/design-hashset/
   705. Design HashSet
*/

/*
   APPROACH-1
   Time Complexity - O(N) for each function
   Space Complexity - O(N) 
*/

class MyHashSet {
public:
    vector<int> v;
    
    MyHashSet(){
        
    }
    
    void add(int key){
        if(contains(key)==false){
            v.push_back(key);
        }
    }
    
    void remove(int key){
        int idx=-1;
        for(int i=0;i<v.size();i++){
            if(v[i]==key){
                idx=i;
                break;
            }
        }
        if(idx!=-1){
            v[idx]=v[v.size()-1];
            v.pop_back(); 
        } 
    }
    
    bool contains(int key){
        bool found_key=false;
        for(int i=0;i<v.size();i++){
            if(v[i]==key){
                found_key=true;
                break;
            }
        }
        return found_key;
    }
};

/*
   APPROACH-2
   Time Complexity - O(1) for each function
   Space Complexity - O(N)
*/

class MyHashSet {
public:
    vector<int> v;
    
    MyHashSet(){
        v.resize(1000001,0);
    }
    
    void add(int key){
        v[key]=1;
    }
    
    void remove(int key){
        v[key]=0;
    }
    
    bool contains(int key){
        if(v[key]==1){
            return true;
        }
        return false;
    }
};
