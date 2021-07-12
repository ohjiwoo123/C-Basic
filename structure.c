#include <stdio.h>

struct GameInfo {
    char * name;
    int year;
    int price;
    char * company;
};

int main(){

    // 구조체 배열
    struct GameInfo gameArray[2] = {
        {"나도게임", 2017, 50, "너도회사"},
        {"너도게임", 2017, 100, "너도회사"}
    };

    printf("-- 구조체 배열 기본 출력 게임 출시 정보 --\n");
    printf("%s\n",gameArray[0].name);
    printf("%d\n",gameArray[0].year);
    printf("%d\n",gameArray[0].price);
    printf("%s\n",gameArray[0].company);
    printf("\n\n%s\n",gameArray[1].name);
    printf("%d\n",gameArray[1].year);
    printf("%d\n",gameArray[1].price);
    printf("%s\n",gameArray[1].company);

    printf("\n\n-- 구조체 배열 다르게 출력 게임 출시 정보 --\n");
    printf("%s\n",gameArray->name);
    printf("%d\n",gameArray->year);
    printf("%d\n",gameArray->price);
    printf("%s\n",gameArray->company);

    printf("\n\n-- 구조체 배열 다르게 출력 게임 출시 정보 --\n");
    printf("%s\n",gameArray->name);
    printf("%d\n",gameArray->year);
    printf("%d\n",gameArray->price);
    printf("%s\n",gameArray->company);
    return 0;

}