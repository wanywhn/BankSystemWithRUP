format 219

classcanvas 128110 class_ref 128110 // kehu
  simpleclassdiagramsettings end
  xyz 89.977 235.488 2000
end
usecasecanvas 128238 usecase_ref 128110 // open_one_card_system
  xyzwh 51 54 3005 77 31 label_xy 33 97
end
usecasecanvas 128494 usecase_ref 134638 // open_online_bank_system
  xyzwh 645 299 3005 64 32 label_xy 599 331
end
usecasecanvas 128622 usecase_ref 134766 // close_account
  xyzwh 388 347 3005 64 32 label_xy 380 380
end
usecasecanvas 128750 usecase_ref 134894 // change_passwd
  xyzwh 433 147 3005 64 32 label_xy 420 179
end
usecasecanvas 128878 usecase_ref 135022 // deposit
  xyzwh 239 41 0 64 32 label_xy 249 74
end
usecasecanvas 129006 usecase_ref 135150 // transfer_account
  xyzwh 465 214 3005 64 32 label_xy 450 253
end
usecasecanvas 129134 usecase_ref 135278 // withdrawal
  xyzwh 314 96 3005 64 32 label_xy 312 129
end
usecasecanvas 129262 usecase_ref 135406 // loss_report
  xyzwh 369 472 3005 87 33 label_xy 368 504
end
usecasecanvas 129390 usecase_ref 135534 // login
  xyzwh 745 74 3005 64 32 label_xy 763 105
end
usecasecanvas 129518 usecase_ref 135662 // cancel_loss_report
  xyzwh 671 500 3005 64 32 label_xy 649 533
end
usecasecanvas 129646 usecase_ref 135790 // reapply_one_card
  xyzwh 655 393 3005 64 32 label_xy 640 443
end
line 128366 --->
  from ref 128110 z 3006 to ref 128238
line 130030 --->
  from ref 128110 z 3006 to ref 128494
line 130158 --->
  from ref 128110 z 3006 to ref 128622
line 130286 --->
  from ref 128110 z 3006 to ref 129262
line 130414 --->
  from ref 128110 z 3006 to ref 129134
line 130542 --->
  from ref 128110 z 3006 to ref 129006
line 130670 --->
  from ref 128110 z 3006 to ref 128878
line 130798 --->
  from ref 128110 z 3006 to ref 128750
simplerelationcanvas 130926 simplerelation_ref 128110
  from ref 128878 z 3006 stereotype "<<include>>" xyz 487 70 3000 to ref 129390
end
simplerelationcanvas 131054 simplerelation_ref 128238
  from ref 129262 z 3006 stereotype "<<extend>>" xyz 521 445 3000 to ref 129646
end
simplerelationcanvas 131182 simplerelation_ref 128366
  from ref 129262 z 3006 stereotype "<<extend>>" xyz 529 502 3000 to ref 129518
end
simplerelationcanvas 131438 simplerelation_ref 128622
  from ref 128750 z 3006 stereotype "<<include>>" xyz 584 124 3000 to ref 129390
end
simplerelationcanvas 131566 simplerelation_ref 128750
  from ref 129006 z 3006 stereotype "<<include>>" xyz 599 157 3000 to ref 129390
end
simplerelationcanvas 131694 simplerelation_ref 128878
  decenter_begin 781
  from ref 128494 z 3006 stereotype "<<include>>" xyz 695 201 3000 to ref 129390
end
simplerelationcanvas 131822 simplerelation_ref 129006
  from ref 128622 z 3006 stereotype "<<include>>" xyz 560 225 3000 to ref 129390
end
simplerelationcanvas 132206 simplerelation_ref 135534
  from ref 129134 z 3006 stereotype "<<include>>" xyz 525 99 3000 to ref 129390
end
end
