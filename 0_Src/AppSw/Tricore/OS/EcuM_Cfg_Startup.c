#include "IfxCpu.h"
#include "Ifx_Types.h"
void EcuM_AL_DriverInitZero(void)
{
    
}

void EcuM_AL_DriverInitOne(void)
{
    uint8 coreId=IfxCpu_getCoreId();
    if(coreId==0)
    {

    }else if(coreId==1)
    {

    }
}