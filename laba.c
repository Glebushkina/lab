#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define lmax 200

void change (char *file_name, char *file_out){
    FILE *input_file, *output_file;
    char a[lmax], k; 
    output_file = fopen(file_out, "w");
    input_file = fopen(file_name, "r");
    if (input_file == NULL){
        printf("Can't open file %s\n", file_name);
        fclose(output_file); 
        return;
    }
    // пока в файле есть строки считаем и обработаем их
    while (fgets(a, lmax, input_file) != NULL){
        for (int i = 0; i < strlen(a) - 2; i += 2){ // пропустить 2 последних символа '\n' и '\0'
            k = a[i];
            a[i] = a[i + 1];
            a[i + 1] = k; 
        }
        fputs(a, output_file);//fputs записывает в файл строку  
    }
    fclose(input_file);
    fclose(output_file);
    return;
}

void show(char *file_name){
    FILE *input_file;
    char a[lmax]; 
    input_file = fopen(file_name, "r");
    if (input_file == NULL){
        printf("Can't open file %s\n", file_name);
        return;
    }
    while (fgets(a, lmax, input_file) != NULL){
        printf("%s", a);    
    }
    fclose(input_file);
    return;
}

int main(){
    char input_file_name[lmax];
    char output_file_name[lmax];
    printf("Input input file name: ");
    fgets(input_file_name, lmax, stdin);
    input_file_name[strcspn(input_file_name, "\n")] = 0;
    printf("Input output file name: ");
    fgets(output_file_name, lmax, stdin);
    output_file_name[strcspn(output_file_name, "\n")] = 0;
    change(input_file_name, output_file_name);
    show(output_file_name);
    return 0;
}