#ifndef ACTION_H
#define ACTION_H
#ifndef TXT_INPUT_H
#define TXT_INPUT_H
#include "linked_list.h"
#include "basic.h"
#endif
struct linked_list *add_list(struct linked_list *list,char user[]);
struct linked_list *delete_list(struct linked_list *list,char user[],int page);
struct linked_list *sort_list(struct linked_list *list,int type,int order);
struct linked_list *search_list(struct linked_list *list);
void log_out(struct linked_list *list,char user[]);
char *comment_choose(struct linked_list *list,char user[],int page);
#endif