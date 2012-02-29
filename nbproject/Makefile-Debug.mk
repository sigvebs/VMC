#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=mpicxx 
CXX=mpicxx 
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/QD_kinetic.o \
	${OBJECTDIR}/Interaction.o \
	${OBJECTDIR}/Coulomb_pot.o \
	${OBJECTDIR}/Wavefunction.o \
	${OBJECTDIR}/Potential.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Kinetic_electron.o \
	${OBJECTDIR}/Kinetic.o \
	${OBJECTDIR}/Hamiltonian.o \
	${OBJECTDIR}/QD_Jastrow.o \
	${OBJECTDIR}/MC_Brute_Force.o \
	${OBJECTDIR}/QD_Harmonic_osc.o \
	${OBJECTDIR}/QD_wavefunction.o \
	${OBJECTDIR}/QVMC.o \
	${OBJECTDIR}/MC_Importance_Sampling.o \
	${OBJECTDIR}/lib.o \
	${OBJECTDIR}/electron_interaction.o \
	${OBJECTDIR}/LA_VMC_APP.o \
	${OBJECTDIR}/Jastrow.o \
	${OBJECTDIR}/includes/ini.o \
	${OBJECTDIR}/QD_VMC_APP.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-o3 -DMPICH_IGNORE_CXX_SEEK -Werror
CXXFLAGS=-o3 -DMPICH_IGNORE_CXX_SEEK -Werror

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/vmc

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/vmc: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/vmc ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/QD_kinetic.o: QD_kinetic.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD_kinetic.o QD_kinetic.cpp

${OBJECTDIR}/Interaction.o: Interaction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Interaction.o Interaction.cpp

${OBJECTDIR}/Coulomb_pot.o: Coulomb_pot.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Coulomb_pot.o Coulomb_pot.cpp

${OBJECTDIR}/Wavefunction.o: Wavefunction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Wavefunction.o Wavefunction.cpp

${OBJECTDIR}/Potential.o: Potential.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Potential.o Potential.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Kinetic_electron.o: Kinetic_electron.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Kinetic_electron.o Kinetic_electron.cpp

${OBJECTDIR}/Kinetic.o: Kinetic.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Kinetic.o Kinetic.cpp

${OBJECTDIR}/Hamiltonian.o: Hamiltonian.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Hamiltonian.o Hamiltonian.cpp

${OBJECTDIR}/QD_Jastrow.o: QD_Jastrow.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD_Jastrow.o QD_Jastrow.cpp

${OBJECTDIR}/MC_Brute_Force.o: MC_Brute_Force.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/MC_Brute_Force.o MC_Brute_Force.cpp

${OBJECTDIR}/QD_Harmonic_osc.o: QD_Harmonic_osc.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD_Harmonic_osc.o QD_Harmonic_osc.cpp

${OBJECTDIR}/QD_wavefunction.o: QD_wavefunction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD_wavefunction.o QD_wavefunction.cpp

${OBJECTDIR}/QVMC.o: QVMC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QVMC.o QVMC.cpp

${OBJECTDIR}/MC_Importance_Sampling.o: MC_Importance_Sampling.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/MC_Importance_Sampling.o MC_Importance_Sampling.cpp

${OBJECTDIR}/lib.o: lib.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/lib.o lib.cpp

${OBJECTDIR}/electron_interaction.o: electron_interaction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/electron_interaction.o electron_interaction.cpp

${OBJECTDIR}/LA_VMC_APP.o: LA_VMC_APP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/LA_VMC_APP.o LA_VMC_APP.cpp

${OBJECTDIR}/Jastrow.o: Jastrow.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Jastrow.o Jastrow.cpp

${OBJECTDIR}/includes/ini.o: includes/ini.cpp 
	${MKDIR} -p ${OBJECTDIR}/includes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/includes/ini.o includes/ini.cpp

${OBJECTDIR}/QD_VMC_APP.o: QD_VMC_APP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD_VMC_APP.o QD_VMC_APP.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/vmc

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
