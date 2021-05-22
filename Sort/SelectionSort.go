//Сортировка выбором

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func SelectionSort(array []int) {
	//3. теперь сортируем хвост списка, исключив из рассмотрения уже отсортированные элементы
	for arrayIndex := range array {
		minValue := array[arrayIndex]
		minIndex := arrayIndex
		for subArrayIndex := arrayIndex + 1; subArrayIndex < len(array); subArrayIndex++ {
			//1. находим номер минимального значения в текущем списке
			if array[subArrayIndex] < minValue {
				minValue = array[subArrayIndex]
				minIndex = subArrayIndex
			}
		}
		//2. производим обмен этого значения со значением первой неотсортированной позиции
		array[minIndex], array[arrayIndex] = array[arrayIndex], array[minIndex]
		fmt.Print("Шаг: ")
		fmt.Println(array)
	}
}

func main() {
	random := rand.New(rand.NewSource(time.Now().UnixNano()))
	array := make([]int, 10)
	for i := range array {
		array[i] = random.Intn(20)
	}
	fmt.Println(array)
	SelectionSort(array)
	fmt.Println(array)
}