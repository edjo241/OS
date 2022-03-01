#include<stdio.h>
#include<stdlib.h>
int main(){
    int x,n,head,t[20],temp,s1,s2,s,pos,i,j;
    float avgs;
    printf("Enter the no of tracks :");
    scanf("%d",&x);
    printf("Enter the no of tracks in the ready queue :");
    scanf("%d",&n);
    printf("Enter the head :");
    scanf("%d",&head);
    n=n+2;
    t[0]=head;
    t[1]=0;
    printf("Enter the ready queue :");
    for(i=2;i<n;i++){
        scanf("%d",&t[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(t[i]>t[j]){
                temp=t[i];
                t[i]=t[j];
                t[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        if(t[i]==head){
            pos=i;
            break;
        }
    }
    s1=t[pos]-t[pos-1];
    s2=t[pos+1]-t[pos];
    if(s2>s1){
        s=(((x-1)-head)+((x-1)-t[0])+(t[pos-1]+t[0]));
    }
    else{
        s=((head-t[0])+((x-1)-t[0])+((x-1)+t[pos+1]));
    }
    printf("Total seek time is %d",s);
}