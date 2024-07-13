# https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/


class Solution(object):
    def robotWithString(self, s):
        smallest_index = len(s) - 1
        indexes = [0 for i in range(len(s))]

        for j in range(len(s), 0, -1):
            i = j-1
            if s[i] < s[smallest_index]:
                smallest_index = i

            indexes[i] = smallest_index

        stack = []
        result = []

        for i, c in enumerate(s):
            while len(stack) > 0 and stack[-1] <= s[indexes[i]]:
                result.append(stack.pop())

            stack.append(c)

        while len(stack) > 0:
            result.append(stack.pop())

        return ''.join(result)
