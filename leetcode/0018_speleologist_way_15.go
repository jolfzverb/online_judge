/* https://coderun.yandex.ru/problem/speleologist-way */

package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	n2 := n * n
	n3 := n * n * n

	var cave = make([]int, n3)
	q := map[int]bool{}

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			var line string
			fmt.Scan(&line)

			for k := 0; k < n; k++ {
				c := i*n2 + j*n + k

				switch line[k] {
				case '#':
					cave[c] = -1
				case '.':
					cave[c] = 0
				case 'S':
					cave[c] = 0
					q[c] = true
				}
			}
		}
	}

	var l = 0

	for len(q) != 0 {
		next_q := map[int]bool{}
		l += 1

		for c, _ := range q {
			if c < n2 {
				fmt.Println(l - 1)

				return
			}

			cave[c] = l
		}

		for c, _ := range q {
			var i = c / n2
			var j = (c % n2) / n
			var k = c % n

			if i > 0 && cave[c-n2] == 0 {
				next_q[c-n2] = true
			}

			if j > 0 && cave[c-n] == 0 {
				next_q[c-n] = true
			}

			if k > 0 && cave[c-1] == 0 {
				next_q[c-1] = true
			}

			if i < n-1 && cave[c+n2] == 0 {
				next_q[c+n2] = true
			}

			if j < n-1 && cave[c+n] == 0 {
				next_q[c+n] = true
			}

			if k < n-1 && cave[c+1] == 0 {
				next_q[c+1] = true
			}
		}

		q = next_q
	}

	fmt.Println(-1)
}
