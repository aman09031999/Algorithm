#include <stdio.h>
#define mAX_INT 100000

void merge(int *A, int low, int mid, int high);

int merge_Sort(int A[], int low, int high)
{
    int mid;
    if(low == high)
        return (A[low]);
    
    else
    {
        mid = (high+low)/2;
        merge_Sort(A, low, mid);
        merge_Sort(A, mid+1, high);
        merge(A,low, mid, high);
        return A;
    }
}

void merge(int *A, int low, int mid, int high)
{
    int p = mid - low + 1;
    int q = high - mid;
    
    int Left[p+1], Right[q+1];
    
    int i, j;
    
    for(i =1;i<=p;i++)
        Left[i] = A[low + i - 1];
        
    for(j=1;j<=q;j++)
        Right[j] = A[mid + j];
        
        Left[p+1] = mAX_INT;
        Right[q+1] = mAX_INT;
        
        i =1;j=1;
    for(int k=low;k<=high;k++)
    {
        if(Left[i]<=Right[j])
        {
            A[k] = Left[i];
            i = i+1;
        }
        else
        {
            A[k] = Right[j];
            j =j+1;
        }
    }   
}
int main()
{
    
    printf("Merge Sort\n");
    int A[] = {8,100,76,32,12,98,43,33,3,65};
    int low = 0; 
    int high = 10;
    
    printf("Unsorted Array : ");
    for(int i=0;i<10;i++)
        printf("%d,",A[i]);
        
    merge_Sort(A,low, high);
    
    
    printf("\n\nsorted Array : ");
    for(int i=0;i<10;i++)
        printf("%d,",A[i]);
    return 0;
}
