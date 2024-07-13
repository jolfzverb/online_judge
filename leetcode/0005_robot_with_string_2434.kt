/* https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string
 */
class Solution {
  fun robotWithString(str: String): String {
    val s = str.toCharArray()
    val indexes = Array<Int>(s.size) { 0 }
    var min_index = s.size - 1

    for (i in s.size - 1 downTo 0) {
      if (s[i] < s[min_index]) {
        min_index = i
      }

      indexes[i] = min_index
    }

    var result = ArrayList<Char>()
    val stack = ArrayDeque<Char>()

    for ((i, c) in s.withIndex()) {
      while (!stack.isEmpty() && stack.last() <= s[indexes[i]]) {
        result.add(stack.removeLast())
      }

      stack.addLast(s[i])
    }

    while (!stack.isEmpty()) {
      result.add(stack.removeLast())
    }

    return result.joinToString("")
  }
}
