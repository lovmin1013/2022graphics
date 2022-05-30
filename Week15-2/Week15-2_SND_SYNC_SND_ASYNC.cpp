#include <windows.h> ///另一種寫法
#include <stdio.h>
int main()
{
    printf("現在是PlaySound()前\n");
    PlaySound("07042111.wav",NULL, SND_ASYNC);///不用等待、不同步
    printf("現在是PlaySound()後\n");
    int N;
    scanf("%d", &N);///等待輸入數字
}

