#! /usr/bin/perl

# This file generates the "ta_libc.pro" using the information
# from all the sub-library:
#    ta_data, ta_abstract, ta_common, ta_func, ta_perf
#
# Reminder: ta_libc.pro is then process by tmake for
#           generating the multi-platform makefiles.
#

use Env;

$origTMAKEPATH = $TMAKEPATH;

# Un-comment the following lines if
# you wish to provide your own TMAKEPATH.
# use Env qw( TMAKEPATH );

$ENV{'TMAKEPATH'} = '../template/win32-msvc';

# Concatenate all the sources of all sub-library into '@source'
if( $^O eq "MSWin32" )
{
   $a = `tmake ..\\ta_data\\ta_data.pro -e Expand("SOURCES")`;
   $b = `tmake ..\\ta_common\\ta_common.pro -e Expand("SOURCES")`;
   $c = `tmake ..\\ta_abstract\\ta_abstract.pro -e Expand("SOURCES")`;
   $d = `tmake ..\\ta_func\\ta_func.pro -e Expand("SOURCES")`;
   $e = `tmake ..\\ta_pm\\ta_pm.pro -e Expand("SOURCES")`;
}
else
{
   $a = `tmake ../ta_data/ta_data.pro -e "Expand("SOURCES")"`;
   $b = `tmake ../ta_common/ta_common.pro -e "Expand("SOURCES")"`;
   $c = `tmake ../ta_abstract/ta_abstract.pro -e "Expand("SOURCES")"`;
   $d = `tmake ../ta_func/ta_func.pro -e "Expand("SOURCES")"`;
   $e = `tmake ../ta_pm/ta_pm.pro -e "Expand("SOURCES")"`;
}

chomp $a;
chomp $b;
chomp $c;
chomp $d;
chomp $e;

@sources = ();
$nbsources = 0;
for $z (split / /, $a ) { @sources = (@sources, $z ); $nbSources += 1}
for $z (split / /, $b ) { @sources = (@sources, $z ); $nbSources += 1}
for $z (split / /, $c ) { @sources = (@sources, $z ); $nbSources += 1}
for $z (split / /, $d ) { @sources = (@sources, $z ); $nbSources += 1}
for $z (split / /, $e ) { @sources = (@sources, $z ); $nbSources += 1}

# Concatenate all the include path of all sub-library into '@incpath'
if( $^O eq "MsWin32" )
{
   $a = `tmake ..\\ta_data\\ta_data.pro -e Expand("INCLUDEPATH")`;
   $b = `tmake ..\\ta_common\\ta_common.pro -e Expand("INCLUDEPATH")`;
   $c = `tmake ..\\ta_abstract\\ta_abstract.pro -e Expand("INCLUDEPATH")`;
   $d = `tmake ..\\ta_func\\ta_func.pro -e Expand("INCLUDEPATH")`;
   $e = `tmake ..\\ta_pm\\ta_pm.pro -e Expand("INCLUDEPATH")`;
}
else
{
   $a = `tmake ../ta_data/ta_data.pro -e "Expand("INCLUDEPATH")"`;
   $b = `tmake ../ta_common/ta_common.pro -e "Expand("INCLUDEPATH")"`;
   $c = `tmake ../ta_abstract/ta_abstract.pro -e "Expand("INCLUDEPATH")"`;
   $d = `tmake ../ta_func/ta_func.pro -e "Expand("INCLUDEPATH")"`;
   $e = `tmake ../ta_pm/ta_pm.pro -e "Expand("INCLUDEPATH")"`;
}

chomp $a;
chomp $b;
chomp $c;
chomp $d;
chomp $e;

@incpath = ();
$nbincpath  = 0;
for $z (split / /, $a )
{ 
   if( $z ne "\\n" ) { @incpath = (@incpath, $z ); $nbincpath += 1 }
}

for $z (split / /, $b )
{ 
   if( $z ne "\\n" ) { @incpath = (@incpath, $z ); $nbincpath += 1 }
}

for $z (split / /, $c ) 
{ 
   if( $z ne "\\n" ) { @incpath = (@incpath, $z ); $nbincpath += 1 }
}

for $z (split / /, $d ) 
{ 
   if( $z ne "\\n" ) { @incpath = (@incpath, $z ); $nbincpath += 1 }
}

for $z (split / /, $e )
{ 
   if( $z ne "\\n" ) { @incpath = (@incpath, $z ); $nbincpath += 1 }
}

# Get the version from ta_common.pro
#
# Not used anymore.
#
# if( $^O eq "MsWin32" )
# {
#   $libversion = `tmake ..\\ta_common\\ta_common.pro -e Expand("VERSION")`;
# }
# else
# {
#   $libversion = `tmake ../ta_common/ta_common.pro -e "Expand("VERSION")"`;
# }

chomp( $libversion );

# Start to create the output from here

# First the header
print "# Do not modify this file. It is automatically\n";
print "# generated by make_pro.pl\n";
print "\n";
print "TEMPLATE  = lib\n";
print "CONFIG   += staticlib\n";
print( "\n" );
print "# Identify the temp dir\n";
print "cmd:OBJECTS_DIR = ../../../../../temp/cmd\n";
print "cmr:OBJECTS_DIR = ../../../../../temp/cmr\n";
print "csd:OBJECTS_DIR = ../../../../../temp/csd\n";
print "csr:OBJECTS_DIR = ../../../../../temp/csr\n";
print "\n";
print "# Identify the target name\n";
print "LIBTARGET = ta_libc\n";
print "cmd:TARGET = ta_libc_cmd\n";
print "cmr:TARGET = ta_libc_cmr\n";
print "csd:TARGET = ta_libc_csd\n";
print "csr:TARGET = ta_libc_csr\n";
print "\n";
print "\# Output info\n";
print "VERSION     = $libversion\n";
print "DESTDIR     = ../../../../../lib\n";

# Output the "SOURCES" variable.
print "\# File to process\n";
$iter = 0;
$firstline = 1;
for $z (@sources) {
   $iter += 1;
   chomp($z);
   if( $firstline ) {   
      print "SOURCES = ";
      $firstline = 0;
   }
   else {
      print "          ";
   }
   if( $iter == $nbSources )
      { print $z; }
   else
      { print $z," \\", "\n"; }
}

print "\n\n\# Compiler Options\n";

# Output the include path of all sub-library.
# We leave it to tmake to eliminate redundancy.
for $z (@incpath)
{ print "INCLUDEPATH *= $z\n"; }
print "\n";

# Output the rest of the .pro file

print "\# debug/release dependent options.\n";
print "debug:DEFINES   *= TA_DEBUG\n";
print "debug:DEFINES   *= _DEBUG\n";
print "DEFINES        += TA_SINGLE_THREAD\n";
print "thread:DEFINES -= TA_SINGLE_THREAD\n";

print "\# Platform dependent options.\n";
print "win32:DEFINES         *= WIN32\n";
print "win32-msvc:DEFINES    *= _MBCS _LIB\n";

print "win32:CLEAN_FILES = ../../../../../bin/*.map ../../../../../bin/*._xe ../../../../../bin/*.tds ../../../../../bin/*.pdb ../../../../../bin/*.pbo ../../../../../bin/*.pbi ../../../../../bin/*.pbt\n";

$TMAKEPATH = $origTMAKEPATH;

