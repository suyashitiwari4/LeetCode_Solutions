class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxlen=0;
        int n=s.size();
        for(int target=1; target<=26;target++){
            unordered_map<char,int>freq;
            int left=0;
            int right=0;
            int uniqcount=0;
            int countk=0;
            while(right<n){
                char rchar=s[right];
                if(freq[rchar]==0){
                    uniqcount++;
                }
                freq[rchar]++;
                if(freq[rchar]==k){
                    countk++;
                }
                right++;
                while(uniqcount>target){
                    char lchar=s[left];
                    if(freq[lchar]==k){
                        countk--;
                    }
                    freq[lchar]--;
                    if(freq[lchar]==0){
                        uniqcount--;
                    }
                    left++;
                }
                if(uniqcount==target && uniqcount==countk){
                    maxlen=max(right-left,maxlen);
                }
            }

        }
        return maxlen;
    }
};