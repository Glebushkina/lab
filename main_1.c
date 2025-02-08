#include <stdio.h>
#include <time.h>
#include <string.h>
#include <limits.h>
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

void input(struct book text[], int *k);
int check_year (int check_year);
void output(struct book text[], int k);
void find(struct book text[], int k, char res[][lmax], int *n);
void output_res(char res[][lmax], int n);

int main() {
  	puts("Laboratory work 6");
  	puts("Task 1");
  	struct book text[lmax];
	char res[lmax][lmax];
  	int i, k, n = 0;
  	input(text, &k);
	output(text, k);
	if (k == 1){
		puts("\nThere is no cheapest book because there is only one book in the structure");
	}
	else{
		find(text, k, res, &n);
		output_res(res, n);
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

void input(struct book text[], int *k) {
	int r, y, i;
	float k1, s, s1, s2;
	puts("Input the number of the book:");
	do{
		r=scanf("%f", &k1);
		if (r != 1 || k1 < 1 || k1 > 199 || k1 != (int)k1){
			puts("Incorrect data, input it again:");}
		while (getchar() != '\n');
	}while (r != 1 || k1 < 1 || k1 > 199 || k1 != (int)k1);
	r = 0;
	*k = (int)k1;
  	for(i = 0; i < *k; i++) {
    	printf("Book %d\n", i+1);
    	do {
      		puts("Input the name of the book:");
      		fgets(text[i].name, lmax, stdin); 
			text[i].name[strcspn(text[i].name, "\n")] = 0;
    	} while(strcmp(text[i].name, "")==0); //Ввод названия книги
		puts("Input price:");
  		do {
			r = scanf("%f", &s);
   			if(r != 1 || s > INT_MAX || s < 0){
				puts("Incorrect data, input it again:");}
     		while(getchar()!='\n');
  		} while(r != 1 || s > INT_MAX || s < 0); //Ввод цены
		r = 0;
		text[i].price = s;
		puts("Input the number of pages:");
		do {
			r = scanf("%f", &s1);
   			if(r != 1  || s1 > INT_MAX || s1 < 1 || s1 != (int)s1){
				puts("Incorrect data, input it again:");}
     		while(getchar()!='\n');
  		} while(r != 1 || s1 > INT_MAX || s1 < 1 || s1 != (int)s1); //Ввод числа страниц
		r = 0;
		text[i].number = (int)s1;
		do {
      		puts("Input the author of the book:");
      		fgets(text[i].author, lmax, stdin);
			text[i].author[strcspn(text[i].author, "\n")] = 0;
    	} while(strcmp(text[i].author, "")==0); //Ввод автора книги
		do {
      		puts("Input the name of the publisher:");
			fgets(text[i].publish.name, lmax, stdin);
			text[i].publish.name[strcspn(text[i].publish.name, "\n")] = 0;
    	} while(strcmp(text[i].publish.name, "")==0); //Ввод названия издательства
		do {
      		puts("Input the city of the publisher:");
      		fgets(text[i].publish.city, lmax, stdin);
			text[i].publish.city[strcspn(text[i].publish.city, "\n")] = 0;
    	} while(strcmp(text[i].publish.city, "")==0); //Ввод города издательства
    	do {
			puts("Input the year of publication:");
      		do {
				r = scanf("%f", &s2);
   				if(r != 1 || s2 > INT_MAX || s2 < 0 || s2 != (int)s2){
					puts("Incorrect data, input it again:");}
     			while(getchar()!='\n');
  			} while(r != 1 || s2 > INT_MAX || s2 < 0 || s2 != (int)s2);
			y = (int)s2;
    	} while(check_year(y) != 1); 
    	text[i].publish.year = y; //Ввод года
}
}

void find(struct book text[], int k, char res[][lmax], int *n){
	int dop[lmax][2], imax = 0;
	if (k == 2){
		if (text[0].price == text[1].price){
			if(strcmp(text[0].publish.name, text[1].publish.name) != 0){
				strcpy(res[0], text[0].publish.name);
				(*n)++;
				strcpy(res[1], text[1].publish.name);
				(*n)++;
			}
			else{
				strcpy(res[0], text[0].publish.name);
				(*n)++;
			}
		}
		else{
			if (text[0].price > text[1].price){
				strcpy(res[0], text[1].publish.name);
				(*n)++;
			}
			else{
				strcpy(res[0], text[0].publish.name);
				(*n)++;
			}
		}
	}
	if (k >= 3){
		float s = k/3;
		*n = (int)s;
		for (int i = 0; i < *n; dop[i++][0] = INT_MAX);
    	for (int i = 0; i < k; i++){
			if (text[i].price < dop[imax][0]){
				dop[imax][0] = text[i].price;
				dop[imax][1] = i;
				for (int j = 0; j < *n; j++){
					if (dop[j][0] > dop[imax][0]){
						imax = j;
					} 
				}
			}
		}
		for (int i = 0; i < *n; i++){
			int j = 0;
			while ((strcmp(res[j], text[dop[i][1]].publish.name) || i == j) && j < *n){
            	j = j+1;
        	}
			if (j >= *n){
				strcpy(res[i], text[dop[i][1]].publish.name);}
		}
    }
}

void output_res(char res[][lmax], int n){
	puts("The name of publishers:");
	for (int i = 0; i < n; i++){
		printf("%s\n", res[i]);
	}

}

void output(struct book text[], int k){
	for(int i = 0; i < k; i++) {
		printf("\t\tBook %d\n", i+1);
		printf("Name: \t\t\t%s\n",text[i].name);
		printf("Price: \t\t\t%.2f\n",text[i].price);
		printf("Pages: \t\t\t%d\n",text[i].number);
		printf("Author: \t\t%s\n",text[i].author);
		puts("Publisher:");
		printf("	Year: \t\t%d\n",text[i].publish.year);
		printf("	Name: \t\t%s\n",text[i].publish.name);
		printf("	City: \t\t%s\n",text[i].publish.city);
	}
}