# Manual Installation LLVM/MPICH

!include getting_started/minimum_requirements.md

## Prerequisites

- Cmake 3.4 or greater will be needed for building PETSc and LLVM. Unless your system is very old, one should
  be able to use their system's package manager (apt-get, yum, zypper, etc) to install a compatible
  version of Cmake. For older systems, you will need to obtain cmake source from http://www.cmake.org,
  and build it appropriately for your system.

- A sane environment. This means having a clean, nothing but the bare minimum as far as available
  libraries go in your running environment. No additional LD_LIBRARY_PATHs, or other extra PATHs
  set. No strange UMASK settings. No odd aliases. It might even be best, to create a separate
  account, strictly for the use of these instructions. I have created an account called 'moose', and
  will assume you have done the same.

!include manual_environment.md

!include manual_gcc.md

!include manual_llvm.md

!alert! note
In order to utilize our newly built LLVM-Clang compiler, we need to export some variables:

!package! code
export CC=clang
export CXX=clang++
export PATH=$PACKAGES_DIR/llvm-__LLVM__/bin:$PATH
export LD_LIBRARY_PATH=$PACKAGES_DIR/llvm-__LLVM__/lib:$LD_LIBRARY_PATH
!package-end!

!alert-end!

!include manual_mpich_llvm.md

!include manual_petsc.md

!include manual_miniconda.md

## bash_profile

Now that everything has been installed, its time to wrap all these environment variables up, and throw them in a bash shell profile somewhere.

Append the following contents into a new file called `moose-environment.sh`:

!package! code
#!/bin/bash
### MOOSE Environment Profile
# GCC __GCC__
# LLVM __LLVM__
# MPICH __MPICH__
# PETSc __PETSC_DEFAULT__

export PACKAGES_DIR=<what ever you exported initially during the Environment setup>

export PATH=$PACKAGES_DIR/llvm-__LLVM__/bin:$PACKAGES_DIR/gcc-__GCC__/bin:$PACKAGES_DIR/mpich-__MPICH__/bin:$PACKAGES_DIR/miniconda/bin:$PATH
export LD_LIBRARY_PATH=$PACKAGES_DIR/llvm-__LLVM__/lib:$PACKAGES_DIR/gcc-__GCC__/lib64:$PACKAGES_DIR/gcc-__GCC__/lib:$PACKAGES_DIR/gcc-__GCC__/lib/gcc/x86_64-unknown-linux-gnu/__GCC__:$PACKAGES_DIR/gcc-__GCC__/libexec/gcc/x86_64-unknown-linux-gnu/__GCC__:$PACKAGES_DIR/mpich-__MPICH__/lib:$LD_LIBRARY_PATH
export C_INCLUDE_PATH=$PACKAGES_DIR/mpich-__MPICH__/include:$C_INCLUDE_PATH
export CPLUS_INCLUDE_PATH=$PACKAGES_DIR/mpich-__MPICH__/include:$CPLUS_INCLUDE_PATH
export FPATH=$PACKAGES_DIR/mpich-__MPICH__/include:$FPATH
export MANPATH=$PACKAGES_DIR/mpich-__MPICH__/share/man:$MANPATH
export PETSC_DIR=$PACKAGES_DIR/petsc-__PETSC_DEFAULT__
export CC=mpicc
export CXX=mpicxx
export FC=mpif90
export F90=mpif90
!package-end!

Thats it! Now you can either source this file manually each time you need to work on a MOOSE based
application:

```bash
source /path/to/moose-environment.sh
```

Or you can permanently have it loaded each time you open a terminal by adding the above `source`
command in your ~/.bash_profile (or ~/.bashrc which ever your system uses).

!include manual_cleanup.md
