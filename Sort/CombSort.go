//Сортировка расческой

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func CombSort(array []int) {
	gapValue := len(array)
	swapCount := 1
	//пока есть прыжок (массиво больше 0) и количество перестановок не 0
	for gapValue >= 1 && swapCount != 0 {
		//считаем прыжок
		if gapValue != 1 {
			gapValue = int(float64(gapValue) / float64(1.3))
		}
		swapCount = 0

		//Устанавливаем границы firstItem| .. |gapValue
		firstItem := 0
		secondItem := gapValue

		//Делаем пузырьковую сортировку в этих границах
		for secondItem != len(array) {
			if array[firstItem] > array[secondItem] {
				array[firstItem], array[secondItem] = array[secondItem], array[firstItem]
				swapCount += 1
			}
			firstItem += 1
			secondItem += 1
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
	CombSort(array)
	fmt.Println(array)
}