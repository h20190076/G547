#include <stdio.h> 
#include<stdlib.h>
#include<fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdint.h>
#include<sys/ioctl.h>
//#include "chardev.h"

#define MAGIC_NUM 'C'

#define CHANNEL 1
#define ALLIGNMENT 2

#define create_channel _IOW(MAGIC_NUM, CHANNEL, unsigned int)
#define create_allignment _IOW(MAGIC_NUM, ALLIGNMENT, unsigned int)

int main()

{ 
  int fd;
  uint16_t value;
  //uint16_t flag=1;
  uint32_t channel, allign;

  //fd=open(adc, O_RDONLY);
  fd = open("/dev/adc8", O_RDWR);
  
  if(fd <0)
  {
  
    printf("cannot read source file adc8\n");
    return 0;
  }
  printf("Enter the Channel number\n");
        scanf("%d",&channel);
        
        
        printf("Writing Value to Driver\n");
        ioctl(fd, create_channel, (int32_t*) &channel);
        
      

        printf("select alignment : 0 for lower bits, 1 for higher bits\n");
        scanf("%d",&allign);
        printf("Writing Value to Driver\n");
        ioctl(fd, create_allignment, (int32_t*) &allign);
       
        read(fd,&value,2);
  printf("adc value: %d\n",value);

  close(fd);
  
  
  return 0;
}
