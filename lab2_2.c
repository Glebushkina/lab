#include <stdio.h>
#include <math.h>
#define lmax 200


int main()
{
	int a[lmax], b[lmax], z, n, p, r, l = -1, z1 = 0;
	float z2, n2, a1[lmax];
	printf("Лабораторная работа № 2\n");
   	// Задание № 1
   	printf("Задание № 2\n");
	printf("Введите цифру Z\n");
	do
	{
		r = scanf("%f", &z2);
		if (z2 != (int)z2 || r != 1 || fabs(z2) != z2 || z2 <= 0 || z2 > 9)
			printf("Некорректные данные, введите заново:\n");
		while (getchar() != '\n');
	} while (r != 1 || z2 != (int)z2 || (fabs(z2) != z2) || z2 <= 0 || z2 > 9);
	printf("Введите длину массива от 1 до 200:\n");
	do
	{
		r = scanf("%f", &n2);
		if (n2 != (int)n2 || r != 1 || n2 <= 0 || n2 >= 200)
			printf("Некорректные данные, введите заново:\n");
		while (getchar() != '\n');
	} while (n2 != (int)n2 || r != 1 || n2 < 1 || n2 >= 200);
	n = (int)n2;
	z = (int)z2;
	printf("Заполните массив:\n");
	for (int i = 0; i < n; i++)
	{
		do
		{
			r = scanf("%f", &a1[i]);
			if (a1[i] != (int)a1[i] || r != 1 || fabs(a1[i]) != a1[i])
				printf("Некорректные данные, введите заново:\n");
			while (getchar() != '\n');
		} while (a1[i] != (int)a1[i] || r != 1 || fabs(a1[i]) != a1[i]);
	}
	
	for (int i = 0; i < n; i++)
		a[i] = (int)a1[i];
	printf("Введен массив:\n");
	for (int i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		p = a[i];
		while (a[i] >= 1)
		{
			z1 = a[i] % 10; // остаток от деления
			a[i] /= 10;
		}
		if (z1 == z)
		{
		    if (l == -1)
		        l = 0;
			b[l] = p;
			l += 1;
		}
	}
	printf("Новый массив:\n");
	if (l >= 0)
	{
		for (int i = 0; i < l; i++)
			printf("%d ", b[i]);
	}
	else
		printf("Нет чисел, начинающихся на %d", z);
}