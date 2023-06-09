#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct linked_list{
    char food_name[50];
    char store_name[50];
    int  price;
    float score;
    char comment_txt[100];
    struct linked_list *next;
};
struct acpd_list{
    char account[20];
    char password[20];
    char data_base_txt[20];
    struct acpd_list *next;
};
struct comment_list{
    char account[20];
    float score;
    char comment_txt[100];
    struct comment_list *next;
};
void insert_front(struct linked_list **list,char food_name[],char store_name[],int price,float score,char comment_txt[]);
void insert_front_acpd(struct acpd_list **list,char account[],char password[],char data_base_txt[]);
void insert_front_comment(struct comment_list **list,char account[],float score,char *comment_txt);
struct linked_list *delete_linked_list(struct linked_list *list,int position);
void free_linked_list(struct linked_list *list);
void free_acpd_list(struct acpd_list *list);
void free_comment_list(struct comment_list *list);
#endif