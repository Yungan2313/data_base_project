#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "lanpa 9.5 comment_test_lanpa.txt";
    char* third_word = NULL;

    char* token = strtok(str, " ");  // 以空白為分隔符號分割字串

    // 迭代到第三個位置
    for (int i = 0; i < 2; i++) {
        token = strtok(NULL, " ");
        if (token == NULL) {
            // printf("找不到目標位置\n");
            return 1;
        }
    }

    // 取得第三個位置的字串
    if (token != NULL) {
        third_word = token;
        printf("%s\n", third_word);
    } else {
        // printf("找不到目標位置\n");
        return 1;
    }

    return 0;
}