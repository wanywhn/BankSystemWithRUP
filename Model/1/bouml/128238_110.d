format 219

classcanvas 128238 class_ref 128238 // one_card_account
  classdiagramsettings member_max_width 0 end
  xyz 241 32 2000
end
classcanvas 128622 class_ref 128366 // saving_subaccount
  classdiagramsettings member_max_width 0 end
  xyz 616 14 2000
end
classcanvas 128878 class_ref 128110 // kehu
  classdiagramsettings member_max_width 0 end
  xyz 66 166 3005
end
classcanvas 129134 class_ref 134894 // saving_info
  classdiagramsettings member_max_width 0 end
  xyz 611 317 2000
end
classcanvas 129390 class_ref 135022 // current_saving
  classdiagramsettings member_max_width 0 end
  xyz 467 501 2000
end
classcanvas 129646 class_ref 135150 // fixed_deposit
  classdiagramsettings member_max_width 0 end
  xyz 630 522 2000
end
classcanvas 130286 class_ref 141806 // interest_table
  classdiagramsettings member_max_width 0 end
  xyz 668 697 2000
end
classcanvas 130926 class_ref 156654 // entity_credit_card
  classdiagramsettings member_max_width 0 end
  xyz 0 488 2005
end
classcanvas 131182 class_ref 156782 // entity_consume_log
  classdiagramsettings member_max_width 0 end
  xyz 280 679 2000
end
relationcanvas 128750 relation_ref 128238 // <unidirectional association>
  from ref 128238 z 2001 stereotype "<<vector>>" xyz 473.5 152 3000 to ref 128622
  role_a_pos 516 138 3000 no_role_b
  multiplicity_a_pos 597 183 3000 multiplicity_b_pos 453 277 3000
end
relationcanvas 129006 relation_ref 128110 // <association>
  from ref 128878 z 3006 to ref 128238
  no_role_a no_role_b
  multiplicity_a_pos 221 294 3000 multiplicity_b_pos 122 235 3000
end
relationcanvas 129262 relation_ref 134766 // <directional composition>
  from ref 128622 z 2001 to ref 129134
  no_role_a no_role_b
  multiplicity_a_pos 647 283 3000 multiplicity_b_pos 653 268 3000
end
relationcanvas 129518 relation_ref 134894 // <directional aggregation>
  from ref 129134 z 2001 stereotype "<<vector>>" xyz 554 437.5 3000 to ref 129390
  role_a_pos 580 467 3000 no_role_b
  multiplicity_a_pos 552 467 3000 no_multiplicity_b
end
relationcanvas 129774 relation_ref 135022 // <directional aggregation>
  decenter_begin 424
  from ref 129134 z 2001 stereotype "<<vector>>" xyz 618.5 448 3000 to ref 129646
  role_a_pos 686 488 3000 no_role_b
  multiplicity_a_pos 658 488 3000 no_multiplicity_b
end
relationcanvas 130414 relation_ref 141678 // <directional aggregation>
  from ref 129134 z 2001 stereotype "<<vector>>" xyz 688 401.5 3000 to point 750 429
  line 130542 z 2001 to point 768 434
  line 130670 z 2001 to point 742 448
  line 130798 z 2001 to ref 129646
  role_a_pos 734 488 3000 no_role_b
  multiplicity_a_pos 706 488 3000 no_multiplicity_b
end
relationcanvas 131054 relation_ref 154734 // <association>
  decenter_end 501
  from ref 128878 z 3006 to ref 130926
  no_role_a no_role_b
  multiplicity_a_pos 74 454 3000 multiplicity_b_pos 70 262 3000
end
relationcanvas 131310 relation_ref 154862 // <association>
  from ref 128878 z 3006 to ref 131182
  no_role_a no_role_b
  multiplicity_a_pos 303 645 3000 multiplicity_b_pos 97 262 3000
end
end
