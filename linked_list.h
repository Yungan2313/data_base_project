#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct linked_list{
    char food_name[20];
    char store_name[20];
    int  price;
    float score;
    struct linked_list *next;
};
void insert_front(struct linked_list **list,char food_name[],char store_name[],int price,float score);

#endif