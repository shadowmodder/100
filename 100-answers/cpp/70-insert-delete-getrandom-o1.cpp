/*
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.

https://www.lintcode.com/problem/insert-delete-getrandom-o1/
*/

class RandomizedSet {
public:
    RandomizedSet() {
    }

    /*
     * @param val: a value to the set
     * @return: true if the set did not already contain the specified element or false
     */
    bool insert(int val) {
        int index = nums.size();
        nums.push_back(val);
        map[val] = index;
    }

    /*
     * @param val: a value from the set
     * @return: true if the set contained the specified element or false
     */
    bool remove(int val) {
        if (map.find(val) == map.end())
            return false;
            
        int index = map[val];
        
        if (index != nums.size() - 1) {
            nums[index] = nums.back();
            map[nums[index]] = index;
        }
        map.erase(val);
        nums.pop_back();
        
        return true;
    }

    /*
     * @return: Get a random element from the set
     */
    int getRandom() {
        int i = rand() % nums.size();
        return nums[i];
    }
    
private:
    vector<int> nums;
    unordered_map<int, int> map; // key is num, value is index 
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param = obj.insert(val);
 * bool param = obj.remove(val);
 * int param = obj.getRandom();
 */