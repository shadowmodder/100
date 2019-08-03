/*
There are n people in the party and only one or 0 Celebrity.
 The Celebrity does not know others. All others know ceberity.  There's a api
 knows(x, y) to check whether x knows y and return 1.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findCelebrity(int n) {
        int c = 0;
        for (int j = 1; j < n; j++) {
            if (!knows(j, c)) c = j;
        }

        for (int j = 0; j < n; j++) {
            if (j != c && knows(c , j)) return -1;
            if (j != c && !knows(j, c)) return -1;
        }

        return c;
    }
};