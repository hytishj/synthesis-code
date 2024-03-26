create_project prj -part xc7z020-clg400-1 -force
set_property target_language verilog [current_project]
set vivado_ver [version -short]
set COE_DIR "../../syn/verilog"
source "E:/journal/tohpp/kur/sqi_ap/solution_SQIs/syn/verilog/overlay_fea_faddfsub_32ns_32ns_32_5_full_dsp_1_ip.tcl"
source "E:/journal/tohpp/kur/sqi_ap/solution_SQIs/syn/verilog/overlay_fea_fdiv_32ns_32ns_32_16_no_dsp_1_ip.tcl"
source "E:/journal/tohpp/kur/sqi_ap/solution_SQIs/syn/verilog/overlay_fea_fmul_32ns_32ns_32_4_max_dsp_1_ip.tcl"
source "E:/journal/tohpp/kur/sqi_ap/solution_SQIs/syn/verilog/overlay_fea_sitofp_32ns_32_6_no_dsp_1_ip.tcl"
