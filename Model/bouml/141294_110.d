format 218

classinstance 128110 class_ref 141934 // bank_assistant
  name ""   xyz 63 4 2000 life_line_z 2000
classinstance 128238 class_ref 128238 // one_card_account
  name ""   xyz 582 5 2000 life_line_z 2000
classinstance 130926 class_ref 148718 // open_one_card_control
  name ""   xyz 372 4 2000 life_line_z 2000
classinstance 131054 class_ref 148590 // BankBoundry
  name ""   xyz 241 4 2000 life_line_z 2000
classinstance 135278 class_ref 149102 // one_card_account_db
  name ""   xyz 711 4 2000 life_line_z 2000
durationcanvas 131182 classinstance_ref 128110 // :bank_assistant
  xyzwh 105 68 2010 11 41
end
durationcanvas 131310 classinstance_ref 131054 // :BankBoundry
  xyzwh 278 68 2010 11 58
end
durationcanvas 131950 classinstance_ref 128110 // :bank_assistant
  xyzwh 105 174 2010 11 40
end
durationcanvas 132078 classinstance_ref 131054 // :BankBoundry
  xyzwh 278 173 2010 11 82
end
durationcanvas 132590 classinstance_ref 128110 // :bank_assistant
  xyzwh 105 292 2010 11 40
end
durationcanvas 132718 classinstance_ref 131054 // :BankBoundry
  xyzwh 278 292 2010 11 25
end
durationcanvas 132974 classinstance_ref 128110 // :bank_assistant
  xyzwh 105 371 2010 11 40
end
durationcanvas 133102 classinstance_ref 131054 // :BankBoundry
  xyzwh 278 371 2010 11 26
end
durationcanvas 133358 classinstance_ref 128110 // :bank_assistant
  xyzwh 105 457 2010 11 40
end
durationcanvas 133486 classinstance_ref 131054 // :BankBoundry
  xyzwh 278 457 2010 11 25
end
durationcanvas 133742 classinstance_ref 130926 // :open_one_card_control
  xyzwh 439 66 2010 11 67
  overlappingdurationcanvas 133998
    xyzwh 445 86 2020 11 25
  end
end
durationcanvas 134254 classinstance_ref 128238 // :one_card_account
  xyzwh 634 113 2010 11 25
end
durationcanvas 134510 classinstance_ref 130926 // :open_one_card_control
  xyzwh 439 200 2010 11 48
  overlappingdurationcanvas 134766
    xyzwh 445 209 2020 11 25
  end
end
durationcanvas 135022 classinstance_ref 128238 // :one_card_account
  xyzwh 634 237 2010 11 25
end
durationcanvas 135406 classinstance_ref 130926 // :open_one_card_control
  xyzwh 439 304 2010 11 25
end
durationcanvas 135662 classinstance_ref 128238 // :one_card_account
  xyzwh 634 315 2010 11 25
end
durationcanvas 135918 classinstance_ref 130926 // :open_one_card_control
  xyzwh 439 386 2010 11 25
end
durationcanvas 136174 classinstance_ref 128238 // :one_card_account
  xyzwh 634 395 2010 11 25
end
durationcanvas 136430 classinstance_ref 130926 // :open_one_card_control
  xyzwh 439 465 2010 11 25
end
durationcanvas 136686 classinstance_ref 128238 // :one_card_account
  xyzwh 634 476 2010 11 25
end
durationcanvas 136942 classinstance_ref 128110 // :bank_assistant
  xyzwh 105 533 2010 11 40
end
durationcanvas 137070 classinstance_ref 131054 // :BankBoundry
  xyzwh 278 533 2010 11 25
end
durationcanvas 137326 classinstance_ref 130926 // :open_one_card_control
  xyzwh 439 544 2010 11 25
end
durationcanvas 137582 classinstance_ref 135278 // :one_card_account_db
  xyzwh 777 551 2010 11 25
end
durationcanvas 137838 classinstance_ref 135278 // :one_card_account_db
  xyzwh 777 618 2010 11 40
end
durationcanvas 137966 classinstance_ref 130926 // :open_one_card_control
  xyzwh 439 618 2010 11 25
end
durationcanvas 138222 classinstance_ref 130926 // :open_one_card_control
  xyzwh 439 727 2010 11 40
end
durationcanvas 138350 classinstance_ref 135278 // :one_card_account_db
  xyzwh 777 727 2010 11 25
end
durationcanvas 138606 classinstance_ref 130926 // :open_one_card_control
  xyzwh 439 812 2010 11 40
end
durationcanvas 138734 classinstance_ref 131054 // :BankBoundry
  xyzwh 278 812 2010 11 25
end
durationcanvas 138990 classinstance_ref 130926 // :open_one_card_control
  xyzwh 439 682 2010 11 40
end
durationcanvas 139118 classinstance_ref 131054 // :BankBoundry
  xyzwh 278 682 2010 11 25
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
msg 133870 synchronous
  from durationcanvas_ref 131310
  to durationcanvas_ref 133742
  yz 83 2015 msg operation_ref 142574 // "set_name()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 331 65
reflexivemsg 134126 synchronous
  to durationcanvas_ref 133998
  yz 86 2025 explicitmsg "check_if_valid"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 424 68
msg 134382 synchronous
  from durationcanvas_ref 133742
  to durationcanvas_ref 134254
  yz 113 2025 msg operation_ref 134638 // "set_name() : string"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 509 95
msg 134638 synchronous
  from durationcanvas_ref 132078
  to durationcanvas_ref 134510
  yz 200 2015 msg operation_ref 142702 // "set_idcard()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 329 182
reflexivemsg 134894 synchronous
  to durationcanvas_ref 134766
  yz 209 2025 explicitmsg "check_if_valid"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 424 191
msg 135150 synchronous
  from durationcanvas_ref 134510
  to durationcanvas_ref 135022
  yz 237 2030 msg operation_ref 134766 // "set_idcard() : string"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 507 219
msg 135534 synchronous
  from durationcanvas_ref 132718
  to durationcanvas_ref 135406
  yz 304 2015 msg operation_ref 143342 // "set_address()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 325 286
msg 135790 synchronous
  from durationcanvas_ref 135406
  to durationcanvas_ref 135662
  yz 315 2015 msg operation_ref 134894 // "set_address() : string"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 503 297
msg 136046 synchronous
  from durationcanvas_ref 133102
  to durationcanvas_ref 135918
  yz 386 2015 msg operation_ref 143470 // "set_phone_number()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 303 368
msg 136302 synchronous
  from durationcanvas_ref 135918
  to durationcanvas_ref 136174
  yz 395 2015 msg operation_ref 135022 // "set_phone_number() : string"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 481 377
msg 136558 synchronous
  from durationcanvas_ref 133486
  to durationcanvas_ref 136430
  yz 465 2015 msg operation_ref 143598 // "set_passwd()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 326 447
msg 136814 synchronous
  from durationcanvas_ref 136430
  to durationcanvas_ref 136686
  yz 476 2015 msg operation_ref 135150 // "set_passwd()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 504 458
msg 137198 synchronous
  from durationcanvas_ref 136942
  to durationcanvas_ref 137070
  yz 533 2015 explicitmsg "submit"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 176 515
msg 137454 synchronous
  from durationcanvas_ref 137070
  to durationcanvas_ref 137326
  yz 544 2015 msg operation_ref 143726 // "sumbit()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 339 526
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
  yz 727 2015 msg operation_ref 142830 // "create()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 590 709
msg 138862 return
  from durationcanvas_ref 138606
  to durationcanvas_ref 138734
  yz 812 2015 explicitmsg "success_of_not"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 319 794
msg 139246 return
  from durationcanvas_ref 138990
  to durationcanvas_ref 139118
  yz 682 2015 explicitmsg "exists"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 347 664
end
