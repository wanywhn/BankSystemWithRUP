format 219

classinstance 128110 class_ref 155886 // sys_boundry
  name ""   xyz 210 4 2000 life_line_z 2000
classinstance 128238 class_ref 156142 // plan_ctrl
  name ""   xyz 368 4 2000 life_line_z 2000
classinstance 128366 class_ref 156014 // modify_plan
  name ""   xyz 462 4 2000 life_line_z 2000
classinstance 128494 class_ref 148974 // DB
  name ""   xyz 667 4 2000 life_line_z 2000
classinstance 128622 class_ref 141934 // bank_assistant
  name ""   xyz 12 4 2000 life_line_z 2000
durationcanvas 128750 classinstance_ref 128622 // :bank_assistant
  xyzwh 69 112 2010 11 40
end
durationcanvas 128878 classinstance_ref 128110 // :sys_boundry
  xyzwh 258 112 2010 11 25
end
durationcanvas 129134 classinstance_ref 128110 // :sys_boundry
  xyzwh 258 189 2010 11 40
end
durationcanvas 129262 classinstance_ref 128238 // :plan_ctrl
  xyzwh 401 189 2010 11 25
end
durationcanvas 130286 classinstance_ref 128238 // :plan_ctrl
  xyzwh 401 397 2010 11 40
end
durationcanvas 130414 classinstance_ref 128366 // :modify_plan
  xyzwh 509 397 2010 11 25
end
durationcanvas 131054 classinstance_ref 128238 // :plan_ctrl
  xyzwh 401 533 2010 11 40
end
durationcanvas 131182 classinstance_ref 128110 // :sys_boundry
  xyzwh 258 533 2010 11 25
end
msg 129006 synchronous
  from durationcanvas_ref 128750
  to durationcanvas_ref 128878
  yz 112 2015 explicitmsg "cancel plan"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 113 87
msg 129390 synchronous
  from durationcanvas_ref 129134
  to durationcanvas_ref 129262
  yz 189 2015 msg operation_ref 172654 // "calcen_current_plan()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 284 165
msg 130542 synchronous
  from durationcanvas_ref 130286
  to durationcanvas_ref 130414
  yz 397 2015 msg operation_ref 172782 // "stop()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 436 372
msg 131310 return
  from durationcanvas_ref 131054
  to durationcanvas_ref 131182
  yz 533 2015 explicitmsg "successed"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 296 508
end
