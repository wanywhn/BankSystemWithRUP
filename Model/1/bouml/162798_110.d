format 219

usecasecanvas 128366 usecase_ref 142318 // modify_config
  xyzwh 272 46 3005 64 32 label_xy 249 78
end
usecasecanvas 128494 usecase_ref 142446 // add_sys_user
  xyzwh 416 123 3005 64 32 label_xy 396 155
end
usecasecanvas 128622 usecase_ref 142574 // delete_sys_user
  xyzwh 604 111 3005 64 32 label_xy 575 143
end
usecasecanvas 128750 usecase_ref 142702 // add_modify_plan
  xyzwh 377 298 3005 64 32 label_xy 342 330
end
usecasecanvas 128878 usecase_ref 142830 // cancel_modify_plan
  xyzwh 617 309 3005 64 32 label_xy 572 341
end
classcanvas 129902 class_ref 141934 // bank_assistant
  simpleclassdiagramsettings end
  xyz 179 234 2000
end
simplerelationcanvas 129518 simplerelation_ref 149742
  from ref 128494 z 3006 stereotype "<<extend>>" xyz 496.5 131 3000 to ref 128622
end
simplerelationcanvas 129774 simplerelation_ref 149870
  from ref 128750 z 3006 stereotype "<<extend>>" xyz 484 317 3000 to ref 128878
end
line 130030 --->
  from ref 129902 z 3006 to ref 128366
line 130158 --->
  from ref 129902 z 3006 to ref 128494
line 130286 --->
  from ref 129902 z 3006 to ref 128750
end
