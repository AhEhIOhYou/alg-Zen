//Бинарный поиск

package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

func BinarySearch(array []int, number int) int {

	minIndex := 0
	maxIndex := len(array) - 1

	//Пока лево и право не столкнутся
	for minIndex <= maxIndex {
		midIndex := int((maxIndex + minIndex) / 2)
		midItem := array[midIndex]

		//если искомое находится в центре - вернем его
		if number == midItem {
			return midIndex
		}

		//если число меньше середины, то производим поиск слева
		if midItem < number {
			minIndex = midIndex + 1

		} else //если число больше середины, то производим поиск справа
		if midItem > number {
			maxIndex = midIndex - 1
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
	find := BinarySearch(array, 12)
	fmt.Println(find)
}