class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;
        vector<string> rows(min(numRows, (int)s.length()));
        int row = 0;
        bool goingDown = false;
        for (char ch : s) {
            rows[row] += ch;
            if (row == 0 || row == numRows - 1) {
                goingDown = !goingDown; 
            }
            row += goingDown ? 1 : -1; 
        }
        string result;
        for (string &r : rows) {
            result += r;
        }
        return result;
    }
};
