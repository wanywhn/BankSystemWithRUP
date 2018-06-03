format 218

classinstance 128110 class_ref 141934 // bank_assistant
  name ""   xyz 105 4 2000 life_line_z 2000
classinstance 128238 class_ref 128238 // one_card_account
  name ""   xyz 307 4 2000 life_line_z 2000
classinstance 129134 class_ref 128366 // saving_subaccount
  name ""   xyz 524 4 2000 life_line_z 2000
durationcanvas 128366 classinstance_ref 128110 // :bank_assistant
  xyzwh 147 82 2010 11 40
end
durationcanvas 128494 classinstance_ref 128238 // :one_card_account
  xyzwh 359 82 2010 11 25
end
durationcanvas 128750 classinstance_ref 128238 // :one_card_account
  xyzwh 359 153 2010 11 40
end
durationcanvas 128878 classinstance_ref 128110 // :bank_assistant
  xyzwh 147 153 2010 11 25
end
durationcanvas 129262 classinstance_ref 128110 // :bank_assistant
  xyzwh 147 217 2010 11 41
end
durationcanvas 129390 classinstance_ref 129134 // :saving_subaccount
  xyzwh 581 217 2010 11 26
end
msg 128622 synchronous
  from durationcanvas_ref 128366
  to durationcanvas_ref 128494
  yz 82 2015 msg operation_ref 135278 // "get_sub_account()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 204 64
msg 129006 return
  from durationcanvas_ref 128750
  to durationcanvas_ref 128878
  yz 153 2015 explicitmsg "sub_account"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 221 135
msg 129518 synchronous
  from durationcanvas_ref 129262
  to durationcanvas_ref 129390
  yz 217 2015 unspecifiedmsg
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
end
