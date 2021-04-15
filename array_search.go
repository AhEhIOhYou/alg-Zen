package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	rand.Seed(time.Now().UTC().UnixNano())
	var arr[70]int
	for i := 0 ; i < 5; i++ {
		arr[i] = i
	}
	for i := 6; i < 20; i++ {
		arr[i] = i
	}
	for i := 31; i < 70; i++ {
		arr[i] = i
	}
	for i := 0; i < 70; i++ {
		fmt.Print(" ", arr[i])
	}
	fmt.Println("\n", len(arr))
	var (
		length    = 0
	)
	maxlength := 0
	begIndex := 0
	trueBegin := 0
	endIndex := 0


	for i := 1; i < len(arr); i++ {
		if arr[i] > arr[i - 1] {
			if length == 0 {
				begIndex = i
			}
			if i + 1 == len(arr) - 1 && length > maxlength  {
				if arr[i + 1] > arr[i] {
					endIndex = i + 1
				} else {
					endIndex = i
				}
			}
			length++
		} else if arr[i] <= arr[i - 1]{
			if length > maxlength {
				trueBegin = begIndex
				maxlength = length
				endIndex = i
			}
			length = 0
		}
	}
	maxlength = length
	trueBegin--
	fmt.Println("\nДлинна: ", maxlength)
	fmt.Println("Начало: ", trueBegin, "Конец: ", endIndex)

	for i := trueBegin; i < endIndex; i++ {
		fmt.Print(arr[i], " ")
	}

}
