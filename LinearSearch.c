#include<stdio.h>

int linear_Search(int *p,int size ,int key)
{
    for(int i = 0; i < size ; i++)  //if index is in boundary
    {
        if( *(p+i) == key) //visit each element in sequence and compare with key
            return i;   //if found
    }
    return -1; //if not found
}

int main()
{
    int key,pos;
    int arr[5] = {45,23,76,12,7};

    printf("Specify a key to search \n");
    scanf("%d",&key);

    pos = linear_Search(arr,5,key);

    if(pos == -1)
        printf("%d key is not present \n",key);
    else 
        printf("%d key is present at %d index location\n",key,pos);    
}

