format 218

classinstance 128110 class_ref 141934 // bank_assistant
  name ""   xyz 80 4 2000 life_line_z 2000
classinstance 128238 class_ref 148590 // BankBoundry
  name ""   xyz 264 4 2000 life_line_z 2000
classinstance 128366 class_ref 148718 // one_card_control
  name ""   xyz 402 4 2000 life_line_z 2000
classinstance 128494 class_ref 149102 // one_card_account_db
  name ""   xyz 701 4 2000 life_line_z 2000
classinstance 128622 class_ref 128238 // one_card_account
  name ""   xyz 565 4 2000 life_line_z 2000
durationcanvas 128750 classinstance_ref 128110 // :bank_assistant
  xyzwh 145 98 2010 11 40
end
durationcanvas 128878 classinstance_ref 128238 // :BankBoundry
  xyzwh 322 98 2010 11 25
end
durationcanvas 129390 classinstance_ref 128110 // :bank_assistant
  xyzwh 145 198 2010 11 40
end
durationcanvas 129518 classinstance_ref 128238 // :BankBoundry
  xyzwh 322 198 2010 11 25
end
durationcanvas 129774 classinstance_ref 128238 // :BankBoundry
  xyzwh 322 303 2010 11 40
end
durationcanvas 129902 classinstance_ref 128366 // :one_card_control
  xyzwh 477 303 2010 11 25
end
durationcanvas 130158 classinstance_ref 128366 // :one_card_control
  xyzwh 477 365 2010 11 40
end
durationcanvas 130286 classinstance_ref 128494 // :one_card_account_db
  xyzwh 801 365 2010 11 25
end
durationcanvas 130542 classinstance_ref 128494 // :one_card_account_db
  xyzwh 801 442 2010 11 40
end
durationcanvas 130670 classinstance_ref 128366 // :one_card_control
  xyzwh 477 442 2010 11 25
end
durationcanvas 130926 classinstance_ref 128366 // :one_card_control
  xyzwh 477 506 2010 11 40
end
durationcanvas 131054 classinstance_ref 128622 // :one_card_account
  xyzwh 645 506 2010 11 25
end
durationcanvas 131310 classinstance_ref 128366 // :one_card_control
  xyzwh 477 597 2010 11 40
end
durationcanvas 131438 classinstance_ref 128494 // :one_card_account_db
  xyzwh 801 597 2010 11 25
end
msg 129006 synchronous
  from durationcanvas_ref 128750
  to durationcanvas_ref 128878
  yz 98 2015 explicitmsg "enter_idcard"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 180 80
msg 129646 synchronous
  from durationcanvas_ref 129390
  to durationcanvas_ref 129518
  yz 198 2015 explicitmsg "enable_online_bank_system"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 134 180
msg 130030 synchronous
  from durationcanvas_ref 129774
  to durationcanvas_ref 129902
  yz 303 2015 msg operation_ref 143982 // "open_online_bank_system_of() : void"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 304 285
msg 130414 synchronous
  from durationcanvas_ref 130158
  to durationcanvas_ref 130286
  yz 365 2015 msg operation_ref 143854 // "check_if_exist()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 555 347
msg 130798 return
  from durationcanvas_ref 130542
  to durationcanvas_ref 130670
  yz 442 2015 explicitmsg "if_exists"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 577 424
msg 131182 synchronous
  from durationcanvas_ref 130926
  to durationcanvas_ref 131054
  yz 506 2015 msg operation_ref 144110 // "set_online_bank_status()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 452 488
msg 131566 synchronous
  from durationcanvas_ref 131310
  to durationcanvas_ref 131438
  yz 597 2015 msg operation_ref 143214 // "update()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 576 579
end
