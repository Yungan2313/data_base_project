#include "basic.h"
#include "linked_list.h"

void insert_front(struct linked_list **list,char food_name[],char store_name[],int price,float score){
    struct linked_list *new_node = malloc(sizeof(struct linked_list));
    new_node->next = NULL;
    strcpy(new_node->food_name,food_name);
    strcpy(new_node->store_name,store_name);
    new_node->price = price;
    new_node->score = score;
    if(*list == NULL){
        *list = new_node;
        return;
    }
    else{
        struct linked_list *now = *list;
        while(now->next != NULL){
            now = now->next;
        }
        now->next = new_node;
        return;
    }
}
void insert_back(struct linked_list **list,char food_name[],char store_name[],int price,float score){
    struct linked_list *new_node = malloc(sizeof(struct linked_list));
    new_node->next = *list;
    strcpy(new_node->food_name,food_name);
    strcpy(new_node->store_name,store_name);
    new_node->price = price;
    new_node->score = score;
    *list = new_node;
}
/*struct linked_list *search(struct linked_list **list,char food_name[],char store_name[],int price,float score){
    struct linked_list *node = *list;


    // switch(choose){
    //     case 0://food_name
    //         char *food_name;
    //         printf("input search:");
    //         fgets(food_name,sizeof(char),stdin);
    //         int len = strlen(food_name);
    //         *(food_name+len-1) = '\0';
    //         while(node->next != NULL){
    //             if(strcmp(food_name,node->food_name)){
    //                 return node;
    //             }
    //             node = node->next;
    //         }
    //         break;
    //     case 1://store_name
    //         char *store_name;
    //         printf("input search:");
    //         fgets(store_name,sizeof(char),stdin);
    //         int len = strlen(store_name);
    //         *(store_name+len-1) = '\0';
    //         while(node->next != NULL){
    //             if(strcmp(store_name,node->store_name)){
    //                 return node;
    //             }
    //             node = node->next;
    //         }
    //         break;
    //     case 2://price
    //         int price;
    //         printf("input search:");
    //         scanf("%d",&price);
    //         while(node->next != NULL){
    //             if(node->price == price){
    //                 return node;
    //             }
    //             node = node->next;
    //         }
    //         break;
    //     case 3://score
    //         float score;
    //         printf("input search:");
    //         scanf("%d",&score);
    //         while(node->next != NULL){
    //             if(node->score == score){
    //                 return node;
    //             }
    //             node = node->next;
    //         }
    //         break;
    //     default:
    //         printf("search failed!\n");
    //         return NULL;
    //}
}*/
void insert_position(){

}
void delete_position(){

}
