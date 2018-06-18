format 218

classcanvas 128111 class_ref 128110 // kehu
  simpleclassdiagramsettings end
  xyz 67 216 2000
end
usecasecanvas 128239 usecase_ref 128111 // open_one_online_bank
  xyzwh 59 13 3005 64 32 label_xy 0 45
end
usecasecanvas 128495 usecase_ref 128239 // inquire_onecard_information
  xyzwh 350 32 3005 64 32 label_xy 267 64
end
usecasecanvas 129391 usecase_ref 128367 // inquire_allcards_information   
  xyzwh 309 375 3010 64 32 label_xy 221 407
end
usecasecanvas 129519 usecase_ref 128495 // transfer_money
  xyzwh 343 137 3005 64 32 label_xy 313 169
end
usecasecanvas 129647 usecase_ref 128623 // change_password
  xyzwh 345 88 3005 64 32 label_xy 308 120
end
usecasecanvas 129775 usecase_ref 128751 // analyse_economy
  xyzwh 318 200 3005 64 32 label_xy 288 235
end
usecasecanvas 129903 usecase_ref 128879 // report _loss
  xyzwh 308 270 3005 64 32 label_xy 294 302
end
usecasecanvas 130031 usecase_ref 129007 // login_
  xyzwh 747 39 3005 64 32 label_xy 755 71
end
line 128367 ---> decenter_begin 164
  from ref 128111 z 3006 to ref 128239
line 130159 --->
  from ref 128111 z 3006 to ref 129903
line 130287 --->
  from ref 128111 z 3006 to ref 129519
simplerelationcanvas 130415 simplerelation_ref 128111
  from ref 129391 z 3011 stereotype "<<include>>" xyz 509 222 3000 to ref 130031
end
simplerelationcanvas 130799 simplerelation_ref 128239
  from ref 128495 z 3006 stereotype "<<include>>" xyz 533 50 3000 to ref 130031
end
line 131183 --->
  from ref 128111 z 3006 to ref 128495
line 131311 --->
  from ref 128111 z 3006 to ref 129775
line 131439 --->
  from ref 128111 z 3006 to ref 129647
line 131567 --->
  from ref 128111 z 3011 to ref 129391
simplerelationcanvas 131695 simplerelation_ref 128367
  from ref 129647 z 3006 stereotype "<<include>>" xyz 531 76 3000 to ref 130031
end
simplerelationcanvas 131823 simplerelation_ref 128495
  from ref 129903 z 3006 stereotype "<<include>>" xyz 510 168 3000 to ref 130031
end
simplerelationcanvas 131951 simplerelation_ref 128623
  from ref 129775 z 3006 stereotype "<<include>>" xyz 517 132 3000 to ref 130031
end
simplerelationcanvas 132079 simplerelation_ref 128751
  from ref 129519 z 3006 stereotype "<<include>>" xyz 530 101 3000 to ref 130031
end
end
