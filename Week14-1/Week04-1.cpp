#include <stdio.h>
int main()
{
    FILE * fout = fopen("file.txt","w+");
    ///�}���ɮ�                /// write+���K�s�W
    printf("Hello World\n");
    fprintf(fout, "Hello World\n");
    ///�L�X�� �g�X��
    fclose(fout); ///�����ɮ�
}
