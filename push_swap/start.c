#include <stdlib.h>
#include <stdio.h>

typedef struct s_node {
	void *value;
	struct s_node *next;
	struct s_node *prev;
} t_node;

typedef struct list { // В случае, когда в списке нет элементов, хэд и тэйл равны нулю
	int size;
	t_node *head;
	t_node *tail;
} DoubleList;

// создаём экземпляр структуры double_list

DoubleList* createDoubleList ()
{
	DoubleList *tmp = (DoubleList *)malloc(sizeof(DoubleList));
	tmp->size = 0;
	tmp->head = tmp->tail = 0;
	return tmp;
}

//   push front - вставка в начало списка
void pushFront(DoubleList *list, void *data)
{
	t_node *tmp = (t_node*)malloc(sizeof(t_node));
	if (tmp == 0)
		exit(1);
	tmp->value = data;
	tmp->next = list->head;
	tmp->prev = 0;
	if (list->head)
		list->head->prev = tmp;
	list->head = tmp;
	if (list->tail == 0)
		list->tail = tmp;
	list->size++;
}

void printInt(void *value) {
    printf("%d ", *((int*) value));
}

void printDoubleList(DoubleList *list, void (*fun)(void*)) {
    t_node *tmp = list->head;
    while (tmp) {
        fun(tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

int main()
{
	DoubleList *new = createDoubleList();
	int a = 10;
	pushFront(new, &a);
	printDoubleList(new, printInt);
}