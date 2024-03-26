set SynModuleInfo {
  {SRCNAME overlay_fea_Pipeline_1 MODELNAME overlay_fea_Pipeline_1 RTLNAME overlay_fea_overlay_fea_Pipeline_1
    SUBMODULES {
      {MODELNAME overlay_fea_flow_control_loop_pipe_sequential_init RTLNAME overlay_fea_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME overlay_fea_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME overlay_fea_Pipeline_Loop_mean MODELNAME overlay_fea_Pipeline_Loop_mean RTLNAME overlay_fea_overlay_fea_Pipeline_Loop_mean}
  {SRCNAME overlay_fea_Pipeline_Loop_kur MODELNAME overlay_fea_Pipeline_Loop_kur RTLNAME overlay_fea_overlay_fea_Pipeline_Loop_kur}
  {SRCNAME overlay_fea MODELNAME overlay_fea RTLNAME overlay_fea IS_TOP 1
    SUBMODULES {
      {MODELNAME overlay_fea_fmul_32ns_32ns_32_4_max_dsp_1 RTLNAME overlay_fea_fmul_32ns_32ns_32_4_max_dsp_1 BINDTYPE op TYPE fmul IMPL maxdsp LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME overlay_fea_fdiv_32ns_32ns_32_16_no_dsp_1 RTLNAME overlay_fea_fdiv_32ns_32ns_32_16_no_dsp_1 BINDTYPE op TYPE fdiv IMPL fabric LATENCY 15 ALLOW_PRAGMA 1}
      {MODELNAME overlay_fea_sitofp_32ns_32_6_no_dsp_1 RTLNAME overlay_fea_sitofp_32ns_32_6_no_dsp_1 BINDTYPE op TYPE sitofp IMPL auto LATENCY 5 ALLOW_PRAGMA 1}
      {MODELNAME overlay_fea_faddfsub_32ns_32ns_32_5_full_dsp_1 RTLNAME overlay_fea_faddfsub_32ns_32ns_32_5_full_dsp_1 BINDTYPE op TYPE fadd IMPL fulldsp LATENCY 4 ALLOW_PRAGMA 1}
      {MODELNAME overlay_fea_buff_RAM_AUTO_1R1W RTLNAME overlay_fea_buff_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME overlay_fea_control_s_axi RTLNAME overlay_fea_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
      {MODELNAME overlay_fea_gmem_m_axi RTLNAME overlay_fea_gmem_m_axi BINDTYPE interface TYPE interface_m_axi}
    }
  }
}
