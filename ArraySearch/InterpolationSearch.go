//Интерполяционный поиск

package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

func InterpolationSearch(array []int, number int) int {
	//границы поиска
	minIndex := 0
	maxIndex := len(array) - 1

	//пока границы не сомкнутся и поисковое значение меньше левой и правой границы
	for minIndex <= maxIndex && number >= array[minIndex] && number <= array[maxIndex] {

		//вычисляем индекс середины по формуле интерполяции
		midIndex := minIndex + (number-array[minIndex])*(maxIndex-minIndex)/(array[maxIndex]-array[minIndex])
		//получаем мид значение
		midItem := array[midIndex]

		//если нашли нужное - вернем
		if midItem == number {
			return midIndex
		} else //если мид меньше искомого, сдвигаем левую границу
		if midItem < number {
			minIndex = midIndex + 1
		} else //если мид больше искомого, сдвигаем правую границу
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
	find := InterpolationSearch(array, 12)
	fmt.Println(find)
}