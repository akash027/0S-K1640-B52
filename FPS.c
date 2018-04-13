#include<stdio.h> 


int main()
 {

   int x,n,awt,atat,i;
   int jb[10],pr[10],bt[10],wt[10],tat[10];
   
   printf("Enter the number of process : ");
   scanf("%d",&n);
   
   printf("\n Enter process : time priorities \n");
   
   for(i=0;i<n;i++)
    {
      printf("\nProcess no %d : ",i+1);
      scanf("%d  %d",&bt[i],&pr[i]);
      jb[i]=i+1;
    }
  for(i=0;i<n-1;i++)
   {
     for(int j=i+1;j<n;j++)
     {
       if(pr[i]<pr[j])
       {
         x=pr[i];
         pr[i]=pr[j];
         pr[j]=x;
         x=bt[i];
         bt[i]=bt[j];
         bt[j]=x;
         x=jb[i];
         jb[i]=jb[j];
         jb[j]=x;
      }
   }
}

wt[0]=0;
awt=0;
tat[0]=bt[0];
atat=tat[0];

for(i=1;i<n;i++)
 {
   wt[i]=tat[i-1];
   awt+=wt[i];
   tat[i]=wt[i]+bt[i];
   atat+=tat[i];
 }

printf("\n\n Job \t Burst Time \t Wait Time \t Turn Around Time   Priority \n");
for(i=0;i<n;i++)

  printf("\n %d \t\t %d  \t\t %d \t\t %d \t\t %d \n",jb[i],bt[i],wt[i],tat[i],pr[i]);

awt/=n;
atat/=n;

printf("\n Average Wait Time : %d \n",awt);
printf("\n Average Turn Around Time : %d \n",atat);

return 0;
}
