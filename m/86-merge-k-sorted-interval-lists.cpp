/*
Merge K sorted interval lists into one sorted interval list. 
You need to merge overlapping intervals too.
Example
Given
[
  [[1,3],[4,7],[6,8]],
  [[1,2],[9,10]]
]
Return

[[1,3],[4,8],[9,10]]
https://www.lintcode.com/problem/merge-k-sorted-interval-lists/description
*/


/**
 * Definition of Interval:
 * */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Interval {
public:
      int start, end;
      Interval(int start, int end) {
          this->start = start;
          this->end = end;
      }
 };
 
 /*
   put first interval into priority queue, key is start time
   if pq is not empty, pop first one.
   while pq not empty
      pop second one
      if (two overlapped)
        first = merge(first, second)
      else 
        put first  into results
    put first into results
    return results
 */

class Solution {
public:
    /**
     * @param intervals: the given k sorted interval lists
     * @return:  the new sorted interval list
     */
    vector<Interval> mergeKSortedIntervalLists(vector<vector<Interval>> &intervals) {
        vector<Interval> results;

        auto cmp = [](IntervalNode &lhs, IntervalNode &rhs) {
            if (lhs.start == rhs.start) return lhs.end > rhs.end;
            return lhs.start > rhs.start;
        };

        priority_queue<IntervalNode, vector<IntervalNode>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].size() > 0) {
                pq.push(IntervalNode(intervals[i][0].start, intervals[i][0].end, i, 0));
            }
        }

        IntervalNode first = pq.top();
        pq.pop();

        if (first.index + 1 < intervals[first.row].size()) {
            pq.push(IntervalNode(intervals[first.row][first.index + 1].start,
                                 intervals[first.row][first.index + 1].end,
                                 first.row, first.index + 1));
        }

        while (!pq.empty()) {
            IntervalNode second = pq.top();
            pq.pop();
            if (second.index + 1 < intervals[second.row].size()) {
                pq.push(IntervalNode(intervals[second.row][second.index + 1].start,
                                    intervals[second.row][second.index + 1].end,
                                     second.row, second.index + 1));
            }

            if (isOverlapped(first, second)) {
                first = merge(first, second);
            } else {
                results.push_back(Interval(first.start, first.end));
                first = second;
            }
        }

        results.push_back(Interval(first.start, first.end));
        return results;
    }
private:
    struct IntervalNode {
        int start;
        int end;
        int row;
        int index;
        IntervalNode(int start, int end, int row, int idx) {
            this->start = start;
            this->end   = end;
            this->row   = row;
            this->index = idx;
        }
    };

    bool isOverlapped(IntervalNode &lhs, IntervalNode &rhs) {
        return !(lhs.end < rhs.start || lhs.start > rhs.end);
    }

    IntervalNode merge(IntervalNode &lhs, IntervalNode &rhs) {
        IntervalNode ans(lhs.start, lhs.end, 0, 0);
        ans.start = lhs.start < rhs.start ? lhs.start :rhs.start;
        ans.end = lhs.end > rhs.end ? lhs.end :rhs.end;
        return ans;
    }
};

int main() {
    vector<vector<Interval>> testCase = {{Interval(1, 3), Interval(4, 7), Interval(6, 8)},
                                         {Interval(1, 2), Interval(9, 10)}};
    Solution *s = new Solution();
    vector<Interval> result = s->mergeKSortedIntervalLists(testCase);
    for (auto& e: result) {
        cout << "["<< e.start << "," << e.end <<"]" << " ";
    }

    return 0;
}