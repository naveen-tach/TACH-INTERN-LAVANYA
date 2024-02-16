import spidev
from gpiozero import DigitalOutputDevice
import time

# MCP2515 SPI Configuration
spi_bus = 0  # SPI bus number (check using 'ls /dev/spi*')
spi_device = 0  # SPI device (chip-select) number
spi_speed = 100000  # SPI speed in Hz

# GPIO Pin for MCP2515 Reset
mcp2515_reset_pin = 17  # Change this to the actual GPIO pin you are using

# Initialize SPI
spi = spidev.SpiDev()
spi.open(spi_bus, spi_device)
spi.max_speed_hz = spi_speed
spi.xfer2([0x0F, 0x80])  # Set Configuration Mode
spi.xfer2([0x2A, 0x00, 0x04, 0x00])  # Set CNF1, CNF2, CNF3 registers
spi.xfer2([0x60, 0x60, 0x60])  # Set RXB0CTRL, RXB1CTRL, TXB0CTRL
# Initialize MCP2515 Reset pin
mcp2515_reset = DigitalOutputDevice(mcp2515_reset_pin)

# Reset MCP2515
mcp2515_reset.on()
time.sleep(0.1)  # Allow time for reset
mcp2515_reset.off()

# MCP2515 Initialization
# Your initialization code for MCP2515 goes here

# Example: Send and receive CAN message in a loop
try:
    while True:
        # Send a CAN message
        message_to_send = [0x01, 0xF0, 0x06]  # Replace with your own data
        sent = spi.xfer2(message_to_send)  # Sending a standard data frame

        # Delay for a short time to allow the MCP2515 to process the message
        time.sleep(0.1)

        # Receive the CAN message
        # received_data = spi.xfer2([0x03, 0, 0, 0, 0, 0, 0, 0])  # Reading a standard data frame
        # received_message = received_data[4:]

        # Delay before the next iteration
        print("Sent message:", sent)
        time.sleep(1)

except KeyboardInterrupt:
    # Close SPI before exiting the program
    spi.close()
    print("SPI closed.")
