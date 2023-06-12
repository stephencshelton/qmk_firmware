SRC += matrix.c \
	   i2c.c \
	   split_util.c \
	   serial.c

MCU = atmega32u4
F_CPU = 16000000
ARCH = AVR8
F_USB = $(F_CPU)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT
OPT_DEFS += -DBOOTLOADER_SIZE=4096

BOOTMAGIC_ENABLE ?= no
MOUSEKEY_ENABLE ?= yes
EXTRAKEY_ENABLE ?= yes
CONSOLE_ENABLE ?= no
COMMAND_ENABLE ?= yes
NKRO_ENABLE ?= no
BACKLIGHT_ENABLE ?= no
MIDI_ENABLE ?= no
AUDIO_ENABLE ?= no
UNICODE_ENABLE ?= no
BLUETOOTH_ENABLE ?= no
RGBLIGHT_ENABLE ?= no
SUBPROJECT_rev1 ?= yes
USE_I2C ?= yes
SLEEP_LED_ENABLE ?= no
CUSTOM_MATRIX = yes

RESET_FILE = /tmp/pro_micro_reset

$(RESET_FILE): build
	ls /dev/tty* > /tmp/1; \
	echo "Reset your Pro Micro now"; \
	while [[ -z $$USB ]]; do \
	  sleep 1; \
	  ls /dev/tty* > /tmp/2; \
	  USB=`diff /tmp/1 /tmp/2 | grep -o '/dev/tty.*'`; \
	done; \
	touch $(RESET_FILE)

avrdude: $(RESET_FILE)
	avrdude -p $(MCU) -c avr109 -P $$USB -U flash:w:$(BUILD_DIR)/$(TARGET).hex

.PHONY: avrdude
