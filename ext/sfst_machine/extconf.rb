require 'mkmf'
CONFIG['CC'] = 'g++'
$CPPFLAGS='-Wall -O3 -Wall -Wcast-qual -Wconversion -DSGI__gnu_cxx -DREADLINE'
create_makefile "sfst_machine"
