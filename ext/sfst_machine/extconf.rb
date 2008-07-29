require 'mkmf'
CONFIG['CC'] = 'g++'
$CFLAGS='-Wall -O3 -Wall -Wcast-qual -Wconversion -DSGIext -DREADLINE'
create_makefile "sfst_machine"
