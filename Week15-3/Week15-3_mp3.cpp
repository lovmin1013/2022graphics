#include "CMP3_MCI.h"
#include <stdio.h>
CMP3_MCI mp3;
int main()
{
    mp3.Load("JJK.mp3");
    mp3.Play();
    printf("現在正在播放音樂\n");
    int N;
    scanf("%d", &N);
}
