#include "basic.h"
#include "linked_list.h"
#include "action.h"

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
    switch(type){
        case 1:
            for(int i=0;i<list_count;i++){
                int change = 0;
                prev = list;
                while(node->next!=NULL){
                    if(strcmp(node->food_name,node->next->food_name)){
                        printf("xxx%s %s %d %0.1f %s\n",node->food_name,node->store_name,node->price,node->score,node->comment_txt);
                        printf("xnx%s %s %d %0.1f %s\n",node->next->food_name,node->next->store_name,node->next->price,node->next->score,node->next->comment_txt);
                        if(order == 2){
                            if(node == list){
                                list = node->next;
                                node = node_switch(node,node->next);
                            }
                            else{
                                node = node_switch(node,node->next);
                                prev->next = node;
                            }
                            // temp = list;
                            // while(temp->next!=node && temp->next!=NULL){
                            //     temp = temp->next;
                            // }
                            // temp->next = node;
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
                                prev->next = node;
                            }
                            change = 1;
                        }
                    }
                    prev = node;
                    node = node->next;
                    test = list;
                    for(int i=0; test != NULL; i++){
                        printf("%d:%s %s %d %0.1f %s\n",i,test->food_name,test->store_name,test->price,test->score,test->comment_txt);
                        test = test->next;
                    }
                }
                if(change == 0){
                    break;
                }
                node = list;
            }
            return list;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }
}
//尋找(回傳值為一個新的linked list)
struct linked_list *search_list(struct linked_list *list){
    
}