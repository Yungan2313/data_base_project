#include "basic.h"
#include "linked_list.h"
#include "txtinput.h"
#include "comment.h"
//#define DEBUG_UI
int database_UI(struct linked_list *list,int page){
    struct linked_list *node = list;
    int food_name_length,store_name_length,fpadd,spadd;
    for(int i = 0;i<page*10;node = node->next){
        printf("%d:%s\n",i,node->food_name);
        if(node == NULL){
           return -1;
        }
        i++;
    }
    printf("|  ID  |        Name        |       Store       |  Price  |  Score  |\n");
    for(int l = 0;l <= 70; l++){
            printf("-");
    }
    printf("\n");
    
    for(int i = 0;i < 10;node = node->next){
        // printf("%d:%d %d\n",i,fpadd,spadd);
        if(node != NULL){
            food_name_length = strlen(node->food_name);
            store_name_length = strlen(node->store_name);
            fpadd = (20 - food_name_length) / 2;
            food_name_length%2==1?food_name_length++:fpadd;
            spadd = (20 - store_name_length) / 2;
            store_name_length%2==0?store_name_length--:spadd;
            // printf("|%4d  |%*s%-*s|%*s%-*s|%*d  |%*.1f  |\n",i,10 + fpadd, node->food_name, 10 - fpadd, "",10 + spadd, node->store_name, 10 - spadd, "",7,7,node->price,7,node->score);
            // printf("|%4d  |%*s|%*s|%*d  |%*.1f  |\n",i, 20, node->food_name, 20, node->store_name, 7, node->price, 7, node->score);
            printf("|%4d  |%*s%*s|%*s%*s|%*d  |%*.1f  |\n",i, fpadd+food_name_length, node->food_name,fpadd,"", spadd+store_name_length, node->store_name,spadd,"", 7, node->price, 7, node->score);
        }else{
            break;
        }
        i++;
    }

    for(int l = 0;l <= 70; l++){
            printf("-");
    }
    printf("\n");
    printf("Page %d\n",page + 1);

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
    for(int i = 0;i<page; node = node->next){
        if(node == NULL){
           return -1;
        }
        i++;
    }
    if(node == NULL){
        return -1;
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
    
    printf("|%4d  |%*s       |%*.1f  |\n",page, 13, node->account, 7, node->score);
    for(int l = 0;l <= 63; l++){
            printf("-");
    }
    printf("\n");
    if(strcmp(node->comment_txt, "0") == 0){
        printf("no comment\n");
    }
    else{
        printf("%s\n",comment_search(node->comment_txt));
    }
    for(int l = 0;l <= 63; l++){
            printf("-");
    }
    printf("\n");
    printf("Average Score: %0.1f\n",average);

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



   