format 219

classcanvas 128110 class_ref 141934 // bank_assistant
  classdiagramsettings member_max_width 0 end
  xyz 161 161 2000
end
classcanvas 128238 class_ref 155758 // sys_account
  classdiagramsettings member_max_width 0 end
  xyz 371 103 2000
end
classcanvas 128494 class_ref 156014 // modify_plan
  classdiagramsettings member_max_width 0 end
  xyz 543 222 2000
end
relationcanvas 128366 relation_ref 154990 // <association>
  from ref 128110 z 2001 to ref 128238
  no_role_a no_role_b
  multiplicity_a_pos 351 160 3000 multiplicity_b_pos 299 188 3000
end
relationcanvas 128622 relation_ref 155502 // <association>
  from ref 128238 z 2001 to ref 128494
  no_role_a no_role_b
  no_multiplicity_a no_multiplicity_b
end
end
