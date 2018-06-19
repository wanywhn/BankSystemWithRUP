format 219

classinstance 128110 class_ref 141934 // bank_assistant
  name ""   xyz 13 4 2000 life_line_z 2000
classinstance 128238 class_ref 155630 // bank_info_ctrl
  name ""   xyz 286 12 2000 life_line_z 2000
classinstance 128494 class_ref 155886 // sys_boundry
  name ""   xyz 166 7 2000 life_line_z 2000
classinstance 128622 class_ref 141806 // interest_table
  name ""   xyz 490 4 2000 life_line_z 2000
classinstance 128878 class_ref 148974 // DB
  name ""   xyz 745 4 2000 life_line_z 2000
durationcanvas 129006 classinstance_ref 128110 // :bank_assistant
  xyzwh 70 126 2010 11 40
end
durationcanvas 129134 classinstance_ref 128494 // :sys_boundry
  xyzwh 214 126 2010 11 25
end
durationcanvas 129390 classinstance_ref 128494 // :sys_boundry
  xyzwh 214 190 2010 11 40
end
durationcanvas 129518 classinstance_ref 128238 // :bank_info_ctrl
  xyzwh 341 190 2010 11 25
end
durationcanvas 129774 classinstance_ref 128238 // :bank_info_ctrl
  xyzwh 341 254 2010 11 40
end
durationcanvas 129902 classinstance_ref 128622 // :interest_table
  xyzwh 543 254 2010 11 25
end
durationcanvas 130158 classinstance_ref 128238 // :bank_info_ctrl
  xyzwh 341 322 2010 11 40
end
durationcanvas 130286 classinstance_ref 128878 // :DB
  xyzwh 764 322 2010 11 25
end
durationcanvas 130542 classinstance_ref 128878 // :DB
  xyzwh 764 395 2010 11 40
end
durationcanvas 130670 classinstance_ref 128238 // :bank_info_ctrl
  xyzwh 341 395 2010 11 25
end
durationcanvas 130926 classinstance_ref 128238 // :bank_info_ctrl
  xyzwh 341 466 2010 11 40
end
durationcanvas 131054 classinstance_ref 128494 // :sys_boundry
  xyzwh 214 466 2010 11 25
end
msg 129262 synchronous
  from durationcanvas_ref 129006
  to durationcanvas_ref 129134
  yz 126 2015 explicitmsg "enter bank info"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 73 101
msg 129646 synchronous
  from durationcanvas_ref 129390
  to durationcanvas_ref 129518
  yz 190 2015 msg operation_ref 171758 // "modity_bank_config()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 198 165
msg 130030 synchronous
  from durationcanvas_ref 129774
  to durationcanvas_ref 129902
  yz 254 2015 explicitmsg "set info"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 418 229
msg 130414 synchronous
  from durationcanvas_ref 130158
  to durationcanvas_ref 130286
  yz 322 2015 msg operation_ref 143214 // "update()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 525 297
msg 130798 return
  from durationcanvas_ref 130542
  to durationcanvas_ref 130670
  yz 395 2015 explicitmsg "success or not"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 503 370
msg 131182 return
  from durationcanvas_ref 130926
  to durationcanvas_ref 131054
  yz 466 2015 explicitmsg "if success"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 246 441
end
