package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

//Константа размера массива
const arrSize = 50

//Вывод результатов поиска
func OutputResult(key, num int) {
	switch {
	case num != -1:
		fmt.Printf("Массив содержит число %d на позиции %d", key, num)
	default:
		fmt.Printf("В массив нет искомого числа %d", key)
	}
	fmt.Println("")
}

//Генерация массива рандомом
func Generate(a []int) {
	for i := 0; i < len(a); i++ {
		a[i] = rand.Intn(50)
	}
}

//Линейный поиск - идем в лоб
func lineSearch(a []int, key int) (index int) {
	fmt.Println("Производится Линейный поиск")
	for i := 0; i < len(a); i++ {
		if a[i] == key {
			return i
		}
	}
	return -1
}

//Метод половинного деления
func binarySearch(a []int, key int) (index int) {
	fmt.Println("Производится Бинарный поиск")
	left := 0
	right := len(a) - 1
	//Бесконечный цикл, пока не return что-то
	for {
		//индекс середины
		mid := (left + right) / 2
		switch {
		// если искомое меньше значения в ячейкею
		case key < a[mid]:
			// смещаем правую границу поиска
			right = mid - 1
		// если искомое больше значения в ячейке
		case key > a[mid]:
			// смещаем левую границу поиска
			left = mid + 1
		// иначе (значения мида и искомого равны)
		default:
			return mid
		}
		// если границы сомкнулись
		if left > right {
			return -1
		}
	}
}

//Хайповый интерполяционный
func InterpolSearch(a []int, key int) int {
	fmt.Println("Производится Интерполяционный поиск")
	left := 0
	right := len(a) - 1
	var mid int

	for a[left] <= key && a[right] >= key {
		//Формула интерполяции
		mid = left + ((key-a[left])*(right-left))/(a[right]-a[left])
		//
		switch {
		case a[mid] < key:
			left = mid + 1
		case a[mid] > key:
			right = mid - 1
		default:
			return mid
		}
	}
	if a[left] == key {
		return left
	} else {
		return -1
	}
}

//Поиск сетки Эратосфена - простых чисел
func EratosthenesSieve() []int {
	fmt.Println("Решето Эратосфена: ")
	var arr [arrSize]int
	var a []int
	for i := 0; i < len(arr); i++ {
		arr[i] = i
	}

	for i := 2; i*i < len(arr); i++ {
		if arr[i] != 0 {
			for j := i * i; j < len(arr); j += i {
				arr[j] = 0
			}
		}
	}
	for i := 0; i < len(arr); i++ {
		if arr[i] != 0 {
			a = append(a, arr[i])
		}
	}
	return a
}

//Поиск индекса входа строки в подстроку
/*func FindSubstrings(s string, w string, n int) int {
	fmt.Println("Поиск строки в подстроке: ")
	var lenS, lenW int = utf8.RuneCountInString(s), utf8.RuneCountInString(w)
	for i := 0; i < (lenS - lenW); i++ {
		for j := 0; s[i + j] == w[j]; j++ {
			if j - lenW == 1 && i == lenS - lenW && (n - 1) != 0 {
				return i
			}
			if j == lenW {
				if (n - 1) == 0 {
					n--
				} else {
					return i
				}
			}
		}
	}
	return -1
}*/

func main() {

	rand.Seed(time.Now().UnixNano())
	//Массив на 50 символов
	var arr [arrSize]int
	Generate(arr[:])
	//Индекс найденого элемента
	var elemNum int
	//Искомое значение
	reqKey := rand.Intn(50)

	fmt.Println("Массив:\n", arr)
	elemNum = lineSearch(arr[:], reqKey)
	OutputResult(reqKey, elemNum)

	sort.Ints(arr[:])

	fmt.Println("Массив:\n", arr)
	elemNum = binarySearch(arr[:], reqKey)
	OutputResult(reqKey, elemNum)

	elemNum = InterpolSearch(arr[:], reqKey)
	OutputResult(reqKey, elemNum)

	a := EratosthenesSieve()
	fmt.Println("Массив:\n", a)
}
