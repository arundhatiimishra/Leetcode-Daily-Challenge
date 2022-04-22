/*
   Question Link - https://leetcode.com/problems/design-hashmap/
   706. Design HashMap
*/

/*
   APPROACH-1
   Time Complexity - O(N) for each function
   Space Complexity - O(N) 
*/

class MyHashMap {
public:
    vector<pair<int,int>> v;
    
    MyHashMap(){
        
    }
    
    void put(int key, int value){
        bool found=false;
        for(int i=0;i<v.size();i++){
            if(v[i].first==key){
                found=true;
                v[i].second=value;
                break;
            }
        }
        if(found==false){
            v.push_back(make_pair(key,value));
        }
    }
    
    int get(int key){
        for(int i=0;i<v.size();i++){
            if(v[i].first==key){
                return v[i].second;
            }
        }
        return -1; 
    }
    
    void remove(int key){
        int idx=-1;
        for(int i=0;i<v.size();i++){
            if(v[i].first==key){
                idx=i;
                break;
            } 
        }
        if(idx!=-1){
            v[idx].first=v[v.size()-1].first;
            v[idx].second=v[v.size()-1].second;
            v.pop_back();
        }
    }
};

/*
   APPROACH-2
   Time Complexity - O(1) for each function
   Space Complexity - O(N)
*/

class MyHashMap {
public:
    vector<int> v;
    
    MyHashMap(){
        v.resize(1000001,-1);
    }
    
    void put(int key, int value){
        v[key]=value;
    }
    
    int get(int key){
        return v[key];
    }
    
    void remove(int key){
        v[key]=-1;
    }
};