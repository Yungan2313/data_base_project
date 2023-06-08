#include "basic.h"
#include "linked_list.h"
#include "txtinput.h"
#include "comment.h"
//#define DEBUG_UI
int database_UI(struct linked_list *list,int page){
    struct linked_list *node = list;

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

    for(int l = 0;l <= 63; l++){
            printf("-");
    }
    printf("\n");
    printf("Page %d",page + 1);

    return page;
}

int comment_UI(struct comment_list *list, int page){
    struct comment_list *node = list;
    float average = 0,count = 0;
    node = list;
    while(node!=NULL){
        average+=node->score;
        count++;
        node = node->next;
    }
    average /= count;
    node = list;
    for(int i = 0;i< page; node = node->next){
        if(node == NULL){
           return -1;
        }
        i++;
    }
    for(int l = 0;l <= 63; l++){
            printf("-");
    }
    printf("\n");

    printf("|  ID  |      Account       |  Score  |\n");
    
    for(int l = 0;l <= 63; l++){
            printf("-");
    }
    printf("\n");
    
    printf("|%4d  |%*s       |%*.1f  |\n",page+1, 13, node->account, 7, node->score);
    for(int l = 0;l <= 63; l++){
            printf("-");
    }
    printf("\n");
    printf("%s",comment_search(node->comment_txt));
    for(int l = 0;l <= 63; l++){
            printf("-");
    }
    printf("\n");
    printf("Average Score: %0.1f",average);

    return page;
}
#ifdef DEBUG_UI
int main(){
    // struct linked_list *list = data_base_read("test.txt");
    // database_UI(list,0);
    struct comment_list *clist = comment_list_read("comment_test.txt");
    // if(clist == NULL){
    //     printf("not ok");
    // }
    comment_UI(clist,0);
}
#endif



   