/**
 * \file AsclinShellInterface.h
 * \brief ASCLIN Shell interface demo
 *
 * \version iLLD_Demos_1_0_1_13_0
 * \copyright Copyright (c) 2014 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * \defgroup IfxLld_Demo_AsclinShellInterface_SrcDoc_Main Demo Source
 * \ingroup IfxLld_Demo_AsclinShellInterface_SrcDoc
 *  Note: This Demo has to be used with the SysSe provided as part of the Service Software.
 * \defgroup IfxLld_Demo_AsclinShellInterface_SrcDoc_Main_Interrupt Interrupts
 * \ingroup IfxLld_Demo_AsclinShellInterface_SrcDoc_Main
 */

#ifndef ASCLINSHELLINTERFACE_H
#define ASCLINSHELLINTERFACE_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Configuration.h"
#include "Bsp.h"

#include "Ifx_Console.h"
#include "Ifx_Shell.h"
#include "IfxAsclin_Asc.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

#define SW_REVISION_DATE    (0x20140630)            // Software date 0xyyyymmdd, with yyyy the year and mm the month and dd the day
#define SW_REVISION         (0x00000103)            // Software version and revision 0x0000vvrr, with vv the version number and rr the revision number
#if defined(__TASKING__)
#  define SW_COMPILER_VERSION ((COMPILER_VERSION / 1000) << 16) | ((COMPILER_VERSION % 10) << 8) | (COMPILER_REVISION)
#endif

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

typedef struct
{
    uint8 tx[CFG_ASC_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
    uint8 rx[CFG_ASC_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
} AppAscBuffer;

/** \brief Application information */
typedef struct
{
    struct
    {
        sint32 srcRev;                  /**< \brief Project source code revision number */
        sint32 srcRevDate;              /**< \brief Project source code revision Date */
        sint32 compilerVer;             /**< \brief Compiler version */
    }            info;
    AppAscBuffer ascBuffer;             /**< \brief ASC interface buffer */
    struct
    {
        IfxAsclin_Asc asc;              /**< \brief ASC interface */
    }         drivers;
    Ifx_Shell shell;                    /**< \brief Shell object */
    struct
    {
        IfxStdIf_DPipe asc;
    }stdIf;
} App_AsclinShellInterface;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

IFX_EXTERN App_AsclinShellInterface g_AsclinShellInterface;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/

IFX_EXTERN void AsclinShellInterface_init(void);
IFX_EXTERN void AsclinShellInterface_run(void);

#endif