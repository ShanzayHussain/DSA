class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (n == 0) return 0;

        // Compute LPS (Longest Prefix Suffix) array for needle
        vector<int> lps(n, 0);
        int len = 0, i = 1;
        while (i < n) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i++] = 0;
                }
            }
        }

        // KMP search in haystack
        i = 0; // index for haystack
        int j = 0; // index for needle
        while (i < m) {
            if (haystack[i] == needle[j]) {
                i++, j++;
            }
            if (j == n) return i - j; // Found match
            if (i < m && haystack[i] != needle[j]) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }

        return -1;
    }
};
