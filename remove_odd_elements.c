#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STR_SIZE 2000

typedef struct list {
    char* word;
    struct list* next;
} list;

list* insert2(char* value, list* head);
void print_odd_elements(list* head);
void reverse_list(list**);
void delete_list(list* head);

int main(int argc, char** argv) {
    list* w_list = NULL;
    char word[STR_SIZE] = "";
    int ch = ' ';
    int i = 0;

    while (EOF != (ch = getchar())) {
        switch (ch) {
            case '.':
            case ' ':
                word[i] = '\0';
                w_list = insert2(word, w_list);
                i = 0;
                break;
            default:
                word[i++] = ch;
                if (i >= STR_SIZE)
                    i = 0; // Защита от переполнения строки
        }
        if ('.' == ch)
            break;
    }

#ifdef DEBUG
    print_list(w_list);
#endif
	//print_list(w_list);
	reverse_list(&w_list);
	//print_list(w_list);
    print_odd_elements(w_list);

    delete_list(w_list);
    return 0;
}
void print_list(list * head)
{
 for (list* i = head; i!=NULL; i=i->next)
 printf("%s ", i->word);
 putchar('\n');
}
void print_odd_elements(list* head) {
    int count = 1;
    for (list* i = head; i != NULL; i = i->next) {
        if (count % 2 != 0) {
            printf("%s ", i->word);
        }
        count++;
    }
    putchar('\n');
}

void delete_list(list* l) {
    list* c = l;
    list* n;
    while (c != NULL) {
        n = c->next;
        free(c->word); // Очищаем память под слово
        free(c);
        c = n;
    }
}

list* insert2(char* value, list* head) {
    list* res = (list*)calloc(1, sizeof(list));
    int len = strlen(value); // Определяем размер строки
    res->word = malloc(len + 1); // Выделяем память под строку
    strcpy(res->word, value); // Копируем строку в память
    res->next = head; // Смещаем указатель на следующий
    return res;
}
void reverse_list(list** head) {
    list* prev = NULL;
    list* current = *head;
    list* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}
