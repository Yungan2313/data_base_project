#include "basic.h"

//帳號：總字數限20、至少2個大寫2個小寫、要有數字、不可空白、不能跟其他帳號重複
void account(char* account_name){
    int access = 0;
    account_name = (char*)malloc(sizeof(char) * 21);
    origin:while(access != 1){
        fget(account_name, 21, stdin);
        if(account_name == NULL){
            printf("Where is your account?\n");
            printf("Please retype it again\n");
            goto origin;
        }
        int big_word = 0, small_word = 0, number = 0;
        for(int i = 0; i < 21; i++){
            if(*(account_name + i) <= 'Z' && *(account_name + i) >= 'A'){
                big_word++;
            }
            else if (*(account_name + i) <= 'z' && *(account_name + i) >= 'a'){
                small_word++;
            }
            else if (*(account_name + i) <= '9' && *(account_name + i) >= '0'){
                number++;
            }
        }
        if(big_word < 2 || small_word < 2 || number == 0){
            printf("Your account name is in the wrong format.\n");
            printf("Please retype it again\n");
        }
        else{
            access = 1;
        }
    }
}

int similiar(char *corres_password, char *account_name){
    int k = 0, g = 0;
    for (int j = 0; *(corres_password + j) != '\0' && *(account_name + j) != '\0'; j++){
        if (*(corres_password + j) < 'Z' && *(corres_password + j) > 'A' &&\
            *(account_name + j) < 'Z' && *(account_name + j) > 'A' &&\
            *(corres_password + j) < 'z' && *(corres_password + j) > 'a' &&\
            *(account_name + j) < 'z' && *(account_name + j) > 'a'){
                *(corres_password + j) = tolower(*(corres_password + j));
                *(account_name + j) = tolower(*(account_name + j));
            }
    }
    for (int j = 0; *(account_name + j) != '\0'; j++){
        k++;
    }                
    char *tmpstring;
    tmpstring = (char *)malloc(sizeof(char) * (k + 1));
    for (int j = 0; *(account_name + j) != '\0'; j++){
        *(tmpstring + j) = *(account_name + j);
    }
    *(tmpstring + k) = '\0';
    for (int i = 1; i < 2; i++){
        if (*(corres_password) != *(tmpstring)){
                printf("No longest common prefix\n");
                return 0;
        }
        for (int j = 0; *(corres_password + j) != '\0'; j++){
            
        }
    }
    for (int j = 0; j < k; j++){
        printf("%c", *(tmpstring + j));
    }
    return 0;
}

//密碼：不能含特殊字元(除了英文跟數字以外的)、字數限20、不可空白、不能跟帳號重複(strcat)或相似(函式、嚴格比對)
void password(char *corres_password, char *account_name){
    int access = 0;
    corres_password = (char *)malloc(sizeof(char) * 21);
    origin:while(access != 1){
        fgets(corres_password, 21, stdin);
        if(corres_password == NULL){
            printf("Where is your account?\n");
            printf("Please try a new password");
            goto origin;
        }
        else if(strcat(corres_password, account_name) == 1){
            printf("Your password is the same as your account");
            printf("Please try a new password");
            goto origin;
        }
        for(int i = 0; i < 21; i++){
            if (~(*(account_name + i) <= 'Z' && *(account_name + i) >= 'A') &&\ 
            ~(*(account_name + i) <= 'z' && *(account_name + i) >= 'a') &&\
            ~(*(account_name + i) <= '9' && *(account_name + i) >= '0')){
                printf("Invalid password.\n");
                printf("Please try a new password");
                goto origin;
            }
        }
        access = 1;
    }
}