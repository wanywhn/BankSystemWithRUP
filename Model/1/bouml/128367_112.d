format 218

classinstance 128111 class_ref 141934 // bank_assistant
  name ""   xyz 73 27 2000 life_line_z 2000
classinstance 128239 class_ref 148590 // BankBoundry
  name ""   xyz 293 34 2000 life_line_z 2000
classinstance 128367 class_ref 128239 // online_bank_control
  name ""   xyz 439 30 2000 life_line_z 2000
classinstance 129647 class_ref 128367 // online_bank
  name ""   xyz 747 43 2000 life_line_z 2000
classinstance 129775 class_ref 128495 // ;online_bank
  name ""   xyz 611 37 2000 life_line_z 2000
durationcanvas 128495 classinstance_ref 128111 // :bank_assistant
  xyzwh 138 111 2010 11 43
end
durationcanvas 128623 classinstance_ref 128239 // :BankBoundry
  xyzwh 351 111 2010 11 59
end
durationcanvas 128879 classinstance_ref 128239 // :BankBoundry
  xyzwh 351 302 2010 11 42
end
durationcanvas 129007 classinstance_ref 128367 // :online_bank_control
  xyzwh 525 291 2010 11 60
end
durationcanvas 129263 classinstance_ref 128111 // :bank_assistant
  xyzwh 138 246 2010 11 40
end
durationcanvas 129391 classinstance_ref 128239 // :BankBoundry
  xyzwh 351 212 2010 11 74
end
durationcanvas 129903 classinstance_ref 129647 // :online_bank
  xyzwh 802 316 2010 11 25
end
durationcanvas 130159 classinstance_ref 129647 // :online_bank
  xyzwh 802 375 2010 11 40
end
durationcanvas 130287 classinstance_ref 128367 // :online_bank_control
  xyzwh 525 375 2010 11 25
end
durationcanvas 130543 classinstance_ref 128367 // :online_bank_control
  xyzwh 525 433 2010 11 40
end
durationcanvas 130671 classinstance_ref 129775 // :;online_bank
  xyzwh 665 433 2010 11 25
end
durationcanvas 130927 classinstance_ref 128367 // :online_bank_control
  xyzwh 525 485 2010 11 40
end
durationcanvas 131055 classinstance_ref 129775 // :;online_bank
  xyzwh 665 485 2010 11 25
end
durationcanvas 131311 classinstance_ref 128367 // :online_bank_control
  xyzwh 525 554 2010 11 40
end
durationcanvas 131439 classinstance_ref 129775 // :;online_bank
  xyzwh 665 554 2010 11 25
end
durationcanvas 131695 classinstance_ref 128367 // :online_bank_control
  xyzwh 525 612 2010 11 40
end
durationcanvas 131823 classinstance_ref 129647 // :online_bank
  xyzwh 802 612 2010 11 25
end
msg 128751 synchronous
  from durationcanvas_ref 128495
  to durationcanvas_ref 128623
  yz 111 2015 explicitmsg "set_cname"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 201 86
msg 129135 synchronous
  from durationcanvas_ref 128879
  to durationcanvas_ref 129007
  yz 324 2015 msg operation_ref 128111 // "register_onlinebank()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 353 299
msg 129519 synchronous
  from durationcanvas_ref 129263
  to durationcanvas_ref 129391
  yz 246 2015 explicitmsg "set_passwd"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 198 221
msg 130031 synchronous
  from durationcanvas_ref 129007
  to durationcanvas_ref 129903
  yz 316 2015 explicitmsg "check_if_exists_username"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 569 291
msg 130415 return
  from durationcanvas_ref 130159
  to durationcanvas_ref 130287
  yz 375 2015 explicitmsg "return if exists"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 608 352
msg 130799 synchronous
  from durationcanvas_ref 130543
  to durationcanvas_ref 130671
  yz 433 2015 explicitmsg "set_name"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 556 408
msg 131183 synchronous
  from durationcanvas_ref 130927
  to durationcanvas_ref 131055
  yz 485 2015 explicitmsg "set_passwd"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 549 460
msg 131567 synchronous
  from durationcanvas_ref 131311
  to durationcanvas_ref 131439
  yz 554 2015 explicitmsg "id_card"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 565 529
msg 131951 synchronous
  from durationcanvas_ref 131695
  to durationcanvas_ref 131823
  yz 612 2015 explicitmsg "create"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 636 587
end
