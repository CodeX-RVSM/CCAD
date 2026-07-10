#include<stdio.h>

#define SIZE 5
typedef int ELEMENT;

typedef struct
{
    ELEMENT eles[SIZE];
    int rear,front;
}QUEUE;

#define TRUE 1
#define FALSE 0

typedef enum {EXIT,PUSHELEMENT,POPELEMENT,TRAVERSE}MENU;


typedef int BOOL;

MENU menu_choice()
{
    MENU choice;
    printf("\n 0. Exit \n");
    printf("\n 1. Add element on QUEUE \n");
    printf("\n 2. Delete element from QUEUE \n");
    printf("\n 3. Traverse QUEUE \n");
    scanf("%d",&choice);
    return choice;
}

void accept_element(ELEMENT *p)
{
    printf("Specify element to push on QUEUE \n");
    scanf("%d",p);
}

void display_element(ELEMENT *p)
{
    printf("Element Value is = %d \n",*p);
}

void init_QUEUE(QUEUE *p)
{
    p->front = -1;
    p->rear  = -1;
    for(int i=0; i<SIZE;i++)
    {
        p->eles[i] = -1;
    }//optional
}

BOOL is_full(QUEUE *p)
{
    return (p->rear == SIZE-1 && p->front==0) || (p->front == p->rear+1) ? TRUE : FALSE ;
}

BOOL is_empty(QUEUE *p)
{
    return (p->rear == -1) ? TRUE : FALSE;
}

void push_element(QUEUE *p,ELEMENT *k)
{
    if(p->rear==SIZE-1)
        p->rear=0;
    else
        p->rear++; //decide top position for new element 
    
    p->eles[p->rear] = *k;   //adding ele on QUEUE
    
    if(p->front ==-1 )
    {
        p->front = 0;
    }
}

ELEMENT peek_element(QUEUE *p)
{
    return p->eles[p->front];
}

void pop_element(QUEUE *p)
{
    p->eles[p->front] = -1; //assume front most element is deleted
    if(p->rear == p->front)
    {
        p->rear=-1; p->front=-1;
    }
    else 
    {
        if(p->front==SIZE-1)
            p->front=0;
        else
            p->front++; 
    }//decide next top element

}

void traverse_queue(QUEUE *p)
{
    for(int i=0; i<SIZE; i++)
    {
        printf("%4d",p->eles[i]);
    }
    printf("\trear=%d front=%d \n",p->rear,p->front);
}
int main()
{
    MENU mchoice;
    ELEMENT ele;

    QUEUE q1;

    init_QUEUE(&q1); 

    while((mchoice = menu_choice())!=EXIT)
    {
        switch(mchoice)
        {
            case PUSHELEMENT:
                            if(is_full(&q1) ) //1.1 if QUEUE is full
                                printf("QUEUE has reached to overflow state\n"); //1.2 show message
                            else//2.1 if QUEUE is not full
                            {
                                accept_element(&ele); //2.2 accept element
                                push_element(&q1,&ele); //2.3 push element on QUEUE
                            }
                            break;
            case POPELEMENT:
                            if(is_empty(&q1))//if QUEUE is empty
                            {   
                                printf("QUEUE has reached underflow state\n");    //show message
                            }
                            else
                            {
                                //if QUEUE is not empty
                                ele = peek_element(&q1); //retrieve element
                                display_element(&ele);  //display top most element
                                pop_element(&q1);
                            }
                            break;
            case TRAVERSE:
                            traverse_queue(&q1);
                            break;
        }
    }

}


