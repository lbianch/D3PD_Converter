This is used to create the "DictOut.cxx" file via rootcint.  From command line

    rootcint -f DictOut.cxx -I../include headers.h Linkdef.h

From the Makefile, this is the $(DICT) target.  The resulting DictOut.cxx file
should be compiled and linked into the target library.  A precompiled module,
"DictOut_rdict.pcm" is also created in this directory and needs to be available
from the ${LD_LIBRARY_PATH} environmental variable, so a link from ../lib is
also created by the Makefile.