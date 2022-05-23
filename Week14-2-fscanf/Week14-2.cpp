#include <stdio.h>
int main()
{
    FILE * fout = fopen("file2.txt","w+");
    fprintf(fout, "angle %d\n", 999);
    fclose(fout);

    FILE * fin = fopen("file2.txt", "r");
    char line[200];
    int a;
    fscanf(fin, "%s %d", line, &a);
    printf("讀到了字串%s 及整數%d", line, a);
    fclose(fin);
}
