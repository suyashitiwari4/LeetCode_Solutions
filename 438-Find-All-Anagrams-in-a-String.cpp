class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length()>s.length()) return {};
        vector<int>freq(26,0);
        vector<int>window(26,0);
        for(int i=0 ;i<p.length();i++){
            freq[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        vector<int>ans;
        if(freq==window)ans.push_back(0);
        for(int i=p.length();i<s.length();i++){
            window[s[i-p.length()]-'a']--;
            window[s[i]-'a']++;
            if(freq==window) ans.push_back(i-p.size()+1);

        }

         return ans;
        
    }
};