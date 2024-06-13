#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STR_SIZE 2000
typedef struct list
{
 char* word;
 struct list *next;
}list;
/* Без заглавного элемента и без двойного
указателя*/
list* insert2(char* value,list *head);
void get_first_last_words(list *head, char **first, char **last);
void delete_list(list *head);

int main(int argc, char** argv) {
    list *w_list = NULL;
    char word[STR_SIZE] = "";
    int ch = ' ';
    int i = 0;
    
    while(EOF != (ch = getchar())){
 switch(ch){
 case '.':
 case ' ':
 word[i] = '\0';
 w_list = insert2(word, w_list);
 i=0;
 break;
 default:
 word[i++] = ch;
 if(i>=STR_SIZE)
 i=0;//Защита от переполнения строки
 }
 if('.' == ch)
 break;
 }
    
    #ifdef DEBUG
    print_list(w_list);
    #endif
    
   
    
    
    char *first_word, *last_word;
    get_first_last_words(w_list, &first_word, &last_word);
    
    if (first_word) {
        printf("First word: %s\n", first_word);
    } else {
        printf("No words in the list\n");
    }
    
    if (last_word) {
        printf("Last word: %s\n", last_word);
    } else {
        printf("No words in the list\n");
    }
    
    delete_list(w_list);
    return 0;
}
void delete_list(list * l){
list * c =l;
list * n;
 while(c != NULL) {
 n = c->next;
 free(c->word);//Очищаем паять под слово
 free(c);
 c = n;
 }
}

/* Без заглавного элемента и без двойного указателя*/
list* insert2(char* value,list *head){
 list *res = (list*)calloc(1,sizeof(list));
int len = strlen(value);//определяем размер строки
 res->word = malloc(len+1);//выделяем память под строку
 strcpy(res->word, value);//копируем строку в память
 res->next = head;//смещаем указатель на следующий
return res;
}


void get_first_last_words(list *head, char **first, char **last) {
    list *current = head;
    
    // Получаем первое слово
    if (current != NULL) {
        *last = current->word;
    } else {
        *last = NULL;
    }
    
    // Получаем последнее слово
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    *first = current ? current->word : NULL;
}
