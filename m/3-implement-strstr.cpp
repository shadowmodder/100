/*
https://www.lintcode.com/problem/implement-strstr/description

*/For a given source string and a target string, you should output the first index(from 0) of target string in source string.

If target does not exist in source, just return -1.

Example
If source = "source" and target = "target", return -1.

If source = "abcdabcdefg" and target = "bcd", return 1.
*/

class Solution {
public:
    /*
     * @param source: source string to be scanned.
     * @param target: target string containing the sequence of characters to match
     * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
     */
    int strStr(const char *source, const char *target) {
        if (source == NULL || target == NULL) return -1;
        
        int slen = strlen(source);
        int tlen = strlen(target);
        if (slen < tlen) return -1;
        if (tlen == 0) return 0;

        for (int s = 0; s < slen; s++) {
            int t;
            for (t = 0; t < tlen; t++) {
                if (source[s + t] != target[t])
                    break;
            }
            if (t == tlen)
               return s;
        }
        
        return -1;
    }
};