struct comp {
   
    bool operator()(pair<int,int> l,pair<int,int> r) 
    {
        return l.second<r.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> p;
        unordered_map<int,int> ump;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ump[nums[i]]++;
        }
        for(auto i:ump){
            p.push(i);
        }
        for(int i=0;i<k;i++){
            result.push_back(p.top().first);
            p.pop();
        }
        return result;
    }
};
