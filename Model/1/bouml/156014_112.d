format 218

classinstance 128110 class_ref 141934 // bank_assistant
  name ""   xyz 46 4 2000 life_line_z 2000
classinstance 128238 class_ref 148718 // one_card_control
  name ""   xyz 383 4 2000 life_line_z 2000
classinstance 128366 class_ref 148590 // BankBoundry
  name ""   xyz 225 4 2000 life_line_z 2000
classinstance 128494 class_ref 149102 // one_card_account_db
  name ""   xyz 607 4 2000 life_line_z 2000
durationcanvas 128622 classinstance_ref 128110 // :bank_assistant
  xyzwh 111 110 2010 11 40
end
durationcanvas 128750 classinstance_ref 128366 // :BankBoundry
  xyzwh 283 110 2010 11 25
end
durationcanvas 129006 classinstance_ref 128110 // :bank_assistant
  xyzwh 111 209 2010 11 40
end
durationcanvas 129134 classinstance_ref 128366 // :BankBoundry
  xyzwh 283 209 2010 11 25
end
durationcanvas 130798 classinstance_ref 128238 // :one_card_control
  xyzwh 458 113 2010 11 25
end
durationcanvas 131054 classinstance_ref 128494 // :one_card_account_db
  xyzwh 707 123 2010 11 25
end
durationcanvas 131566 classinstance_ref 128238 // :one_card_control
  xyzwh 458 215 2010 11 25
end
durationcanvas 131822 classinstance_ref 128238 // :one_card_control
  xyzwh 458 287 2010 11 40
end
durationcanvas 131950 classinstance_ref 128494 // :one_card_account_db
  xyzwh 707 287 2010 11 25
end
msg 128878 synchronous
  from durationcanvas_ref 128622
  to durationcanvas_ref 128750
  yz 110 2015 explicitmsg "enter_idcard"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 143 92
msg 129262 synchronous
  from durationcanvas_ref 129006
  to durationcanvas_ref 129134
  yz 209 2015 explicitmsg "submit"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 159 191
msg 130926 synchronous
  from durationcanvas_ref 128750
  to durationcanvas_ref 130798
  yz 113 2015 msg operation_ref 142702 // "set_idcard() : void"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 317 95
msg 131182 synchronous
  from durationcanvas_ref 130798
  to durationcanvas_ref 131054
  yz 123 2020 msg operation_ref 143854 // "check_if_exist()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 512 105
msg 131694 synchronous
  from durationcanvas_ref 129134
  to durationcanvas_ref 131566
  yz 215 2015 msg operation_ref 157806 // "set_loss()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 324 197
msg 132078 synchronous
  from durationcanvas_ref 131822
  to durationcanvas_ref 131950
  yz 287 2015 msg operation_ref 143214 // "update()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 533 269
end
