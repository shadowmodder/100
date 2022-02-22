/*
https://www.lintcode.com/problem/sort-colors-ii/description
Given an array of n objects with k different colors (numbered from 1 to k), sort them so that objects of the same color are adjacent, with the colors in the order 1, 2, ... k.

Example
Given colors=[3, 2, 2, 1, 4], k=4, your code should sort colors in-place to [1, 2, 2, 3, 4].

*/

/*
In sortRange, each time, it put two min/max colors into correct position.
In the second exchange, do not forget to recover cur index. ie.cur--.
exch(colors, cur--, right--);
*/

class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        
        //sortRange(colors, 1, k, 0, colors.size() - 1);
        //paritionSort(colors, 1, k, 0, colors.size() - 1);
    }
    
private:
    void sortRange(vector<int> & colors, int leftColor,
                                         int rightColor,
                                         int start, int end)
    {
        if (start >= end) return;
        
        int left = start, right = end;
        for (int cur = start; cur <= right; cur++) {
            if (colors[cur] == leftColor) {
                exch(colors, cur, left++);
            }
            if (colors[cur] == rightColor) {
                exch(colors, cur--, right--); // cur need minus one
            }
        }
        sortRange(colors, ++leftColor, --rightColor, left, right);
    }
  
   void paritionSort(vector<int>& colors, int colorFrom,
                                          int colorTo,
                                          int start,
                                          int end) {
                                              
        if (colorFrom == colorTo) return;                                      
                                              
        int lo = start, hi = end; 
        int mid = (colorFrom +colorTo) / 2;
        while (lo <= hi) {
            while (lo <= hi && colors[lo] <= mid) {
                lo++;
            }
            
            while (lo <= hi && colors[hi] > mid) {
                hi--;
            }
            
            if (lo < hi) {
                exch (colors, lo, hi);
                lo++;
                hi--;
            }
        }
        paritionSort(colors, colorFrom, mid, start, hi);
        paritionSort(colors, mid + 1, colorTo, hi + 1, end);
    }
   
    void exch(vector<int> & colors, int i, int j) {
        int temp = colors[i];
        colors[i] = colors[j];
        colors[j] = temp;
    }
};