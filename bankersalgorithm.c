#include<stdio.h>
struct file
{
    int all[10];
    int max[10];
    int need[10];
    int flag;
};
void main(){
    struct file f[10];
    int fl;
    int n,r,i,j,k,g,b,count=0,id,newr;
    int avail[10],seq[10];
    printf("Enter the no of processes : ");
    scanf("%d",&n);
    printf("Enter the no of resources : ");
    scanf("%d",&r);
    for(i=0;i<n;i++){
        printf("Enter the deatils of P%d",i);
        printf("\n Enter alloction : ");
        for(j=0;j<r;j++){
            scanf("%d",&f[i].all[j]);
        }
        printf(" Enter the MAX : ");
        for(j=0;j<r;j++){
            scanf("%d",&f[i].max[j]);
        }
        f[i].flag=0;
    }
    printf("Enter Available Resources : ");
    for(i=0;i<r;i++){
        scanf("%d",&avail[i]);
    }
    printf("Enter New Request Details : ");
    printf("Enter process id : ");
    scanf("%d",&id);
    printf("Enter request for resources : ");
    for(i=0;i<r;i++){
        scanf("%d",&newr);
        f[id].all[i]+=newr;
        avail[i]=avail[i]-newr;
    }
    // calculating need
    for(i=0;i<n;i++){
        for(j=0;j<r;j++){
            f[i].need[j]=f[i].max[j]-f[i].all[j];
            if(f[i].need[j]<0) f[i].need[j]=0;
        }
    }
    //calculation of resources
    count=0;
    fl=0;
    while(count!=n){
        g=0;
        for(i=0;i<n;i++){
            if(f[i].flag==0){
                b=0;
                for(j=0;j<r;j++){
                    if(avail[j]>=f[i].need[j]) b=b+1;
                    else b=b-1;
                }
                    if(b==r){
                        printf("\nP%d is visited",i);
                        seq[fl++]=i;
                        f[i].flag=1;
                        for(k=0;k<r;k++){
                            avail[k]+=f[i].all[k];
                        }
                        count+=1;
                        // printing available
                        printf("(");
                        for(k=0;k<r;k++){
                            printf("%3d",avail[k]);
                        }
                        printf(")");
                        g=1;
                    }
                
            }
        }
        if(g==0){
            printf("Request not granted-Deadlock occured");
            printf("\nSystem is in unsafe state");
            goto y;
        }

    }
    printf("\nSystem is in safe state");
    printf("The safe sequence is --(");
    for(i=0;i<fl;i++){
        printf("P%d",seq[i]);
    }
    printf(")");
 y: printf("\nProcess\t\tAllocation\t\tMax\t\t\tNeed\n");
for(i=0;i<n;i++)
{
printf("P%d\t",i);
for(j=0;j<r;j++)
printf("%6d",f[i].all[j]);
for(j=0;j<r;j++)
printf("%6d",f[i].max[j]);
for(j=0;j<r;j++)
printf("%6d",f[i].need[j]);
printf("\n");
}
}