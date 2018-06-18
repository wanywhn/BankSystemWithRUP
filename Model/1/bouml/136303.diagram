format 218

classinstance 128111 class_ref 128110 // kehu
  name ""   xyz 54 23 2000 life_line_z 2000
classinstance 128239 class_ref 128367 // online_bank
  name ""   xyz 664 11 2000 life_line_z 2000
classinstance 128367 class_ref 128495 // ;online_bank
  name ""   xyz 501 7 2000 life_line_z 2000
classinstance 128623 class_ref 128239 // online_bank_control
  name ""   xyz 310 15 2000 life_line_z 2000
classinstance 128751 class_ref 128623 // online_bank_boundary
  name ""   xyz 110 14 2000 life_line_z 2000
durationcanvas 128112 classinstance_ref 128623 // :online_bank_control
  xyzwh 396 373 2010 11 40
end
durationcanvas 128240 classinstance_ref 128239 // :online_bank
  xyzwh 719 373 2010 11 25
end
durationcanvas 128496 classinstance_ref 128239 // :online_bank
  xyzwh 719 420 2010 11 40
end
durationcanvas 128624 classinstance_ref 128623 // :online_bank_control
  xyzwh 396 420 2010 11 25
end
durationcanvas 128879 classinstance_ref 128111 // :kehu
  xyzwh 74 169 2010 11 40
end
durationcanvas 128880 classinstance_ref 128623 // :online_bank_control
  xyzwh 396 459 2010 11 40
end
durationcanvas 129007 classinstance_ref 128751 // :online_bank_boundary
  xyzwh 207 169 2010 11 25
end
durationcanvas 129008 classinstance_ref 128751 // :online_bank_boundary
  xyzwh 207 459 2010 11 25
end
durationcanvas 129263 classinstance_ref 128751 // :online_bank_boundary
  xyzwh 207 230 2010 11 40
end
durationcanvas 129391 classinstance_ref 128623 // :online_bank_control
  xyzwh 396 230 2010 11 25
end
durationcanvas 129647 classinstance_ref 128623 // :online_bank_control
  xyzwh 396 270 2010 11 40
end
durationcanvas 129775 classinstance_ref 128239 // :online_bank
  xyzwh 719 270 2010 11 25
end
durationcanvas 130031 classinstance_ref 128239 // :online_bank
  xyzwh 719 322 2010 11 40
end
durationcanvas 130159 classinstance_ref 128623 // :online_bank_control
  xyzwh 396 322 2010 11 25
end
msg 128368 synchronous
  from durationcanvas_ref 128112
  to durationcanvas_ref 128240
  yz 373 2015 explicitmsg "set_loss()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 520 350
msg 128752 return
  from durationcanvas_ref 128496
  to durationcanvas_ref 128624
  yz 420 2015 unspecifiedmsg
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
msg 129135 synchronous
  from durationcanvas_ref 128879
  to durationcanvas_ref 129007
  yz 169 2015 explicitmsg "loss report"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 99 146
msg 129136 synchronous
  from durationcanvas_ref 128880
  to durationcanvas_ref 129008
  yz 459 2015 explicitmsg "loss_success"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 249 436
msg 129519 synchronous
  from durationcanvas_ref 129263
  to durationcanvas_ref 129391
  yz 230 2015 explicitmsg "loss_report()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 245 205
msg 129903 synchronous
  from durationcanvas_ref 129647
  to durationcanvas_ref 129775
  yz 270 2015 explicitmsg "check_if_lose()"
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
  label_xy 489 245
msg 130287 return
  from durationcanvas_ref 130031
  to durationcanvas_ref 130159
  yz 322 2015 unspecifiedmsg
  show_full_operations_definition default show_class_of_operation default drawing_language default show_context_mode default
end
