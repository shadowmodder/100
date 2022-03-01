import java.util.HashSet;

public class allpalindrome {
// 1. Longet palindroopme's size.
    public int longestpalindrome(String s) {
        int count = 0;
        HashSet<Character> data = new HashSet<Character>();
        for (int i = 0; i < s.length(); i ++) {
            char c = s.charAt(i);
            if (data.contains(c)) {
                count += 2;
                data.remove(c);
            }
            else { data.add(c); }
        }
        if (data.size() > 0) { count ++; }
        return count;
    }
// 2. is palindrome char?
    public boolean isPalindrome(String s) {
        if (s == null || s.equals("")){
            return true;
        }
        s = s.toLowerCase();
        s = s.replaceAll("[^A-Za-z0-9]","");
        int i = 0;
        int j = s.length() -1;
        for (; i < j; i ++, j --){
            if (s.charAt(i) != s.charAt(j)){
                return false;
            }
        }
        return true;
    }//isPalindrome

// 3. is palindrome number?
public boolean isPalindromenum(int x) {
    if (x < 0) {
        return false;
    }
    int left = 1;
    while (x / left >= 10) {
        left = left * 10;
    }
    int right = 1;
    while (left > right) {
        if ((x / left) % 10 != (x / right) % 10 ) {
            return false;
        }
        left = left / 10;
        right = right * 10;
    }
    return true;
}

    public static void main(String[] args) {
        allpalindrome lp = new allpalindrome();
        //System.out.println("Averages of subarrays of size K: " + (lp.longestpalindrome("abccccdduui")));
        //System.out.println("is palindropme?: " + (lp.isPalindrome("A man, a plan, a canal: Panama")));
        System.out.println("is palindropmenum ?: " + (lp.isPalindromenum(676767676)));
      }
}