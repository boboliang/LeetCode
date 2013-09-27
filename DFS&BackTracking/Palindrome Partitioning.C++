class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string>> result;
        vector<string> output;
        getPartition(result, output, 0, s);
        return result;
    }
    
    void getPartition(vector<vector<string>> &result, vector<string>& output, int start, string& s){
        if(start == s.size())
            result.push_back(output);
            
        for(int i = start; i < s.size(); ++i){
            if(isPalindrome(s, start, i)){
                output.push_back(s.substr(start, i - start +1));
                getPartition(result, output, i+1, s);
                output.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int start, int end){
        while(start < end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};