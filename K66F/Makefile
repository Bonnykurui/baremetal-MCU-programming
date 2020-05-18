#K.Kipruto
# Sun May 12
#Toolchain and Path Configuration
TOOLCHAIN=/home/kipruto/opt/gcc-arm-none-eabi-9-2019-q4-major/bin
PREFIX=$(TOOLCHAIN)/arm-none-eabi-
CC=$(PREFIX)gcc
LD=$(PREFIX)gcc
AS=$(PREFIX)as
OBJCOPY=$(PREFIX)objcopy
SIZE=$(PREFIX)size
RM=rm -f

#Files Location
SRC=$(wildcard *.c)
OBJ=$(patsubst  %.c, %.o, $(SRC) )
ASSRC=$(wildcard *.S)
ASOBJ=$(patsubst  %.S, %.o, $(ASSRC) )

#GNU ARM GCC Configuration and Platform configurations
ARCHFLAGS=-mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mfpu=fpv4-sp-d16
INCLUDE=-I./includes/
CFLAGS= -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g3 \
	 -Xlinker --gc-sections -specs=nano.specs -specs=nosys.specs
LDFLAGS= $(ARCHFLAGS) -T "MK66FN2M0xxx18.ld" -L"./" -Wl,-Map,$(TARGET).map

#Output file
TARGET=main

#Makefile rules
all: build bin size
build: elf
elf: $(TARGET).elf
bin: $(TARGET).bin
#srec: $(TARGET).srec

clean:
	$(RM) $(TARGET).bin $(TARGET).srec $(TARGET).elf $(TARGET).map $(OBJ) $(ASOBJ)

#Compiling each source file
%.o: %.c 
	$(CC) -c $(ARCHFLAGS) $(CFLAGS) $(INCLUDE) -o $@ $<

#Linking project
$(TARGET).elf: $(OBJ) $(ASOBJ)
	@echo '### Linking files ###'
	$(LD) $(LDFLAGS) $(CFLAGS) $(OBJ) $(ASOBJ) -o $@
%.bin: %.elf
	@echo 'Binary'
	$(OBJCOPY) -O binary $< $@
size:
	@echo "---- RAM/Flash Usage ----"
	$(SIZE) $(TARGET).elf

#%.srec: %.elf
#	$(OBJCOPY) -O srec $< $@

