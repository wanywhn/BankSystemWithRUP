format 219

classinstance 128110 class_ref 141934 // bank_assistant
  name ""   xyz 21 4 2000 life_line_z 2000
classinstance 128238 class_ref 148590 // BankBoundry
  name ""   xyz 237 10 2000 life_line_z 2000
classinstance 131310 class_ref 128238 // one_card_account
  name ""   xyz 474 4 2000 life_line_z 2000
classinstance 131438 class_ref 149102 // one_card_account_db
  name ""   xyz 711 4 2000 life_line_z 2000
classinstance 131566 class_ref 148718 // one_card_control
  name ""   xyz 358 4 2000 life_line_z 2000
classinstance 133358 class_ref 128366 // saving_subaccount
  name ""   xyz 598 4 2000 life_line_z 2000
durationcanvas 128494 classinstance_ref 128110 // :bank_assistant
  xyzwh 78 97 2010 11 41
end
durationcanvas 128622 classinstance_ref 128238 // :BankBoundry
  xyzwh 288 97 2010 11 26
end
durationcanvas 128878 classinstance_ref 128238 // :BankBoundry
  xyzwh 288 159 2010 11 40
end
durationcanvas 129006 classinstance_ref 128110 // :bank_assistant
  xyzwh 78 159 2010 11 25
end
durationcanvas 130542 classinstance_ref 128110 // :bank_assistant
  xyzwh 78 223 2010 11 40
end
durationcanvas 130670 classinstance_ref 128238 // :BankBoundry
  xyzwh 288 223 2010 11 25
end
durationcanvas 130926 classinstance_ref 128110 // :bank_assistant
  xyzwh 78 297 2010 11 40
end
durationcanvas 131054 classinstance_ref 128238 // :BankBoundry
  xyzwh 288 297 2010 11 25
end
durationcanvas 131694 classinstance_ref 128238 // :BankBoundry
  xyzwh 288 139 2010 11 40
end
durationcanvas 131822 classinstance_ref 131566 // :one_card_control
  xyzwh 425 139 2010 11 25
end
durationcanvas 132078 classinstance_ref 131438 // :one_card_account_db
  xyzwh 799 149 2010 11 26
end
durationcanvas 132590 classinstance_ref 131438 // :one_card_account_db
  xyzwh 799 237 2010 11 40
end
durationcanvas 132718 classinstance_ref 131566 // :one_card_control
  xyzwh 425 237 2010 11 25
end
durationcanvas 132974 classinstance_ref 131566 // :one_card_control
  xyzwh 425 350 2010 11 40
end
durationcanvas 133102 classinstance_ref 131310 // :one_card_account
  xyzwh 544 350 2010 11 25
end
durationcanvas 133486 classinstance_ref 131310 // :one_card_account
  xyzwh 544 428 2010 11 40
end
durationcanvas 133614 classinstance_ref 131566 // :one_card_control
  xyzwh 425 428 2010 11 25
end
durationcanvas 134254 classinstance_ref 131566 // :one_card_control
  xyzwh 425 568 2010 11 40
end
durationcanvas 134382 classinstance_ref 131438 // :one_card_account_db
  xyzwh 799 568 2010 11 25
end
durationcanvas 134638 classinstance_ref 128238 // :BankBoundry
  xyzwh 288 334 2010 11 40
end
durationcanvas 134766 classinstance_ref 131566 // :one_card_control
  xyzwh 425 334 2010 11 25
end
durationcanvas 135022 classinstance_ref 133358 // :saving_subaccount
  xyzwh 670 365 2010 11 25
end
msg 128750 synchronous
  from durationcanvas_ref 128494
  to durationcanvas_ref 128622
  yz 97 2015 explicitmsg "enter_idcard"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 115 78
msg 129134 return
  from durationcanvas_ref 128878
  to durationcanvas_ref 129006
  yz 159 2015 explicitmsg "select_subaccount"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 132 141
msg 130798 synchronous
  from durationcanvas_ref 130542
  to durationcanvas_ref 130670
  yz 223 2015 explicitmsg "enter_money"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 129 205
msg 131182 synchronous
  from durationcanvas_ref 130926
  to durationcanvas_ref 131054
  yz 297 2015 explicitmsg "deposit"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 146 279
msg 131950 synchronous
  from durationcanvas_ref 131694
  to durationcanvas_ref 131822
  yz 139 2020 msg operation_ref 142702 // "set_idcard() : void"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 319 121
msg 132206 synchronous
  from durationcanvas_ref 131822
  to durationcanvas_ref 132078
  yz 149 2015 msg operation_ref 143854 // "check_if_exist()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 524 131
msg 132846 return
  from durationcanvas_ref 132590
  to durationcanvas_ref 132718
  yz 237 2015 unspecifiedmsg
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
msg 133230 synchronous
  from durationcanvas_ref 132974
  to durationcanvas_ref 133102
  yz 350 2015 msg operation_ref 164974 // "deposit()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 418 332
msg 133742 return
  from durationcanvas_ref 133486
  to durationcanvas_ref 133614
  yz 428 2015 unspecifiedmsg
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
msg 134510 synchronous
  from durationcanvas_ref 134254
  to durationcanvas_ref 134382
  yz 568 2015 msg operation_ref 143214 // "update()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 572 550
msg 134894 synchronous
  from durationcanvas_ref 134638
  to durationcanvas_ref 134766
  yz 334 2015 msg operation_ref 158062 // "deposit()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 320 316
msg 135150 synchronous
  from durationcanvas_ref 133102
  to durationcanvas_ref 135022
  yz 365 2015 msg operation_ref 150894 // "deposit()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 566 353
end
