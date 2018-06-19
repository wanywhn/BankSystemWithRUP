format 219

classinstance 128110 class_ref 128110 // kehu
  name ""   xyz 56 4 2000 life_line_z 2000
classinstance 128238 class_ref 156398 // boundry_credit_card
  name ""   xyz 144 4 2005 life_line_z 2000
classinstance 128366 class_ref 156526 // control_credit_card
  name ""   xyz 305 4 2010 life_line_z 2000
classinstance 128494 class_ref 156654 // entity_credit_card
  name ""   xyz 465 4 2000 life_line_z 2000
classinstance 128622 class_ref 156782 // entity_consume_log
  name ""   xyz 587 4 2000 life_line_z 2000
classinstance 128750 class_ref 148974 // DB
  name ""   xyz 766 4 2000 life_line_z 2000
durationcanvas 128878 classinstance_ref 128110 // :kehu
  xyzwh 74 121 2010 11 40
end
durationcanvas 129006 classinstance_ref 128238 // :boundry_credit_card
  xyzwh 224 121 2010 11 25
end
durationcanvas 129262 classinstance_ref 128110 // :kehu
  xyzwh 74 192 2010 11 40
end
durationcanvas 129390 classinstance_ref 128238 // :boundry_credit_card
  xyzwh 224 192 2010 11 25
end
durationcanvas 129646 classinstance_ref 128110 // :kehu
  xyzwh 74 265 2010 11 40
end
durationcanvas 129774 classinstance_ref 128238 // :boundry_credit_card
  xyzwh 224 265 2010 11 25
end
durationcanvas 130030 classinstance_ref 128238 // :boundry_credit_card
  xyzwh 224 312 2010 11 40
end
durationcanvas 130158 classinstance_ref 128366 // :control_credit_card
  xyzwh 380 312 2010 11 25
end
durationcanvas 130414 classinstance_ref 128366 // :control_credit_card
  xyzwh 380 360 2010 11 40
end
durationcanvas 130542 classinstance_ref 128494 // :entity_credit_card
  xyzwh 535 360 2010 11 25
end
durationcanvas 130798 classinstance_ref 128366 // :control_credit_card
  xyzwh 380 440 2010 11 40
end
durationcanvas 130926 classinstance_ref 128494 // :entity_credit_card
  xyzwh 535 440 2010 11 25
end
durationcanvas 131182 classinstance_ref 128366 // :control_credit_card
  xyzwh 380 498 2010 11 40
end
durationcanvas 131310 classinstance_ref 128622 // :entity_consume_log
  xyzwh 664 498 2010 11 25
end
durationcanvas 131566 classinstance_ref 128366 // :control_credit_card
  xyzwh 380 562 2010 11 40
end
durationcanvas 131694 classinstance_ref 128750 // :DB
  xyzwh 785 562 2010 11 25
end
durationcanvas 131950 classinstance_ref 128366 // :control_credit_card
  xyzwh 380 630 2010 11 40
end
durationcanvas 132078 classinstance_ref 128238 // :boundry_credit_card
  xyzwh 224 630 2010 11 25
end
msg 129134 synchronous
  from durationcanvas_ref 128878
  to durationcanvas_ref 129006
  yz 121 2015 explicitmsg "enter credita_card"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 83 96
msg 129518 synchronous
  from durationcanvas_ref 129262
  to durationcanvas_ref 129390
  yz 192 2015 explicitmsg "set money"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 114 167
msg 129902 synchronous
  from durationcanvas_ref 129646
  to durationcanvas_ref 129774
  yz 265 2015 explicitmsg "set type"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 123 240
msg 130286 synchronous
  from durationcanvas_ref 130030
  to durationcanvas_ref 130158
  yz 312 2015 msg operation_ref 173038 // "pay()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 287 287
msg 130670 synchronous
  from durationcanvas_ref 130414
  to durationcanvas_ref 130542
  yz 360 2015 msg operation_ref 173166 // "check_if_enough()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 392 335
msg 131054 synchronous
  from durationcanvas_ref 130798
  to durationcanvas_ref 130926
  yz 440 2015 msg operation_ref 173294 // "spend_money()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 403 415
msg 131438 synchronous
  from durationcanvas_ref 131182
  to durationcanvas_ref 131310
  yz 498 2015 msg operation_ref 173422 // "log_pay_info()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 472 473
msg 131822 synchronous
  from durationcanvas_ref 131566
  to durationcanvas_ref 131694
  yz 562 2015 msg operation_ref 143214 // "update()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 555 537
msg 132206 return
  from durationcanvas_ref 131950
  to durationcanvas_ref 132078
  yz 630 2015 explicitmsg "success"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 277 605
end
