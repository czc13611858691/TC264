B_GNUC_TRICORE_PATH:= C:\HighTec\toolchains\tricore\v4.9.3.0-infineon-1.0
CC        := "$(B_GNUC_TRICORE_PATH)/bin"/tricore-gcc
LD        := "$(B_GNUC_TRICORE_PATH)/bin"/tricore-gcc
OBJCOPY   := "$(B_GNUC_TRICORE_PATH)/bin"/tricore-objcopy

rfilterout = $(foreach a,$(1),$(a)/%)
rwildcard = $(foreach d,$(wildcard $(addsuffix *,$(1))), \
	    $(call rwildcard,$(d)/,$(2))$(filter-out $(call rfilterout,$(FILTEROUTSRC)),$(filter $(subst *,%,$(2)),$(d))))

BUILD_SRC    += 0_Src/AppSw 0_Src/BaseSw 0_Src/CDD 0_Src/Mcs/Out/mcs00
INCLUDES = -I0_Src/BaseSw/iLLD/Infra/Platform/ -I0_Src/BaseSw/iLLD/CpuGeneric -I0_Src/BaseSw/Infra/Platform -I0_Src/BaseSw/Service/CpuGeneric

BUILD_OUTPUT_NAME ?= 2_Out/TC264
BUILD_OUTPUT ?= $(BUILD_OUTPUT_NAME)/

BUILD_ELF    = $(BUILD_OUTPUT_NAME)/TC264.elf
BUILD_HEX    = $(BUILD_OUTPUT_NAME)/TC264.hex
BUILD_S19    = $(BUILD_OUTPUT_NAME)/TC264.s19

CFLAGS =  -g -O2 

B_GEN_LCF_FILE_TRICORE_TC ?= 1_ToolEnv/0_Build/1_Config/Config_Tricore_Gnuc/Lcf_Gnuc_Tricore_Tc.lsl

COMPILE_CFLAGS  :=-mtc162  -fno-common -fstrict-volatile-bitfields \
		-ffunction-sections -fdata-sections -Wall -std=c99 -maligned-data-sections 

LD_LIBS= -mtc162 -Wl,--gc-sections -nostartfiles -Wl,-n


SOURCES := $(sort $(call rwildcard,$(BUILD_SRC),*.c))
OBJECTS = $(addprefix $(BUILD_OUTPUT),$(patsubst %.c,%.o,$(SOURCES)))
INCLUDES_DIR = $(sort \
	       $(foreach d,$(call rwildcard,$(BUILD_SRC),*.h),$(dir -I$d)) \
	       $(INCLUDES))
DEPENDS = $(OBJECTS:.o=.d)
ALL_FLAGS = $(CFLAGS) $(COMPILE_CFLAGS)

PHONY := all
all: $(BUILD_ELF) $(BUILD_HEX)
	@:
$(BUILD_ELF): $(OBJECTS) $(B_GEN_LCF_FILE_TRICORE_TC)
	@mkdir -p $(@D)
	@-rm -f $@
	@echo "    LD  $@"
	@$(CC) $(LD_LIBS) -Wl,-T $(B_GEN_LCF_FILE_TRICORE_TC) -Wl,-Map=$(@:.elf=.map) -Wl,--extmap=a $(OBJECTS) -o $@

$(BUILD_OUTPUT)%.o: %.c
	@mkdir -p $(@D)
	@echo "    CC  $@"
	@$(CC) $(ALL_FLAGS) $(INCLUDES_DIR) -c $< -o $@ -save-temps=obj -MMD

# Make-rule to build: hex
$(BUILD_HEX): $(BUILD_ELF)
	@mkdir -p $(@D)
	@-rm -f $@
	@echo '    OBJCOPY $(BUILD_HEX)'
	@$(OBJCOPY) $< -O ihex $@

# Make-rule to build: srec
$(BUILD_S19): $(BUILD_ELF)
	@mkdir -p $(@D)
	@-rm -f $@
	@echo '    OBJCOPY $(BUILD_S19)'
	@$(OBJCOPY) $< -O srec $@

PHONY := clean
clean:
	@-rm -rf $(BUILD_OUTPUT)

-include $(DEPENDS)