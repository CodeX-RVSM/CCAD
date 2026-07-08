#include<stdio.h>
#define SIZE 5
//selection Sort

//select element in sequence and compare it with remaining element in linear direction

//Lowest element will be placed in order after completion of 1st pass

//

void select_sort(int *p,int size)
{
    int i,j;
    for(i=0; i < size-1 ; i++) //pass loop //select element
    {
        for(j=i+1 ; j <size ; j++)
        {
            if(p[i] > p[j]) //compare selecetd index position value with forward index value till n-1
            {
                p[i] = p[i] + p[j];
                p[j] = p[i] - p[j];
                p[i] = p[i] - p[j];
            }
        }
    }
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

    select_sort(arr,SIZE);

    printf("\nArray Elements After Sort \n");
    display_array_elements(arr,SIZE);

}