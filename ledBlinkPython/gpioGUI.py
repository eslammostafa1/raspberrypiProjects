import tkinter as gui
import RPi.GPIO as GPIO 


LED=20

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(LED, GPIO.OUT)

x=0

def LED_Toggle():
    global x
    x^=1
    GPIO.output(LED, x)

tk1=gui.Tk()
tk1.title("LED Toggle")
tk1.geometry("400x200+500+300")
tk1.resizable(False,False)
tk1.configure(background="black")

buttontoggle=gui.Button(tk1, text="led toggle" , command=LED_Toggle, bg="blue") 

buttontoggle.place(x=50, y=50)

tk1.mainloop()
