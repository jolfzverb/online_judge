/* https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/
 */

class Solution {
  public String robotWithString(String str) {
    char[] s = str.toCharArray();

    int[] indexes = new int[s.length];
    int last_smallest = s.length - 1;

    for (int i = s.length - 1; i >= 0; --i) {
      if (s[i] < s[last_smallest]) {
        last_smallest = i;
      }

      indexes[i] = last_smallest;
    }

    char[] r = new char[s.length];
    int r_index = 0;
    Stack<Character> stack = new Stack<>();

    for (int i = 0; i < s.length; i++) {
      while (!stack.empty() && stack.peek() <= s[indexes[i]]) {
        r[r_index++] = stack.pop();
      }

      if (i == indexes[i]) {
        r[r_index++] = s[i];
      } else {
        stack.push(s[i]);
      }
    }

    while (!stack.empty()) {
      r[r_index++] = stack.pop();
    }

    return new String(r);
  }
}
