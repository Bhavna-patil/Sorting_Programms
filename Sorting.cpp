#include<iostream>
#include<string.h>
#include<stack>
#include<vector>
using namespace std;

// MODIFIED BUBBLE SORT
void BubbleSort(int arr[],int size)
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

//SELECTION SORT
int MinValueIndex(int arr[],int size,int j)
{
   int min=arr[j],minIndex=j;
   for(int i=j+1 ;i<size ;i++)
   {
      if(arr[i]<min)
      {
         min=arr[i];
         minIndex=i;
      } 
   }
   return minIndex;
}
void SelectionSort(int arr[],int size)
{
    int i,t,minIndex;
    for(i=0;i<size-1;i++)
    {
       minIndex=MinValueIndex(arr,size,i);
       t=arr[minIndex];
       arr[minIndex]=arr[i];
       arr[i]=t;
    }
}

//INSERTION SORT
void InsertionSort(int arr[],int size)
{
   int i,j,t;
   for(i=1;i<size;i++)
   {
      t=arr[i];
      for(j=i-1;j>=0;j--)
      {
         if(t < arr[j])
           arr[j+1]=arr[j];
         else
            break ;
      }
      arr[j+1]=t;
   }
}
void swap(int arr[],int a,int b)
{
   int t;
   t=arr[a];
   arr[a]=arr[b];
   arr[b]=t;
}
//QUICK SORT
int Quick(int arr[],int left,int right)
{
   int t,loc=left;
   while(left<right)
   {
      while(left<right && arr[loc]<=arr[right])
         right--;
      if(left==right)   
        break;
      swap(arr,loc,right);
      loc=right;
      while(left<right && arr[left]<=arr[loc])
        left++;
      if(left==right)  
        break;
      swap(arr,loc,left) ; 
      loc=left;
   }
  return loc;
}
void Rec_QuickSort(int arr[],int l,int h)
{ 
   int loc;
   loc=Quick(arr,l,h);
   if(loc > l+1)
      Rec_QuickSort(arr,l,loc-1);
   if(loc < h-1)   
      Rec_QuickSort(arr,loc+1,h);
}
void Iterative_QuickSort(int arr[],int l,int h)
{
   int i,j,loc;
   stack<int> low;
   stack<int>  high;
   low.push(l);
   high.push(h);
   while(!low.empty())
   {
      i=low.top();
      j=high.top();
      loc=Quick(arr,i,j);
      low.pop();
      high.pop();
      if(loc > i+1)
      {
         low.push(i);
         high.push(loc-1);
      }
      if(loc < j-1)
      {
         low.push(loc+1);
         high.push(j);
      }
   }
}
void merge(int arr[],int low,int mid,int high)
{
   int k=0,i,j;
   i=low;
   j=mid+1;
   int temp[low+high+1];
   while(i<=mid&&j<=high)
   {
      if(arr[i]<arr[j])
      {
         temp[k]=arr[i];
         i++;
      }
      else
      {
         temp[k]=arr[j];
         j++;
      }
      k++;
   }
   while(i<=mid)
   {
      temp[k]=arr[i];
      i++;
       k++;
   }
   while(j<=high)
   {
      temp[k]=arr[j];
      j++;
      k++;
   }
   k=0;
   for(j=low;j<=high;j++,k++)
      arr[j]=temp[k];
}
void MergeSort(int arr[],int low,int high)
{
   if(low<high)
   {
      int mid;
      mid=(low+high)/2;
      MergeSort(arr,low,mid);
      MergeSort(arr,mid+1,high);
      merge(arr,low,mid,high);
   }
}

int main()
{
   int a[15]={2,4,78,90,23,14,18,23,19,26,89,34,21,22,87};
   for(int i =0; i< 15 ;i++)
   cout<<a[i]<<" ";
   cout<<endl;
   Iterative_QuickSort(a,0,14);
   for(int i =0; i< 15 ;i++)
   cout<<a[i]<<" ";
   return 0;
}