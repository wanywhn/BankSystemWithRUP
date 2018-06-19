format 219

classcanvas 128110 class_ref 157166 // BankSystem
  classdiagramsettings member_max_width 0 end
  xyz 395 277 2000
end
fragment 128622 "one_card_control"
  xyzwh 60 28 2010 225 541
end
fragment 128750 "online_bank_control"
  xyzwh 368 2 2000 283 249
end
fragment 128878 "control_credit_card"
  xyzwh 304 383 2000 203 200
end
fragment 129006 "plan_ctrl"
  xyzwh 542 418 2000 135 180
end
fragment 129134 "modify_user"
  xyzwh 636 211 2000 191 170
end
classcanvas 130286 class_ref 148718 // one_card_control
  classdiagramsettings member_max_width 0 end
  xyz 63 58 2015
end
classcanvas 130542 class_ref 128239 // online_bank_control
  classdiagramsettings member_max_width 0 end
  xyz 502 10 2005
end
classcanvas 131310 class_ref 156526 // control_credit_card
  classdiagramsettings member_max_width 0 end
  xyz 319 428 2005
end
classcanvas 131566 class_ref 156142 // plan_ctrl
  classdiagramsettings member_max_width 0 end
  xyz 532 458 2005
end
classcanvas 131822 class_ref 156270 // modify_user
  classdiagramsettings member_max_width 0 end
  xyz 704 241 2005
end
fragment 132078 "bank_info_ctrl"
  xyzwh 674 405 2000 172 223
end
classcanvas 132206 class_ref 155630 // bank_info_ctrl
  classdiagramsettings member_max_width 0 end
  xyz 691 451 2005
end
relationcanvas 130414 relation_ref 155630 // <dependency>
  from ref 128110 z 2016 to ref 130286
  no_role_a no_role_b
  no_multiplicity_a no_multiplicity_b
end
relationcanvas 131182 relation_ref 155758 // <dependency>
  from ref 128110 z 2006 to ref 130542
  no_role_a no_role_b
  no_multiplicity_a no_multiplicity_b
end
relationcanvas 131438 relation_ref 155886 // <dependency>
  from ref 128110 z 2006 to ref 131310
  no_role_a no_role_b
  no_multiplicity_a no_multiplicity_b
end
relationcanvas 131694 relation_ref 156014 // <dependency>
  from ref 128110 z 2006 to ref 131566
  no_role_a no_role_b
  no_multiplicity_a no_multiplicity_b
end
relationcanvas 131950 relation_ref 156142 // <dependency>
  from ref 128110 z 2006 to ref 131822
  no_role_a no_role_b
  no_multiplicity_a no_multiplicity_b
end
relationcanvas 132334 relation_ref 156270 // <dependency>
  from ref 128110 z 2006 to ref 132206
  no_role_a no_role_b
  no_multiplicity_a no_multiplicity_b
end
end
