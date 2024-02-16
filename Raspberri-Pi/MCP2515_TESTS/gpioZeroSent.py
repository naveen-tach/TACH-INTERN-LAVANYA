import spidev
from gpiozero import DigitalOutputDevice
import time

# MCP2515 SPI Configuration
spi_bus = 0  # SPI bus number (check using 'ls /dev/spi*')
spi_device = 0  # SPI device (chip-select) number
spi_speed = 1000000  # SPI speed in Hz

# GPIO Pin for MCP2515 Reset
mcp2515_reset_pin = 17  # Change this to the actual GPIO pin you are using

# Initialize SPI
spi = spidev.SpiDev()
#spi.max_speed_hz =  1000000

# Initialize MCP2515 Reset pin
mcp2515_reset = DigitalOutputDevice(mcp2515_reset_pin)

# Reset MCP2515
mcp2515_reset.on()
time.sleep(0.1) # Allow time for reset
mcp2515_reset.off()

# MCP2515 Initialization
# Your initialization code for MCP2515 goes here

# Example: Send and receive CAN message in a loop
try:
	while True:
		# Send a CAN message
		spi.open(spi_bus,spi_device)
		#message_to_send = int([0x07,0x09])  # Replace with your own data
		#sent = spi.xfer2([0x01,240,message_to_send] )  # Sending a standard data frame
		
		message_to_send = 6
		#message_to_send = int(message_to_send)
		sent = spi.xfer2(tuple([1, 240, message_to_send]))
        	# Delay for a short time to allow the MCP2515 to process the message
		time.sleep(0.1)
        # Receive the CAN message
       # received_data = spi.xfer2([0x03, 0, 0, 0, 0, 0, 0, 0])  # Reading a standard data frame
        #received_message = received_data[4:]
        # Delay before the next iteration
		#print("Sent message :")
		print(sent)
		time.sleep(1)
		spi.close()

except KeyboardInterrupt:
    pass

# Close SPI connection when done
spi.close()
