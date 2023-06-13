#include "basic.h"
#include "linked_list.h"
#include "txtinput.h"
#include "login.h"
#include "sign.h"
#include "UI.h"
#include "action.h"
#include "comment.h"
char *user_account(char *data_base_txt){
    int i = 0;
    char *user = malloc(sizeof(char)*100);
    while(*(data_base_txt+i)!= '.'){
        // printf("%c", *(data_base_txt+i));
        *(user+i) = *(data_base_txt+i);
        i++;
    }
    *(user+i) = '\0';
    return user;
}

int main(){
    struct linked_list *list = NULL;
    struct linked_list *search_linked_list = NULL;
    struct comment_list *comment_list = NULL;
    char *user, *database_txt,*comment_txt = malloc(sizeof(char)*100);
    int temp,page = 0,type,order,choose;
    int search_page = 0,comment_page = 0;
    while(1){
        list = NULL;
        search_linked_list = NULL;
        printf("welcome to the database!\n");
        printf("log in or register?\n");
        printf("    [1]login\n");
        printf("    [2]register\n");
        printf("    [3]quit\n");
        printf("enter: ");
        scanf("%d",&choose);
        getchar();
        system("cls");
        if(choose == 1){
            database_txt = login();
            if(database_txt == NULL){
                database_txt = account();
            }
            else if(database_txt == "exit"){
                continue;
            }
        }
        else if(choose == 2){
            database_txt = account();
        }
        else if(choose == 3){
            break;
        }
        // printf("ok");
        // printf("%s------------------------------\n", database_txt);
        user = user_account(database_txt);
        // printf("%s------------------------------\n",user);
        list = data_base_read(database_txt);
        page = 0;
        free_linked_list(search_linked_list);
        while(1){
            if(database_UI(list,page)==-1){
                page--;
                printf("there is no next page\n");
                continue;
            }
            printf("action you can do:\n");
            printf("    [1]next page\n");
            printf("    [2]last page\n");
            printf("    [3]create new data\n");
            printf("    [4]delete data\n");
            printf("    [5]sort the data\n");
            printf("    [6]search the data\n");
            printf("    [7]see the comment\n");
            printf("    [8]logout\n");
            printf("enter: ");
            scanf("%d",&temp);
            getchar();
            switch(temp){
                case 1:
                    page++;
                    system("cls");
                    continue;
                case 2:
                    page--;
                    system("cls");
                    if(page<0){
                        page++;
                        system("cls");
                        printf("you already at the first page!\n");
                    }
                    continue;
                case 3:
                    // printf("%s %s----------------------------\n",user,database_txt);//----------------------------------------------------------------
                    list = add_list(list,user);
                    system("cls");
                    continue;
                case 4:
                    list = delete_list(list,user,page);
                    system("cls");
                    continue;
                case 5:
                    printf("which one is your basic type?\n");
                    printf("    [1]price\n");
                    printf("    [2]score\n");
                    printf("enter: ");
                    scanf("%d",&type);
                    getchar();
                    printf("For what order?\n");
                    printf("    [1]great to small\n");
                    printf("    [2]small to great\n");
                    printf("enter: ");
                    scanf("%d",&order);
                    getchar();
                    list = sort_list(list,type,order);
                    page = 0;
                    system("cls");
                    continue;
                case 6:
                    search_page = 0;
                    search_linked_list = search_list(list);
                    system("cls");
                    while(1){
                        if(database_UI(search_linked_list,search_page) == -1){
                            search_page--;
                            printf("there is no next page\n");
                            system("cls");
                            continue;
                        }
                        printf("action you can do:\n");
                        printf("    [1]next page\n");
                        printf("    [2]last page\n");
                        printf("    [3]quit search\n");
                        printf("enter: ");
                        scanf("%d",&choose);
                        getchar();
                        system("cls");
                        switch(choose){
                            case 1:
                                search_page++;
                                system("cls");
                                continue;
                            case 2:
                                search_page--;
                                system("cls");
                                if(search_page <0){
                                    search_page++;
                                    system("cls");
                                    printf("you already at the first page!\n");
                                }
                                continue;
                            case 3:
                                system("cls");
                                break;
                        }
                        break;
                    }
                    continue;
                case 7://搜尋list裡的位置，輸出txt，丟到UI，記得做page切換
                    comment_page = 0;
                    while(1){
                        // printf("%s %d\n", user,comment_page);
                        comment_txt = comment_choose(list,user,comment_page);
                        if(comment_txt == NULL){
                            system("cls");
                            printf("please enter the correct ID\n");
                            continue;
                        }
                        comment_list = comment_list_read(comment_txt);
                        break;
                    }
                    system("cls");
                    while(1){
                        if(comment_UI(comment_list,comment_page) == -1){
                            if(comment_page == 0){
                                system("cls");
                                printf("there is no comment\n");
                                break;
                            }
                            comment_page--;
                            system("cls");
                            printf("there is no next page\n");
                            continue;
                        }
                        printf("action you can do:\n");
                        printf("    [1]next page\n");
                        printf("    [2]last page\n");
                        printf("    [3]quit comment\n");
                        printf("enter: ");
                        scanf("%d",&choose);
                        getchar();
                        switch(choose){
                            case 1:
                                comment_page++;
                                system("cls");
                                continue;
                            case 2:
                                comment_page--;
                                system("cls");
                                if(comment_page <0){
                                    comment_page++;
                                    system("cls");
                                    printf("you already at the first page!\n");
                                }
                                continue;
                            case 3:
                                system("cls");
                                break;
                        }
                        break;
                    }
                    // printf("here!\n");----------------------------------------------
                    // free_comment_list(comment_list);
                    // printf("here!\n");
                    // free(comment_txt);
                    // printf("here!\n");
                    // comment_list = NULL;
                    // printf("here!\n");
                    continue;
                case 8:
                    log_out(list,user);
                    system("cls");
                    break;
            }
            system("cls");
            break;
        }

    }
    return 0;
}