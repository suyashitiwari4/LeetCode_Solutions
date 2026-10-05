class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> mp;
        unordered_map<char,int>charcount;
        int left=0;
        int maxocc=0;
       
        for(int right=0; right<s.size(); right++){
            charcount[s[right]]++;
            if(right-left+1>minSize){
                charcount[s[left]]--;
                if(charcount[s[left]]==0){
                    charcount.erase(s[left]);
                }
                left++;
            }
            if(right-left+1 ==minSize){
                if(charcount.size()<=maxLetters){
                    string sub=s.substr(left, minSize);
                    mp[sub]++;
                    maxocc=max(maxocc,mp[sub]);
                }
            }
        }
        return maxocc;

    }
};