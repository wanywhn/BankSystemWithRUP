format 218

classinstance 128110 class_ref 141934 // bank_assistant
  name ""   xyz 56 4 2000 life_line_z 2000
classinstance 128238 class_ref 148590 // BankBoundry
  name ""   xyz 207 4 2000 life_line_z 2000
classinstance 128366 class_ref 148718 // one_card_control
  name ""   xyz 365 4 2000 life_line_z 2000
classinstance 128494 class_ref 149102 // one_card_account_db
  name ""   xyz 737 12 2000 life_line_z 2000
classinstance 131310 class_ref 128238 // one_card_account
  name ""   xyz 580 4 2000 life_line_z 2000
durationcanvas 128622 classinstance_ref 128110 // :bank_assistant
  xyzwh 121 105 2010 11 40
end
durationcanvas 128750 classinstance_ref 128238 // :BankBoundry
  xyzwh 265 105 2010 11 25
end
durationcanvas 129006 classinstance_ref 128110 // :bank_assistant
  xyzwh 121 204 2010 11 40
end
durationcanvas 129134 classinstance_ref 128238 // :BankBoundry
  xyzwh 265 204 2010 11 25
end
durationcanvas 129390 classinstance_ref 128110 // :bank_assistant
  xyzwh 121 300 2010 11 40
end
durationcanvas 129518 classinstance_ref 128238 // :BankBoundry
  xyzwh 265 300 2010 11 25
end
durationcanvas 129774 classinstance_ref 128238 // :BankBoundry
  xyzwh 265 359 2010 11 40
end
durationcanvas 129902 classinstance_ref 128366 // :one_card_control
  xyzwh 440 359 2010 11 25
end
durationcanvas 130158 classinstance_ref 128366 // :one_card_control
  xyzwh 440 425 2010 11 40
end
durationcanvas 130286 classinstance_ref 128494 // :one_card_account_db
  xyzwh 837 425 2010 11 25
end
durationcanvas 130542 classinstance_ref 128494 // :one_card_account_db
  xyzwh 837 500 2010 11 40
end
durationcanvas 130670 classinstance_ref 128366 // :one_card_control
  xyzwh 440 500 2010 11 25
end
durationcanvas 130926 classinstance_ref 128366 // :one_card_control
  xyzwh 440 552 2010 11 40
end
durationcanvas 131054 classinstance_ref 128494 // :one_card_account_db
  xyzwh 837 552 2010 11 25
end
durationcanvas 131438 classinstance_ref 128366 // :one_card_control
  xyzwh 440 480 2010 11 40
end
durationcanvas 131566 classinstance_ref 131310 // :one_card_account
  xyzwh 660 480 2010 11 25
end
msg 128878 synchronous
  from durationcanvas_ref 128622
  to durationcanvas_ref 128750
  yz 105 2015 explicitmsg "want_to_change_passwd"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 103 87
msg 129262 synchronous
  from durationcanvas_ref 129006
  to durationcanvas_ref 129134
  yz 204 2015 explicitmsg "enter_idcard"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 139 186
msg 129646 synchronous
  from durationcanvas_ref 129390
  to durationcanvas_ref 129518
  yz 300 2015 explicitmsg "enter_new_passwd"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 120 282
msg 130030 synchronous
  from durationcanvas_ref 129774
  to durationcanvas_ref 129902
  yz 359 2015 msg operation_ref 144366 // "change_passwd_of() : void"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 274 341
msg 130414 synchronous
  from durationcanvas_ref 130158
  to durationcanvas_ref 130286
  yz 425 2015 msg operation_ref 143854 // "check_if_exist()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 507 407
msg 130798 return
  from durationcanvas_ref 130542
  to durationcanvas_ref 130670
  yz 500 2015 unspecifiedmsg
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
msg 131182 synchronous
  from durationcanvas_ref 130926
  to durationcanvas_ref 131054
  yz 552 2015 msg operation_ref 143214 // "update()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 528 534
msg 131694 synchronous
  from durationcanvas_ref 131438
  to durationcanvas_ref 131566
  yz 480 2015 msg operation_ref 164846 // "change_passwd()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 476 468
end
