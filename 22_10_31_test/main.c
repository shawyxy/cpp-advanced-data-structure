#include <stdio.h>
int main()
{
    FILE* fp = fopen("log.txt", "r") // 以只读形式打开文件
    if(fp == NULL)
    {
        perror("fopen");
        return 1;
    }
    const char line[64];
    while(fgets(line, sizeof(line), fp) != NULL)
    {
        fprintf(stdout, "%s\n", line);
    }
    fclose(fp);
    return 0;
}
