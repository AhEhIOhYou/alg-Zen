package main

import "fmt"

func Fibonachi(until int) []int {
	var items []int
	//Суть: следущее число = текущее + предыдущее
	for i, j := 0, 1; i < until; i, j = i+j,i {
		items = append(items, i)
	}
	return items
}

func main() {
	fmt.Println(Fibonachi(100))
}