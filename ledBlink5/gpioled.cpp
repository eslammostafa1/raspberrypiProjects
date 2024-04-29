#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

#define PIN_NUMBER "20" 
#define PIN_DIRECTION "out"
#define PIN_HIGH "1" 
#define PIN_LOW "0"

class MyClass
{
public:
    MyClass();
    MyClass(MyClass &&) = default;
    MyClass(const MyClass &) = default;
    MyClass &operator=(MyClass &&) = default;
    MyClass &operator=(const MyClass &) = default;
    ~MyClass();

private:
    
};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int main (){
    int fd;
    fd = open("/sys/class/gpio/export", O_WRONLY);
    if(fd == -1){
        std::cout<< "we can not open file. " << "\n";
    }
    write( fd, PIN_NUMBER, strlen(PIN_NUMBER));
    sleep(1);
    close(fd);

    fd = open("/sys/class/gpio/gpio20/direction", O_WRONLY);
    if(fd == -1){
        std::cout<< "we can not open file. " << "\n";
    }
    write( fd, PIN_DIRECTION, strlen(PIN_DIRECTION));
    sleep(1);
    close(fd);

    fd = open("/sys/class/gpio/gpio20/value", O_WRONLY);
    if(fd == -1){
        std::cout<< "we can not open file. " << "\n";
    }
    for(int i=0; i < 5; i++){
        write( fd, PIN_HIGH, strlen(PIN_HIGH));
        std::cout<< "led in on ... \n" << "\n";

        sleep(1);
        write( fd, PIN_LOW ,strlen(PIN_LOW));
        std::cout<< "led in off ... \n" << "\n";

        sleep(1);

    }
    close(fd);

    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    if(fd == -1){
        std::cout<< "unexport not found" << "\n";
    }
    write( fd, PIN_NUMBER, strlen(PIN_NUMBER));
    sleep(1);
    close(fd);
    return 0;
}
