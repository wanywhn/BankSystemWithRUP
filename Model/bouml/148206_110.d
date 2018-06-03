format 218

packagecanvas 128110 
  package_ref 128110 // Presentation
    xyzwh 160 37 2000 83 91
end
packagecanvas 128238 
  package_ref 128238 // Application
    xyzwh 403 116 2000 75 91
end
packagecanvas 128366 
  package_ref 128366 // Presistence
    xyzwh 405 277 2000 75 91
end
componentcanvas 129006 component_ref 128110 // Qt
  
  xyzwh 63 465 2000 165 63
end
componentcanvas 129262 component_ref 128238 // MySQL
  
  xyzwh 364 465 2000 165 63
end
simplerelationcanvas 128494 simplerelation_ref 142062
  from ref 128110 z 2001 to ref 128238
end
simplerelationcanvas 128622 simplerelation_ref 142190
  from ref 128238 z 2001 to ref 128366
end
simplerelationcanvas 129134 simplerelation_ref 142318
  from ref 128110 z 2001 to ref 129006
end
simplerelationcanvas 129390 simplerelation_ref 142446
  from ref 128366 z 2001 to ref 129262
end
simplerelationcanvas 129518 simplerelation_ref 142574
  from ref 128366 z 2001 to ref 129006
end
end
