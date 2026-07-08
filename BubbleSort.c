#include<stdio.h>
#define SIZE 5

void bubble_sort(int *p,int size)
{
    int i,j;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-1-i;j++)
        {
            if(p[j] > p[j+1]) //compare bubble elements
            {
                p[j] = p[j] + p[j+1];
                p[j+1] = p[j] - p[j+1];
                p[j] = p[j] - p[j+1]; 
            }
        }
    }//pass counter
}
void display_array_elements(int *p,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%4d",p[i]); //*(p+i)
    }
}
int main()
{
    int arr[SIZE] = {34,23,5,13,32};
    printf("\nArray Elements Before Sort \n");
    display_array_elements(arr,SIZE);

    bubble_sort(arr,SIZE);

    printf("\nArray Elements After Sort \n");
    display_array_elements(arr,SIZE);

}



34   32   5   13  7   

