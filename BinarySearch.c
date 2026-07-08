#include<stdio.h>

int binary_Search(int *p,int size ,int key)
{
    int left=0,right=size-1,mid;
    while(left<=right)  //if valid array boundary //keep using divide and conquer till key is not found or single unit of collection
    {
        mid = (left+right)/2;
        if(key == *(p+mid)) //as per algorithm if key is present always will be available at mid location
            return mid;
        else if(key < *(p+mid)) //if key is less than mid position value it may be available in left partition
            right = mid -1;
        else if(key > *(p+mid)) //if key is greater than mid position value it may be available in right partition
            left = mid + 1;
    }
    return -1; //if key is not present
}

int main()
{
    int key,pos;
    int arr[5] = {45,23,76,12,7};

    printf("Specify a key to search \n");
    scanf("%d",&key);

    pos = binary_Search(arr,5,key);

    if(pos == -1)
        printf("%d key is not present \n",key);
    else 
        printf("%d key is present at %d index location\n",key,pos);    
}

