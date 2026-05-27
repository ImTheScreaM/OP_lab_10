import ctypes

lib = ctypes.CDLL("build/libcipher.so")

lib.caesar_encryption.argtypes = [
    ctypes.c_char_p,
    ctypes.c_char_p,
    ctypes.c_size_t,
    ctypes.c_int
]

lib.caesar_encryption.restype = ctypes.c_int

buffer = ctypes.create_string_buffer(256)

status = lib.caesar_encryption(
    b"HELLO",
    buffer,
    256,
    3
)

print("status =", status)
print("encrypted =", buffer.value.decode())