#include<stdio.h>
int binarysearch(int a[],int length,int key)       
{
    int l=0,u=length-1,mid,flag;
    
    while(l<=u)
    {
        mid=(l+u)/2;


    if(a[mid]==key) 
        {
            flag=1;
            break;
        }

    else if(a[mid]<key)   
            l=mid+1;
     
    else
            u=mid-1;
    }
    if(flag==1)
    return mid+1;
    else
    return -1;

}              

int main()
{
    int key,length,position;
    int a[10];
    printf("enter no.of element");
    scanf("%d",&length);
    for(int i=0;i<length;i++)
    {
        printf("enter elements %d:",i+1);
        scanf("%d",&a[i]);
    
    }
    printf("enter the element to be searched");
    scanf("%d",&key);
    position=binarysearch(a,length,key);
    if(position==-1)
    printf("the element is not found");
    else
    printf("%d the element is found in poistion %d",key,position);


}
