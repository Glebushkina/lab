#include <stdio.h>
#include <stdbool.h> //библиотека, которая нужна для работы с типом данных bool. Bool (булев тип) — тип данных в информатике, принимающий два возможных значения: истину (true) и ложь (false).  
#include <math.h> 
#define lmax 200

int main(){
	int n, m, r, a[lmax][lmax], k = 0, b[lmax], count, i = 0;
	float n1, m1, a1[lmax][lmax];
	bool flag;
	printf("Лабораторная работа № 2\n");
            // Задание № 1
            printf("Задание № 1\n");
	printf("Введите размеры матрицы n на m от 1 до %d:\n", lmax);
	do{
r = scanf("%f%f", &n1, &m1); //n-строки, m-столбцы
		if (r != 2 || n1 > 199 || n1 < 1 || m1 > 199 || m1 < 1 || n1 != (int)n1 || m1 != (int)m1)
			printf("Некорректные данные, введите заново:\n");
		while (getchar() != '\n'); //очистка входного потока    
	} while (r != 2 || n1 > 199 || n1 < 1 || m1 > 199 || m1 < 1 || n1 != (int)n1 || m1 != (int)m1);
	n = (int)n1;
	m = (int)m1;
	printf("Заполните матрицу %d на %d (по одному элементу на каждой строке):\n", n, m);
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			do
			{
				r = scanf("%f", &a1[i][j]);
				if (r != 1 || a1[i][j] != (int)a1[i][j])
					printf("Некорректные данные, введите заново:\n");
				while (getchar() != '\n');
			} while (r != 1 || a1[i][j] != (int)a1[i][j]);
		}
	}
	for (i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = (int)a1[i][j];
	printf("Введенная матрица:\n");
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%8d ", a[i][j]);
		    	printf("\n");
	}
	for (int j = 0; j < m; j++) {// проходимся по столбцам
        flag=false;
        i=0;
        while (flag == false && i < n){
            if (a[i][j] == 0){//если нашли 0,то выходим
                flag=true;
                }
            i++;
        }
        if (flag == true){
            for (i = 0; i < n; i++){
                a[i][k]=a[i][j];
            }
            k++;
        }
	}
	printf("Измененная матрица:\n");
	if (k!=0){
    	for (i = 0; i < n; i++)
	    	{
		    for (int j = 0; j < k; j++){
		    	printf("%8d ", a[i][j]);
		    }
		    	printf("\n");
	    	}
	}
    else
        printf("Все элементы удалены!");
return 0;
}