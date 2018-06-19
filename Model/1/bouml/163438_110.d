format 219

classinstance 128110 class_ref 141934 // bank_assistant
  name ""   xyz 19 4 2000 life_line_z 2000
classinstance 128238 class_ref 155758 // sys_account
  name ""   xyz 465 4 2000 life_line_z 2000
classinstance 128366 class_ref 148974 // DB
  name ""   xyz 642 4 2000 life_line_z 2000
classinstance 128494 class_ref 156270 // modify_user
  name ""   xyz 292 4 2000 life_line_z 2000
classinstance 128622 class_ref 155886 // sys_boundry
  name ""   xyz 159 4 2000 life_line_z 2000
durationcanvas 128750 classinstance_ref 128110 // :bank_assistant
  xyzwh 76 113 2010 11 40
end
durationcanvas 128878 classinstance_ref 128622 // :sys_boundry
  xyzwh 207 113 2010 11 25
end
durationcanvas 129134 classinstance_ref 128110 // :bank_assistant
  xyzwh 76 193 2010 11 40
end
durationcanvas 129262 classinstance_ref 128622 // :sys_boundry
  xyzwh 207 193 2010 11 25
end
durationcanvas 129518 classinstance_ref 128622 // :sys_boundry
  xyzwh 207 260 2010 11 40
end
durationcanvas 129646 classinstance_ref 128494 // :modify_user
  xyzwh 339 260 2010 11 25
end
durationcanvas 130286 classinstance_ref 128494 // :modify_user
  xyzwh 339 382 2010 11 40
end
durationcanvas 130414 classinstance_ref 128366 // :DB
  xyzwh 661 382 2010 11 25
end
durationcanvas 130670 classinstance_ref 128366 // :DB
  xyzwh 661 455 2010 11 40
end
durationcanvas 130798 classinstance_ref 128494 // :modify_user
  xyzwh 339 455 2010 11 25
end
durationcanvas 131054 classinstance_ref 128494 // :modify_user
  xyzwh 339 523 2010 11 40
end
durationcanvas 131182 classinstance_ref 128622 // :sys_boundry
  xyzwh 207 521 2010 11 44
end
durationcanvas 131438 classinstance_ref 128494 // :modify_user
  xyzwh 339 498 2010 11 40
end
durationcanvas 131566 classinstance_ref 128366 // :DB
  xyzwh 661 498 2010 11 25
end
msg 129006 synchronous
  from durationcanvas_ref 128750
  to durationcanvas_ref 128878
  yz 113 2015 explicitmsg "inter user info"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 93 88
msg 129390 synchronous
  from durationcanvas_ref 129134
  to durationcanvas_ref 129262
  yz 193 2015 explicitmsg "click delete"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 113 168
msg 129774 synchronous
  from durationcanvas_ref 129518
  to durationcanvas_ref 129646
  yz 260 2015 msg operation_ref 172014 // "user_delete()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 237 235
msg 130542 synchronous
  from durationcanvas_ref 130286
  to durationcanvas_ref 130414
  yz 382 2015 msg operation_ref 143086 // "query()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 475 357
msg 130926 return
  from durationcanvas_ref 130670
  to durationcanvas_ref 130798
  yz 455 2015 explicitmsg "if exists"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 450 430
msg 131310 return
  from durationcanvas_ref 131054
  to durationcanvas_ref 131182
  yz 540 2015 explicitmsg "disp info"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 249 515
msg 131694 synchronous
  from durationcanvas_ref 131438
  to durationcanvas_ref 131566
  yz 498 2015 msg operation_ref 142958 // "delete()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 475 473
end
