ledBlink5 project 
------------------

#complie using crosscompling for c language. 

arm-linux-gnueabi-gcc -static gpioled.c -o ledblink

#copy compiled file to raspberrypi to run it.
 
scp ledblink pi@192.168.62.38:/home/pi/app

#run compiled file on raspberrypi.

./ledblink
