
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> bracketMap = {{')', '('}, {']', '['}, {'}', '{'}};
        for (char ch : s) {
            if (bracketMap.count(ch)) {
                if (stk.empty() || stk.top() != bracketMap[ch]) {
                    return false; 
                }
                stk.pop();
            } else {
                stk.push(ch); 
            }
        }
        return stk.empty(); 
    }
};
