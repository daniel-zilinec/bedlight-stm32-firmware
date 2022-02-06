# bedlight-stm32-firmware
Firmware for programable bedlight based on ST NUCLEO-L031K6 (STM32L031K6 processor).

# Binary files
Binary files are in Releases section: https://github.com/daniel-zilinec/bedlight-stm32-firmware/releases

# Nucleo upgrade
To get rid of the Nucleo LEDs that are constantly on or even flashing it's needed to remove LEDs or this resistors:
* R18 to disable red part of the ST-link's red/green LED LD1
* R17 or R19 (or both) to disable green part of the ST-link's red/green LED LD1
* R22 to disable the always on red LED LD2

Remove resistors from the Nucleo board before assembling it to the PCB, because they are on the bottom side of Nucleo (under red/green LED) and will be unreachable.

Links:

NUCLEO-L031K6 webpage: https://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-mpu-eval-tools/stm32-mcu-mpu-eval-tools/stm32-nucleo-boards/nucleo-l031k6.html
