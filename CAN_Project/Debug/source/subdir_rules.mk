################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
source/croutine.obj: ../source/croutine.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/OS_Tasks/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/APP/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/MCAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/HAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/HAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/APP/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/include" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/MQueue/portable/MemMang" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/Message_queue/portable/CCS/ARM_CM4F" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="source/croutine.d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

source/event_groups.obj: ../source/event_groups.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/OS_Tasks/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/APP/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/MCAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/HAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/HAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/APP/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/include" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/MQueue/portable/MemMang" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/Message_queue/portable/CCS/ARM_CM4F" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="source/event_groups.d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

source/list.obj: ../source/list.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/OS_Tasks/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/APP/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/MCAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/HAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/HAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/APP/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/include" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/MQueue/portable/MemMang" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/Message_queue/portable/CCS/ARM_CM4F" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="source/list.d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

source/queue.obj: ../source/queue.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/OS_Tasks/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/APP/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/MCAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/HAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/HAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/APP/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/include" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/MQueue/portable/MemMang" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/Message_queue/portable/CCS/ARM_CM4F" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="source/queue.d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

source/stream_buffer.obj: ../source/stream_buffer.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/OS_Tasks/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/APP/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/MCAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/HAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/HAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/APP/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/include" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/MQueue/portable/MemMang" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/Message_queue/portable/CCS/ARM_CM4F" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="source/stream_buffer.d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

source/tasks.obj: ../source/tasks.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/OS_Tasks/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/APP/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/MCAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/HAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/HAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/APP/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/include" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/MQueue/portable/MemMang" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/Message_queue/portable/CCS/ARM_CM4F" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="source/tasks.d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

source/timers.obj: ../source/timers.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/OS_Tasks/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/APP/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/MCAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/HAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/HAL/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/APP/Headers" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/CAN_Project/include" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/MQueue/portable/MemMang" --include_path="C:/Users/AVE-LAP-069/Desktop/NEW_WS/Message_queue/portable/CCS/ARM_CM4F" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="source/timers.d_raw" --obj_directory="source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


