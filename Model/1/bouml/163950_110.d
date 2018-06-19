format 219

classinstance 128110 class_ref 128110 // kehu
  name ""   xyz 46 4 2000 life_line_z 2000
classinstance 128366 class_ref 128623 // online_bank_boundary
  name ""   xyz 117 4 2005 life_line_z 2000
classinstance 128494 class_ref 128239 // online_bank_control
  name ""   xyz 325 4 2010 life_line_z 2000
classinstance 128622 class_ref 148974 // DB
  name ""   xyz 599 4 2000 life_line_z 2000
durationcanvas 128750 classinstance_ref 128110 // :kehu
  xyzwh 64 117 2010 11 40
end
durationcanvas 128878 classinstance_ref 128366 // :online_bank_boundary
  xyzwh 205 117 2010 11 25
end
durationcanvas 129134 classinstance_ref 128110 // :kehu
  xyzwh 64 205 2010 11 40
end
durationcanvas 129262 classinstance_ref 128366 // :online_bank_boundary
  xyzwh 205 205 2010 11 25
end
durationcanvas 129518 classinstance_ref 128366 // :online_bank_boundary
  xyzwh 205 161 2010 11 40
end
durationcanvas 129774 classinstance_ref 128366 // :online_bank_boundary
  xyzwh 205 261 2010 11 40
end
durationcanvas 129902 classinstance_ref 128494 // :online_bank_control
  xyzwh 404 261 2010 11 25
end
durationcanvas 130158 classinstance_ref 128494 // :online_bank_control
  xyzwh 404 307 2010 11 40
end
durationcanvas 130286 classinstance_ref 128622 // :DB
  xyzwh 618 307 2010 11 25
end
durationcanvas 130542 classinstance_ref 128622 // :DB
  xyzwh 618 363 2010 11 40
end
durationcanvas 130670 classinstance_ref 128494 // :online_bank_control
  xyzwh 404 363 2010 11 25
end
durationcanvas 130926 classinstance_ref 128494 // :online_bank_control
  xyzwh 404 445 2010 11 40
end
durationcanvas 131054 classinstance_ref 128622 // :DB
  xyzwh 618 445 2010 11 25
end
durationcanvas 131310 classinstance_ref 128494 // :online_bank_control
  xyzwh 404 520 2010 11 40
end
durationcanvas 131438 classinstance_ref 128366 // :online_bank_boundary
  xyzwh 205 520 2010 11 25
end
msg 129006 synchronous
  from durationcanvas_ref 128750
  to durationcanvas_ref 128878
  yz 117 2015 explicitmsg "open_credit_card"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 72 92
msg 129390 synchronous
  from durationcanvas_ref 129134
  to durationcanvas_ref 129262
  yz 205 2015 explicitmsg "enter id"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 110 180
reflexivemsg 129646 synchronous
  to durationcanvas_ref 129518
  yz 161 2015 explicitmsg "get_user_id"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 180 136
msg 130030 synchronous
  from durationcanvas_ref 129774
  to durationcanvas_ref 129902
  yz 261 2015 msg operation_ref 172910 // "delete user()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 262 236
msg 130414 synchronous
  from durationcanvas_ref 130158
  to durationcanvas_ref 130286
  yz 307 2015 msg operation_ref 143086 // "query()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 488 282
msg 130798 return
  from durationcanvas_ref 130542
  to durationcanvas_ref 130670
  yz 363 2015 explicitmsg "if exists"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 487 338
msg 131182 synchronous
  from durationcanvas_ref 130926
  to durationcanvas_ref 131054
  yz 445 2015 msg operation_ref 142958 // "delete()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 486 420
msg 131566 return
  from durationcanvas_ref 131310
  to durationcanvas_ref 131438
  yz 520 2015 explicitmsg "success"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 280 495
end
