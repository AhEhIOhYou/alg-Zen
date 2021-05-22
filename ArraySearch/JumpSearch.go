//Поиск прыжками

package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
	"math"
)

func JumpSearch(array []int, number int) int {
	//Прыжок считаем так = квадратный корень от длины массива
	jumpValue := int(math.Floor(math.Sqrt(float64(len(array)))))

	//границы линейного поиска
	//изначально |0 - прыжок|
	minIndex := 0
	maxIndex := jumpValue

	//поиск правой границы, чтоб искомое число было меньше или равно ей
	for array[maxIndex] <= number {

		minIndex += jumpValue
		maxIndex = minIndex + jumpValue

		//если уперлись в конец массив, останавливаемся
		if maxIndex >= len(array) {
			maxIndex = len(array)
			minIndex = maxIndex - jumpValue
			break
		}
	}

	//линеный поиск в наших границах minIndex| .. |maxIndex
	for i := minIndex; i < maxIndex; i++ {
		if array[i] == number {
			return i
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
	find := JumpSearch(array, 12)
	fmt.Println(find)
}