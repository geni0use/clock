import serial
import time
from datetime import datetime


arduino_port = 'COM5'
baud_rate = 9600  

# Establish serial connection
ser = serial.Serial(arduino_port, baud_rate)

# Allow time for the serial connection to initialize
time.sleep(2)
t=1
try:
        while True:
            if(t==1 or datetime.now().strftime('%S') == '00'):
            # Get the current time
                current_time_hour = int(datetime.now().strftime('%H'))
                current_time_minute = int(datetime.now().strftime('%M'))
                current_time=""+str(current_time_hour//10)+" "+ str(current_time_hour%10)+" "+str(current_time_minute//10)+" "+ str(current_time_minute%10)
                # Send the current time to Arduino
                ser.write(current_time.encode('utf-8'))  # Send time as a byte string # Send a newline character
                print(f"Sent time to Arduino: {current_time}")
                time.sleep(1)
                t=0

except KeyboardInterrupt:
    print("Program stopped by user.")
finally:
    ser.close()  # Close the serial connection when done
