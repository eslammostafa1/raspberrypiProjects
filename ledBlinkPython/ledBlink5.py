from time import sleep
import os 
import RPi.GPIO as GPIO

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(20,GPIO.OUT)

while True:
    x=input(" enter ON or OFF: ")
    if x == "on" or x == "ON":
        GPIO.output(20,GPIO.HIGH)
    else:
        GPIO.output(20,GPIO.LOW)
