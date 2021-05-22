//Тернаный поиск

package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

func TernarySearch(array []int, number int) int {
	minIndex := 0
	maxIndex := len(array) - 1
	// пока границы не сомкнуться
	for minIndex <= maxIndex {
		//Получаем
		midIndex1 := minIndex + int((maxIndex-minIndex)/3)
		midIndex2 := maxIndex - int((maxIndex-minIndex)/3)
		midItem1 := array[midIndex1]
		midItem2 := array[midIndex2]
		if midItem1 == number {
			return midIndex1
		} else if midItem2 == number {
			return midIndex2
		}
		if midItem1 < number {
			minIndex = midIndex1 + 1
		} else if midItem2 > number {
			maxIndex = midIndex2 - 1
		} else {
			minIndex = midIndex1 + 1
			maxIndex = midIndex2 - 1
		}
	}
	return -1
}

func main() {
	random := rand.New(rand.NewSource(time.Now().UnixNano()))
	array := make([]int, 30)
	for i := range array {
		array[i] = random.Intn(30)
	}
	sort.Ints(array)
	fmt.Println(array)
	find := TernarySearch(array, 12)
	fmt.Println(find)
}