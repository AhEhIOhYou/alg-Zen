//Экспоненциальный поиск

package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

//Ищем нужные границы
func ExponentialSearch(array []int, number int) int {
	//Идея состоит в том, чтобы начать с размера подмассива 1, сравнить его последний элемент с x,
	//затем попробовать размер 2, затем 4 и т. Д., Пока последний элемент подмассива не станет больше.
	boundValue := 1
	for boundValue < len(array) && array[boundValue] < number {
		boundValue *= 2
	}

	//если выйдем за границу массива, то вернуть искомую границу - как конец массива
	if boundValue > len(array) {
		boundValue = len(array) - 1
	}
	return BinarySearch(array, boundValue+1, number)
}

//Обычный бинарынй поиск
func BinarySearch(array []int, bound, number int) int {
	minIndex := 0
	maxIndex := bound - 1
	for minIndex <= maxIndex {
		midIndex := int((maxIndex + minIndex) / 2)
		midItem := array[midIndex]
		if number == midItem {
			return midIndex
		}
		if midItem < number {
			minIndex = midIndex + 1
		} else if midItem > number {
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
	find := ExponentialSearch(array, 12)
	fmt.Println(find)
}