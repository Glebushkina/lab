#include <stdio.h>
#include <math.h>
#include <limits.h>

float formula(float a,float b,float c,float d,float e,float f);
void vivod(float a,float b,float c,float d,float e,float f);
float input();

int main()
{
	float a, b, c, d, e, f;
	printf("Лабораторная работа № 3\n");
   	printf("Задание № 1\n");
	printf("Введите a:\n");
	a=input();
	do
	{
	    if (a == 0){
			printf("Некорректные данные (в знаменателе a=0), введите заново:\n");
			a=input();
	    }
	} while (a == 0);
	printf("Введите b:\n");
	b=input();
	printf("Введите c:\n");
	c=input();
	printf("Введите d:\n");
	d=input();
	printf("Введите e:\n");
	e=input();
	printf("Введите f:\n");
	f=input();
	vivod(a, b, c, d, e, f);
	return 0;
}

float formula(float a,float b,float c,float d,float e,float f)
{
    return (f-c*d/a)/(e-d*b/a);
}
void vivod(float a,float b,float c,float d,float e,float f){
    float x,y;
    if ((e-d*b/a)==0){
        printf("В знаменателе 0 ((e-d*b/a)=0), решения нет");
    }
    else{
        x=c/a-b/a*formula(a,b,c,d,e,f);
        y=formula(a,b,c,d,e,f);
        printf("x = %f, y = %f\n", x, y);
    }
}
float input(){
    float n;
    int r;
    do
	{
		r = scanf("%f", &n);
		if (r != 1 || n>INT_MAX)
		    printf("Некорректные данные, введите заново:\n");
		while (getchar() != '\n');
	} while (r != 1 || n>INT_MAX);
	return n;
}
