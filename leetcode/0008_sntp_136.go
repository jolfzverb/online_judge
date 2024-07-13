/* https://coderun.yandex.ru/problem/sntp */

package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var before, server, after string

	fmt.Scan(&before)
	fmt.Scan(&server)
	fmt.Scan(&after)

	before_arr := strings.Split(before, ":")
	server_arr := strings.Split(server, ":")
	after_arr := strings.Split(after, ":")

	before_hh, _ := strconv.Atoi(before_arr[0])
	before_mm, _ := strconv.Atoi(before_arr[1])
	before_ss, _ := strconv.Atoi(before_arr[2])

	server_hh, _ := strconv.Atoi(server_arr[0])
	server_mm, _ := strconv.Atoi(server_arr[1])
	server_ss, _ := strconv.Atoi(server_arr[2])

	after_hh, _ := strconv.Atoi(after_arr[0])
	after_mm, _ := strconv.Atoi(after_arr[1])
	after_ss, _ := strconv.Atoi(after_arr[2])

	diff_hh := after_hh - before_hh
	diff_mm := after_mm - before_mm
	diff_ss := after_ss - before_ss

	if diff_ss < 0 {
		diff_ss += 60
		diff_mm -= 1
	}

	if diff_mm < 0 {
		diff_mm += 60
		diff_hh -= 1
	}

	if diff_hh < 0 {
		diff_hh += 24
	}

	result_ss := server_ss + diff_ss/2

	if diff_ss%2 != 0 {
		result_ss += 1
	}

	result_mm := server_mm + diff_mm/2

	if diff_mm%2 != 0 {
		result_ss += 30
	}

	result_hh := server_hh + diff_hh/2

	if diff_hh%2 != 0 {
		result_mm += 30
	}

	result_mm += result_ss / 60
	result_ss = result_ss % 60

	result_hh += result_mm / 60
	result_mm = result_mm % 60

	result_hh = result_hh % 24

	fmt.Printf("%02d:%02d:%02d\n", result_hh, result_mm, result_ss)
}
