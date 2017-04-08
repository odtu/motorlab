################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
BlinkingLED-DevInit_F2802x.obj: ../BlinkingLED-DevInit_F2802x.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.2.LTS/bin/cl2000" -v28 -ml -mt --include_path="C:/Users/User/Desktop/piccolo/blink" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.2.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="BlinkingLED-DevInit_F2802x.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

BlinkingLED-Main.obj: ../BlinkingLED-Main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.2.LTS/bin/cl2000" -v28 -ml -mt --include_path="C:/Users/User/Desktop/piccolo/blink" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-c2000_16.9.2.LTS/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="BlinkingLED-Main.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


