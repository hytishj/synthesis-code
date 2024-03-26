############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
# open_project -reset sampen01
# set_top sampen
# add_files sampen.hpp
# add_files sampen.cpp
# add_files -tb sampen_test.cpp
# open_solution -reset "solution1"
# set_part {xc7z020-clg400-1}
# create_clock -period 10 -name default
# #source "./sampen01/solution2/directives.tcl"
# csim_design
# csynth_design
# cosim_design
# export_design -rtl verilog -format ip_catalog
open_project -reset sqi_ap
# open_project -reset sampen_TestSort

# Add design files
add_files feature.c
# Add test bench & files
add_files -tb feature_test.c 

# Set the top-level function
set_top overlay_fea

# ########################################################

# set values {"20" "50" "100" "200" "500" "1000" "2000" "5000" "10000" "20000" "50000"}
# set values {"200" "2000" "20000"}
# # set values {"2000"}
# foreach value $values {
    
# 	set solution_name "solution_${value}"	
# 	put $solution_name

# 	set headerFile [open "paras.hpp" "w"]
# 	puts $headerFile "#define Length $value"
# 	close $headerFile	
# Create a solution
set solution_name "solution_SQIs"

open_solution -reset ${solution_name} -flow_target vivado
# Define technology and clock rate
#set_part  {xcvu9p-flga2104-2-i}
set_part {xc7z020-clg400-1}
create_clock -period 10

# Set variable to select which steps to execute
# set hls_exec 3
set hls_exec 2


csim_design
# Set any optimization directives
# set_directive_interface -register sampen in_val
# set_directive_interface -mode ap_ctrl_hs -register sampen return
# set_directive_pipeline sampen

# End of directives

if {$hls_exec == 1} {
	# Run Synthesis and Exit
	csynth_design
	
} elseif {$hls_exec == 2} {
	# Run Synthesis, RTL Simulation and Exit
	csynth_design
	
	cosim_design
} elseif {$hls_exec == 3} {
	# Run Synthesis, RTL Simulation, RTL implementation and Exit
	csynth_design
	
	# cosim_design
#    export_design -format ip_catalog -version 2.0.1
    export_design -format ip_catalog
} else {
	# Default is to exit after setup
}

# }

exit
