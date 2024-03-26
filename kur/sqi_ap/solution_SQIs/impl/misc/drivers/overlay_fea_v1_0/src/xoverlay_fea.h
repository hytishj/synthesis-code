// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XOVERLAY_FEA_H
#define XOVERLAY_FEA_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xoverlay_fea_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_BaseAddress;
} XOverlay_fea_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XOverlay_fea;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XOverlay_fea_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XOverlay_fea_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XOverlay_fea_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XOverlay_fea_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XOverlay_fea_Initialize(XOverlay_fea *InstancePtr, u16 DeviceId);
XOverlay_fea_Config* XOverlay_fea_LookupConfig(u16 DeviceId);
int XOverlay_fea_CfgInitialize(XOverlay_fea *InstancePtr, XOverlay_fea_Config *ConfigPtr);
#else
int XOverlay_fea_Initialize(XOverlay_fea *InstancePtr, const char* InstanceName);
int XOverlay_fea_Release(XOverlay_fea *InstancePtr);
#endif


void XOverlay_fea_Set_data(XOverlay_fea *InstancePtr, u64 Data);
u64 XOverlay_fea_Get_data(XOverlay_fea *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
