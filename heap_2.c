#include<stdio.h>
#include<limits.h>

int heap[1000], heap_size, size, lim=4;

void intialize()
{
    heap_size = 0;
    heap[0] = -INT_MAX;
}

void insert(int no)
{
    heap_size++;
    heap[heap_size] = no;
    printf("location=%d,value=%d \n", heap_size, heap[heap_size]);

    int now = heap_size;
    while (heap[now / 2] > no)
    {
        heap[now] = heap[now / 2];
        now /= 2;
        printf("now is %i\n",now);
    }
    heap[now] = no;
}

void option_1()
{
	printf("How many elements you want to add?\n");
	int new_size;
    scanf("%i", &new_size);
    size += new_size;
    printf("%i\n", size);
    int no, iter;
    for(iter = 1; iter <= new_size; iter++) {
        printf("Enter next elements you want to add to the heap!:  ");
        scanf("%i", &no);
        insert(no);
    }
    printf("array contains: ");
    for(iter = 1; iter <= size; iter++)
    {
        printf("%d ", heap[iter]);
    }
}

void option_2()
{
	//do nothing
}
void option_3()
{
	//do nothing
}

int main()
{
	//intially
    printf("How many elements you want to add?\n");
    scanf("%i", &size);
    printf("%i\n", size);
    intialize();
    int no, iter;
    for(iter = 1; iter <= size; iter++) {
        printf("Enter next elements you want to add to the heap!:  ");
        scanf("%i", &no);
        insert(no);
        //printf("%i, %i \n", iter, size);
    }
    printf("array contains: ");
    for(iter = 1; iter <= size; iter++)
    {
        printf("%d ", heap[iter]);
    }
    //end intially
    
    //now three option
    printf("\nWhat do you want to do now?\n1:Insert\n2:Extract Min\n3:Is Empty\n");
    int ques;
    scanf("%i", &ques);
    printf("%i\n", ques);
    switch(ques)
    {
    	case 1:
    		option_1();
    		break;
    	case 2:
    		option_2();
    		break;
    	case 3:
    		option_3();
    		break;
    }
}
