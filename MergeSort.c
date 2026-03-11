#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int nums[],int left,int mid,int right){
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;
    int l[n1],r[n2];

    for(i=0;i<n1;i++){
        l[i]=nums[left+i];
    }
    for(j=0;j<n2;j++){
        r[j]=nums[mid+1+j];
    }

    i=0;
    j=0;
    k=left;

    while(i<n1 && j<n2){
        if(l[i]<=r[j]){
            nums[k]=l[i];
            i++;
        }
        else{
            nums[k]=r[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        nums[k]=l[i];
        i++;
        k++;
    }

    while(j<n2){
        nums[k]=r[j];
        j++;
        k++;
    }
}

void mergeSort(int nums[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
}

int main(){
    int n;
    clock_t start,end;
    double timetaken;

    printf("Enter the number for array elements : ");
    scanf("%d",&n);

    int nums[n];

    srand(time(NULL));

    for(int i=0;i<n;i++){
        nums[i]=rand()%10000000;
    }

    start=clock();
    mergeSort(nums,0,n-1);
    end=clock();

    timetaken=((double)(end-start))/CLOCKS_PER_SEC;

    printf("The sorted array is : ");
    for(int i=0;i<n;i++){
        printf("%d ",nums[i]);
    }

    printf("\nThe total runtime was : %f",timetaken);

    return 0;
}

