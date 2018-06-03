format 218

classcanvas 128238 class_ref 128238 // one_card_account
  classdiagramsettings member_max_width 0 end
  xyz 210 4 2000
end
classcanvas 128622 class_ref 128366 // saving_subaccount
  classdiagramsettings member_max_width 0 end
  xyz 548 35 2000
end
classcanvas 128878 class_ref 128110 // kehu
  classdiagramsettings member_max_width 0 end
  xyz 66 166 3005
end
classcanvas 129134 class_ref 134894 // saving_info
  classdiagramsettings member_max_width 0 end
  xyz 574 203 2000
end
classcanvas 129390 class_ref 135022 // current_saving
  classdiagramsettings member_max_width 0 end
  xyz 271 406 2000
end
classcanvas 129646 class_ref 135150 // fixed_deposit
  classdiagramsettings member_max_width 0 end
  xyz 444 418 2000
end
classcanvas 130286 class_ref 141806 // interest_table
  classdiagramsettings member_max_width 0 end
  xyz 61 380 2000
end
relationcanvas 128750 relation_ref 128238 // <unidirectional association>
  from ref 128238 z 2001 stereotype "<<vector>>" xyz 412 135 3000 to ref 128622
  role_a_pos 470 80 3000 no_role_b
  multiplicity_a_pos 531 113 3000 multiplicity_b_pos 348 174 3000
end
relationcanvas 129006 relation_ref 128110 // <association>
  from ref 128878 z 3006 to ref 128238
  no_role_a no_role_b
  multiplicity_a_pos 192 201 3000 multiplicity_b_pos 116 211 3000
end
relationcanvas 129262 relation_ref 134766 // <directional composition>
  from ref 128622 z 2001 to ref 129134
  no_role_a no_role_b
  multiplicity_a_pos 603 178 3000 multiplicity_b_pos 603 154 3000
end
relationcanvas 129518 relation_ref 134894 // <directional aggregation>
  from ref 129134 z 2001 stereotype "<<vector>>" xyz 450 325 3000 to ref 129390
  role_a_pos 387 374 3000 no_role_b
  multiplicity_a_pos 387 407 3000 no_multiplicity_b
end
relationcanvas 129774 relation_ref 135022 // <directional aggregation>
  from ref 129134 z 2001 stereotype "<<vector>>" xyz 533 331 3000 to ref 129646
  role_a_pos 538 393 3000 no_role_b
  multiplicity_a_pos 512 393 3000 no_multiplicity_b
end
relationcanvas 130414 relation_ref 141678 // <directional aggregation>
  from ref 129134 z 2001 stereotype "<<vector>>" xyz 661 324 3000 to point 750 404
  line 130542 z 2001 to ref 129646
  role_a_pos 560 434 3000 no_role_b
  multiplicity_a_pos 560 467 3000 no_multiplicity_b
end
end
