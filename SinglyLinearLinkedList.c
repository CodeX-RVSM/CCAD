#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node_t;

typedef enum {EXIT,ADDATFIRST,ADDATLAST,ADDATPOS,DELFIRST,DELLAST,DELFROMPOS,TRAVERSE}MENU;

MENU menu_choice()
{
    MENU mchoice;
    printf("\n0. Exit \n");
    printf("1. Add element at First\n");
    printf("2. Add element at Last\n");
    printf("3. Add element at Position\n");
    printf("4. Delete element from First\n");
    printf("5. Delete element from Last\n");
    printf("6. Delete element from Given Position\n");
    printf("7. TraverseList\n");
    scanf("%d",&mchoice);
    return mchoice;
}
void accept_element(int *p)
{
    printf("Specify element\n");
    scanf("%d",p);
}
void display_element(const int *p)
{
    printf("Element is %d\n",*p);
}

node_t *head = NULL;

node_t * create_node()
{
    node_t *temp ;
    temp = (node_t *) malloc(sizeof(node_t));
    temp->next = NULL;
    return temp;
}

void add_element_at_first(int val)
{
    node_t *newnode;
    //1. request memory for a new element at runtime
     
    newnode = create_node();
    //2. assign data part
    newnode->data =val;
    //3. attach new element in linkedlist
    if(head == NULL)//3.1. check if list is empty
        head = newnode; 
    else //3.2 check if list is ready
    {
        newnode->next = head;
        head = newnode;
    }
}

void traverse_list_forward()
{
    node_t *trav=head;
    if(head==NULL)
    {
        printf("\nList is Empty \n");
        return ;
    }
    else
    {
        while(trav!=NULL)
        {
            printf("%d-->",trav->data);
            trav = trav->next;
        }
    }
}

int size()
{
    int cnt=0;
    node_t *trav=head;
    
    while(trav!=NULL)
    {
        cnt++;
        trav = trav->next;
    }
    return cnt;
}

void del_element_from_first()
{
    node_t *temp;
    temp = head;
    head=head->next;
    free(temp);
    temp=NULL;
}

void del_element_from_last()
{
    node_t *trav=head,*prev=NULL;

    while(trav->next!=NULL)
    {
        prev=trav;
        trav=trav->next;
    }
    if(prev == NULL)
    {
        head=NULL;
    }
    else
        prev->next=NULL;

    free(trav);
    trav=NULL;
}

void del_element_from_pos(int pos)
{
    node_t *trav,*temp;
    int p;
    if(pos==1)
        del_element_from_first();
    else if(pos==size())
        del_element_from_last();
    else
    {
        trav=head;
        p=1;
        while(p<pos-1)
        {
            trav=trav->next;
            p++;
        }
        temp=trav->next;
        trav->next=temp->next;
        free(temp);
        temp=NULL;
    }
}
void free_list()
{
    while(head!=NULL)
    {
        del_element_from_first();
    }
}
void add_element_at_pos(int val,int pos)
{
    node_t *trav=NULL,*newnode;
	int p; 
    if(pos==1)
        add_element_at_first(val);
    else if(pos==size()+1)
        add_element_at_last(val);
    else
    {
        newnode = create_node();
        newnode->data = val;
        trav=head;
		p=1;
		while(p < pos-1)
		{
		    trav=trav->next;
			p++;
        }
		newnode->next = trav->next;
		trav->next = newnode;
	}
}
void add_element_at_last(int val)
{
    node_t *newnode,*trav=NULL;
    //1. request memory for a new element at runtime
     
    newnode = create_node();
    //2. assign data part
    newnode->data =val;
    //3. attach new element in linkedlist
    if(head == NULL)//3.1. check if list is empty
        head = newnode; 
    else //3.2 check if list is ready
    {
        trav=head;
        while(trav->next!=NULL)
        {
            trav=trav->next;
        }
        trav->next = newnode;
    }
}
int main()
{
    MENU mchoice;
    int data,pos;
    while((mchoice= menu_choice())!=EXIT)
    {
        switch(mchoice)
        {
            case ADDATFIRST:
                            accept_element(&data);
                            add_element_at_first(data);
                            break;
            case ADDATLAST:
                            accept_element(&data);
                            add_element_at_last(data);
                            break;
            case ADDATPOS:
                            printf("Specify position for new element \n");
                            scanf("%d",&pos);
                            if(pos<=0 || pos > (size()+1))
                                printf("Invalid position \n");
                            else
                            {
                                accept_element(&data);
                                add_element_at_pos(data,pos);
                            }
                            break;
            case DELFIRST:
                        del_element_from_first();
                        break;
            case DELLAST:
                        del_element_from_last();
                        break;
            case DELFROMPOS:
                        printf("Specify position for new element \n");
                        scanf("%d",&pos);
                        if(pos<=0 || pos > size())
                            printf("Invalid position \n");
                        else
                        {
                            del_element_from_pos(pos);
                        }
                        break;
            case TRAVERSE:
                        printf("Traverse in Forword Direction \n");
                        traverse_list_forward();    
                        break;                        
        }
    }
    free_list();
}