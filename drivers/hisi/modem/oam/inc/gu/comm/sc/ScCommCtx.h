/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and 
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may 
 * *    be used to endorse or promote products derived from this software 
 * *    without specific prior written permission.
 * 
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/******************************************************************************

                  ???????? (C), 2001-2012, ????????????????

 ******************************************************************************
  ?? ?? ??   : ScCtx.h
  ?? ?? ??   : ????
  ??    ??   : w00184875
  ????????   : 2012??04??19??
  ????????   :
  ????????   : ScCtx.c ????????
  ????????   :
  ????????   :
  1.??    ??   : 2012??04??19??
    ??    ??   : w00184875
    ????????   : ????????

******************************************************************************/

#ifndef __SCCOMMCTX_H__
#define __SCCOMMCTX_H__

/*****************************************************************************
  1 ??????????????
*****************************************************************************/
#include "ScComm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 ??????
*****************************************************************************/
#define     SC_RAND_DATA_LEN            (4)         /* ?????????????? */

#define     SC_SEC_AT_KEY_LEN           (16)                /* ????AT key?????? */

#define     SC_SECURITY_ITEM_NUM        (16)                /* ?????????????? */


/*****************************************************************************
  3 ????????
*****************************************************************************/
/*****************************************************************************
 ??????    : SC_AUTH_STATUS_ENUM
 ????????  : ????????????

  1.??    ??   : 2012??04??07??
    ??    ??   : w00184875
    ????????   : AP-Modem????????????????????
*****************************************************************************/
enum SC_AUTH_STATUS_ENUM
{
    SC_AUTH_STATUS_UNDO          = 0x00,             /* ?????????? */
    SC_AUTH_STATUS_DONE          = 0x01,             /* ???????? */
    SC_AUTH_STATUS_BUTT
};
typedef VOS_UINT8 SC_AUTH_STATUS_ENUM_UINT8;

/*****************************************************************************
 ??????    : SC_APSEC_FILE_STATE_INIT_ENUM
 ????????  : ??????????????????????

  1.??    ??   : 2012??8??27??
    ??    ??   : h59254
    ????????   : V7R1C50 ISDB????????????????
*****************************************************************************/
enum SC_APSEC_FILE_STATE_INIT_ENUM
{
    SC_SECURITY_FILE_STATE_INIT         =   0x5A5A5A5A,     /* ?????????????????????? */
    SC_SECURITY_FILE_STATE_IDEL         =   0x5A5A55AA,     /* ???????????????????????? */
    SC_SECURITY_FILE_STATE_BUTT,
};
typedef VOS_UINT32 SC_APSEC_FILE_STATE_INIT_ENUM_UINT32;

/*****************************************************************************
  4 ????????????
*****************************************************************************/


/*****************************************************************************
  5 ??????????
*****************************************************************************/


/*****************************************************************************
  6 ????????
*****************************************************************************/


/*****************************************************************************
  7 STRUCT????
*****************************************************************************/
/*****************************************************************************
 ??????    : SC_COMM_GLOBAL_STRU
 ????????  : SC COMM??????????????????
 1.??    ??   : 2012??04??19??
   ??    ??   : w00184875
   ????????   : ????

*****************************************************************************/
typedef struct
{
    VOS_CHAR                           *acSecretFileName[SC_SECRET_FILE_TYPE_BUTT];
    VOS_CHAR                           *acSignFileName[SC_SECRET_FILE_TYPE_BUTT];
}SC_COMM_GLOBAL_STRU;

/*****************************************************************************
??????    : SC_FAC_GLOBAL_STRU
????????  : ????????????????????????

  1.??    ??   : 2012??04??16??
    ??    ??   : w00184875
    ????????   : ????????
*****************************************************************************/
typedef struct
{
    SC_AUTH_STATUS_ENUM_UINT8               enScFacAuthStatus;
    VOS_UINT8                               aucScFacRandData[SC_RAND_DATA_LEN];
    /* ???????????????? VOS_FALSE: ??????????????; VOS_TRUE: ?????????????? */
    VOS_UINT8                               ucIdentifyStartFlg;
    VOS_UINT8                               aucReserved[2];         /* ???????????????????????? */
}SC_FAC_GLOBAL_STRU;

/*****************************************************************************
 ??????    : SC_APSEC_ITEM_STRU
 ????????  : ????????????????????????????????

  1.??    ??   : 2012??8??27??
    ??    ??   : h59254
    ????????   : V7R1C50 ISDB????????????????
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulItemLen;
    VOS_CHAR                           *pucContent;
    VOS_UINT8                           aucHash[SC_HASH_LEN];
}SC_APSEC_ITEM_STRU;

/* Added by h59254 for V7R1C50 ISDB Project, 2012/08/28, begin */
/*****************************************************************************
 ??????    : SC_APSEC_GLOBAL_STRU
 ????????  : ????????????????????????????????

  1.??    ??   : 2012??8??27??
    ??    ??   : h59254
    ????????   : V7R1C50 ISDB????????????????
*****************************************************************************/
typedef struct
{
    VOS_UINT8                                               ucSeqID;
    VOS_UINT8                                               aucReserved[2];
    VOS_UINT8                                               ucSecATkeyFlg;
    VOS_UINT8                                               aucSecATkey[SC_SEC_AT_KEY_LEN];
    SC_APSEC_FILE_STATE_INIT_ENUM_UINT32                    ulInitState;
    SC_APSEC_ITEM_STRU                                      astApSecItem[SC_SECURITY_ITEM_NUM];
    VOS_CHAR                                               *pApSecFileA;
    VOS_CHAR                                               *pApSecFileC;
}SC_APSEC_GLOBAL_STRU;
/* Added by h59254 for V7R1C50 ISDB Project, 2012/08/28, end */

/*****************************************************************************
 ??????    : SC_CONTEXT_STRU
 ????????  : SC ??????????????
 1.??    ??   : 2012??04??19??
   ??    ??   : w00184875
   ????????   : ????

*****************************************************************************/
typedef struct
{
    SC_COMM_GLOBAL_STRU                 stScCommGlobalVar;
    SC_FAC_GLOBAL_STRU                  stScFacGlobalVar;
    /* Added by h59254 for V7R1C50 ISDB Project, 2012/08/28, begin */
    SC_APSEC_GLOBAL_STRU                stScApSecGlobalVar;
    /* Added by h59254 for V7R1C50 ISDB Project, 2012/08/28, end */
}SC_CONTEXT_STRU;

/*****************************************************************************
  8 UNION????
*****************************************************************************/


/*****************************************************************************
  9 OTHERS????
*****************************************************************************/


/*****************************************************************************
  10 ????????
*****************************************************************************/

/*****************************************************************************
 ?? ?? ??  : SC_CTX_GetCommGlobalVarAddr
 ????????  : ????SC??????????????????????
 ????????  : ??
 ????????  : ??
 ?? ?? ??  : SC????????????????????????????
 ????????  :
 ????????  :

 ????????      :
  1.??    ??   : 2012??04??19??
    ??    ??   : w00184875
    ????????   : ??????????
*****************************************************************************/
extern SC_COMM_GLOBAL_STRU*  SC_CTX_GetCommGlobalVarAddr( VOS_VOID );

/*****************************************************************************
 ?? ?? ??  : SC_CTX_GetScCtxAddr
 ????????  : ????????SC??CTX
 ????????  : ??
 ????????  : ??
 ?? ?? ??  : ????????SC??CTX????
 ????????  :
 ????????  :

 ????????      :
 1.??    ??   : 2012??04??20??
   ??    ??   : w00184875
   ????????   : ??????????

*****************************************************************************/
extern SC_CONTEXT_STRU* SC_CTX_GetScCtxAddr(VOS_VOID);

#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif
