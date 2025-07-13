import time
import os

current_pid = os.getpid()
print(f"The PID of the current test process is: {current_pid}")

while 1:
    print("Sleepy Task")
    time.sleep(5)