format 218

classinstance 128110 class_ref 141934 // bank_assistant
  name ""   xyz 31 4 2000 life_line_z 2000
classinstance 128238 class_ref 148590 // BankBoundry
  name ""   xyz 185 4 2000 life_line_z 2000
classinstance 128366 class_ref 148718 // one_card_control
  name ""   xyz 346 4 2000 life_line_z 2000
classinstance 128494 class_ref 149102 // one_card_account_db
  name ""   xyz 656 5 2000 life_line_z 2000
durationcanvas 128750 classinstance_ref 128110 // :bank_assistant
  xyzwh 96 129 2010 11 40
end
durationcanvas 128878 classinstance_ref 128238 // :BankBoundry
  xyzwh 243 129 2010 11 25
end
durationcanvas 129390 classinstance_ref 128110 // :bank_assistant
  xyzwh 96 237 2010 11 40
end
durationcanvas 129518 classinstance_ref 128238 // :BankBoundry
  xyzwh 243 237 2010 11 25
end
durationcanvas 129774 classinstance_ref 128366 // :one_card_control
  xyzwh 421 251 2010 11 25
end
durationcanvas 130030 classinstance_ref 128366 // :one_card_control
  xyzwh 421 311 2010 11 40
end
durationcanvas 130158 classinstance_ref 128494 // :one_card_account_db
  xyzwh 756 311 2010 11 25
end
durationcanvas 130414 classinstance_ref 128494 // :one_card_account_db
  xyzwh 756 400 2010 11 40
end
durationcanvas 130542 classinstance_ref 128366 // :one_card_control
  xyzwh 421 400 2010 11 25
end
durationcanvas 130798 classinstance_ref 128366 // :one_card_control
  xyzwh 421 458 2010 11 40
end
durationcanvas 130926 classinstance_ref 128494 // :one_card_account_db
  xyzwh 756 458 2010 11 25
end
msg 129006 synchronous
  from durationcanvas_ref 128750
  to durationcanvas_ref 128878
  yz 129 2015 explicitmsg "enter_idcard"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 116 111
msg 129646 synchronous
  from durationcanvas_ref 129390
  to durationcanvas_ref 129518
  yz 237 2015 explicitmsg "confirm_delete"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 109 219
msg 129902 synchronous
  from durationcanvas_ref 129518
  to durationcanvas_ref 129774
  yz 251 2020 msg operation_ref 144238 // "delete_account_of() : void"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 256 233
msg 130286 synchronous
  from durationcanvas_ref 130030
  to durationcanvas_ref 130158
  yz 311 2015 msg operation_ref 143854 // "check_if_exist()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 518 293
msg 130670 return
  from durationcanvas_ref 130414
  to durationcanvas_ref 130542
  yz 400 2015 explicitmsg "exists"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 547 382
msg 131054 synchronous
  from durationcanvas_ref 130798
  to durationcanvas_ref 130926
  yz 458 2015 msg operation_ref 142958 // "delete()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 541 440
end
