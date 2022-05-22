#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int cnt = 0;
    if((fp = fopen(argv[2], "r")) == NULL) {
        puts("error!\n");
    }
    if(argv[1][1] == 'w') {
        char s[1024];
        while(fscanf(fp,"%s",s) != EOF) {
            cnt++;
            for(int i = 1 ; i < strlen(s) - 1 ; i++) {
                if(s[i] == ',') {
                    cnt++;
                }
            }
        }
        printf("单词数=%d\n",cnt);
    } else if(argv[1][1] == 'c') {
        char c;
        while((c = fgetc(fp)) != EOF) cnt++;
        printf("字符数=%d\n",cnt);
    }
    fclose(fp);
    return 0;
}
