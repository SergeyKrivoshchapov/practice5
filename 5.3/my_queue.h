#include "WIFI.h"
#ifndef MY_QUEUE_H 
#define MY_QUEUE_H

typedef struct WIFI_item
{
	WIFI* data; // указатель на экземпляр структуры с данными о роутере
	struct WIFI_item* next; // Указатель на следующий элемент очереди
	struct WIFI_item* prev; // Указатель на предыдущий элемент очереди
}WIFI_item;

typedef struct WIFI_queue
{
	struct WIFI_item* head; // Указатель на первый элемент очереди
}WIFI_queue;

// Функция добавления элемента в начало очереди
// Принимает в качестве аргументов список роутеров по указателю, указатель на данные о роутере. 
// Выделяет память динамически для нового элемента. 
// Устанавливаются новые значения указателей next, head 
// Возвращает 0 при успешном исходе, иначе 1
int enqueue(WIFI_queue* queue, WIFI* data);

// Функция извлечения последнего элемента очереди
// Принимает в качестве аргумента указатель на очередь роутеров по значению.
// освобождает память для удаленного элемента очереди, зануляет значение указателя next предпоследнего эемента.
// Вовращает указатель на извлеченный экземпляр структуры данных роутера
WIFI* dequeue(WIFI_queue* queue);

void extract_data(WIFI_queue* queue);

// Функция вывода сведений для каждого элемента очереди
// Принимает в качестве аргумента указатель на очередь роутеров по значению.
// Внутри вызывает print_struct
void print_queue(const WIFI_queue* queue);

// Функция удаления всех элементов очереди.
// Принимает в качестве аргумента указатель на очередь роутеров по значению.
// вызывает dequeue, пока в списке есть элементы
void delete_queue(WIFI_queue* queue);

int write_queue_tofile(const char* filename, WIFI_queue* queue);

int read_queue_fromfile(const char* filename, WIFI_queue* queue);

#endif
