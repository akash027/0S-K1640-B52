#include<stdio.h> 
 
int main() 
{ 
 
  int i,n,time,remain,flag=0,tq; 
  int awt=0;
  int atat=0;
  int at[10],bt[10],rt[10]; 

  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  remain=n; 

  for(i=0;i<n;i++) 
  { 
 	printf("Enter Arrival Time and Burst Time for Process Process Number %d :",i+1);
 
    scanf("%d",&at[i]); 
    scanf("%d",&bt[i]); 
    
	rt[i]=bt[i]; 
  }
 
  printf("Enter Time Quantum :\t"); 
  scanf("%d",&tq); 

  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
 
 for(time=0,i=0;remain!=0;) 
  { 
    if(rt[i]<=tq && rt[i]>0) 
    { 
      time+=rt[i]; 
      rt[i]=0; 
      flag=1; 
    } 
    
    else if(rt[i]>0) 
    { 
      rt[i]-=tq; 
      time+=tq; 
    } 
    
    if(rt[i]==0 && flag==1) 
    { 
      remain--; 
    
  	  printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i); 
  
      awt+=time-at[i]-bt[i]; 
      
      atat+=time-at[i]; 
      
      flag=0; 
      
    } 

    if(i==n-1) 
      i=0; 
    else if(at[i+1]<=time) 
      i++; 
    else 
      i=0; 
  } 


	awt/=n;
	atat/=n;

  printf("\nAverage Waiting Time= %f\n",awt); 
  printf("Avg Turnaround Time = %f",atat); 
  
  return 0; 
}
