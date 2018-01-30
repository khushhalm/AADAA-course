#include<stdio.h>
#include<limits.h>

int heap[1000], heap_size, size;

void print_array()
{
	printf("array contains: ");
	int iter;
	for(iter = 1; iter <= size; iter++)
    {
        printf("%d ", heap[iter]);
    }
}

void insert(int no)
{
    heap_size++;
    heap[heap_size] = no;

    int now = heap_size;
    while (heap[now / 2] > no)
    {
        heap[now] = heap[now / 2];
        now /= 2;
    }
    heap[now] = no;
}

void inserting_elements(int inserting)
{
    int no, iter;
    for(iter = 1; iter <= inserting; iter++) {
        printf("Enter next elements you want to insert to the heap!:  ");
        scanf("%i", &no);
        insert(no);
    }
    print_array();
}

void option_0()
{
    printf("How many elements you want to insert?\n");
    scanf("%i", &size);
    
    //init array
    heap_size = 0;
    heap[0] = -INT_MAX;
    //end of init
    
    int inserting=size;
    inserting_elements(inserting);
}

void option_1()
{
    printf("How many elements you want to insert?\n");
    int new_size;
    scanf("%i", &new_size);
    size += new_size;
    int inserting=new_size;
    inserting_elements(inserting);
}

void e_min()
{
	printf("Min no is %i", heap[1]);
	int now=1, even=2, odd=3;
	int no = heap[size];
	heap[now]=heap[size];
	size-=1;
	heap_size-=1;
	while (odd<=size)
	{
		if (heap[even]<=heap[odd])
		{
			if (heap[even]<no)
			{
				heap[now]=heap[even];
				heap[even]=no;
			}
			else
			{
				print_array();
				break;
			}
			now=even;
			even*=2;
			odd=even+1;
		}
		else if (heap[odd]<heap[even])
		{
			if (heap[odd]<no)
			{
				heap[now]=heap[odd];
				heap[odd]=no;
			}
			else
			{
				print_array();
				break;
			}
			now=odd;
			even=odd*2;
			odd=even+1;
		}
		else
		{
			printf("broken");
			print_array();
		}
	}
	if(even==size)
	{
		if (heap[even]<no)
		{
			heap[now]=heap[even];
			heap[even]=no;
		}
	}
	print_array();
}
void option_3()
{
	//check for empty
	if (heap_size==0)
		printf("It is empty");
	else
		printf("It is not empty");
}

int main()
{  
    while(1)
	{
		printf("\nWhat do you want to do now?\n1:Insert\n2:Extract Min\n3:Is Empty\n4:Exit\n");
		int ques;
		scanf("%i", &ques);
		switch(ques)
		{
			case 1:
				if(size==0)
				{
					option_0();
				}
				else
				{
					option_1();
				}
				break;
			case 2:
				e_min();
				break;
			case 3:
				option_3();
				break;
			case 4:
				return 0;
		}
    }
}
