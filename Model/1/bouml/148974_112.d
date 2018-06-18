format 218

classcanvas 128238 class_ref 128238 // one_card_account
  classdiagramsettings member_max_width 0 end
  xyz 55 229 2000
end
classcanvas 128366 class_ref 148974 // DB
  classdiagramsettings member_max_width 0 end
  xyz 405 18 2000
end
classcanvas 128494 class_ref 149102 // one_card_account_db
  classdiagramsettings member_max_width 0 end
  xyz 597 30 2000
end
classcanvas 128750 class_ref 134894 // saving_info
  classdiagramsettings member_max_width 0 end
  xyz 595 179 2000
end
classcanvas 128878 class_ref 135022 // current_saving
  classdiagramsettings member_max_width 0 end
  xyz 742 328 3005
end
classcanvas 129134 class_ref 135278 // dinghuo_liangbian
  classdiagramsettings member_max_width 0 end
  xyz 673 478 2006
end
classcanvas 129390 class_ref 141806 // interest_table
  classdiagramsettings member_max_width 0 end
  xyz 120 43 2000
end
classcanvas 129518 class_ref 135150 // fixed_deposit
  classdiagramsettings member_max_width 0 end
  xyz 384 463 2006
end
classcanvas 129902 class_ref 128366 // saving_subaccount
  classdiagramsettings member_max_width 0 end
  xyz 307 169 3011
end
relationcanvas 128622 relation_ref 148206 // <generalisation>
  from ref 128494 z 2001 to ref 128366
  no_role_a no_role_b
  no_multiplicity_a no_multiplicity_b
end
relationcanvas 129006 relation_ref 134894 // <directional aggregation>
  from ref 128750 z 3006 stereotype "<<vector>>" xyz 669 281 3006 to ref 128878
  role_a_pos 763 297 3000 no_role_b
  multiplicity_a_pos 735 297 3000 no_multiplicity_b
end
relationcanvas 129262 relation_ref 135150 // <directional aggregation>
  from ref 128750 z 2007 stereotype "<<vector>>" xyz 648.5 357 2007 to ref 129134
  no_role_a no_role_b
  multiplicity_a_pos 728 447 3000 no_multiplicity_b
end
relationcanvas 129646 relation_ref 135022 // <directional aggregation>
  from ref 128750 z 2007 stereotype "<<vector>>" xyz 510 349 2007 to ref 129518
  role_a_pos 515 432 3000 no_role_b
  multiplicity_a_pos 487 432 3000 no_multiplicity_b
end
relationcanvas 129774 relation_ref 141678 // <directional aggregation>
  from ref 128750 z 2007 stereotype "<<vector>>" xyz 510 349 2007 to ref 129518
  role_a_pos 515 432 3000 no_role_b
  multiplicity_a_pos 487 432 3000 no_multiplicity_b
end
relationcanvas 130030 relation_ref 134766 // <directional composition>
  from ref 129902 z 3012 to ref 128750
  no_role_a no_role_b
  multiplicity_a_pos 573 236 3000 multiplicity_b_pos 509 264 3000
end
relationcanvas 130158 relation_ref 128238 // <unidirectional association>
  from ref 128238 z 3012 stereotype "<<vector>>" xyz 242 98 3012 to ref 129902
  role_a_pos 305 384 3000 no_role_b
  multiplicity_a_pos 277 384 3000 multiplicity_b_pos 251 388 3000
end
end
