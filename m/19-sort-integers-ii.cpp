/*
https://www.lintcode.com/problem/sort-integers-ii/
Given an integer array, sort it in ascending order. Use quick sort, merge sort, heap sort or any O(nlogn) algorithm.
*/

class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) {
        //quickSort(A, 0, A.size() - 1);
        heapSort(A);
    }

private:
    void mergeSort(vector<int> &A, int lo, int hi) {
        if (lo >= hi) return;
        
        int mid = lo + (hi - lo) / 2;
        mergeSort(A, lo, mid);
        mergeSort(A, mid + 1, hi);
        merge(A, lo, mid, hi);
    }
    
    void merge(vector<int> &A, int lo, int mid, int hi) {
        int left = lo, right = mid + 1;
        int cnt = 0;
        vector<int> temp(hi - lo + 1);
        
        while(left <= mid && right <= hi) {
            if   (A[left] < A[right]) temp[cnt++] = A[left++];
            else temp[cnt++] = A[right++];
        }
        while (left <= mid) temp[cnt++] = A[left++];
        while (right <= hi) temp[cnt++] = A[right++];
        
        for (int i = 0; i < cnt; i++) {
            A[lo + i] = temp[i];
        }
    }
    
    void quickSort(vector<int> &A, int begin, int end) {
        if (begin >= end) return;
        
        int index = partition(A, begin, end);
        quickSort(A, begin, index - 1);
        quickSort(A, index + 1, end);
    }
    
    int partition(vector<int> &A, int begin, int end) {
        int k = begin;
        for (int i = begin; i < end; i++) {
            if (A[i] < A[end]) {
                exch(A, i, k);
                k++;
            }
        }
        exch(A, k, end);
        return k;
    }
    
    void heapSort(vector<int> &A) {
        int n = A.size();
        
        for (int i = n/2; i >= 1; i--) {
            sink(A, i, n);
        }
        
        for (int i = n; i > 0; i--) {
            exchForHeap(A, 1, i);
            sink(A, 1, i - 1);
        }
    }
    
    void sink(vector<int> &A, int k, int end) {
        while (2 * k <=  end) {
            int j = 2 * k;
            if (j < end && less(A, j, j + 1)) j++;
            if (less(A, k, j)) {
                exchForHeap(A, k, j);
                k = j;
            } else {
                break;
            }
        }
    }
    
    bool less(vector<int> &A, int i, int j) {
        return A[i-1] < A[j-1];
    }
    
    void exchForHeap(vector<int> &A, int i, int j) {
        int temp = A[i - 1];
        A[i - 1] = A[j - 1];
        A[j - 1] = temp;
    }
    
    void exch(vector<int> &A, int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
};