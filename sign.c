#include "basic.h"
//帳密總字數限20、至少2個大寫2個小寫、不可空白

void account(){
    char* account_name;
    account_name = (char*)malloc(sizeof(char) * 21);
    fgets(account_name, 21, stdin);
}
void password(){

}