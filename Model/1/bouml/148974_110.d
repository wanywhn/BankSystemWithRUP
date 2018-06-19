format 219

classcanvas 128238 class_ref 128238 // one_card_account
  classdiagramsettings member_max_width 0 end
  xyz 49.2341 209.988 2000
end
classcanvas 128366 class_ref 148974 // DB
  classdiagramsettings member_max_width 0 end
  xyz 405.453 18.8651 2000
end
classcanvas 128494 class_ref 149102 // one_card_account_db
  classdiagramsettings member_max_width 0 end
  xyz 597.718 30.2833 2000
end
classcanvas 128750 class_ref 134894 // saving_info
  classdiagramsettings member_max_width 0 end
  xyz 575.934 183.936 2000
end
classcanvas 128878 class_ref 135022 // current_saving
  classdiagramsettings member_max_width 0 end
  xyz 737.249 298.712 3005
end
classcanvas 129134 class_ref 135278 // dinghuo_liangbian
  classdiagramsettings member_max_width 0 end
  xyz 673.212 478.196 2006
end
classcanvas 129390 class_ref 141806 // interest_table
  classdiagramsettings member_max_width 0 end
  xyz 89.4419 20.7405 2000
end
classcanvas 129518 class_ref 135150 // fixed_deposit
  classdiagramsettings member_max_width 0 end
  xyz 354.414 438.653 2006
end
classcanvas 129902 class_ref 128366 // saving_subaccount
  classdiagramsettings member_max_width 0 end
  xyz 307.084 169.053 3011
end
classcanvas 130414 class_ref 155758 // sys_account
  classdiagramsettings member_max_width 0 end
  xyz 684.562 579.064 2000
end
classcanvas 130542 class_ref 156014 // modify_plan
  classdiagramsettings member_max_width 0 end
  xyz 523.779 555.136 2005
end
classcanvas 130670 class_ref 156654 // entity_credit_card
  classdiagramsettings member_max_width 0 end
  xyz 257.586 640.89 2010
end
classcanvas 130798 class_ref 156782 // entity_consume_log
  classdiagramsettings member_max_width 0 end
  xyz 690.688 669.933 2000
end
relationcanvas 128622 relation_ref 148206 // <generalisation>
  from ref 128494 z 2001 to ref 128366
  no_role_a no_role_b
  no_multiplicity_a no_multiplicity_b
end
relationcanvas 129006 relation_ref 134894 // <directional aggregation>
  from ref 128750 z 3006 stereotype "<<vector>>" xyz 657 270.5 3006 to ref 128878
  role_a_pos 669 276 3000 no_role_b
  multiplicity_a_pos 718 321 3000 no_multiplicity_b
end
relationcanvas 129262 relation_ref 135150 // <directional aggregation>
  from ref 128750 z 2007 stereotype "<<vector>>" xyz 638.5 359 2007 to ref 129134
  no_role_a no_role_b
  multiplicity_a_pos 713 444 3000 no_multiplicity_b
end
relationcanvas 129646 relation_ref 135022 // <directional aggregation>
  from ref 128750 z 2007 stereotype "<<vector>>" xyz 488.5 338.5 2007 to ref 129518
  role_a_pos 490 404 3000 no_role_b
  multiplicity_a_pos 462 404 3000 no_multiplicity_b
end
relationcanvas 129774 relation_ref 141678 // <directional aggregation>
  from ref 128750 z 2007 stereotype "<<vector>>" xyz 488.5 338.5 2007 to ref 129518
  role_a_pos 490 404 3000 no_role_b
  multiplicity_a_pos 462 404 3000 no_multiplicity_b
end
relationcanvas 130030 relation_ref 134766 // <directional composition>
  from ref 129902 z 3012 to ref 128750
  no_role_a no_role_b
  multiplicity_a_pos 555 237 3000 multiplicity_b_pos 477 271 3000
end
relationcanvas 130158 relation_ref 128238 // <unidirectional association>
  from ref 128238 z 3012 stereotype "<<vector>>" xyz 239 90 3012 to ref 129902
  role_a_pos 207 318 3000 no_role_b
  multiplicity_a_pos 288 363 3000 multiplicity_b_pos 261 413 3000
end
relationcanvas 130926 relation_ref 155502 // <association>
  from ref 130414 z 2006 to ref 130542
  no_role_a no_role_b
  no_multiplicity_a no_multiplicity_b
end
end