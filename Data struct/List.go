package main

import "fmt"

//Элемент - значение и указатель на следующий
type Node struct {
	data int
	next *Node
}

//Список - вершина
type List struct {
	head *Node
}

//Добавить элемент вперед
func (list *List) InsertFirst(i int) {
	data := &Node{data: i}
	if list.head != nil {
		data.next = list.head
	}
	list.head = data
}

//Добавить элемент назад
func (list *List) InsertLast(i int) {
	data := &Node{data: i}
	if list.head == nil {
		list.head = data
		return
	}
	current := list.head
	for current.next != nil {
		current = current.next
	}
	current.next = data
}

//Удалить по значению
func (list *List) RemoveByValue(i int) bool {
	if list.head == nil {
		return false
	}
	if list.head.data == i {
		list.head = list.head.next
		return true
	}
	current := list.head
	for current.next != nil {
		if current.next.data == i {
			current.next = current.next.next
			return true
		}
		current = current.next
	}
	return false
}

//Удалить по индексу
func (list *List) RemoveByIndex(i int) bool {
	if list.head == nil {
		return false
	}
	if i < 0 {
		return false
	}
	if i == 0 {
		list.head = list.head.next
		return true
	}
	current := list.head
	for u := 1; u < i; u++ {
		if current.next.next == nil {
			return false
		}
		current = current.next
	}
	current.next = current.next.next
	return true
}

//Линейная проверка на существование значения
func (list *List) SearchValue(i int) bool {
	if list.head == nil {
		return false
	}
	current := list.head
	for current != nil {
		if current.data == i {
			return true
		}
		current = current.next
	}
	return false
}

//Получить значение вершины
func (list *List) GetFirst() (int, bool) {
	if list.head == nil {
		return 0, false
	}
	return list.head.data, true
}

//Получить замыкающее значение
func (list *List) GetLast() (int, bool) {
	if list.head == nil {
		return 0, false
	}
	current := list.head
	for current.next != nil {
		current = current.next
	}
	return current.data, true
}

//Подсчет размера списка
func (list *List) GetSize() int {
	count := 0
	current := list.head
	for current != nil {
		count += 1
		current = current.next
	}
	return count
}

//Получить все значения списка
func (list *List) GetItems() []int {
	var items []int
	current := list.head
	for current != nil {
		items = append(items, current.data)
		current = current.next
	}
	return items
}

//Проверка на пустоту
func (list *List) IsEmpty() bool {
	return list.head == nil
}

//Очищает стек
func (list *List) Empty() {
	list.head = nil
}

func main() {
	var l = List{
		head: nil,
	}

	fmt.Print("Список пустой: ")
	fmt.Println(l.IsEmpty())

	//12, 2, 32
	l.InsertFirst(2)
	l.InsertFirst(12)
	l.InsertLast(32)

	fmt.Print("Список: ")
	fmt.Println(l.GetItems())

	fmt.Print("Вершина: ")
	fmt.Println(l.GetFirst())

	fmt.Print("Последний: ")
	fmt.Println(l.GetLast())

	fmt.Print("Элементов: ")
	fmt.Println(l.GetSize())

	fmt.Print("Число 10 есть?: ")
	fmt.Println(l.SearchValue(10))

	fmt.Print("Число 32 есть?: ")
	fmt.Println(l.SearchValue(32))

	fmt.Print("Список пустой: ")
	fmt.Println(l.IsEmpty())
}