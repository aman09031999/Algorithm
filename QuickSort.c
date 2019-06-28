#include <stdio.h>
#define mAX_INT 100000

int Partition(int A[], int low, int high);
void swap(int arr[], int k, int i);


int quick_Sort(int A[], int low, int high)
{
    if(low < high)
    {
        int k = Partition(A, low, high);
        quick_Sort(A, low, k-1);
        quick_Sort(A, k+1, high);    
    }
}        
    
    
int Partition(int A[], int low, int high)
{
    int pivot = A[high];
    int i = low - 1;
    
    for(int j=low; j<high; j++)
    {
        if(A[j]<=pivot)
        {
            i = i+1;
            if(i !=j)
                swap(A, j, i);
        }
    }
    
    swap(A, high, i + 1);
    
    return i+1;
}

void swap(int arr[], int k, int i)
  {
    int temp;
    temp = arr[k];
    arr[k] = arr[i];
    arr[i] = temp;
  }

int main()
{
    
    printf("Hello, World!\n");
    int A[] = {8,100,76,32,12,98,43,33,3,65};
    int low = 0; 
    int high = 9;
    
    printf("Unsorted Array : ");
    for(int i=0;i<10;i++)
        printf("%d,",A[i]);
        
    
    quick_Sort(A, low, high);
    
    
    printf("\n\nsorted Array : ");
    for(int i=0;i<10;i++)
        printf("%d,",A[i]);
    return 0;
}
