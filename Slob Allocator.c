#include<stdio.h>
#include<conio.h>
#include<windows.h>

#define max 25



void FirstFit(){

	int b[max],f[max],i,j,nb,nf,temp,highest=0;

	static int bf[max],ff[max];int flag,flagn[max],fragi = 0,fragx = 0;



	printf("\n\tMemory Management Scheme - First Fit");

	printf("\nEnter the number of blocks:");

	scanf("%d",&nb);

	printf("Enter the number of Process:");

	scanf("%d",&nf);

	printf("\nEnter the size of the blocks:-\n");

	int orig[nb];

	for(i=1;i<=nb;i++) {

		printf("Block %d:",i);

		scanf("%d",&b[i]);
		
		orig[i] = b[i];
		
		ff[i] = i;

	}

	printf("Enter the size of the Processes :-\n");



	for(i=1;i<=nf;i++) {

		printf("Process %d:",i);

		scanf("%d",&f[i]);

	}

	int x = 1;

	printf("\n\nProcess_No\tProcess_Size\tBlock_No\tBlock_Size\tFragment\n");

	for(i=1;i<=nf;i++)

	{

		flag = 1;

		for(j=x;j<=nb;j++)		/*just used x for starting from index 1 and added in else x = 1 or  else it will be next fit*/

		{

			if(f[i] <= b[j]){

				flagn[j] = 1;

				printf("%-15d\t%-15d\t%-15d\t%-15d\t",i, f[i],ff[j],b[j]);

				b[j] = b[j] - f[i];

				printf("%-15d\n",b[j]);

				break;

			}

			else

			{flagn[j] = 0;

				x = 1;

			flag++;

			}

		}

		if(flag > nb)

		printf("%-15d\t%-15d\t%-15s\t%-15s\t%-15s\n",i, f[i],"WAIT...","WAIT...","WAIT...");

	}
		
	printf("\nBlock No. \t\t Original Block \t\t Allocatable Block Size\n");
	
	for(i=1;i<=nb;i++){
		printf("%d\t\t\t%d\t\t\t\t%d\n",i,orig[i],b[i]);
	}

	fragi = 0;
		
	for (j= 1; j <=nb ; j++) {
		if (orig[j] != b[j])

				fragi = fragi + b[j];

	}
	
	printf("\nInternal Fragmentation = %d",fragi );
	
	fragx = 0;
	
	for (j= 1; j <=nb ; j++) {
		if (orig[j] == b[j])

				fragx = fragx + b[j];

	}

	printf("\nExternal Fragmentation = %d\n",fragx);
}

void BestFit(){

 int b[max],f[max],i,j,nb,nf,temp,lowest=10000;

 static int bf[max],ff[max],fragi = 0;



 printf("\n\tMemory Management Scheme - Best Fit");

 printf("\nEnter the number of blocks:");

 scanf("%d",&nb);

 printf("Enter the number of files:");

 scanf("%d",&nf);

 printf("\nEnter the size of the blocks:-\n");
 
 int orig[nb];
int orig2[nb];
 for(i=1;i<=nb;i++) {

   printf("Block %d:",i);

   scanf("%d",&b[i]);
	
   orig[i] = b[i];
   orig2[i]=b[i];
	
   ff[i] = i;

 }

 printf("Enter the size of the Processes :-\n");



 for(i=1;i<=nf;i++) {

   printf("Process %d:",i);

   scanf("%d",&f[i]);

 }

int y,m,z,temp1,flag;
int temp2,y1,z1;
for(y=1;y<=nb;y++)

  {

    for(z=y;z<=nb;z++)

    {
		
      if(b[y]>b[z])

      {
		y1=y;
		z1=z;
        temp=b[y];
        temp2=orig[y];

        b[y]=b[z];
		orig[y1]=orig[z1];
        b[z]=temp;
		orig[z]=temp2;
        temp1=ff[y];

        ff[y]=ff[z];

        ff[z]=temp1;

      }

    }

  }

  int flagn[max];

  int fragx = 0;



    printf("\n\nProcess_No\tProcess_Size\tBlock_No\tBlock_Size\tFragment\n");

    for(i=1;i<=nf;i++)

    {

      flag = 1;

      for(j=1;j<=nb;j++)

      {

        if(f[i] <= b[j]){

          flagn[j] = 1;

          printf("%-15d\t%-15d\t%-15d\t%-15d\t",i, f[i],ff[j],b[j]);

          b[j] = b[j] - f[i];

          printf("%-15d\n",b[j]);

          break;

        }

        else

        {flagn[j] = 0;

        flag++;

        }

      }

      if(flag > nb)

      printf("%-15d\t%-15d\t%-15s\t%-15s\t%-15s\n",i, f[i],"WAIT...","WAIT...","WAIT...");

    }

	printf("\nBlock No. \t\t Original Block \t\t Allocatable Block Size\n");
	
	for(i=1;i<=nb;i++){
		for( j=1;j<=nb;j++)
		{
			if(orig2[i]==orig[j])
			printf("%d\t\t\t%d\t\t\t\t%d\n",i,orig2[i],b[j]);	
		}
		
	}

	fragi = 0;
		
	for (j= 1; j <=nb ; j++) {
		if (orig[j] != b[j])

				fragi = fragi + b[j];

	}
	
	printf("\nInternal Fragmentation = %d",fragi );
	
	fragx = 0;
	
	for (j= 1; j <=nb ; j++) {
		if (orig[j] == b[j])

				fragx = fragx + b[j];

	}

	printf("\nExternal Fragmentation = %d\n",fragx);
}

void WorstFit(){

	int b[max],f[max],i,j,nb,nf,temp,highest=0;

	static int bf[max],ff[max];int flag,fragi = 0;



	printf("\n\tMemory Management Scheme - Worst Fit");

	printf("\nEnter the number of blocks:");

	scanf("%d",&nb);

	printf("Enter the number of Process:");

	scanf("%d",&nf);

	printf("\nEnter the size of the blocks:-\n");
	int orig[nb];
	int orig2[nb];
	for(i=1;i<=nb;i++) {

		printf("Block %d:",i);

		scanf("%d",&b[i]);
		orig[i]=b[i];
		orig2[i]=b[i];
		ff[i] = i;

	}

	printf("Enter the size of the Processes :-\n");



	for(i=1;i<=nf;i++) {

		printf("Process %d:",i);

		scanf("%d",&f[i]);

	}

	int y,z,temp1;
	int temp2,y1,z1;


	for(y=1;y<=nb;y++)

	{

		for(z=y;z<=nb;z++)

		{

			if(b[y]<b[z])    

			{
				y1=y;
				z1=z;
				temp=b[y];
				temp2=orig[y1];	
				b[y]=b[z];
				orig[y1]=orig[z1];
				b[z]=temp;
				orig[z]=temp2;
				temp1=ff[y];

				ff[y]=ff[z];

				ff[z]=temp1;

			}

          }

	}

	int flagn[max];


  int fragx = 0;



    printf("\n\nProcess_No\tProcess_Size\tBlock_No\tBlock_Size\tFragment\n");

    for(i=1;i<=nf;i++)

    {

      flag = 1;

      for(j=1;j<=nb;j++)

      {

        if(f[i] <= b[j]){

          flagn[j] = 1;

          printf("%-15d\t%-15d\t%-15d\t%-15d\t",i, f[i],ff[j],b[j]);

          b[j] = b[j] - f[i];

          printf("%-15d\n",b[j]);

          break;

        }

        else

        {flagn[j] = 0;

        flag++;

        }

      }

      if(flag > nb)

      printf("%-15d\t%-15d\t%-15s\t%-15s\t%-15s\n",i, f[i],"WAIT...","WAIT...","WAIT...");

    }
    
	printf("\nBlock No. \t\t Original Block \t\t Allocatable Block Size\n");
	
	for(i=1;i<=nb;i++){
		for( j=1;j<=nb;j++)
		{
			if(orig2[i]==orig[j])
			printf("%d\t\t\t%d\t\t\t\t%d\n",i,orig2[i],b[j]);	
		}
		
	}

	fragi = 0;
		
	for (j= 1; j <=nb ; j++) {
		if (orig[j] != b[j])

				fragi = fragi + b[j];

	}
	
	printf("\nInternal Fragmentation = %d",fragi );
	
	fragx = 0;
	
	for (j= 1; j <=nb ; j++) {
		if (orig[j] == b[j])

				fragx = fragx + b[j];

	}

	printf("\nExternal Fragmentation = %d\n",fragx);
}

void main(){
ooo:
	system("cls");
	printf("\t\t\t\tSlob Allocator Simulator...\n\n1-First Fit\n2-Best Fit\n3-Worst Fit\n\n--");
	int n;
	scanf("%d",&n);
	
	switch(n){
		case 1:
			FirstFit();
			break;
			
		case 2:
			BestFit();
			break;
		
		case 3:
			WorstFit();
			break;
			
	}
	printf("\n\n\t\t\t\t\t\tContinue: Yes(Y) or No(N)");
	if( (getch() == 'Y') || (getch() == 'y') )
	goto ooo;
	
} 
