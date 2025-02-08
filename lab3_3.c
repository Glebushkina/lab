#include <stdio.h>
#define lmax 200

void masiv_input(int *n, int a[lmax]);
void kolvo(int n, int a[lmax]);
void nov(int n, int a[lmax]);

int main() {
    int n, a[lmax];
    printf("Лабораторная работа № 3\n");
    printf("Задание № 3\n");
    masiv_input(&n, a);//Передача по адресу: Когда передаете адрес переменной, как в случае с &n, функция получает доступ к оригинальной переменной. Изменения, внесенные внутри функции, будут видны за её пределами
    kolvo(n, a);//функция, считающая количество повторений каждого элемента массива
    nov(n, a);//функция новый массив, состоящий из элементов, которые не повторяются в массиве A

    return 0;
}

void masiv_input(int *n, int a[lmax]){
    int r;
    float n1, a1[lmax];
    printf("Введите длину массива от 1 до 200:\n");
	do
	{
		r = scanf("%f", &n1);
		if (n1 != (int)n1 || r != 1 || n1 <= 0 || n1 >= 200)
			printf("Некорректные данные, введите заново:\n");
		while (getchar() != '\n');
	} while (n1 != (int)n1 || r != 1 || n1 < 1 || n1 >= 200);
	*n = (int)n1;
	printf("Заполните массив:\n");
	for (int i = 0; i < *n; i++)
	{
		do
		{
			r = scanf("%f", &a1[i]);
			if (a1[i] != (int)a1[i] || r != 1)
				printf("Некорректные данные, введите заново:\n");
			while (getchar() != '\n');
		} while (a1[i] != (int)a1[i] || r != 1);
	}
	
	for (int i = 0; i < *n; i++)
		a[i] = (int)a1[i];
	printf("Введен массив:\n");
	for (int i = 0; i < *n; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void kolvo(int n, int a[lmax]){
    int nb = 0, kol[lmax], b[lmax];
    for(int i = 0; i < n; i++){
        int j = 0;
        while (a[i] != b[j] && j <= nb){//проверка присутствия  a[i]  в массиве b
            j = j+1;
        }
        if (j > nb){//a[i] отсутствует в b
			b[nb]=a[i];
			kol[nb]=1;
			nb=nb+1;
            }
        else{
            kol[j]=kol[j]+1;
        }
        }
    for(int i = 0; i < nb; i++){
        printf("Элемент %d встречается в массиве %d раз(а)", b[i], kol[i]);
        printf("\n");
    }
}

void nov(int n, int a[lmax]){
    int nb, b[lmax];
    nb = 0;
    for(int i = 0; i < n; i++){
        int j = 0;
        while ((a[i] != a[j] || i == j) && j <= n){
            j = j+1;
        }
        if (j > n){ //a[i] не повторяется
			b[nb]=a[i]; 
			nb=nb+1;	
        }
    }
    if (nb == 0){
        printf("Нет уникальных элементов\n");
    }
    else{
        printf("Массив из уникальных элементов\n");
        for(int i = 0; i < nb; i++){
            printf("%d ", b[i]);
        }
    }
}
