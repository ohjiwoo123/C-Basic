#include <stdio.h>

struct GameInfo {
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame; // 연관 업체 게임
};

typedef struct GameInformation {
    char * name;
    int year;
    int price;
    char * company;

    struct GameInfo * friendGame; // 연관 업체 게임
} GAME_INFO;

int main()
{

int i = 1;
typedef int 정수;
typedef float 실수;
정수 정수변수 = 3; // int i = 3
실수 실수변수 = 3.23f; // float f = 3.23f
printf("정수변수 : %d, 실수변수 % 2f\n\n", 정수변수, 실수변수);

typedef struct GameInfo 게임정보;

게임정보 game1;

game1.name = "한글게임";
game1.year = 2015;

GAME_INFO game2;
game2.name="한글게임2";
game2.year=2012;

printf("게임 이름 : %s, 발매연도 : %d\n\n", game1.name, game1.year);
printf("게임 이름 : %s, 발매연도 : %d\n", game2.name, game2.year);

}