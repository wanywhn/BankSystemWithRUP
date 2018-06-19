format 219

classinstance 128110 class_ref 141934 // bank_assistant
  name ""   xyz 35 4 2000 life_line_z 2000
classinstance 128238 class_ref 148590 // BankBoundry
  name ""   xyz 220 5 2000 life_line_z 2000
classinstance 128366 class_ref 148718 // one_card_control
  name ""   xyz 368 4 2000 life_line_z 2000
classinstance 128494 class_ref 149102 // one_card_account_db
  name ""   xyz 563 4 2000 life_line_z 2000
durationcanvas 129006 classinstance_ref 128110 // :bank_assistant
  xyzwh 92 113 2010 11 40
end
durationcanvas 129134 classinstance_ref 128238 // :BankBoundry
  xyzwh 271 113 2010 11 25
end
durationcanvas 129390 classinstance_ref 128110 // :bank_assistant
  xyzwh 92 257 2010 11 40
end
durationcanvas 129518 classinstance_ref 128238 // :BankBoundry
  xyzwh 271 257 2010 11 25
end
durationcanvas 131438 classinstance_ref 128366 // :one_card_control
  xyzwh 435 267 2010 11 25
end
durationcanvas 131694 classinstance_ref 128366 // :one_card_control
  xyzwh 435 122 2010 11 25
end
durationcanvas 131950 classinstance_ref 128494 // :one_card_account_db
  xyzwh 651 132 2010 11 25
end
durationcanvas 132462 classinstance_ref 128366 // :one_card_control
  xyzwh 435 316 2010 11 40
end
durationcanvas 132718 classinstance_ref 128366 // :one_card_control
  xyzwh 435 382 2010 11 40
end
durationcanvas 132974 classinstance_ref 128366 // :one_card_control
  xyzwh 435 468 2010 11 40
end
durationcanvas 133102 classinstance_ref 128494 // :one_card_account_db
  xyzwh 651 468 2010 11 25
end
msg 129262 synchronous
  from durationcanvas_ref 129006
  to durationcanvas_ref 129134
  yz 113 2015 explicitmsg "enter_idcard"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 135 95
msg 129646 synchronous
  from durationcanvas_ref 129390
  to durationcanvas_ref 129518
  yz 257 2015 explicitmsg "request_cancel"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 128 239
msg 131566 synchronous
  from durationcanvas_ref 129518
  to durationcanvas_ref 131438
  yz 267 2020 msg operation_ref 158190 // "cancel_loss()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 304 249
msg 131822 synchronous
  from durationcanvas_ref 129134
  to durationcanvas_ref 131694
  yz 122 2020 msg operation_ref 142702 // "set_idcard() : void"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 307 104
msg 132078 synchronous
  from durationcanvas_ref 131694
  to durationcanvas_ref 131950
  yz 132 2025 msg operation_ref 143854 // "check_if_exist()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 482 114
reflexivemsg 132590 synchronous
  to durationcanvas_ref 132462
  yz 316 2015 explicitmsg "lost_day_gt_one_week"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 370 298
reflexivemsg 132846 synchronous
  to durationcanvas_ref 132718
  yz 382 2015 msg operation_ref 157806 // "set_loss()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 409 364
msg 133230 synchronous
  from durationcanvas_ref 132974
  to durationcanvas_ref 133102
  yz 468 2015 msg operation_ref 143214 // "update()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 503 450
end
