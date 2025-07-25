import wifi

print("My MAC addr: %02X:%02X:%02X:%02X:%02X:%02X" % tuple(wifi.radio.mac_address))
print("My IP address is", wifi.radio.ipv4_address)