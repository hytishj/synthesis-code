// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xoverlay_fea.h"

extern XOverlay_fea_Config XOverlay_fea_ConfigTable[];

XOverlay_fea_Config *XOverlay_fea_LookupConfig(u16 DeviceId) {
	XOverlay_fea_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XOVERLAY_FEA_NUM_INSTANCES; Index++) {
		if (XOverlay_fea_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XOverlay_fea_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XOverlay_fea_Initialize(XOverlay_fea *InstancePtr, u16 DeviceId) {
	XOverlay_fea_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XOverlay_fea_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XOverlay_fea_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

