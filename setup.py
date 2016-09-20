#!/usr/bin/env python

# This file is autogenerated by Autocmake v1.0.0-alpha-x http://autocmake.org
# Copyright (c) 2015-2016 by Radovan Bast, Jonas Juselius, and contributors.

import os
import sys

sys.path.insert(0, 'cmake')
from autocmake import configure
from autocmake.external import docopt


options = """
Usage:
  ./setup.py [options] [<builddir>]
  ./setup.py (-h | --help)

Options:
  --cc=<CC>                              C compiler [default: gcc].
  --extra-cc-flags=<EXTRA_CFLAGS>        Extra C compiler flags [default: ''].
  --cxx=<CXX>                            C++ compiler [default: g++].
  --extra-cxx-flags=<EXTRA_CXXFLAGS>     Extra C++ compiler flags [default: ''].
  --ccache=<USE_CCACHE>                  Toggle use of ccache <ON/OFF> [default: ON].
  --add-definitions=<STRING>             Add preprocesor definitions [default: ''].
  --coverage                             Enable code coverage [default: False].
  --pcmsolver=<ENABLE_PCMSOLVER>         Toggle use of PCMSolver <ON/OFF> [default: ON].
  --type=<TYPE>                          Set the CMake build type (debug, release, or relwithdeb) [default: release].
  --generator=<STRING>                   Set the CMake build system generator [default: Unix Makefiles].
  --show                                 Show CMake command and exit.
  --cmake-executable=<CMAKE_EXECUTABLE>  Set the CMake executable [default: cmake].
  --cmake-options=<STRING>               Define options to CMake [default: ''].
  --prefix=<PATH>                        Set the install path for make install.
  <builddir>                             Build directory.
  -h --help                              Show this screen.
"""


def gen_cmake_command(options, arguments):
    """
    Generate CMake command based on options and arguments.
    """
    command = []
    command.append('CC={0}'.format(arguments['--cc']))
    command.append('CXX={0}'.format(arguments['--cxx']))
    command.append(arguments['--cmake-executable'])
    command.append('-DEXTRA_CFLAGS="{0}"'.format(arguments['--extra-cc-flags']))
    command.append('-DEXTRA_CXXFLAGS="{0}"'.format(arguments['--extra-cxx-flags']))
    command.append('-DUSE_CCACHE={0}'.format(arguments['--ccache']))
    command.append('-DPREPROCESSOR_DEFINITIONS="{0}"'.format(arguments['--add-definitions']))
    command.append('-DENABLE_CODE_COVERAGE={0}'.format(arguments['--coverage']))
    command.append('-DENABLE_PCMSOLVER={0}'.format(arguments['--pcmsolver']))
    command.append('-DCMAKE_BUILD_TYPE={0}'.format(arguments['--type']))
    command.append('-G "{0}"'.format(arguments['--generator']))
    if arguments['--cmake-options'] != "''":
        command.append(arguments['--cmake-options'])
    if arguments['--prefix']:
        command.append('-DCMAKE_INSTALL_PREFIX="{0}"'.format(arguments['--prefix']))

    return ' '.join(command)


# parse command line args
try:
    arguments = docopt.docopt(options, argv=None)
except docopt.DocoptExit:
    sys.stderr.write('ERROR: bad input to {0}\n'.format(sys.argv[0]))
    sys.stderr.write(options)
    sys.exit(-1)


# use extensions to validate/post-process args
if configure.module_exists('extensions'):
    import extensions
    arguments = extensions.postprocess_args(sys.argv, arguments)


root_directory = os.path.dirname(os.path.realpath(__file__))


build_path = arguments['<builddir>']


# create cmake command
cmake_command = '{0} {1}'.format(gen_cmake_command(options, arguments), root_directory)


# run cmake
configure.configure(root_directory, build_path, cmake_command, arguments['--show'])