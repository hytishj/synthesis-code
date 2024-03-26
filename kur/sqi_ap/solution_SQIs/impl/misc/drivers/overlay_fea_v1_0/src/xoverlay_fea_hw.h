// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// control
// 0x00 : reserved
// 0x04 : reserved
// 0x08 : reserved
// 0x0c : reserved
// 0x10 : Data signal of data
//        bit 31~0 - data[31:0] (Read/Write)
// 0x14 : Data signal of data
//        bit 31~0 - data[63:32] (Read/Write)
// 0x18 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XOVERLAY_FEA_CONTROL_ADDR_DATA_DATA 0x10
#define XOVERLAY_FEA_CONTROL_BITS_DATA_DATA 64

