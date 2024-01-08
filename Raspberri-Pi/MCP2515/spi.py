import spidev
import time

# MCP2515 SPI Configuration
spi_bus = 0  # SPI bus number (check using 'ls /dev/spi*')
spi_device = 0  # SPI device (chip-select) number
spi_speed = 1000000  # SPI speed in Hz

# Initialize SPI
spi = spidev.SpiDev()
spi.open(spi_bus, spi_device)
spi.max_speed_hz = spi_speed

try:
    while True:
        # Send data to SPI device
        data_to_send = [0xAA, 0xBB, 0xCC, 0xDD]
        received_data = spi.xfer2(data_to_send)

        # Print sent and received data
        print("Sent Data:", data_to_send)
        print("Received Data:", received_data)

        # Delay before the next iteration
        time.sleep(1)

except KeyboardInterrupt:
    pass

finally:
    # Close SPI connection when done
    spi.close()
