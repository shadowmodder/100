/*
Merge two sorted (ascending) lists of interval and return it as a new sorted list. The new sorted list should be made by splicing together the intervals of the two lists and sorted in ascending order.
https://www.lintcode.com/problem/merge-two-sorted-interval-lists/description
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param list1: one of the given list
     * @param list2: another list
     * @return: the new sorted list of interval
     */
     
     /*
     1. which one is selected to merge?
     2. Using a last to remember to last one merged
     3. do not forget the end case.
     */
    vector<Interval> mergeTwoInterval(vector<Interval> &list1, vector<Interval> &list2) {
        if (list1.size() == 0) return list2;
        if (list2.size() == 0) return list1;
        
        vector<Interval> results;
        
        Interval last(-1, -1), cur;
        int i = 0, j = 0;
        while (i < list1.size() && j < list2.size()) {
            if (list1[i].start < list2[j].start) {
                cur = list1[i++];
            } else {
                cur = list2[j++];
            }
            
            last = merge(results, last, cur);
        }
        
        while (i < list1.size()) {
            last = merge(results, last, list1[i++]);
        }
        while (j < list2.size()) {
            last = merge(results, last, list2[j++]);
        }
        
        results.push_back(last);
        
        return results;
    }
    
private:

    Interval merge(vector<Interval> &results, Interval& last, Interval & cur) {
        if (last.start == -1) return cur;
        
        if (isCross(last, cur)) {
            last.start = last.start < cur.start ? last.start :cur.start;
            last.end   = last.end   < cur.end   ? cur.end :last.end;
        } else {
            results.push_back(last);
            last = cur;
        }
        
        return last;
    }
    
    bool isCross(Interval v, Interval w) {
        return !(v.end < w.start || w.end < v.start);
    }
};