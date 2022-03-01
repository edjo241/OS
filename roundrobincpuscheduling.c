#include<stdio.h>
int main(){
    int i,n,quant,wt=0,sum=0,tat=0,y,temp[10],bt[10],at[10],count;
    float avg_tat,avg_wt;
    printf("Enter the no of process: ");
    scanf("%d",&n);
    y=n;
    // reading
    printf("Enter the burst time and arrival time of each process : \n");
    for(i=0;i<n;i++){
        printf("Arrival time of P[%d]:",i+1);
        scanf("%d",&at[i]);
        printf("Burst time of P[%d]",i+1);
        scanf("%d",&bt[i]);
        temp[i]=bt[i];
    }
    printf("Enter the quantum time : ");
    scanf("%d",&quant);
    printf("\n Process \t Burst time \t TAT \t WT");
    // calculation and printinf result
    for(sum=0,i=0;y!=0;){
        if(temp[i]<=quant && temp[i]>0){
            sum=sum + temp[i];
            temp[i]=0;
            count=1;
        }
        else if (temp[i]>0){
            temp[i]=temp[i]-quant;
            sum=sum+quant;
        }
        if(temp[i]==0 && count==1){
            y--;
            printf("\nP[%d] \t\t %d \t\t %d \t\t %d",i+1,bt[i],sum-at[i],sum-at[i]-bt[i]);
            count=0;
            wt=wt+(sum-at[i]-bt[i]);
            tat=tat+(sum-at[i]);
        }
        if(i==n-1) i=0;
        else if (at[i+1]<=sum) i++;
        else i=0;
    }
    avg_tat=(float) tat/n;
    avg_wt=(float) wt/n;
printf("\n Average waiting time is %f ",avg_wt);
printf("\n Average turn around time is %f ",avg_tat);

}