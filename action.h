#ifndef ACTION_H
#define ACTION_H
#ifndef TXT_INPUT_H
#define TXT_INPUT_H
#include "linked_list.h"
#include "basic.h"
#endif
struct linked_list *add_list(struct linked_list *list,char food_name[],char store_name[],int price,float score,char comment_txt[]);
struct linked_list *delete_list(struct linked_list *list,int position);
struct linked_list *sort_list(struct linked_list *list,int type,int order);
struct linked_list *search_list(struct linked_list *list);
#endif