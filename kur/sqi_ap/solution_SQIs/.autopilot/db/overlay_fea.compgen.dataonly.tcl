# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_control {
data { 
	dir I
	width 64
	depth 1
	mode ap_none
	offset 16
	offset_end 27
}
ap_local_deadlock { 
	dir O
	width 1
	depth 1
	mode ap_none
	offset -1
	offset_end -1
}
}
dict set axilite_register_dict control $port_control


