/* https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/
 */

class Solution {
 public:
  string robotWithString(string s) {
    std::multiset<char> letters;
    for (size_t i = 0; i < s.size(); i++) {
      letters.emplace(s[i]);
    }

    std::string result;
    std::stack<char> st;

    for (auto c : s) {
      while (!st.empty() && st.top() <= *letters.begin()) {
        result += st.top();
        st.pop();
      }

      st.push(c);
      letters.erase(letters.find(c));
    }

    while (!st.empty()) {
      result += st.top();
      st.pop();
    }

    return result;
  }
};
