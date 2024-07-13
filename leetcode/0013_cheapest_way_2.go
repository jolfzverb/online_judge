/* https://coderun.yandex.ru/problem/cheapest-way */

package main

import (
	"fmt"
)

func main() {
	var N, M int

	fmt.Scan(&N)
	fmt.Scan(&M)

	arr := make([][]int, N)

	for i := 0; i < N; i++ {
		arr[i] = make([]int, M)

		for j := 0; j < M; j++ {
			var value int
			fmt.Scan(&value)

			if i == 0 {
				if j == 0 {
					arr[i][j] = value
				} else {
					arr[i][j] = value + arr[i][j-1]
				}
			} else {
				if j == 0 {
					arr[i][j] = value + arr[i-1][j]
				} else {
					min := arr[i-1][j]

					if arr[i][j-1] < arr[i-1][j] {
						min = arr[i][j-1]
					}

					arr[i][j] = value + min
				}
			}
		}
	}

	fmt.Println(arr[N-1][M-1])
}
