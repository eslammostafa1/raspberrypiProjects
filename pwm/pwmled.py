import RPi.GPIO as GPIO 
import time 

LED_PIN=12

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_PIN, GPIO.OUT)

pi_pwm = GPIO.PWM(LED_PIN, 1000)
pi_pwm.start(0)

while True:
    for duty in range(0,101,1):
        pi_pwm.ChangeDutyCycle(duty)
        time.sleep(0.01)
    time.sleep(0.5)

    for duty in range(100, -1, -1):
        pi_pwm.ChangeDutyCycle(duty)
        time.sleep(0.01)
    time.sleep(0.5)
