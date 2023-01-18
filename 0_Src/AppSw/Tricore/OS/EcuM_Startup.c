#include "IfxCpu.h"
#include "Ifx_Types.h"
#include "EcuM_Callout.h"

void EcuM_Init(void)
{
    uint8 coreId=(uint8)(IfxCpu_getCoreId());

    if(coreId==0)
    {
        EcuM_AL_DriverInitZero();
    }
    EcuM_AL_DriverInitOne();
    if(coreId==0)
    {
        // EcuM_Prv_StartSlaveCores();
    }
    // EcuM_Prv_StartOS();
}