#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t ProcessId1=0,ProcessId2= 0;
	int i = 0;
	int StatFrChild1 =0,StatFrChild2=0;
	ProcessId1 =fork();

	if (ProcessId1 > 0)
	{
		ProcessId2 =fork();
		if(ProcessId2 >0)
		{
			waitpid(ProcessId1,NULL,0);
			waitpid(ProcessId2,NULL,0);
			printf("bye bye!!\n");
		}
		else
		{
			for(i=0;i<5;i++)
			{
				printf("P2: Am Alive\n");
			}
			exit(0);
		}

	}
	else if(ProcessId1 == 0)
	{
		for(i=0;i<5;i++)
		{
			printf("P1: Am Alive\n");
		}
		exit(0);

		
		
	}
	return 0;
}
