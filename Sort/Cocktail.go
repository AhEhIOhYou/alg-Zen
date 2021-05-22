//Шейкерная сортировка

package main

import (
	"fmt"
	"math/rand"
	"time"
)

func CocktailSort(array []int) {
	swapCount := 1
	for swapCount > 0 {
		swapCount = 0
		//границы 0| .. | array size
		for itemIndex := 0; itemIndex < len(array)-1; itemIndex++ {
			//Произошел bubblesort
			if array[itemIndex] > array[itemIndex+1] {
				array[itemIndex], array[itemIndex+1] = array[itemIndex+1], array[itemIndex]
				swapCount += 1
			}
		}
		//границы  array size| .. |0
		for itemIndex := len(array) - 1; itemIndex > 0; itemIndex-- {
			//Произошел bubblesort
			if array[itemIndex] < array[itemIndex-1] {
				array[itemIndex], array[itemIndex-1] = array[itemIndex-1], array[itemIndex]
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
	CocktailSort(array)
	fmt.Println(array)
}