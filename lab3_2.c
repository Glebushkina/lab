#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#define lmax 200

void matrix_input(int n, int m, float a[lmax][lmax]);
void matrix_output(int n, int m, float a[lmax][lmax]);
float matrix_func(int n, int m, float a[lmax][lmax]);
int input();
void output(int n, float min);

int main()
{
    int n, m;
    float min, a[lmax][lmax];
	printf("Лабораторная работа № 3\n");
   	printf("Задание № 2\n");
   	printf("Введите количество строк в матрице:\n");
   	n = input();
   	printf("Введите количество столбцов в матрице:\n");
   	m = input();
   	matrix_input(n, m, a);
	printf("Введенная матрица:\n");
	matrix_output(n, m, a);
	min = matrix_func(n, m, a);
	output(n, min);
return 0;
}

void matrix_input(int n, int m, float a[lmax][lmax]){
    int r;
    printf("Заполните матрицу %d на %d (по одному элементу на каждой строке):\n", n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			do
			{
				r = scanf("%f", &a[i][j]);
				if (r != 1 || a[i][j] > INT_MAX)
					printf("Некорректные данные, введите заново:\n");
				while (getchar() != '\n');
			} while (r != 1 || a[i][j] > INT_MAX);
		}
	}
}
void matrix_output(int n, int m, float a[lmax][lmax]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%.3f ", a[i][j]);
        }
        printf("\n");
    }
}

int input(){
    float n1;
    int r, n;
    do
	{
		r = scanf("%f", &n1);
		if (r != 1 || n1 > 199 || n1 < 1 || n1 != (int)n1)
		    printf("Некорректные данные, введите заново:\n");
		while (getchar() != '\n');
	} while (r != 1 || n1 > 199 || n1 < 1 || n1 != (int)n1);
	n = (int)n1;
	return n;
}

float matrix_func(int n, int m, float a[lmax][lmax]){
    float min = INT_MAX,max;
    for (int j = 0; j < m; j++){
	   max = 0;
	   for (int i = 0; i < n - 1 ; i++){
	        if(fabs(a[i][j] - a[i+1][j])>fabs(max)){
	        	max = (a[i][j] - a[i+1][j]);
	       	    }
	        }
	   if (max < min){
	        min = max;
	        }
	    }return min;
}

void output(int n, float z){
    if (n == 1){
	    printf("Массив состоит из одной строки => нет разницы между элементами");
	}
	else{
	    printf("Полученное значение:\n");
	    printf("%.3f ", z);
	}
}