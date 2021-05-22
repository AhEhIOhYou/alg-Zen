//Сортировка пузырьком
package main

import (
	"fmt"
	"math/rand"
	"time"
)

func BubbleSort(array []int) {
	swapCount := 1
	//пока количество перестановок не станет 0
	for swapCount > 0 {
		swapCount = 0
		//весь массив проходим
		for itemIndex := 0; itemIndex < len(array)-1; itemIndex++ {
			//если следующий больше текущего
			if array[itemIndex] > array[itemIndex+1] {
				//меняем местами текущий и следующий
				array[itemIndex], array[itemIndex+1] = array[itemIndex+1], array[itemIndex]
				swapCount += 1
			}
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
	BubbleSort(array)
	fmt.Println(array)
}