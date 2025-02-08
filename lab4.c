#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define lmax 200

void substr(int *n, char str[lmax][lmax], char str1[lmax][lmax], int k, int num [], int *c);
int nomer(char str1[][lmax], int n);
void change(char str[][lmax], int z);

int main() {
    float k1;
    int r, k, n = 0, num[lmax], l, c = 0;
    char str[lmax][lmax], str1[lmax][lmax];
    printf("Лабораторная работа № 4\n");
    printf("Введите количество строк до 200:\n");
    do
    {
        r = scanf("%f", &k1);
        if (r != 1 || k1 > 199 || k1 < 1 || k1 != (int)k1){
            printf("Некорректные данные, введите заново:\n");}
        while (getchar() != '\n');
    } while (r != 1 || k1 > 199 || k1 < 1 || k1 != (int)k1);
    k = (int)k1;
    printf("Введите строки, содержащие не более, чем %d символов:\n", lmax);
    for(int i = 0; i < k; ++i){
        fgets(str[i], lmax, stdin);
        str[i][strcspn(str[i], "\n")] = 0;
    }
    puts("Задание 1");
    substr(&n, str, str1, k, num, &c);
    if (n == 0){
        printf("Полное удаление\n");
    }
    else{
        if(c == 0){
            printf("Удаления не было\n");
        }
        else{
            printf("Подстроки:\n");
            for (int i = 0; i < n; i++){
                puts(str1[i]);
        }
        }
    }
    puts("Задание 2");
    int z = nomer(str1, n);
    if (z == -1){
        puts("Нет необходимой подстроки");
        puts("Задание 3 не может быть выполнено");
    }
    else{
        puts("Строка, начинающаяся с четного (но не нулевого) числа цифр:");
        puts(str1[z]);
        puts("Задание 3");
        int g = strlen(str[num[z]]);
        int b = num[z];
        change(str,b);
        if (g == strlen(str[b])){
            puts("Нет удаления");
        }
        else{
            puts("Строка после удаления латинских букв:");
            puts(str[num[z]]);
        }
    }
    return 0;
}

void substr(int *n, char str[][lmax], char str1[][lmax], int k, int num [], int *c) {//n-кол-во подстрок, num - массив с номерами строк из которых выделялись подсроки
    char *s, *s1;//s-указатель на текущий элемент, s1 - на начало подстроки
    *n = 0;
    for(int i = 0; i < k ; i++){
        s = str[i];
        s1 = s;
        while (*s){
            if (*s == '.' || *s == ',' || *s == ';' || *s == ':'){
                (*c)++;
                if (s != s1){
                    num[*n] = i;
                    strncpy(str1[*n], s1, s - s1);
                    str1[*n][s - s1] = '\0';
                    (*n)++;
                }
                while(*s && (*s == '.' || *s == ',' || *s == ';' || *s == ':')){
                    s++;
                } 
            s1 = s;
            }
            else {
                s++;}
        }
        if (s != s1){
            num[*n] = i;
            strncpy(str1[*n], s1, s - s1);
            str1[*n][s - s1] = '\0';
            (*n)++;
        }
    }
}

int nomer(char str1[][lmax], int n){
    int m = -1, count = 0, f = 0;
    char *s;
    for(int i = 0; i < n && f == 0; i++){
        s = str1[i];
        while(*s && isdigit(*s)){
            count++;
            s++;
        }
        if(count % 2 == 0 && count != 0){
            m = i;
            f = 1;
        }
        else{
            count = 0;
        }
    }
    return(m);
}

void change(char str[][lmax], int z) {
    char *s = str[z];
    char *s1 = str[z];
    while (*s) {
        if (!isalpha(*s)) {
            *s1 = *s; 
            s1++;
        }
        s++;
    }
    *s1 = '\0';
}
