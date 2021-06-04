package main

import (
	"fmt"
)

//Значение, следующий, предыдущий элементы
type Node struct {
	data int
	next *Node
	prev *Node
}

//Начало и конец
type LinkedList struct {
	head *Node
	tail *Node
}

//Далее - data := &Node{data: i} - создание звена с путыми указателями и значением i

//Вставка в конец
func (list *LinkedList) InsertLast(i int) {
	data := &Node{data: i}
	//Если список пустой - элемент становится головным и хвостом
	if list.head == nil {
		list.head = data
		list.tail = data
		return
	}
	//добавляем элемент в конец - назначяем хвостом
	if list.tail != nil {
		list.tail.next = data
		data.prev = list.tail
	}
	list.tail = data
}

//Удаляем по значения
func (list *LinkedList) RemoveByValue(i int) bool {
	//Вернем если пусто
	if list.head == nil {
		return false
	}
	//Проверим голову и хвост на совпадение
	if list.head.data == i {
		list.head = list.head.next
		list.head.prev = nil
		return true
	}
	if list.tail.data == i {
		list.tail = list.tail.prev
		list.tail.next = nil
		return true
	}
	//Иначе перебираем все элементы, просто сменяя current, который первоначально - голова
	current := list.head
	for current.next != nil {
		if current.next.data == i {
			if current.next.next != nil {
				current.next.next.prev = current
			}
			current.next = current.next.next
			return true
		}
		current = current.next
	}
	//не найдено
	return false
}

//Удалить по индексу
func (list *LinkedList) RemoveByIndex(i int) bool {
	if list.head == nil {
		return false
	}
	//Проверка на корректность индекса
	if i < 0 {
		return false
	}
	//Первый элемент - он же нулевой
	if i == 0 {
		list.head.prev = nil
		list.head = list.head.next
		return true
	}
	//Перебираем все элементы, попутно считая их число
	current := list.head
	for u := 1; u < i; u++ {
		if current.next.next == nil {
			return false
		}
		current = current.next
	}
	if current.next.next != nil {
		current.next.next.prev = current
	}
	current.next = current.next.next
	return true
}

//Поиск по списку
func (list *LinkedList) SearchValue(i int) bool {
	if list.head == nil {
		return false
	}
	//Перебираем все звенья, используя current, пока не совпдает значение
	current := list.head
	for current != nil {
		if current.data == i {
			return true
		}
		current = current.next
	}
	//Не нашли
	return false
}

//Возвращает головной элемент списка, если не пусто
func (list *LinkedList) GetFirst() (int, bool) {
	if list.head == nil {
		return 0, false
	}
	return list.head.data, true
}

//Возвращает хвостовой элемент списка, если не пусто
func (list *LinkedList) GetLast() (int, bool) {
	if list.head == nil {
		return 0, false
	}
	current := list.head
	for current.next != nil {
		current = current.next
	}
	return current.data, true
}

//Возвращает кол-во элементов списка, если не пусто
func (list *LinkedList) GetSize() int {
	count := 0
	current := list.head
	for current != nil {
		count += 1
		current = current.next
	}

	return count
}

//Вывод элементов от головы к хвосту
func (list *LinkedList) Show() []int {
	var items []int
	current := list.head
	for current != nil {
		items = append(items, current.data)
		current = current.next
	}
	return items
}

func main() {
	var l = LinkedList{
		head: nil,
		tail: nil,
	}

	//12, 2, 32
	l.InsertLast(-12)
	l.InsertLast(22)
	l.InsertLast(3)

	fmt.Print("Список: ")
	fmt.Println(l.Show())

	fmt.Print("Вершина: ")
	fmt.Println(l.GetFirst())

	fmt.Print("Последний: ")
	fmt.Println(l.GetLast())

	fmt.Print("Элементов: ")
	fmt.Println(l.GetSize())

	fmt.Print("Число 52 есть?: ")
	fmt.Println(l.SearchValue(52))

	fmt.Print("Число -12 есть?: ")
	fmt.Println(l.SearchValue(-12))
}
