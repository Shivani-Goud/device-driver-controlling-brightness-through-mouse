#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


#define DEVICE "/dev/new_dev_1"


int main()
{
	int i,user_fd;
	char c,to[100],from[100];
	int fd, bytes;
    unsigned char data[3];
    const char *pDevice = "/dev/input/mice";
	 int left, middle, right;
    signed char x, y;
    int x2,y2,x1,y1;
  	 int b;
    x=0;y=0;

	user_fd =open(DEVICE,O_RDWR);
	if(user_fd==-1)
	{
		printf("cannot open dev file\n");
		exit(0);
	}
	else
	{
		printf("opened DEVICE file\n");
	}
	fd = open(pDevice, O_RDWR);
   if(fd == -1)
   {
        printf("ERROR Opening %s\n", pDevice);
        return -1;
   }
   else
   {
   	int inst;
   	printf("opened %s\n",pDevice);
   	scanf("%d",&inst);
   	scanf("%s",to);
   	read(user_fd,from,sizeof(from));
   	printf("device:%s\n",from);
   	
   	write(user_fd,to,sizeof(to));
   	//write(user_fd,from,sizeof(from));
   	
   	/*
   	b= atoi(from);
   	printf("brightnessis %d",b);
   	snprintf(from,sizeof(from),"%d",b);
   	printf("britnees in strinng %s",from);
   	printf("Exiting\n");
   	
   	close(fd);
					close(user_fd);
					exit(0);
   	*/
   	
   }
   
   while(1)
    {
        // Read Mouse     
        bytes = read(fd, data, sizeof(data));

        if(bytes > 0)
        {
            left = data[0] & 0x1;
            right = data[0] & 0x2;
            middle = data[0] & 0x4;

				x1=x;y1=y;
				printf("x=%d, y=%d, left=%d, middle=%d, right=%d\n", x, y, left, middle, right);
				
				if(right==2)
				{
					close(fd);
					close(user_fd);
					printf("exiting\n");
					exit(0);
				}
				printf("%d %d\n",x1,y1);
            x = x +data[1];
            y = y+ data[2];
            x2=x;y2=y;
            printf("%d %d\n",x2,y2);
            if((x2-x1)==0)
            {
            	continue;
					printf("plain");            
            }
            if(((y2-y1)/(x2-x1))>=0)
            {
            	b= b+10;
            	snprintf(from,sizeof(from),"%d",b);
            	write(user_fd,from,sizeof(from));
            	printf("increasing slope\n");
  				}
            else
            {
            	b= b-10;
            	snprintf(from,sizeof(from),"%d",b);
            	write(user_fd,from,sizeof(from));
            	printf("decresing slope\n");
            }
            
        }   
    }
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	printf("enter ch: ");
	scanf("%c",&c);
	switch(c)
	{
	
	case 'r':
				scanf("%s",to);
				write(user_fd,to,sizeof(to));
				break;
	case 'w':
	
				read(user_fd,from,sizeof(from));
				printf("device: %s\n",from);
				break;
	
	default:
				printf("wrong cmd");	
				break;
	}
	*/
	return 0;
}
