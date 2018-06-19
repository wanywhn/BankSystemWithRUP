format 219

deploymentnodecanvas 128238 deploymentnode_ref 128110 // SystemServer
  xyzwh 291 230 2000 129 42
end
deploymentnodecanvas 128366 deploymentnode_ref 128238 // Client
  xyzwh 144 405 2000 68 42
end
deploymentnodecanvas 128494 deploymentnode_ref 128366 // CreditCardEQU
  xyzwh 430 415 2000 139 42
end
deploymentnodecanvas 128622 deploymentnode_ref 128494 // DataBase
  xyzwh 297 72 2000 95 42
end
line 128750 ----
  from ref 128238 z 2001 label "Lan" max_width 255 xyz 334 146 3000 to ref 128622
line 128878 ----
  from ref 128238 z 2001 label "Internet" max_width 255 xyz 232 312 3000 to ref 128366
line 129006 ----
  from ref 128238 z 2001 label "Internet" max_width 255 xyz 396 317 3000 to ref 128494
end
