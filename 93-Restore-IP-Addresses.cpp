class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>result;
        if(s.length()<4 || s.length()>12) return result;
        backtrack(s,0,0,"",result);
        return result;
       
    }
private: 
    void backtrack(string& s, int start, int dots, string currentIP, vector<string>& result){
        if(dots == 4){
            if(start == s.length()){
                currentIP.pop_back();
                result.push_back(currentIP);
            }
            return;
        }
        for(int len=1; len<=3; ++len){
            if(start+len>s.length()) break;
            string segment = s.substr(start,len);
            if(len>1 && segment[0]=='0')break;
            int val = stoi(segment);
            if(val>255)break;
            backtrack(s,start+len,dots+1, currentIP+ segment+".",result);
        }
    }
};