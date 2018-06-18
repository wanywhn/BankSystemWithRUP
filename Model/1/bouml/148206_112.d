format 218

packagecanvas 128238 
  package_ref 128238 // Application
    xyzwh 343 134 2000 105 125
end
componentcanvas 129006 component_ref 128110 // Qt
  
  xyzwh 63 465 2000 243 83
end
componentcanvas 129262 component_ref 128238 // MySQL
  
  xyzwh 364 465 2000 243 83
end
packagecanvas 129646 
  package_ref 128366 // Presentation
    xyzwh 201 19 2006 119 125
end
packagecanvas 130158 
  package_ref 128110 // Presistence
    xyzwh 381 311 2000 113 125
end
simplerelationcanvas 130286 simplerelation_ref 142702
  from ref 129646 z 2007 to ref 129006
end
simplerelationcanvas 130414 simplerelation_ref 142830
  from ref 129646 z 2007 to ref 128238
end
simplerelationcanvas 130542 simplerelation_ref 142958
  from ref 128238 z 2001 to point 403 253
  line 128111 z 2001 to ref 130158
end
simplerelationcanvas 130670 simplerelation_ref 143086
  from ref 130158 z 2001 to ref 129262
end
simplerelationcanvas 130798 simplerelation_ref 143214
  from ref 130158 z 2001 to ref 129006
end
end
