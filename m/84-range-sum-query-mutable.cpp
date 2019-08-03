/*
https://www.lintcode.com/problem/range-sum-query-mutable/description
Fenwick Tree or binary index tree data structure
*/

/*
How to get next or parent node?
index +/- (index & -index)
The index tree is start from 1.

When upate a value, it requires to update the diff.
*/

#include <vector>
#include <iostream>

using namespace std;

class FenwickTree {
public:
    void updateBinaryIndex(int val, int i) {
        int index = i + 1;
        while (index < binaryIndexArray.size()) {
            binaryIndexArray[index] += val;
            index = getNext(index);
        }
    }
    
    
    void update(int i, int val) {
        int diff = val - arr[i];
        arr[i] = val;
        updateBinaryIndex(diff, i);
    }

    int getSum(int i) {
        if (i < 0) return 0;

        int index = i + 1;
        int sum = 0;
        while (index > 0) {
            sum += binaryIndexArray[index];
            index = getParent(index);
        }
        
        return sum;
    }
    
    int getRange(int i, int j) {
        return getSum(j) - getSum(i - 1);    
    }
    
    void buildTree(vector<int> &nums) {
        arr.insert(arr.end(), nums.begin(), nums.end());
        binaryIndexArray.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            updateBinaryIndex(nums[i], i);
        }
    }
    
private:
    vector<int> arr;
    vector<int> binaryIndexArray;
    
    /* 2's complement to get minus of index AND  index
     * add that with index
     */
    int getNext(int index) {
        return index + (index & -index);
    }
    
    int getParent(int index) {
        return index - (index & -index);
    }
};


class NumArray {
public:
    NumArray(vector<int> nums) {
        ft = new FenwickTree();
        ft->buildTree(nums);
    }
    
    void update(int i, int val) {
        ft->update(i, val);
    }
    
    int sumRange(int i, int j) {
        return ft->getRange(i, j);
    }
    
    ~NumArray() {
        delete ft;
    }
private:
    FenwickTree *ft;
};


int main() {
    vector<int> input {0,9,5,7,3};
    NumArray *nm = new NumArray(input);
    cout << nm->sumRange(4, 4) << endl;
    cout << nm->sumRange(2, 4) << endl;
    cout << nm->sumRange(0, 1) << endl;

    return 0;
}

/*
ref:
https://github.com/mission-peace/interview/blob/master/src/com/interview/tree/FenwickTree.java
*/