#include<iostream>
using namespace std;
int k=-1;
void SortArr(int arr[],int size)
{
    int round,j,t;
    bool no_swap;
    for(round=1;round<size;round++)
    {
       no_swap=false;
        for(j=0; j<=size-round ;j++)
        {
           if(arr[j]>arr[j+1])
           {
              t=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=t;
              no_swap=true;
           }
        }
        if(no_swap==false)// Array has been sorted
           break;
    }
}
int binary_search(int arr[],int low,int high,int data)
{
    int mid;
    while(low<=high)
    {
       mid=(low+high)/2;
       if(arr[mid]==data)
          return mid;
       else if(data<arr[mid])   
          high=mid-1;
       else
         low=mid+1;   
    }
    return -1;
}

int main()
{
    int arr[20]={5,36,27,189,90,67,3,5,8,10,34,23,45,15,25,66,101,251,19,20};
    SortArr(arr,19);
    for(int i=0 ;i< 20;i++)
      cout<<arr[i]<<" ";
      cout<<endl;
    cout<<binary_search(arr,0,19,20);
    return 0;
}