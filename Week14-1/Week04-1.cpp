#include <stdio.h>
int main()
{
    FILE * fout = fopen("file.txt","w+");
    ///開啟檔案                /// write+順便新增
    printf("Hello World\n");
    fprintf(fout, "Hello World\n");
    ///印出來 寫出來
    fclose(fout); ///關閉檔案
}
