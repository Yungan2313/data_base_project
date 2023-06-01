#include "basic.h"
#include "linked_list.h"
#include "action.h"
#define FLOAT_TOLERANCE 0.01
// #define DEBUG 1
static struct linked_list *node_switch(struct linked_list *node1, struct linked_list *node2){
    node1->next = node2->next;
    node2->next = node1;
    return node2;
}

//新增
struct linked_list *add_list(struct linked_list *list,char food_name[],char store_name[],int price,float score,char comment_txt[]){
    
}
//刪除
struct linked_list *delete_list(struct linked_list *list,int position){

}
//排列(回傳的只有兩個)
struct linked_list *sort_list(struct linked_list *list,int type,int order){
    struct linked_list *node = list,*test_line = list,*test = list,*prev = list;
    int list_count = 0;
    while(test_line!= NULL){
        list_count++;
        test_line = test_line->next;
    } 
    if(list == NULL || list->next == NULL){
        return list;
    }
    // int size = linked_list_len(list),swapped,i;
    switch(type){
        case 1:
            for(int i=0;i<list_count;i++){
                int change = 0;
                prev = list;
                while(node->next!=NULL){
                    if(node->price>node->next->price){
                        #ifdef DEBUG
                        printf("xxx%s %s %d %0.1f %s\n",node->food_name,node->store_name,node->price,node->score,node->comment_txt);
                        printf("xnx%s %s %d %0.1f %s\n",node->next->food_name,node->next->store_name,node->next->price,node->next->score,node->next->comment_txt);
                        #endif
                        if(order == 2){
                            if(node == list){
                                list = node->next;
                                node = node_switch(node,node->next);
                            }
                            else{
                                node = node_switch(node,node->next);
                                prev->next = node;
                            }
                            change = 1;
                        }
                    }
                    else{
                        if(order == 1){
                            if(node == list){
                                list = node->next;
                                node = node_switch(node,node->next);
                            }
                            else{
                                node = node_switch(node,node->next);
                                prev->next = node;
                            }
                            change = 1;
                        }
                    }
                    prev = node;
                    node = node->next;
                    test = list;
                    for(int i=0; test != NULL; i++){
                        #ifdef DEBUG
                        printf("%d:%s %s %d %0.1f %s\n",i,test->food_name,test->store_name,test->price,test->score,test->comment_txt);
                        #endif
                        test = test->next;
                    }
                }
                if(change == 0){
                    break;
                }
                node = list;
            }
            return list;
        case 2:
            for(int i=0;i<list_count;i++){
                int change = 0;
                prev = list;
                while(node->next!=NULL){
                    if(node->score - node->next->score > FLOAT_TOLERANCE){
                        #ifdef DEBUG
                        printf("xxx%s %s %d %0.1f %s\n",node->food_name,node->store_name,node->price,node->score,node->comment_txt);
                        printf("xnx%s %s %d %0.1f %s\n\n",node->next->food_name,node->next->store_name,node->next->price,node->next->score,node->next->comment_txt);
                        #endif
                        if(order == 2){
                            if(node == list){
                                list = node->next;
                                node = node_switch(node,node->next);
                            }
                            else{
                                node = node_switch(node,node->next);
                                prev->next = node;
                            }
                            change = 1;
                        }
                    }
                    else{
                        if(order == 1){
                            if(node == list){
                                list = node->next;
                                node = node_switch(node,node->next);
                            }
                            else{
                                node = node_switch(node,node->next);
                                prev->next = node;
                            }
                            change = 1;
                        }
                    }
                    prev = node;
                    node = node->next;
                    test = list;
                    for(int i=0; test != NULL; i++){
                        #ifdef DEBUG
                        printf("%d:%s %s %d %0.1f %s\n",i,test->food_name,test->store_name,test->price,test->score,test->comment_txt);
                        #endif
                        test = test->next;
                    }
                }
                if(change == 0){
                    break;
                }
                node = list;
            }
            return list;
    }
}
//尋找(回傳值為一個新的linked list)
struct linked_list *search_list(struct linked_list *list){
    
}