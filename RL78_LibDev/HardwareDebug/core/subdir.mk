################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../core/start.S 

C_SRCS += \
../core/hwinit.c \
../core/inthandler.c \
../core/option.c \
../core/rl78_clock_sys.c \
../core/vects.c 

LST += \
hwinit.lst \
inthandler.lst \
option.lst \
rl78_clock_sys.lst \
start.lst \
vects.lst 

C_DEPS += \
./core/hwinit.d \
./core/inthandler.d \
./core/option.d \
./core/rl78_clock_sys.d \
./core/vects.d 

OBJS += \
./core/hwinit.o \
./core/inthandler.o \
./core/option.o \
./core/rl78_clock_sys.o \
./core/start.o \
./core/vects.o 

MAP += \
RL78_LibDev.map 

S_UPPER_DEPS += \
./core/start.d 


# Each subdirectory must supply rules for building sources it contributes
core/%.o: ../core/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-O0 -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wpointer-arith -Wshadow -Waggregate-return -Wstack-usage=40 -g2 -mcpu=s2 -mmul=g13 -std=gnu11 -I"C:/Work/Projects 2024/Renesas/Software/RL78G13_Libdev/RL78_LibDev/core" -Wa,-adlnh="$(basename $(notdir $<)).lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" "$<" -c -o "$@")
	@echo $< && rl78-elf-gcc @"$@.in"
core/%.o: ../core/%.S
	@echo 'Building file: $<'
	$(file > $@.in,-O0 -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wpointer-arith -Wshadow -Waggregate-return -Wstack-usage=40 -g2 -mcpu=s2 -mmul=g13 -x assembler-with-cpp -Wa,--gdwarf2 -I"C:/Work/Projects 2024/Renesas/Software/RL78G13_Libdev/RL78_LibDev/src" -Wa,-adlhn="$(basename $(notdir $<)).lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c "$<" -o "$@")
	@echo $< && rl78-elf-gcc @"$@.in"

