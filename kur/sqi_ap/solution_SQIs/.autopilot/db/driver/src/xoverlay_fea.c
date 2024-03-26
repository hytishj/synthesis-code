// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xoverlay_fea.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XOverlay_fea_CfgInitialize(XOverlay_fea *InstancePtr, XOverlay_fea_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XOverlay_fea_Set_data(XOverlay_fea *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XOverlay_fea_WriteReg(InstancePtr->Control_BaseAddress, XOVERLAY_FEA_CONTROL_ADDR_DATA_DATA, (u32)(Data));
    XOverlay_fea_WriteReg(InstancePtr->Control_BaseAddress, XOVERLAY_FEA_CONTROL_ADDR_DATA_DATA + 4, (u32)(Data >> 32));
}

u64 XOverlay_fea_Get_data(XOverlay_fea *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XOverlay_fea_ReadReg(InstancePtr->Control_BaseAddress, XOVERLAY_FEA_CONTROL_ADDR_DATA_DATA);
    Data += (u64)XOverlay_fea_ReadReg(InstancePtr->Control_BaseAddress, XOVERLAY_FEA_CONTROL_ADDR_DATA_DATA + 4) << 32;
    return Data;
}

