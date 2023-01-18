#pragma once

#include "IfxCpu_IntrinsicsGnuc.h"
#include "IfxCpu_reg.h"
#include "Compiler.h"

#define OS_IS_BIT (0x200U)

extern FUNC(void,OS_CODE) Os_StartCoreGate(void);

#define OS_MAIN() extern void inner_main(void); int main(void){__mtcr(CPU_PSW,OS_IS_BIT|__mfcr(CPU_PSW));Os_StartCoreGate(); inner_main();return 0;} void inner_main(void)