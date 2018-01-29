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
    //printf("location=%d,value=%d \n", heap_size, heap[heap_size]);

    int now = heap_size;
    while (heap[now / 2] > no)
    {
        heap[now] = heap[now / 2];
        now /= 2;
        //printf("now is %i\n",now);
    }
    heap[now] = no;
}

void option_0()
{
	printf("How many elements you want to insert?\n");
    scanf("%i", &size);
    printf("%i\n", size);
    
    //init array
    heap_size = 0;
    heap[0] = -INT_MAX;
    //end of init
    
    int no, iter;
    for(iter = 1; iter <= size; iter++) {
        printf("Enter next elements you want to insert to the heap!:  ");
        scanf("%i", &no);
        insert(no);
        //printf("%i, %i \n", iter, size);
    }
    print_array();
}

void option_1()
{
    printf("How many elements you want to insert?\n");
    int new_size;
    scanf("%i", &new_size);
    size += new_size;
    //printf("%i\n", size);
    int no, iter;
    for(iter = 1; iter <= new_size; iter++) {
        printf("Enter next elements you want to insert to the heap!:  ");
        scanf("%i", &no);
        insert(no);
    }
    print_array();
}

void option_2()
{
	//do nothing
	//extract min
	printf("Min no is %i", heap[1]);
	heap[1]=heap[size];
	int no = heap[size];
	size-=1;
	int now = size/2;
	int now_even;
	if (now==1 && size==2)
	{
		//now = 1;
		now_even = size;
		printf("\nnow=%i and now_even=%i\n",now, now_even);	
	}
	else if (now==1 && size==3)
	{
		now = 2;
		now_even = size;
		printf("\nnow=%i and now_even=%i\n",now, now_even);	
	}
	else if (now==2 && size==4)
	{
		//now = 2;
		now_even = 3;
		printf("\nnow=%i and now_even=%i\n",now, now_even);	
	}	
	else if (size%2==0)
	{
		now_even = size/2-1;
		printf("\nnow=%i and now_even=%i\n",now, now_even);	
	}
	else
	{
		now_even = size/2+1;
		printf("\nnow=%i and now_even=%i\n",now, now_even);
	}
	heap_size=size;
	int new_no = 1;
	while (now>=1 && now<=size && now_even>=1 && now_even<=size)
    {
    	if (heap[now]<no && heap[now]<=heap[now_even])
    	{
		    heap[now/2] = heap[now];
		    //no = heap[now];
		    new_no = now;
		    now *= 2;
		    now_even = now+1;
		    printf("\nnow is %i",now);
		    print_array();
        }
        else if (heap[now_even]<no && heap[now]>=heap[now_even])
        {
		    heap[now_even/2] = heap[now_even];
		    //no = heap[now_even];
		    new_no = now_even;
		    now_even *= 2;
		    now = now_even+1;
		    printf("\nnow_even is %i",now_even);
		    print_array();
		}
        else
        {
        	break;
        }
        printf("\nnow=%i and now_even=%i and \n",now, now_even);
    }
    
    heap[new_no]=no;
    printf("\nnow is %i, heap[now] is %i\n",now, heap[now]);
    print_array();
}
void option_3()
{
	//do nothing
	//check for empty
	if (heap_size==0)
	{
		printf("It is empty");
	}
	else
	{
		printf("It is not empty");
	}
}

int main()
{  
    //now three option
    while(1)
	{
		printf("\nWhat do you want to do now?\n1:Insert\n2:Extract Min\n3:Is Empty\n4:Exit\n");
		int ques;
		scanf("%i", &ques);
		//printf("%i\n", ques);
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
				option_2();
				break;
			case 3:
				option_3();
				break;
			case 4:
				printf("\nThanks\n");
				return 0;
		}
    }
}
