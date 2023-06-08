#include "basic.h"
#include "linked_list.h"
#include "txtinput.h"
#include "login.h"
#include "sign.h"
#include "UI.h"
#include "action.h"
#include "comment.h"

int main(){
    int type,order;
    printf("which one is your basic type?\n");
    printf("    [1]price\n");
    printf("    [2]score");
    scnaf("%d",&type);
    printf("For what order\n");
    printf(" [1]great to small\n");
    printf(" [2]small to great");
    scnaf("%d",&order);
}