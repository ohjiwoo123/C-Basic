#include <stdio.h>

struct GameInfo {
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame; // 연관 업체 게임
};

int main(void)
{

// 구조체 사용 
struct GameInfo gameInfo1;
gameInfo1.name="나도게임";
gameInfo1.year=2017;
gameInfo1.price=50;
gameInfo1.company="나도회사";

struct GameInfo gameInfo2 = {"너도게임", 2017, 100, "너도회사"};

// 구조체 포인터
struct GameInfo * gamePtr; // 미션맨
gamePtr = &gameInfo1;
printf("\n\n-- 미션맨의 게임 출시 정보 --\n");
printf("  게임명  : %s\n", (*gamePtr).name);
printf("  발매년도  : %d\n", (*gamePtr).year);
printf("  가격  : %d\n", (*gamePtr).price);
printf("  제작사  : %s\n", (*gamePtr).company);

printf("\n\n-- 미션맨의 게임 출시 정보 --\n");
printf("  게임명  : %s\n", gamePtr->name);
printf("  발매년도  : %d\n", gamePtr->year);
printf("  가격  : %d\n", gamePtr->price);
printf("  제작사  : %s\n", gamePtr->company);

// 연관 업체 게임 소개 
gameInfo1.friendGame = &gameInfo2;

// 연관 업체의 게임 출시 정보
printf("\n\n-- 미션맨 친구의 게임 출시 정보 --\n");
printf("  게임명  : %s\n", gameInfo1.friendGame->name);
printf("  발매년도  : %d\n", gameInfo1.friendGame->year);
printf("  가격  : %d\n", gameInfo1.friendGame->price);
printf("  제작사  : %s\n", gameInfo1.friendGame->company);

}