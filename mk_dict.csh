#!/bin/tcsh

make clean
foreach file ( *_LinkDef.h)
 set cpp_dict = `echo $file | sed "s/_LinkDef.h/_Dict.cc/"`
 set h_file = `echo $file | sed "s/_LinkDef//"`
 #echo $file | sed "s/_LinkDef//" 
 #echo $file $cpp_dict $h_file

 ###root v5
 #rootcint -f ${cpp_dict} -c ${h_file} ${file}

 ###root v6
 echo "rootcling -f ${cpp_dict} ${h_file} ${file}"
 rootcling -f ${cpp_dict} ${h_file} ${file}

end

###root v6
cp *.pcm bin/
