################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/RL78_LibDev.c \
../src/rl78_interval_timer.c 

LST += \
RL78_LibDev.lst \
rl78_interval_timer.lst 

C_DEPS += \
./src/RL78_LibDev.d \
./src/rl78_interval_timer.d 

OBJS += \
./src/RL78_LibDev.o \
./src/rl78_interval_timer.o 

MAP += \
RL78_LibDev.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-O0 -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wstack-usage=40 -g2 -mcpu=s2 -mmul=g13 -I"C:/Work/Projects 2024/Renesas/Software/RL78G13_Libdev/RL78_LibDev/core" -Wa,-adlnh="$(basename $(notdir $<)).lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" "$<" -c -o "$@")
	@echo $< && rl78-elf-gcc @"$@.in"

