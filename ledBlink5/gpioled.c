#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define PIN_NUMBER "20" 
#define PIN_DIRECTION "out"
#define PIN_HIGH "1" 
#define PIN_LOW "0"

int main (){
    int fd;
    fd = open("/sys/class/gpio/export", O_WRONLY);
    if(fd == -1){
        printf("we can not open file. ");
    }
    write( fd, PIN_NUMBER, strlen(PIN_NUMBER));
    sleep(1);
    close(fd);

    fd = open("/sys/class/gpio/gpio20/direction", O_WRONLY);
    if(fd == -1){
        printf("we can not open file direction. ");
    }
    write( fd, PIN_DIRECTION, strlen(PIN_DIRECTION));
    sleep(1);
    close(fd);

    fd = open("/sys/class/gpio/gpio20/value", O_WRONLY);
    if(fd == -1){
        printf("we can not open file value.  ");
    }
    for(int i=0; i < 5; i++){
        write( fd, PIN_HIGH, strlen(PIN_HIGH));
        printf("led in on ... \n");
        sleep(1);
        write( fd, PIN_LOW ,strlen(PIN_LOW));
        printf("led in off ...\n");

        sleep(1);

    }
    close(fd);

    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if(fd == -1){
        printf("we can not open file UNEXPORT. ");
    }
    write( fd, PIN_NUMBER, strlen(PIN_NUMBER));
    sleep(1);
    close(fd);
    return 0;
}
