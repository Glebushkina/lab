#include <stdio.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#define lmax 200

struct information{
    char name[lmax], city[lmax];
  	int year;
};

struct book {
  	char name[lmax], author[lmax];
    float price;
  	int number;
  	struct information publish;
};

void getdata(struct book text[], int *k, char filename[]);
int check_year (int check_year);
void output(struct book text[], int k);
void find(struct book text[], int k, char res[][lmax], int *n);
void make_res_2(char fileres[], char res[][lmax], int n);
void make_res_1(char fileres[]);
void deln(char *s);
void input_string(FILE *f, char input[], int j);
void clean(FILE *f);
int probel(char *str);

int main() {
  	puts("Laboratory work 6");
  	puts("Task 1");
  	struct book text[lmax];
	char res[lmax][lmax], filename[lmax], fileres[lmax];
  	int i, k, n = 0;
    puts("Input file name");
	fgets(filename, lmax, stdin); 
    filename[strcspn(filename, "\n")] = 0;
  	getdata(text, &k, filename);
	output(text, k);
    puts("Input the file name for the result");
	fgets(fileres, lmax, stdin); 
    fileres[strcspn(fileres, "\n")] = 0;
	if (k == 1){
        make_res_1(fileres);
	}
	else{
		find(text, k, res, &n);
        make_res_2(fileres, res, n);
	}
  	return 0;
}

int check_year (int check_year) {
  	int flag = 0;
 	time_t t;
  	time(&t);
  	struct tm *today = localtime(&t);
  	int year = today->tm_year + 1900;
 	if(year >= check_year) {
    		flag = 1;
  	}
  	return flag;
}

void deln(char *s){
	for (; *s && *s!='\n'; s++);
    *s='\0';
}

void input_string(FILE *f, char input[], int j) {
  	if(fgets(input, lmax , f) == NULL ){
    	printf("The mistake in data in the string %d (end of file or input error)\n", j);
    	exit(1);
  	}
	if(strcmp(input, "\n") == 0 || probel(input) == 1){
		printf("The mistake in data in the string %d (the line is empty)\n", j);
    	exit(2);
	}
	deln (input);
}

int probel(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace((unsigned char)str[i])) { // если не пробел, то 0(isspace)
            return 0;
		}
    }
    return 1; // Все символы - пробелы
}

void clean(FILE *f) {
    int c;
    while ((c = fgetc(f)) != '\n' && c != EOF);
}

void getdata(struct book text[], int *k, char filename[]) {
    FILE *f = fopen(filename,"r");
	struct book *uk = text;
    int j = 1;
    if (!f) {
        puts("Error opening file");
        exit(1);
    }
    while (!feof(f)){
        float s;
		input_string(f, uk->name, j);
		printf("%s\n", uk->name);
        j++;
        if(fscanf(f, "%f",&uk->price)!= 1) {
    		printf("The mistake in the data in the string %d\n", j);
    		exit(3);
        }
		clean(f);
        j++;
		printf("%f\n", uk->price);
        if(fscanf(f, "%f", &s) != 1 || s!=(int)s) {
    		printf("The mistake in the data in the string %d (The number should be integer)\n", j);
    		exit(4);
        }
		clean(f);
        uk->number = (int)s;
		printf("%d\n", uk->number);
		s = 0;
        j++;
		input_string(f, uk->author, j);
		printf("%s\n", uk->author);
        j++;
        int flag=1;
  	    if(fscanf(f, "%d", &uk->publish.year)!= 1) {
    		printf("The mistake in the data in the string %d (The number should be integer)\n", j);
    		exit(6);
  	    }
  	    else {
    		flag = check_year(uk->publish.year);
    		if(flag == 0) {
      			printf("The year in the string %d is wrong (It should be up to the present day)\n", j);
      			exit(7);
    		}
        }
		clean(f);
        j++;
		input_string(f, uk->publish.name, j);
		printf("%s\n", uk->publish.name);
        j++;
		input_string(f, uk->publish.city, j);
		printf("%s\n", uk->publish.city);
        j++;
        (*k)++;
		uk++;
    }
    fclose(f);
}

void find(struct book text[], int k, char res[][lmax], int *n){
	struct book *uk = text;
	int dop[lmax][2], imax = 0;
	if (k == 2){
		if (uk->price == (uk+1)->price){
			if(strcmp(uk->publish.name, (uk+1)->publish.name) != 0){
				strcpy(res[0], uk->publish.name);
				(*n)++;
				strcpy(res[1], (uk+1)->publish.name);
				(*n)++;
			}
			else{
				strcpy(res[0], uk->publish.name);
				(*n)++;
			}
		}
		else{
			if (uk->price > (uk+1)->price){
				strcpy(res[0], (uk+1)->publish.name);
				(*n)++;
			}
			else{
				strcpy(res[0], uk->publish.name);
				(*n)++;
			}
		}
	}
	if (k >= 3){
		float s = k/3;
		*n = (int)s;
		for (int i = 0; i < *n; dop[i++][0] = INT_MAX);
		for(int i = 0;uk < text + k; uk++, i++) {
			if (uk->price < dop[imax][0]){
				dop[imax][0] = uk->price;
				dop[imax][1] = i;
				for (int j = 0; j < *n; j++){
					if (dop[j][0] > dop[imax][0]){
						imax = j;
					} 
				}
			}
		}
		for (int i = 0; i < *n; i++){
			uk = text;
			int j = 0;
			int k = dop[i][1];
			while ((strcmp(res[j], (uk+k)->publish.name) || i == j) && j < *n){
            	j = j+1;
        	}
			if (j >= *n){
				strcpy(res[i], (uk+k)->publish.name);}
		}
    }
}

void make_res_1(char fileres[]){
    FILE *f = fopen(fileres,"w");
    fputs("There is no cheapest book because there is only one book in the structure", f);
    puts("Result in the file");
    fclose(f);
}

void make_res_2(char fileres[], char res[][lmax], int n){
    FILE *f = fopen(fileres,"w");
	fputs("The name of publishers:", f);
	for (int i = 0; i < n; i++){
		fprintf(f, "\n%s", res[i]);
	}
    puts("Result in the file");
    fclose(f);
}

void output(struct book text[], int k){
	struct book *uk = text;
	int i = 1;
	for(;uk < text + k; uk++) {
		printf("\t\tBook %d\n", i++);
		printf("Name: \t\t\t%s\n",uk->name);
		printf("Price: \t\t\t%.2f\n",uk->price);
		printf("Pages: \t\t\t%d\n",uk->number);
		printf("Author: \t\t%s\n",uk->author);
		puts("Publisher:");
		printf("	Year: \t\t%d\n",uk->publish.year);
		printf("	Name: \t\t%s\n",uk->publish.name);
		printf("	City: \t\t%s\n",uk->publish.city);
	}
}