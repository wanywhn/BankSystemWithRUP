format 218

classinstance 128110 class_ref 141934 // bank_assistant
  name ""   xyz 63.6535 4.48804 2000 life_line_z 2000
classinstance 128238 class_ref 128238 // one_card_account
  name ""   xyz 543.919 5.46671 2000 life_line_z 2000
classinstance 130926 class_ref 148718 // one_card_control
  name ""   xyz 389.079 5.42405 2000 life_line_z 2000
classinstance 131054 class_ref 148590 // BankBoundry
  name ""   xyz 241.963 4.48804 2000 life_line_z 2000
classinstance 135278 class_ref 149102 // one_card_account_db
  name ""   xyz 701.519 4 2000 life_line_z 2000
durationcanvas 131182 classinstance_ref 128110 // :bank_assistant
  xyzwh 128 68 2010 11 41
end
durationcanvas 131310 classinstance_ref 131054 // :BankBoundry
  xyzwh 299 67 2010 11 58
end
durationcanvas 131950 classinstance_ref 128110 // :bank_assistant
  xyzwh 128 173 2010 11 40
end
durationcanvas 132078 classinstance_ref 131054 // :BankBoundry
  xyzwh 299 173 2010 11 82
end
durationcanvas 132590 classinstance_ref 128110 // :bank_assistant
  xyzwh 128 292 2010 11 40
end
durationcanvas 132718 classinstance_ref 131054 // :BankBoundry
  xyzwh 299 292 2010 11 25
end
durationcanvas 132974 classinstance_ref 128110 // :bank_assistant
  xyzwh 128 370 2010 11 40
end
durationcanvas 133102 classinstance_ref 131054 // :BankBoundry
  xyzwh 299 370 2010 11 26
end
durationcanvas 133358 classinstance_ref 128110 // :bank_assistant
  xyzwh 128 456 2010 11 40
end
durationcanvas 133486 classinstance_ref 131054 // :BankBoundry
  xyzwh 299 457 2010 11 25
end
durationcanvas 136942 classinstance_ref 128110 // :bank_assistant
  xyzwh 128 533 2010 11 40
end
durationcanvas 137070 classinstance_ref 131054 // :BankBoundry
  xyzwh 299 533 2010 11 25
end
durationcanvas 137326 classinstance_ref 130926 // :one_card_control
  xyzwh 464 544 2010 11 25
end
durationcanvas 137582 classinstance_ref 135278 // :one_card_account_db
  xyzwh 801 551 2010 11 25
end
durationcanvas 137838 classinstance_ref 135278 // :one_card_account_db
  xyzwh 801 618 2010 11 40
end
durationcanvas 137966 classinstance_ref 130926 // :one_card_control
  xyzwh 464 618 2010 11 25
end
durationcanvas 138222 classinstance_ref 130926 // :one_card_control
  xyzwh 464 747 2010 11 40
end
durationcanvas 138350 classinstance_ref 135278 // :one_card_account_db
  xyzwh 801 754 2010 11 31
end
durationcanvas 138606 classinstance_ref 130926 // :one_card_control
  xyzwh 464 812 2010 11 40
end
durationcanvas 138734 classinstance_ref 131054 // :BankBoundry
  xyzwh 299 812 2010 11 25
end
durationcanvas 138990 classinstance_ref 130926 // :one_card_control
  xyzwh 464 657 2010 11 40
end
durationcanvas 139118 classinstance_ref 131054 // :BankBoundry
  xyzwh 299 657 2010 11 50
end
durationcanvas 139374 classinstance_ref 130926 // :one_card_control
  xyzwh 464 719 2010 11 40
end
durationcanvas 139502 classinstance_ref 128238 // :one_card_account
  xyzwh 623 719 2010 11 25
end
msg 131438 synchronous
  from durationcanvas_ref 131182
  to durationcanvas_ref 131310
  yz 68 2015 explicitmsg "set_name"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 162 50
msg 132206 synchronous
  from durationcanvas_ref 131950
  to durationcanvas_ref 132078
  yz 174 3005 explicitmsg "set_idcard"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 167 156
msg 132846 synchronous
  from durationcanvas_ref 132590
  to durationcanvas_ref 132718
  yz 294 2015 explicitmsg "set_address"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 162 276
msg 133230 synchronous
  from durationcanvas_ref 132974
  to durationcanvas_ref 133102
  yz 371 2015 explicitmsg "set_phone_number"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 140 353
msg 133614 synchronous
  from durationcanvas_ref 133358
  to durationcanvas_ref 133486
  yz 457 2015 explicitmsg "set_passwd"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 163 439
msg 137198 synchronous
  from durationcanvas_ref 136942
  to durationcanvas_ref 137070
  yz 533 2015 explicitmsg "submit"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 176 515
msg 137454 synchronous
  from durationcanvas_ref 137070
  to durationcanvas_ref 137326
  yz 544 2015 msg operation_ref 143726 // "register() : void"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 337 526
msg 137710 synchronous
  from durationcanvas_ref 137326
  to durationcanvas_ref 137582
  yz 551 2015 msg operation_ref 143854 // "check_if_exist()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 567 533
msg 138094 return
  from durationcanvas_ref 137838
  to durationcanvas_ref 137966
  yz 618 2015 explicitmsg "isexists"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 592 600
msg 138478 asynchronous
  from durationcanvas_ref 138222
  to durationcanvas_ref 138350
  yz 774 2015 msg operation_ref 142830 // "create()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 590 756
msg 138862 return
  from durationcanvas_ref 138606
  to durationcanvas_ref 138734
  yz 812 2015 explicitmsg "success_of_not"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 319 794
msg 139246 return
  from durationcanvas_ref 138990
  to durationcanvas_ref 139118
  yz 657 2015 explicitmsg "exists"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 347 639
msg 139630 synchronous
  from durationcanvas_ref 139374
  to durationcanvas_ref 139502
  yz 719 2015 explicitmsg "set_info"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 517 701
end
