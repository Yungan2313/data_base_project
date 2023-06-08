#include "basic.h"
#include "linked_list.h"
#include "txtinput.h"
int database_UI(struct linked_list *list,int page){
    struct linked_list *node = list;
    int linked_list_len = 0,pages;

    for(int i = 0;i<page*10;node = node->next){
        if(node == NULL){
           return -1;
        }
        i++;
    }
    node = list;
    printf("|  ID  |      Name      |     Store     |  Price  |  Score  |\n");
    for(int l = 0;l <= 63; l++){
            printf("-");
    }
    printf("\n");
    
    for(int i = 0;i < 10;node = node->next){
        if(node != NULL){
            printf("|%4d  |%*s      |%*s     |%*d  |%*.1f  |\n",i+1, 10, node->food_name, 10, node->store_name, 7, node->price, 7, node->score);
        }else{
            break;
        }
        i++;
    }
    printf("ok");
    for(int l = 0;l <= 63; l++){
            printf("-");
    }
    printf("\n");

    return page;
}

void comment(){

}

int main(){
    struct linked_list *list = data_base_read("test.txt");
    database_UI(list,0);
}




   