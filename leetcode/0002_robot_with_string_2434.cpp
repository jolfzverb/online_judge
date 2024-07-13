/* https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string
 */

class Solution {
 public:
  string robotWithString(string s) {
    if (s.empty()) return s;

    std::vector<size_t> smallest_index;
    smallest_index.resize(s.size());

    size_t last_smallest = s.size() - 1;

    for (size_t j = s.size(); j > 0; --j) {
      size_t i = j - 1;

      if (s[i] < s[last_smallest]) {
        smallest_index[i] = i;
        last_smallest = i;
      } else {
        smallest_index[i] = last_smallest;
      }
    }

    std::string result;
    std::stack<char> stack;

    for (size_t i = 0; i < s.size(); i++) {
      while (!stack.empty() && stack.top() <= s[smallest_index[i]]) {
        result += stack.top();
        stack.pop();
      }
      if (i != smallest_index[i]) {
        stack.push(s[i]);
      } else {
        result += s[i];
      }
    }

    while (!stack.empty()) {
      result += stack.top();
      stack.pop();
    }

    return result;
  }
};
