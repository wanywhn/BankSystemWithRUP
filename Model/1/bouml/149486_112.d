format 218

classinstance 128110 class_ref 141934 // bank_assistant
  name ""   xyz 45 4 2000 life_line_z 2000
classinstance 128238 class_ref 149102 // one_card_account_db
  name ""   xyz 675 4 2000 life_line_z 2000
classinstance 128366 class_ref 148590 // BankBoundry
  name ""   xyz 246 4 2000 life_line_z 2000
classinstance 128494 class_ref 148718 // one_card_control
  name ""   xyz 423 4 2000 life_line_z 2000
classinstance 131182 class_ref 128366 // saving_subaccount
  name ""   xyz 548 4 2000 life_line_z 2000
durationcanvas 128622 classinstance_ref 128110 // :bank_assistant
  xyzwh 110 131 2010 11 40
end
durationcanvas 128750 classinstance_ref 128366 // :BankBoundry
  xyzwh 304 131 2010 11 25
end
durationcanvas 129006 classinstance_ref 128110 // :bank_assistant
  xyzwh 110 402 2010 11 77
end
durationcanvas 129134 classinstance_ref 128366 // :BankBoundry
  xyzwh 304 406 2010 11 73
end
durationcanvas 129390 classinstance_ref 128366 // :BankBoundry
  xyzwh 304 165 2010 11 102
end
durationcanvas 129518 classinstance_ref 128494 // :one_card_control
  xyzwh 498 174 2010 11 85
end
durationcanvas 129774 classinstance_ref 128238 // :one_card_account_db
  xyzwh 775 223 2010 11 25
end
durationcanvas 130030 classinstance_ref 128238 // :one_card_account_db
  xyzwh 775 300 2010 11 40
end
durationcanvas 130158 classinstance_ref 128494 // :one_card_control
  xyzwh 498 300 2010 11 25
end
durationcanvas 130414 classinstance_ref 128494 // :one_card_control
  xyzwh 498 345 2010 11 40
end
durationcanvas 130542 classinstance_ref 128366 // :BankBoundry
  xyzwh 304 345 2010 11 25
end
durationcanvas 130798 classinstance_ref 128366 // :BankBoundry
  xyzwh 304 510 2010 11 40
end
durationcanvas 130926 classinstance_ref 128494 // :one_card_control
  xyzwh 498 510 2010 11 27
end
durationcanvas 131310 classinstance_ref 131182 // :saving_subaccount
  xyzwh 630 526 2010 11 25
end
durationcanvas 131566 classinstance_ref 128494 // :one_card_control
  xyzwh 498 573 2010 11 40
end
durationcanvas 131694 classinstance_ref 128238 // :one_card_account_db
  xyzwh 775 573 2010 11 25
end
msg 128878 synchronous
  from durationcanvas_ref 128622
  to durationcanvas_ref 128750
  yz 131 2015 explicitmsg "enter_other_account"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 129 113
msg 129262 synchronous
  from durationcanvas_ref 129006
  to durationcanvas_ref 129134
  yz 468 2015 explicitmsg "enter_money"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 151 450
msg 129646 synchronous
  from durationcanvas_ref 129390
  to durationcanvas_ref 129518
  yz 174 2015 msg operation_ref 151022 // "set_target_idcard()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 359 156
msg 129902 synchronous
  from durationcanvas_ref 129518
  to durationcanvas_ref 129774
  yz 223 2015 msg operation_ref 143854 // "check_if_exist()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 554 205
msg 130286 return
  from durationcanvas_ref 130030
  to durationcanvas_ref 130158
  yz 300 2015 unspecifiedmsg
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
msg 130670 return
  from durationcanvas_ref 130414
  to durationcanvas_ref 130542
  yz 345 2015 explicitmsg "display_info"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 358 327
msg 131054 synchronous
  from durationcanvas_ref 130798
  to durationcanvas_ref 130926
  yz 510 2015 msg operation_ref 151150 // "transfer_money()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 343 492
msg 131438 synchronous
  from durationcanvas_ref 130926
  to durationcanvas_ref 131310
  yz 526 2020 msg operation_ref 165230 // "transfer_money()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 505 514
msg 131822 synchronous
  from durationcanvas_ref 131566
  to durationcanvas_ref 131694
  yz 573 2015 msg operation_ref 143214 // "update()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 585 561
end
