#
# Top driver script for scons to build a Mu2e base release or satellite release.
#
import os, re, string, sys

# Functions that do small tasks and build lists
from sconstruct_helper import *
# handles how the input files are collected and the output files are named
from mu2e_helper import *

# this will contain global config info about the build
mu2eOpts = {}

# add a mu2e debug print option like "--mu2ePrint=5"
AddOption('--mu2ePrint', dest='mu2ePrint', 
          type='int',nargs=1,default=1,
          help='mu2e print level (0-10) default=1')
mu2ePrint = GetOption("mu2ePrint")

mu2eOpts["mu2ePrint"] = mu2ePrint

# Check that some important environment variables have been set; 
# result is a dictionary of the options
moreOpts = mu2eEnvironment()
mu2eOpts.update(moreOpts)

if mu2ePrint > 1:
    print "mu2eOpts:"
    print mu2eOpts


if mu2ePrint > 5:
    print "building Evironment:"
    print "\nCPPPATH = ",cppPath(mu2eOpts)
    print "\nLIBPATH = ",libPath(mu2eOpts)
    print "\nENV = ",exportedOSEnvironment()
    print "\nFORTRAN = 'gfortran'"
    print "\nBABARLIBS = ", BaBarLibs()
    print "\nmerge Flags =",mergeFlags(mu2eOpts)

# this the scons object which contains the methods to build code
env = Environment( CPPPATH = cppPath(mu2eOpts),   # $ART_INC ...
                   LIBPATH = libPath(mu2eOpts),   # /lib, $ART_LIB ...
                   ENV = exportedOSEnvironment(), # LD_LIBRARY_PATH, ROOTSYS, ...
                   FORTRAN = 'gfortran',
                   BABARLIBS = BaBarLibs()
                 )

# Define and register the rule for building dictionaries.
# sources are classes.h, classes_def.xml, 
# targets are dict.cpp, .rootmap and .pcm
# LIBTEXT is the library for the dict - not a target, only text for names
genreflex = Builder(action="genreflex ${SOURCES[0]} -s ${SOURCES[1]} $_CPPINCFLAGS -l $LIBTEXT -o ${TARGETS[0]} --fail_on_warnings --rootmap-lib=$LIBTEXT  --rootmap=${TARGETS[1]} $DEBUG_FLAG" )
env.Append(BUILDERS = {'DictionarySource' : genreflex})

# this sets the build flags, like -std=c++14 -Wall -O3, etc
SetOption('warn', 'no-fortran-cxx-mix')
env.MergeFlags( mergeFlags(mu2eOpts) )

# env construction variables, in SConscript: var=env['VARNAME']
env.Append( ROOTLIBS = rootLibs() )
env.Append( BABARLIBS = BaBarLibs() )
env.Append( MU2EBASE = mu2eOpts["base"] )
env.Append( BINDIR = mu2eOpts['bindir'] )
env.Append( BUILD = mu2eOpts["build"] )
env.Append( G4VIS = mu2eOpts["g4vis"] )

# make the scons environment visible to all SConscript files (Import('env'))
Export('env')

# Export the class so that it can be used in the SConscript files
# For reasons I don't understand, this must come before the env.SConscript(ss) line.
# also it is undocumented how you can export a class name, not a variable
Export('mu2e_helper')

# the list of SConscript files in the directory tree
ss = sconscriptList(mu2eOpts)

# make sure lib, bin and tmp are there
makeSubDirs(mu2eOpts)

# operate on the SConscript files
# regular python commands like os.path() are executed immediately as they are encontered, 
# scons builder commands like env.SharedLibrary are examined for dependences and scheduled
# to be executed in parallel, as possible
env.SConscript(ss)

#  with -c, scons will remove all dependant files it knows about.
#  this code removes orphan files caused by a parent that was removed
if ( GetOption('clean') and not COMMAND_LINE_TARGETS):
    extraCleanup()

# This tells emacs to view this file in python mode.
# Local Variables:
# mode:python
# End:
