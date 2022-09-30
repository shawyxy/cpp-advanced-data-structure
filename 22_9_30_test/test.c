// #include <stdio.h>
// #include <unistd.h>
// int main()
// {
// 	printf("hello world");
// 	pid_t id = fork();
// 	if(id == 0)//子进程返回0
// 	{
// 		while(1)
// 		{
// 			printf("子进程：\n");
// 			sleep(1);
// 		}		
// 	}
// 	else if(id > 0)//父进程返回PID
// 	{
// 		while(1)
// 		{
// 			printf("父进程：\n");
// 			sleep(1);
// 		}
// 	}

// 	return 0;
//}
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// int main()
// {
// 	printf("I am running...\n");
// 	pid_t id = fork();
// 	if(id == 0){ //child
// 		int count = 5;
// 		while(count){
// 			printf("I am child...PID:%d, PPID:%d, count:%d\n", getpid(), getppid(), count);
// 			sleep(1);
// 			count--;
// 		}
// 		printf("child quit...\n");
// 		exit(1);
// 	}
// 	else if(id > 0){ //father
// 		while(1){
// 			printf("I am father...PID:%d, PPID:%d\n", getpid(), getppid());
// 			sleep(1);
// 		}
// 	}
// 	return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// int main()
// {
// 	printf("I am running...\n");
// 	pid_t id = fork();
// 	if(id == 0){ //child
// 		int count = 3;
// 		while(count){
// 			printf("I am child...PID:%d, PPID:%d, count:%d\n", getpid(), getppid(), count);
// 			sleep(1);
// 			count--;
// 		}
// 		printf("child quit...\n");
// 		exit(1);
// 	}
// 	else if(id > 0){ //father
// 		while(1){
// 			printf("I am father...PID:%d, PPID:%d\n", getpid(), getppid());
// 			sleep(1);
// 		}
// 	}
// 	return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// int main()
// {
//     printf("hello world\n");
//     pid_t id = fork();
//     if(id == 0){ //child
//         while(1){
//                 printf("子进程:PID:%d, PPID:%d\n", getpid(), getppid());
//                 sleep(1);
//         }
//         exit(1);
//     }
//     else if(id > 0){ //father
//     	int count = 3;
//     	while(count){
//       	printf("父进程PID:%d, PPID:%d, count:%d\n", getpid(), getppid(), count);
//         sleep(1);
//         count--;
//         }
// 	}
//     return 0;
// } 
// #include <stdio.h>
// int main(int argc, char* argv[], char* envp[])
// {
// 	for(int i = 0; envp[i]; i++)
// 	{
// 		printf("envp[%d]:%s\n", i, envp[i]);
// 	}
// 	return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// int main(int argc, char* argv[], char* envp[])
// {
// 	printf("%s\n", getenv("PATH"));
// 	printf("pid:%d, ppid:%d\n", getpid(), getppid());
// 	return 0;
// }
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int g_val = 1;
int main()
{
	pid_t id = fork();
	if(id == 0)//子进程
	{
		g_val = 2;
		printf("子进程：PID:%d, PPID:%d, g_val:%d, &g_val:%p\n", getpid(), getppid(), g_val, &g_val);
	}
	else if(id > 0)//父进程
	{
		printf("父进程：PID:%d, PPID:%d, g_val:%d, &g_val:%p\n", getpid(), getppid(), g_val, &g_val);
	}
	return 0;
}