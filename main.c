#include  <stdio.h>
#include <malloc.h>
#include <string.h>
#define lmax 200 

typedef struct node{
    struct node *next; 
    int info; 
} Node;

Node *getdata ();
void output (Node *queue);
void free_memory(Node *queue);
Node *new(Node *queue, int *f1);
void new_file (Node *queue, int f);
Node *sort(Node *queue, int *f2);


int main(){
    Node *queue;
    int f1 = 0, f2 = 0;
    puts("Laboratory work 6");
    puts("Task 1");
    queue = getdata();
    output(queue);
    puts("Task 2");
    queue = new(queue, &f1);
    if (f1 == 0){
        puts("The queue does not change");
        output(queue);
        new_file (queue, f1);
    }
    else{
        output(queue);
        new_file (queue, f1);
    }
    puts("Task 3");
    queue = sort(queue, &f2);
    output(queue);
    new_file (queue, f2);
    free_memory(queue);
}

Node *getdata () {
  	float n;
  	Node *add, *last, *first=NULL;
  	FILE *f;
  	char filename[lmax];
  	puts("Input file name");
    fgets(filename, lmax, stdin); 
    filename[strcspn(filename, "\n")] = 0;
  	if(!(f = fopen(filename, "r"))) {
    		puts("The file has not been found!");
    		exit(1);
  	}
    fseek(f, 0, SEEK_END);
    if (ftell(f) == 0) {
        puts("The file is empty!");
        fclose(f);
        exit(2);
    }
    fseek(f, 0, SEEK_SET);
    int j = 1;
    if(fscanf(f, "%f", &n) != 1 || n!=(int)n) {
            printf("The mistake in the data in the string %d (The number should be integer)\n", j);
            exit(3);
    }
    j++;
    first = (Node *) malloc(sizeof(Node)); 
    first->info = (int)n; //занесем число в поле данных
    last = first; //сделаем эту запись последней
    last->next = NULL; 
    while(fscanf(f, "%f",&n) == 1 ){ 
        if (n != (int)n){
            printf("The mistake in the data in the string %d (The number should be integer)\n", j);
            exit(4);
        }
        else{
            add = (struct node*) malloc(sizeof(struct node)); //память для добавляемой записи
            add->info = (int)n; 
            last->next = add; //присоединим её к cписку
            last = add; //сделаем эту запись последней
            last->next=NULL; 
            j++;
        }
    }
  	fclose(f);
  	return first;
}

void output (Node *queue){ //вывод списка на экран
    while(queue){
        printf("%7d", queue->info);
        queue = queue->next;
    }
    printf("\n");
}

void free_memory(Node *queue){ //освобождение памяти
    Node *now = queue, *next = queue;
    while (next){
        next=now->next;
        free(now);
        now=next;   
    }
    puts("Now memory is free");
}

Node *new(Node *queue, int *f1) {
    Node *add, *last = queue, *now = queue, *first = queue;
    if(now->info %2 != 0) {
        add = (Node *)malloc(sizeof(Node));
        add->info = 1;
        add->next = first;
        first = add;
        now = now->next;
        *f1 = 1;
    }
    while(now) {
        if(now->info %2 != 0) {
            add = (Node *)malloc(sizeof(Node));
            add->info = 1;
            add->next = now;
            last->next = add;
            last = add;
            *f1 = 1;
        }
    last = now;
    now = now->next;
    }
    return first;
}

void new_file (Node *queue, int l) {
    FILE *f;
    char fileres[lmax];
  	puts("Input file name");
    fgets(fileres, lmax, stdin); 
    fileres[strcspn(fileres, "\n")] = 0;
    f = fopen(fileres, "w");
    if (l == 0){
        fputs("The queue does not change\n", f);
    }
    while(queue){
        fprintf(f, "%d\n", queue->info);
        queue = queue->next;
    }
    puts("The result is in the file!");
    fclose(f);
}

Node *sort(Node *queue, int *f2) {
    Node *now = queue;
    while (now && now->info <= 0) {
        now = now->next;
    }

    if (!now || !now->next) {
        puts("There are no positive numbers or one number in the queue, the queue does not change.");
        return queue; // Если положительных элементов нет или только один, возвращаем очередь
    }

    int flag;
    Node *curr, *otsort = NULL;
    do {
        flag = 0;
        curr = now->next; // Начинаем с элемента после первого положительного
        while (curr->next != otsort) {
            if (curr->info < curr->next->info) {
                // Меняем данные местами
                int dop = curr->info;
                curr->info = curr->next->info;
                curr->next->info = dop;
                flag = 1;
                *f2 = 1;
            }
            curr = curr->next;
        }
        otsort = curr; // Перемещаем otsort на предыдущий узел
    } while (flag);

    return queue;
}