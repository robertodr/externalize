#.rst:
#
# Enables OpenMP support.
#
# Variables used::
#
#   ENABLE_OPENMP
#   OPENMP_FOUND
#
# Variables modified (provided the corresponding language is enabled)::
#
#   CMAKE_Fortran_FLAGS
#   CMAKE_C_FLAGS
#   CMAKE_CXX_FLAGS
#
# autocmake.cfg configuration::
#
#   docopt: --omp Enable OpenMP parallelization [default: False].
#   define: '-DENABLE_OPENMP=%s' % arguments['--omp']

option(ENABLE_OPENMP "Enable OpenMP parallelization" OFF)

if(ENABLE_OPENMP)
    if(DEFINED CMAKE_Fortran_COMPILER_ID)
        # we do this in a pedestrian way because the Fortran support is relatively recent
        if(CMAKE_Fortran_COMPILER_ID MATCHES GNU)
            set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -fopenmp")
        endif()
        if(CMAKE_Fortran_COMPILER_ID MATCHES Intel)
            set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -openmp")
        endif()
        if(CMAKE_Fortran_COMPILER_ID MATCHES PGI)
            set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -mp")
        endif()
        if(CMAKE_Fortran_COMPILER_ID MATCHES XL)
            set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -qsmp")
        endif()
        if(CMAKE_Fortran_COMPILER_ID MATCHES Cray)
            # do nothing in this case
        endif()
        set(OPENMP_FOUND TRUE)
    endif()

    if(NOT OPENMP_FOUND)
        find_package(OpenMP)
    endif()

    if(OPENMP_FOUND)
        add_definitions(-DHAVE_OPENMP)
        if(DEFINED CMAKE_C_COMPILER_ID)
            set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
        endif()
        if(DEFINED CMAKE_CXX_COMPILER_ID)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
        endif()
    endif()
endif()
