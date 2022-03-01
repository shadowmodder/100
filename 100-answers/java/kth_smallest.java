import java.util.Arrays;
import java.util.PriorityQueue;

public class kth_smallest {

// inplace sorting
    public static int findKthSmallestNumber(int[] nums, int k) {
        Arrays.sort(nums);
        return nums[k - 1];
      }

// PQ sorting
    public static int findKthSmallestNumberpq(int[] nums, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>((n1, n2) -> n2 - n1);
        // put first k numbers in the max heap
        for (int i = 0; i < k; i++)
          maxHeap.add(nums[i]);
    
        // go through the remaining numbers of the array, if the number from the array is smaller than the
        // top (biggest) number of the heap, remove the top number from heap and add the number from array
        for (int i = k; i < nums.length; i++) {
          if (nums[i] < maxHeap.peek()) {
            maxHeap.poll();
            maxHeap.add(nums[i]);
          }
        }
        // the root of the heap has the Kth smallest number
        return maxHeap.peek();
    }
// O(K∗logK+(N−K)∗logK) which is asymptotically equal to O(N*logK)O(N∗logK). The space complexity will be O(K)O(K)  
    public static void main(String[] args) {
        kth_smallest up = new kth_smallest();
        int[]arr = { 3 ,6, 1 };
        System.out.println("is simpleuniquePaths ?: " + (up.findKthSmallestNumber(arr, 2)));
      }

}