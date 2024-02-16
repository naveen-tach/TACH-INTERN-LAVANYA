
import spidev
import time
import Driver

# MCP2515 SPI Configuration
spi_bus = 0  # SPI bus number (check using 'ls /dev/spi*')
spi_device = 1  # SPI device (chip-select) number
spi_speed = 1000000  # SPI speed in Hz

# GPIO Pin for MCP2515 Reset
mcp2515_reset_pin = 17  # Change this to the actual GPIO pin you are using

# Initialize SPI
spi = spidev.SpiDev()
spi.open(spi_bus, spi_device)
spi.max_speed_hz = spi_speed

# Open spidev1.0 with mode 0 and max speed 1MHz
#spi1_1 = SPI("/dev/spidev0.1", 0, 1000000)  #ss0 10000000
#create mcp2515 instance
mcp2515_instance = exp1.MCP2515()

#create CAN frame object
CAN_frame_instance =exp1.CAN_FRAME( 0x0F6 , 8 ,[ 0x8E , 0x87 , 0x32 , 0xFA , 0x26 , 0x8E , 0xBE , 0x86 ] )


val= mcp2515_instance.setBitrate(exp1.CAN_SPEED.CAN_125KBPS,spi)
print("set function :" , val)
val = mcp2515_instance.setNormalMode(spi)
print("set function :" , val)
val = mcp2515_instance.sendmessage(CAN_frame_instance,spi)
print("set function :" , val)
try:
   while True:
     val = mcp2515_instance.sendmessage(CAN_frame_instance,spi)
     print("set function :" , val)
finally:
   spi.close()




