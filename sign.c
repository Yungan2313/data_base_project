#include "basic.h"
//帳密總字數限20、至少2個大寫2個小寫、要有數字、不可空白

void account(char* account_name){
    char* account_name;
    int access = 0;
    account_name = (char*)malloc(sizeof(char) * 21);
    while(access != 1){
        fget(account_name, 21, stdin);
        int big_word = 0, small_word = 0, number = 0;
        for(int i = 0; i < 21; i++){
            if(*(account_name + i) <= 'Z' && *(account_name + i) >= 'A'){
                big_word++;
            }
            else if (*(account_name + i) <= 'z' && *(account_name + i) >= 'a'){
                small_word++;
            }
            else if (*(account_name + i) <= '9' && *(account_name + i) >= '1'){
                number++;
            }
        }
        if(big_word < 2 || small_word < 2 || number == 0){
            printf("Your account name is at risk.\n");
            printf("Please retype again\n");
        }
    }

}
void password(){

}