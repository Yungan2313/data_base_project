#include "basic.h"
#include "linked_list.h"
#include "txtinput.h"
#define DEBUG 1
int main(){
    struct linked_list *list = NULL;
    char txt[] = "test.txt";
    list = data_base_read(txt);
    #ifdef DEBUG
    for(int i=0; list != NULL; i++){
        printf("%d:%s %s %d %0.1f\n",i,list->food_name,list->store_name,list->price,list->score);
        list = list->next;
    }
    #endif
}