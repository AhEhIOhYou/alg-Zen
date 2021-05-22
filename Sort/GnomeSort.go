//Гномья сортировка

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func GnomeSort(array []int) {
	itemIndex := 0
	//закончится, когда дойдем до последнего
	for itemIndex < len(array)-1 {
		//если текущий больше следующего
		if array[itemIndex] > array[itemIndex+1] {
			//меняем их местами
			array[itemIndex], array[itemIndex+1] = array[itemIndex+1], array[itemIndex]
			//идем назад
			if itemIndex != 0 {
				itemIndex -= 1
			}
		} else {
			//Иначе идем вперед
			itemIndex += 1
		}
	}
}

func main() {
	random := rand.New(rand.NewSource(time.Now().UnixNano()))
	array := make([]int, 10)
	for i := range array {
		array[i] = random.Intn(20)
	}
	fmt.Println(array)
	GnomeSort(array)
	fmt.Println(array)
}