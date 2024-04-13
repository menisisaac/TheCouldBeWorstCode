import ctypes
import time

print("Be careful we decentivize large number to make you use your brain") 
print("Give us a small number and we'll help out")
f = ctypes.CDLL("./libtest.so").subtract_c
f.restype = None
a = int(input("Enter value a: "))
time.sleep(a)
b = int(input("Enter value b: "))
time.sleep(b)
print("Are you sure")
f(a, b)
