#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bme280.h"

int
main( int argc, char **argv )
{
  int file;
  char devname[40];
  int addr = 0x76;

  sprintf(devname, "/dev/i2c-1");
  file = open(devname, O_RDWR);
  if (file < 0) {
    perror("Failed to open the i2c bus");
    exit(1);
  }
  if ( ioctl(file, I2C_SLAVE, addr) < 0) {
    perror("Failed to acquire bus access ...");
    exit(1);
  }

  __u8 reg = 0x10;
  __s32 res;
  char buf[10];

  res = i2c_smbus_read_word_data(file, reg);
  if (res <0) {
  } else {
    printf("%s\n", res);
  }
  
  close(file);
  return(0);
}
