class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int currsum=0;
        unordered_map<int,int>prefix_map;
        prefix_map[0]=1;// base case
        for(int i: nums){
            currsum+=i;
            if(prefix_map.find(currsum-k)!=prefix_map.end()){
                count+=prefix_map[currsum-k];
            }
            prefix_map[currsum]++;

        }
        return count;
    }
};