#include<stdio.h>

typedef enum {EXIT,PUSHELEMENT,POPELEMENT,TRAVERSE} MENU;
#define TRUE 1
#define FALSE 0

#define SIZE 5

typedef int BOOL;

typedef int ELEMENT;


typedef struct 
{
    ELEMENT arr[SIZE];
    int rear,front;
}QUEUE;

MENU menu_choice()
{
    MENU choice;
    printf("0. Exit \n");
    printf("1. Push element on QUEUE \n");
    printf("2. Pop element from QUEUE \n");
    printf("3. Traverse QUEUE \n");
    scanf("%d",&choice);
    return choice;
}

BOOL is_empty(QUEUE *q)
{
    return q->rear == -1 || q->front> q->rear ? TRUE : FALSE;  
}

ELEMENT peek_element(QUEUE *q)
{
    return q->arr[q->front] ;
}

void pop_element(QUEUE *q)
{
    q->arr[q->front]=-1; //assume front most element is deleted
    q->front++; //take a decision which element will be now on top
}

BOOL is_full(QUEUE *q)
{
    return q->rear == SIZE-1 ? TRUE: FALSE; 
}

void push_element(QUEUE *q, ELEMENT *e)
{
    q->rear++; //manage top position for new element
    q->arr[q->rear] = *e; 
    if(q->front ==-1)
        q->front=0;
}
void init_QUEUE(QUEUE *q)
{
    q->rear = -1;   q->front=-1;

    for(int i=0; i< SIZE; i++)
    {
        q->arr[i] = -1;
    }
}

void traverse_queue(QUEUE *q)
{
    for(int i=0; i< SIZE; i++)
    {
        printf("%4d",q->arr[i]);
    }
    printf("\trear=%d front=%d \n",q->rear,q->front);
}
void accept_element(ELEMENT *q)
{
    printf("Specify element to push on QUEUE\n");
    scanf("%d",q);
}

void display_element(const ELEMENT *q)
{
    printf("Element = %d \n",*q);
}
int main()
{
    QUEUE q1;
    ELEMENT ele;
    MENU choice;
    init_QUEUE(&q1);

    while( (choice = menu_choice())!=EXIT)
    {
        switch(choice)
        {
            case PUSHELEMENT:
                            if( is_full(&q1) )//if QUEUE is full 
                                printf("QUEUE is full !!!\n");//show message
                            else//if QUEUE is not full
                            {
                                accept_element(&ele);//accept element
                                push_element(&q1,&ele); //push element on QUEUE
                            }
                            break;
            case POPELEMENT:
                            if( is_empty(&q1) )  //if QUEUE is empty
                                printf("QUEUE is empty !!!\n");//show message
                            else //if QUEUE is not empty
                            {
                                ele = peek_element(&q1);//peek element
                                display_element(&ele); //display peeked element
                                pop_element(&q1);
                            }
                            break;
            case TRAVERSE:
                            traverse_queue(&q1);   
                            break;
        }
    }   

}