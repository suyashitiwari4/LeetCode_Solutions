class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=0;
        bool counting=false;
        for(char c:s){
            if(c!=' '){
                if(!counting){
                    counting=true;
                    length=1;
                }
                else{
                    length++;
                }
            }
            else{
                counting=false;
            }
        }
        return length;
    }
};