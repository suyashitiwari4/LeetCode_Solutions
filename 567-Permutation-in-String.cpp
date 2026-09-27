class Solution {
    

public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        vector<int> s1_count(26,0);
        vector<int> window_count(26,0);

        for(int i=0;i<s1.length();i++){
            s1_count[s1[i]-'a']++;
            window_count[s2[i]-'a']++;
            
        }
        if(s1_count==window_count) return true;
        int windowlen=s1.length();
        for(int i=windowlen;i<s2.length();i++){
            window_count[s2[i]-'a']++;
            int old_char=s2[i-windowlen];
            window_count[old_char-'a']--;
            if(s1_count==window_count) return true;
        }

      return false;
    }
};