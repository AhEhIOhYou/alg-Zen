//Сортировка вставками

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func InsertionSort(array []int) {
	for itemIndex, itemValue := range array {
		//пока индекс не 0 и текущий элемент меньше предыдущего
		for itemIndex != 0 && array[itemIndex-1] > itemValue {
			//меняем текущий и предыдущий местами
			array[itemIndex] = array[itemIndex-1]
			itemIndex -= 1
		}
		array[itemIndex] = itemValue
	}
}

func main() {
	random := rand.New(rand.NewSource(time.Now().UnixNano()))
	array := make([]int, 10)
	for i := range array {
		array[i] = random.Intn(20)
	}
	fmt.Println(array)
	InsertionSort(array)
	fmt.Println(array)
}