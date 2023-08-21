import ctypes

# Define our custom time function
def time(t):
    return 12345

# Create a C callable function from our Python function
c_time = ctypes.CFUNCTYPE(ctypes.c_uint, ctypes.POINTER(ctypes.c_uint))(time)

# Get a handle to the C runtime library
libc = ctypes.CDLL("libc.so.6")

# Override the time function in the C runtime library with our custom function
libc.time = c_time
