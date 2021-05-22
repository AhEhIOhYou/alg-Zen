//Линеный поиск

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func LinearSearch(array []int, number int) int {
	for index, value := range array {
		if value == number {
			return index
		}
	}
	return -1
}

func main() {
	random := rand.New(rand.NewSource(time.Now().UnixNano()))
	array := make([]int, 20)
	for i := range array {
		array[i] = random.Intn(10)
	}
	fmt.Println(array)
	find := LinearSearch(array, 2)
	fmt.Println(find)
}