#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct linked_list{
    char food_name[20];
    char store_name[20];
    int  price;
    float score;
    struct linked_list *next;
};
struct acpd_list{
    char account[20];
    char password[20];
    char data_base_txt[20];
    struct acpd_list *next;
};
void insert_front(struct linked_list **list,char food_name[],char store_name[],int price,float score);
void insert_front_acpd(struct acpd_list **list,char account[],char password[],char data_base_txt[]);

#endif