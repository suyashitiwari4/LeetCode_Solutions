class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Min-heap storing pair<count, element>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;

        for (auto& [num, count] : freq) {
            minheap.push({count, num});
            if (minheap.size() > k) {
                minheap.pop(); // Keeps only top k elements in the heap
            }
        }

        vector<int> ans;
        while (!minheap.empty()) {
            ans.push_back(minheap.top().second);
            minheap.pop();
        }

        return ans;
    }
};