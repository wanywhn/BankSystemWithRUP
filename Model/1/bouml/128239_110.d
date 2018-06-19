format 219

classcanvas 128111 class_ref 128110 // kehu
  simpleclassdiagramsettings end
  xyz 67 216 2000
end
usecasecanvas 128239 usecase_ref 128111 // open_online_bank
  xyzwh 59 13 3005 64 32 label_xy 19 44
end
usecasecanvas 128495 usecase_ref 128239 // inquire_onecard_information
  xyzwh 338 26 3005 64 32 label_xy 255 58
end
usecasecanvas 129391 usecase_ref 128367 // inquire_allcards_information   
  xyzwh 324 377 3010 64 32 label_xy 236 409
end
usecasecanvas 129519 usecase_ref 128495 // transfer_money
  xyzwh 339 142 3005 64 32 label_xy 309 174
end
usecasecanvas 129647 usecase_ref 128623 // change_password
  xyzwh 336 88 3005 64 32 label_xy 299 120
end
usecasecanvas 129775 usecase_ref 128751 // analyse_economy
  xyzwh 325 207 3005 64 32 label_xy 295 242
end
usecasecanvas 129903 usecase_ref 128879 // report _loss
  xyzwh 310 279 3005 64 32 label_xy 301 320
end
usecasecanvas 130031 usecase_ref 129007 // login_
  xyzwh 721 155 3005 64 32 label_xy 729 187
end
line 128367 ---> decenter_begin 164
  from ref 128111 z 3006 to ref 128239
line 130159 --->
  from ref 128111 z 3006 to ref 129903
line 130287 --->
  from ref 128111 z 3006 to ref 129519
simplerelationcanvas 130415 simplerelation_ref 128111
  from ref 129391 z 3011 stereotype "<<include>>" xyz 503 280.5 3000 to ref 130031
end
simplerelationcanvas 130799 simplerelation_ref 128239
  from ref 128495 z 3006 stereotype "<<include>>" xyz 514 105 3000 to ref 130031
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
  from ref 129647 z 3006 stereotype "<<include>>" xyz 513.5 135.5 3000 to ref 130031
end
simplerelationcanvas 131823 simplerelation_ref 128495
  from ref 129903 z 3006 stereotype "<<include>>" xyz 500.5 230 3000 to ref 130031
end
simplerelationcanvas 131951 simplerelation_ref 128623
  from ref 129775 z 3006 stereotype "<<include>>" xyz 507.5 194 3000 to ref 130031
end
simplerelationcanvas 132079 simplerelation_ref 128751
  from ref 129519 z 3006 stereotype "<<include>>" xyz 515 162.5 3000 to ref 130031
end
end
