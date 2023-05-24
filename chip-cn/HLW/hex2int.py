

def convert_hex_to_int(hex_value):
  bytes = [int(hex_value[i:i+2], 16) for i in range(0, len(hex_value), 2)]
  int_value = bytes[0] << 16 | bytes[1] << 8 | bytes[2]
  return int_value

hex_value = "02 DC D0"
int_value = convert_hex_to_int(hex_value)
print(int_value)

