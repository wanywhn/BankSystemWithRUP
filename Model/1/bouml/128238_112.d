format 218

classcanvas 128238 class_ref 128238 // one_card_account
  classdiagramsettings member_max_width 0 end
  xyz 219 -94 2000
end
classcanvas 128622 class_ref 128366 // saving_subaccount
  classdiagramsettings member_max_width 0 end
  xyz 554 49 2000
end
classcanvas 128878 class_ref 128110 // kehu
  classdiagramsettings member_max_width 0 end
  xyz 66 166 3005
end
classcanvas 129134 class_ref 134894 // saving_info
  classdiagramsettings member_max_width 0 end
  xyz 545 338 2000
end
classcanvas 129390 class_ref 135022 // current_saving
  classdiagramsettings member_max_width 0 end
  xyz 289 562 2000
end
classcanvas 129646 class_ref 135150 // fixed_deposit
  classdiagramsettings member_max_width 0 end
  xyz 535 483 2000
end
classcanvas 130286 class_ref 141806 // interest_table
  classdiagramsettings member_max_width 0 end
  xyz 46 436 2000
end
relationcanvas 128750 relation_ref 128238 // <unidirectional association>
  from ref 128238 z 2001 stereotype "<<vector>>" xyz 431.5 114 3000 to ref 128622
  role_a_pos 444 143 3000 no_role_b
  multiplicity_a_pos 535 184 3000 multiplicity_b_pos 455 193 3000
end
relationcanvas 129006 relation_ref 128110 // <association>
  from ref 128878 z 3006 to ref 128238
  no_role_a no_role_b
  multiplicity_a_pos 197 210 3000 multiplicity_b_pos 130 217 3000
end
relationcanvas 129262 relation_ref 134766 // <directional composition>
  from ref 128622 z 2001 to ref 129134
  no_role_a no_role_b
  multiplicity_a_pos 589 307 3000 multiplicity_b_pos 598 294 3000
end
relationcanvas 129518 relation_ref 134894 // <directional aggregation>
  from ref 129134 z 2001 stereotype "<<vector>>" xyz 435.5 480 3000 to ref 129390
  role_a_pos 436 531 3000 no_role_b
  multiplicity_a_pos 408 531 3000 no_multiplicity_b
end
relationcanvas 129774 relation_ref 135022 // <directional aggregation>
  from ref 129134 z 2001 stereotype "<<vector>>" xyz 550 439 3000 to ref 129646
  role_a_pos 613 452 3000 no_role_b
  multiplicity_a_pos 585 452 3000 no_multiplicity_b
end
relationcanvas 130414 relation_ref 141678 // <directional aggregation>
  from ref 129134 z 2001 stereotype "<<vector>>" xyz 666.5 390 3000 to point 750 404
  line 130542 z 2001 to ref 129646
  role_a_pos 694 458 3000 no_role_b
  multiplicity_a_pos 666 458 3000 no_multiplicity_b
end
end
