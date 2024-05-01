import RPi.GPIO as GPIO 
import time 
LED_PIN=20
BUTTON_PIN=2

def initDevices(): 
    GPIO.setwarnings(False)
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(BUTTON_PIN, GPIO.IN, pull_up_down=GPIO.PUD_UP)
    GPIO.setup(LED_PIN, GPIO.OUT)

try:
    initDevices()
    while(True):
        val=GPIO.input(BUTTON_PIN)
        GPIO.output(LED_PIN, not val)
        if(val == 0):
            print(" button pressed ... \n")
            time.sleep(0.3)
except:
    GPIO.output(LED_PIN, 0)
    print(" program closed ... \n")
    # ctrl + z  while we press button it pause program it do not close led 
    # ctrl + c  while we press button it kill program it will close led 
        