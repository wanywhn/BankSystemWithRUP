format 218

classinstance 128110 class_ref 141934 // bank_assistant
  name ""   xyz 160 4 2000 life_line_z 2000
classinstance 128238 class_ref 128238 // one_card_account
  name ""   xyz 352 4 2000 life_line_z 2000
classinstance 128366 class_ref 128366 // saving_subaccount
  name ""   xyz 511 4 2000 life_line_z 2000
durationcanvas 128494 classinstance_ref 128110 // :bank_assistant
  xyzwh 202 98 2010 11 40
end
durationcanvas 128622 classinstance_ref 128238 // :one_card_account
  xyzwh 404 98 2010 11 25
end
durationcanvas 128878 classinstance_ref 128238 // :one_card_account
  xyzwh 404 159 2010 11 40
end
durationcanvas 129006 classinstance_ref 128110 // :bank_assistant
  xyzwh 202 159 2010 11 25
end
durationcanvas 129262 classinstance_ref 128110 // :bank_assistant
  xyzwh 202 233 2010 11 40
end
durationcanvas 129390 classinstance_ref 128366 // :saving_subaccount
  xyzwh 568 233 2010 11 25
end
durationcanvas 129646 classinstance_ref 128110 // :bank_assistant
  xyzwh 202 318 2010 11 40
end
durationcanvas 129774 classinstance_ref 128366 // :saving_subaccount
  xyzwh 568 318 2010 11 25
end
durationcanvas 130030 classinstance_ref 128110 // :bank_assistant
  xyzwh 202 391 2010 11 40
end
durationcanvas 130158 classinstance_ref 128366 // :saving_subaccount
  xyzwh 568 391 2010 11 25
end
msg 128750 synchronous
  from durationcanvas_ref 128494
  to durationcanvas_ref 128622
  yz 98 2015 msg operation_ref 135278 // "get_sub_account()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 254 80
msg 129134 return
  from durationcanvas_ref 128878
  to durationcanvas_ref 129006
  yz 159 2015 explicitmsg "sub_account"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 271 141
msg 129518 synchronous
  from durationcanvas_ref 129262
  to durationcanvas_ref 129390
  yz 233 2015 msg operation_ref 135406 // "add_huoqi()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 355 215
msg 129902 synchronous
  from durationcanvas_ref 129646
  to durationcanvas_ref 129774
  yz 318 2015 msg operation_ref 135534 // "add_dingqi()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 353 300
msg 130286 synchronous
  from durationcanvas_ref 130030
  to durationcanvas_ref 130158
  yz 391 2015 msg operation_ref 135662 // "add_dinghuo()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 348 373
end
