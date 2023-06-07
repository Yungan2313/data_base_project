#include "basic.h"
#include "linked_list.h"

void insert_front(struct linked_list **list,char food_name[],char store_name[],int price,float score,char comment_txt[]){
    struct linked_list *new_node = malloc(sizeof(struct linked_list));
    new_node->next = NULL;
    strcpy(new_node->food_name,food_name);
    strcpy(new_node->store_name,store_name);
    strcpy(new_node->comment_txt,comment_txt);
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
void insert_front_acpd(struct acpd_list **list,char account[],char password[],char data_base_txt[]){
    struct acpd_list *new_node = malloc(sizeof(struct acpd_list));
    new_node->next = NULL;
    strcpy(new_node->account,account);
    strcpy(new_node->password,password);
    strcpy(new_node->data_base_txt,data_base_txt);
    if(*list == NULL){
        *list = new_node;
        return;
    }
    else{
        struct acpd_list *now = *list;
        while(now->next != NULL){
            now = now->next;
        }
        now->next = new_node;
        return;
    }
}
void insert_front_comment(struct comment_list **list,char account[],float score,char comment_txt[]){
    struct comment_list *new_node = malloc(sizeof(struct comment_list));
    new_node->next = NULL;
    strcpy(new_node->account,account);
    strcpy(new_node->comment_txt,comment_txt);
    new_node->score = score;
    if(*list == NULL){
        *list = new_node;
        return;
    }
    else{
        struct comment_list *now = *list;
        while(now->next != NULL){
            now = now->next;
        }
        now->next = new_node;
        return;
    }
}

struct linked_list *delete_linked_list(struct linked_list *list,int position){
    struct linked_list *new_node;
    if(position == 0){
        return list->next;
    }
    for(int i = 0;i<position;i++){
        new_node = new_node->next;
    }
    new_node->next = new_node->next->next;
    return list;
}

//將空間釋放
void free_linked_list(struct linked_list *list){
    struct linked_list *prev = list;
    if(list == NULL){
        return;
    }
    if(list->next == NULL){
        free(list);
        return;
    }
    list = list->next;
    while(list!=NULL){
        free(prev);
        prev = list;
        list = list->next;
    }
    free(prev);
}
void free_acpd_list(struct acpd_list *list){
    struct acpd_list *prev = list;
    if(list == NULL){
        return;
    }
    if(list->next == NULL){
        free(list);
        return;
    }
    list = list->next;
    while(list!=NULL){
        free(prev);
        prev = list;
        list = list->next;
    }
    free(prev);
}
void free_comment_list(struct comment_list *list){
    struct comment_list *prev = list;
    if(list == NULL){
        return;
    }
    if(list->next == NULL){
        free(list);
        return;
    }
    list = list->next;
    while(list!=NULL){
        free(prev);
        prev = list;
        list = list->next;
    }
    free(prev);
}