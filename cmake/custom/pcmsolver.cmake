#.rst:
#
# Adds PCMSolver support.
#
# Variables used::
#
#   ENABLE_PCMSOLVER
#
# autocmake.yml configuration::
#
#   docopt: "--pcmsolver=<ENABLE_PCMSOLVER> Toggle use of PCMSolver <ON/OFF> [default: ON]."
#   define: "'-DENABLE_PCMSOLVER={0}'.format(arguments['--pcmsolver'])"
