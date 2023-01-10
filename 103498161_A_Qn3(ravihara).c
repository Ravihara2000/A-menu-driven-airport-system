#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct plane
{
	int plID;
	int routeID;
	time_t sched;//time data type
	
};

typedef struct plane Plane;

//function prototype
void planemenu();//main men
Plane addplanes();//generate rand numbers
void planedetails(Plane te[],int x);//display details about olane array
Plane numb(Plane te[],int x);//generate ran numbs for each plane
Plane select(Plane te[],int x);//sort plane array accoding to schedule time
Plane lead(Plane te[],int x);//display arrays first position value
Plane final(Plane te[],int x);//display arrays last position value
int getRanNo(int max,int min);//



int main() 

{
	
	Plane ary[15]; // create plane array (size 15)
	int w;
	int menu[3] = {0};
	int opt;
	int amnt = 10;
	
	do//this is a menu driven program
	{
		planemenu();//display menu
		printf("Enter your option   :");
		scanf("%d", &opt);
		printf("\n");
		
		switch(opt)
		{
			case 1:
			
			{
				if(menu[0] ==0)
				{
					for(w = 0; w < amnt; w++)
					{
						ary[w] = addplanes();
					}
					
						printf("\n--Planes are  available now--\n");
						menu[0] = 1;
							
				}
				else
				{
					printf("\n--You can't select this option--\n");
					
				}
				
			}break;
			
			case 2:
			
			{
				if(menu[0] == 1)
				{
					if(amnt < 0)
					{
						printf("\n--No planes avilable--\n");
					}
					
					else
					{
						printf("\n-- Available planes list--\n");
						planedetails(ary,amnt);
					}
				}
				
				else
				{
					printf("\n--you should select option num 1--\n");
				}
			}break;
			
			case 3:
			{
				if(menu[0]==1)
					{
						ary[amnt] = numb(ary,amnt);
						
						printf("\n--Made depature time for planes--\n");
						menu[1] = 1;
						
					}
					
					else
						{
							printf("\n--you should select option num 1--\n");
						}
						
			}break;
			
			case 4:
			{
				if(menu[1]==1)
					{
						ary[amnt] = select(ary,amnt);
						
						printf("\n--Recreate the planes schedule--\n");
						menu[2] =1;
						
					}
					
					else
						{
							printf("\n--First you should select option num 3--\n");
						}
						
			}break;
			
			case 5:
			{
				if(menu[2]==1)
					{
						amnt -= 1;
						
						if(amnt < 0)
							{
								printf("\n--NO planes available--\n");
								
							}
							else
							{
								ary[amnt] = lead(ary,amnt+1);
								
							}
							
					}
					
					else
						{
							printf("\n--You should select option num 4--\n");
							
						}
			}break;
			
			case 6:
				{
					if(menu[2]==1)
					{
						amnt -= 1;
						if(amnt<0)
						{
							printf("\n-- Currently Planes are not available--\n");
						}
						else
						{
							ary[amnt] = final(ary,amnt);
						}
						
					}
					
					else
					{
						printf("\n--you should enter num 4--\n");
					}
					
				}break;
				
			case 7:
			
			exit(0);
			break;
			
		}
		
	}while(1);
	
	return 0;
	
}

void planemenu()
{
	//display the main menu
	printf("\n\n---Menu---\n");
	printf("\n");
	printf("1--Create Flights--\n");
	printf("2--display Flights--\n");
	printf("3--scheduled Flights--\n");
	printf("4--Rearranged Flights--\n");
	printf("5--Release Flights--\n"); 
	printf("6--Emergency Flights--\n");
	printf("7-- Exit From Program--\n");
}
//function call
Plane addplanes()
{
	Plane te;
	te.plID= getRanNo(100,1);
	
	te.routeID= getRanNo(1200,1000);//destination id
	te.sched= time(NULL);//Null the time
	
	return te;
	
}


//function call
Plane numb(Plane te[], int x)
{
	time_t time1;//variable to store time
	int w;
	
	for(w = 0; w < x; w++)
		{
			time1 = time(NULL) + rand()%9999;//randomly create e time
			te[w].sched =time1;
		}
		
		return te[x];
		
}

Plane select(Plane te[], int x)
{
	int w=0, k;
	Plane aray;
	
	
	while(w < x-1)
		{
			for(k =0; k <x; k++)
			{
				if(te[k].sched > te[k+1].sched)
				{
					aray = te[k];
					te[k] = te[k+1];
					te[k+1]= aray;
				}
			}
			w++;
		}
		
	
}

void planedetails(Plane te[], int x)
{
	int w;
	
	char*timStr;
	
	for(w=0; w < x; w++)
	{
		timStr = ctime(&te[w].sched);
		printf("--Plane ID   : %d \t Route ID  : %d \t Depature Time   :%s", te[w].plID, te[w].routeID, timStr);
	}
	
	
	printf("\n\n");
	
	
}

Plane final(Plane te[], int x)//schedule the time 
{
	Plane left;
	int w;
	
	left = te[x];
	
	printf("\n--Plane ID  :%d, Leave depot--\n", left.plID);
	
	return te[x];
	
	
	
}

int getRanNo(int max, int min)//genarate random numbers
{
	int Ra = rand();
	Ra = (Ra%(max - min +1))+ min;
	
	return Ra;
}

Plane lead(Plane te[], int x)
{
	Plane left;
	int w;
	
	left = te[0];
	
	for(w=0; w< x; w++)
	{
		te[w] = te[w+1];
	}
	
	printf("\n--Plane ID  :%d,  Leave the depot--\n", left.plID);
	
	return te[x-1];
}		
				
					
			
							
				
					
			
					
						
					