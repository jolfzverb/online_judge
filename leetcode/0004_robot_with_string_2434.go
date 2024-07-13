/* https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/
 */
package task_2434

func robotWithString(s string) string {
	var indexes = make([]int, len(s))
	var min_index = len(s) - 1

	for i := len(s) - 1; i >= 0; i-- {
		if s[i] < s[min_index] {
			min_index = i
		}

		indexes[i] = min_index
	}

	var stack []byte
	var r []byte

	for i := 0; i < len(s); i++ {
		for len(stack) > 0 && stack[len(stack)-1] <= s[indexes[i]] {
			r = append(r, stack[len(stack)-1])
			stack = stack[:len(stack)-1]
		}

		if i != indexes[i] {
			stack = append(stack, s[i])
		} else {
			r = append(r, s[i])
		}
	}

	for len(stack) > 0 {
		r = append(r, stack[len(stack)-1])
		stack = stack[:len(stack)-1]
	}

	return string(r[:])
}
