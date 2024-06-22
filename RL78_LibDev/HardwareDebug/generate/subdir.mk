################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LINKER_SCRIPT += \
../generate/linker_script.ld 

S_UPPER_SRCS += \
../generate/start.S 

C_SRCS += \
../generate/hwinit.c \
../generate/inthandler.c \
../generate/vects.c 

LST += \
hwinit.lst \
inthandler.lst \
start.lst \
vects.lst 

C_DEPS += \
./generate/hwinit.d \
./generate/inthandler.d \
./generate/vects.d 

OBJS += \
./generate/hwinit.o \
./generate/inthandler.o \
./generate/start.o \
./generate/vects.o 

MAP += \
RL78_LibDev.map 

S_UPPER_DEPS += \
./generate/start.d 


# Each subdirectory must supply rules for building sources it contributes
generate/%.o: ../generate/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-Og -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wstack-usage=40 -g2 -mcpu=s2 -mmul=g13 -I"C:/Work/Projects 2024/Renesas/Software/RL78_Lib/RL78_LibDev/generate" -Wa,-adlnh="$(basename $(notdir $<)).lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" "$<" -c -o "$@")
	@echo $< && rl78-elf-gcc @"$@.in"
generate/%.o: ../generate/%.S
	@echo 'Building file: $<'
	$(file > $@.in,-Og -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wstack-usage=40 -g2 -mcpu=s2 -mmul=g13 -x assembler-with-cpp -Wa,--gdwarf2 -I"C:/Work/Projects 2024/Renesas/Software/RL78_Lib/RL78_LibDev/src" -Wa,-adlhn="$(basename $(notdir $<)).lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c "$<" -o "$@")
	@echo $< && rl78-elf-gcc @"$@.in"

