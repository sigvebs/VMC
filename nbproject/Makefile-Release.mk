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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Interaction.o \
	${OBJECTDIR}/QD/QD_Jastrow.o \
	${OBJECTDIR}/Coulomb_pot.o \
	${OBJECTDIR}/Wavefunction.o \
	${OBJECTDIR}/QD/QD_VMC_APP.o \
	${OBJECTDIR}/Potential.o \
	${OBJECTDIR}/QD/QD_kinetic.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Kinetic_electron.o \
	${OBJECTDIR}/Slater.o \
	${OBJECTDIR}/Kinetic.o \
	${OBJECTDIR}/Hamiltonian.o \
	${OBJECTDIR}/QD/QD_wavefunction.o \
	${OBJECTDIR}/includes/lib.o \
	${OBJECTDIR}/MC_Brute_Force.o \
	${OBJECTDIR}/QD/QD_Harmonic_osc.o \
	${OBJECTDIR}/QD/QD_Orbital.o \
	${OBJECTDIR}/QVMC.o \
	${OBJECTDIR}/Hermite.o \
	${OBJECTDIR}/MC_Importance_Sampling.o \
	${OBJECTDIR}/QD_electron_interaction.o \
	${OBJECTDIR}/electron_interaction.o \
	${OBJECTDIR}/LA_VMC_APP.o \
	${OBJECTDIR}/Jastrow.o \
	${OBJECTDIR}/includes/ini.o \
	${OBJECTDIR}/Orbital.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

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

${OBJECTDIR}/Interaction.o: Interaction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Interaction.o Interaction.cpp

${OBJECTDIR}/QD/QD_Jastrow.o: QD/QD_Jastrow.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_Jastrow.o QD/QD_Jastrow.cpp

${OBJECTDIR}/Coulomb_pot.o: Coulomb_pot.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Coulomb_pot.o Coulomb_pot.cpp

${OBJECTDIR}/Wavefunction.o: Wavefunction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Wavefunction.o Wavefunction.cpp

${OBJECTDIR}/QD/QD_VMC_APP.o: QD/QD_VMC_APP.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_VMC_APP.o QD/QD_VMC_APP.cpp

${OBJECTDIR}/Potential.o: Potential.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Potential.o Potential.cpp

${OBJECTDIR}/QD/QD_kinetic.o: QD/QD_kinetic.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_kinetic.o QD/QD_kinetic.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Kinetic_electron.o: Kinetic_electron.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Kinetic_electron.o Kinetic_electron.cpp

${OBJECTDIR}/Slater.o: Slater.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Slater.o Slater.cpp

${OBJECTDIR}/Kinetic.o: Kinetic.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Kinetic.o Kinetic.cpp

${OBJECTDIR}/Hamiltonian.o: Hamiltonian.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Hamiltonian.o Hamiltonian.cpp

${OBJECTDIR}/QD/QD_wavefunction.o: QD/QD_wavefunction.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_wavefunction.o QD/QD_wavefunction.cpp

${OBJECTDIR}/includes/lib.o: includes/lib.cpp 
	${MKDIR} -p ${OBJECTDIR}/includes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/includes/lib.o includes/lib.cpp

${OBJECTDIR}/MC_Brute_Force.o: MC_Brute_Force.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/MC_Brute_Force.o MC_Brute_Force.cpp

${OBJECTDIR}/QD/QD_Harmonic_osc.o: QD/QD_Harmonic_osc.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_Harmonic_osc.o QD/QD_Harmonic_osc.cpp

${OBJECTDIR}/QD/QD_Orbital.o: QD/QD_Orbital.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_Orbital.o QD/QD_Orbital.cpp

${OBJECTDIR}/QVMC.o: QVMC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/QVMC.o QVMC.cpp

${OBJECTDIR}/Hermite.o: Hermite.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Hermite.o Hermite.cpp

${OBJECTDIR}/MC_Importance_Sampling.o: MC_Importance_Sampling.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/MC_Importance_Sampling.o MC_Importance_Sampling.cpp

${OBJECTDIR}/QD_electron_interaction.o: QD_electron_interaction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD_electron_interaction.o QD_electron_interaction.cpp

${OBJECTDIR}/electron_interaction.o: electron_interaction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/electron_interaction.o electron_interaction.cpp

${OBJECTDIR}/LA_VMC_APP.o: LA_VMC_APP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/LA_VMC_APP.o LA_VMC_APP.cpp

${OBJECTDIR}/Jastrow.o: Jastrow.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Jastrow.o Jastrow.cpp

${OBJECTDIR}/includes/ini.o: includes/ini.cpp 
	${MKDIR} -p ${OBJECTDIR}/includes
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/includes/ini.o includes/ini.cpp

${OBJECTDIR}/Orbital.o: Orbital.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Orbital.o Orbital.cpp

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
