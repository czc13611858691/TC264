#include "Compiler.h"
#include "Os_Compiler_Cfg.h"
#include "Ifx_Types.h"
#include "IfxCpu_IntrinsicsGnuc.h"
#include "IfxCpu_reg.h"
#include "OsTargetTypes.h"

OS_VOLATILE VAR(uint32 ,OS_VAR_CLEARED) Os_StartBlock[1]={0};

FUNC(void,OS_CODE) Os_StartCoreGate(void)
{
    uint32 core=__mfcr(CPU_CORE_ID);

    while ((core==1)&&(Os_StartBlock[0]!=0xa55aa5a5))
    {
        __nop();
    }
    
}