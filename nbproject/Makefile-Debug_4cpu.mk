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
CND_CONF=Debug_4cpu
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
	${OBJECTDIR}/QD/QD_Conjugate_Gradient.o \
	${OBJECTDIR}/includes/minimization/model.o \
	${OBJECTDIR}/Slater.o \
	${OBJECTDIR}/One_Body_Density/One_Body_Density.o \
	${OBJECTDIR}/Kinetic.o \
	${OBJECTDIR}/Hamiltonian.o \
	${OBJECTDIR}/QD/QD_wavefunction.o \
	${OBJECTDIR}/includes/lib.o \
	${OBJECTDIR}/MC_Brute_Force.o \
	${OBJECTDIR}/includes/minimization/vectormatrixclass.o \
	${OBJECTDIR}/QD/QD_Harmonic_osc.o \
	${OBJECTDIR}/DMC.o \
	${OBJECTDIR}/QD/QD_Orbital.o \
	${OBJECTDIR}/QVMC.o \
	${OBJECTDIR}/Hermite.o \
	${OBJECTDIR}/MC_Importance_Sampling.o \
	${OBJECTDIR}/QD_electron_interaction.o \
	${OBJECTDIR}/electron_interaction.o \
	${OBJECTDIR}/LA_VMC_APP.o \
	${OBJECTDIR}/Blocking/Blocking.o \
	${OBJECTDIR}/Jastrow.o \
	${OBJECTDIR}/includes/ini.o \
	${OBJECTDIR}/Orbital.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-o3 -DMPICH_IGNORE_CXX_SEEK -llapack -lblas -larmadillo
CXXFLAGS=-o3 -DMPICH_IGNORE_CXX_SEEK -llapack -lblas -larmadillo

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
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Interaction.o Interaction.cpp

${OBJECTDIR}/QD/QD_Jastrow.o: QD/QD_Jastrow.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_Jastrow.o QD/QD_Jastrow.cpp

${OBJECTDIR}/Coulomb_pot.o: Coulomb_pot.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Coulomb_pot.o Coulomb_pot.cpp

${OBJECTDIR}/Wavefunction.o: Wavefunction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Wavefunction.o Wavefunction.cpp

${OBJECTDIR}/QD/QD_VMC_APP.o: QD/QD_VMC_APP.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_VMC_APP.o QD/QD_VMC_APP.cpp

${OBJECTDIR}/Potential.o: Potential.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Potential.o Potential.cpp

${OBJECTDIR}/QD/QD_kinetic.o: QD/QD_kinetic.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_kinetic.o QD/QD_kinetic.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Kinetic_electron.o: Kinetic_electron.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Kinetic_electron.o Kinetic_electron.cpp

${OBJECTDIR}/QD/QD_Conjugate_Gradient.o: QD/QD_Conjugate_Gradient.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_Conjugate_Gradient.o QD/QD_Conjugate_Gradient.cpp

${OBJECTDIR}/includes/minimization/model.o: includes/minimization/model.cpp 
	${MKDIR} -p ${OBJECTDIR}/includes/minimization
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/includes/minimization/model.o includes/minimization/model.cpp

${OBJECTDIR}/Slater.o: Slater.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Slater.o Slater.cpp

${OBJECTDIR}/One_Body_Density/One_Body_Density.o: One_Body_Density/One_Body_Density.cpp 
	${MKDIR} -p ${OBJECTDIR}/One_Body_Density
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/One_Body_Density/One_Body_Density.o One_Body_Density/One_Body_Density.cpp

${OBJECTDIR}/Kinetic.o: Kinetic.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Kinetic.o Kinetic.cpp

${OBJECTDIR}/Hamiltonian.o: Hamiltonian.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Hamiltonian.o Hamiltonian.cpp

${OBJECTDIR}/QD/QD_wavefunction.o: QD/QD_wavefunction.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_wavefunction.o QD/QD_wavefunction.cpp

${OBJECTDIR}/includes/lib.o: includes/lib.cpp 
	${MKDIR} -p ${OBJECTDIR}/includes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/includes/lib.o includes/lib.cpp

${OBJECTDIR}/MC_Brute_Force.o: MC_Brute_Force.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/MC_Brute_Force.o MC_Brute_Force.cpp

${OBJECTDIR}/includes/minimization/vectormatrixclass.o: includes/minimization/vectormatrixclass.cpp 
	${MKDIR} -p ${OBJECTDIR}/includes/minimization
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/includes/minimization/vectormatrixclass.o includes/minimization/vectormatrixclass.cpp

${OBJECTDIR}/QD/QD_Harmonic_osc.o: QD/QD_Harmonic_osc.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_Harmonic_osc.o QD/QD_Harmonic_osc.cpp

${OBJECTDIR}/DMC.o: DMC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/DMC.o DMC.cpp

${OBJECTDIR}/QD/QD_Orbital.o: QD/QD_Orbital.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_Orbital.o QD/QD_Orbital.cpp

${OBJECTDIR}/QVMC.o: QVMC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QVMC.o QVMC.cpp

${OBJECTDIR}/Hermite.o: Hermite.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Hermite.o Hermite.cpp

${OBJECTDIR}/MC_Importance_Sampling.o: MC_Importance_Sampling.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/MC_Importance_Sampling.o MC_Importance_Sampling.cpp

${OBJECTDIR}/QD_electron_interaction.o: QD_electron_interaction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD_electron_interaction.o QD_electron_interaction.cpp

${OBJECTDIR}/electron_interaction.o: electron_interaction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/electron_interaction.o electron_interaction.cpp

${OBJECTDIR}/LA_VMC_APP.o: LA_VMC_APP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/LA_VMC_APP.o LA_VMC_APP.cpp

${OBJECTDIR}/Blocking/Blocking.o: Blocking/Blocking.cpp 
	${MKDIR} -p ${OBJECTDIR}/Blocking
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Blocking/Blocking.o Blocking/Blocking.cpp

${OBJECTDIR}/Jastrow.o: Jastrow.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Jastrow.o Jastrow.cpp

${OBJECTDIR}/includes/ini.o: includes/ini.cpp 
	${MKDIR} -p ${OBJECTDIR}/includes
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/includes/ini.o includes/ini.cpp

${OBJECTDIR}/Orbital.o: Orbital.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Orbital.o Orbital.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/newsimpletest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/newsimpletest.o: tests/newsimpletest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/newsimpletest.o tests/newsimpletest.cpp


${OBJECTDIR}/Interaction_nomain.o: ${OBJECTDIR}/Interaction.o Interaction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Interaction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Interaction_nomain.o Interaction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Interaction.o ${OBJECTDIR}/Interaction_nomain.o;\
	fi

${OBJECTDIR}/QD/QD_Jastrow_nomain.o: ${OBJECTDIR}/QD/QD_Jastrow.o QD/QD_Jastrow.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	@NMOUTPUT=`${NM} ${OBJECTDIR}/QD/QD_Jastrow.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_Jastrow_nomain.o QD/QD_Jastrow.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/QD/QD_Jastrow.o ${OBJECTDIR}/QD/QD_Jastrow_nomain.o;\
	fi

${OBJECTDIR}/Coulomb_pot_nomain.o: ${OBJECTDIR}/Coulomb_pot.o Coulomb_pot.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Coulomb_pot.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Coulomb_pot_nomain.o Coulomb_pot.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Coulomb_pot.o ${OBJECTDIR}/Coulomb_pot_nomain.o;\
	fi

${OBJECTDIR}/Wavefunction_nomain.o: ${OBJECTDIR}/Wavefunction.o Wavefunction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Wavefunction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Wavefunction_nomain.o Wavefunction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Wavefunction.o ${OBJECTDIR}/Wavefunction_nomain.o;\
	fi

${OBJECTDIR}/QD/QD_VMC_APP_nomain.o: ${OBJECTDIR}/QD/QD_VMC_APP.o QD/QD_VMC_APP.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	@NMOUTPUT=`${NM} ${OBJECTDIR}/QD/QD_VMC_APP.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_VMC_APP_nomain.o QD/QD_VMC_APP.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/QD/QD_VMC_APP.o ${OBJECTDIR}/QD/QD_VMC_APP_nomain.o;\
	fi

${OBJECTDIR}/Potential_nomain.o: ${OBJECTDIR}/Potential.o Potential.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Potential.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Potential_nomain.o Potential.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Potential.o ${OBJECTDIR}/Potential_nomain.o;\
	fi

${OBJECTDIR}/QD/QD_kinetic_nomain.o: ${OBJECTDIR}/QD/QD_kinetic.o QD/QD_kinetic.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	@NMOUTPUT=`${NM} ${OBJECTDIR}/QD/QD_kinetic.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_kinetic_nomain.o QD/QD_kinetic.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/QD/QD_kinetic.o ${OBJECTDIR}/QD/QD_kinetic_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/Kinetic_electron_nomain.o: ${OBJECTDIR}/Kinetic_electron.o Kinetic_electron.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Kinetic_electron.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Kinetic_electron_nomain.o Kinetic_electron.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Kinetic_electron.o ${OBJECTDIR}/Kinetic_electron_nomain.o;\
	fi

${OBJECTDIR}/QD/QD_Conjugate_Gradient_nomain.o: ${OBJECTDIR}/QD/QD_Conjugate_Gradient.o QD/QD_Conjugate_Gradient.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	@NMOUTPUT=`${NM} ${OBJECTDIR}/QD/QD_Conjugate_Gradient.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_Conjugate_Gradient_nomain.o QD/QD_Conjugate_Gradient.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/QD/QD_Conjugate_Gradient.o ${OBJECTDIR}/QD/QD_Conjugate_Gradient_nomain.o;\
	fi

${OBJECTDIR}/includes/minimization/model_nomain.o: ${OBJECTDIR}/includes/minimization/model.o includes/minimization/model.cpp 
	${MKDIR} -p ${OBJECTDIR}/includes/minimization
	@NMOUTPUT=`${NM} ${OBJECTDIR}/includes/minimization/model.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/includes/minimization/model_nomain.o includes/minimization/model.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/includes/minimization/model.o ${OBJECTDIR}/includes/minimization/model_nomain.o;\
	fi

${OBJECTDIR}/Slater_nomain.o: ${OBJECTDIR}/Slater.o Slater.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Slater.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Slater_nomain.o Slater.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Slater.o ${OBJECTDIR}/Slater_nomain.o;\
	fi

${OBJECTDIR}/One_Body_Density/One_Body_Density_nomain.o: ${OBJECTDIR}/One_Body_Density/One_Body_Density.o One_Body_Density/One_Body_Density.cpp 
	${MKDIR} -p ${OBJECTDIR}/One_Body_Density
	@NMOUTPUT=`${NM} ${OBJECTDIR}/One_Body_Density/One_Body_Density.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/One_Body_Density/One_Body_Density_nomain.o One_Body_Density/One_Body_Density.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/One_Body_Density/One_Body_Density.o ${OBJECTDIR}/One_Body_Density/One_Body_Density_nomain.o;\
	fi

${OBJECTDIR}/Kinetic_nomain.o: ${OBJECTDIR}/Kinetic.o Kinetic.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Kinetic.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Kinetic_nomain.o Kinetic.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Kinetic.o ${OBJECTDIR}/Kinetic_nomain.o;\
	fi

${OBJECTDIR}/Hamiltonian_nomain.o: ${OBJECTDIR}/Hamiltonian.o Hamiltonian.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Hamiltonian.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Hamiltonian_nomain.o Hamiltonian.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Hamiltonian.o ${OBJECTDIR}/Hamiltonian_nomain.o;\
	fi

${OBJECTDIR}/QD/QD_wavefunction_nomain.o: ${OBJECTDIR}/QD/QD_wavefunction.o QD/QD_wavefunction.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	@NMOUTPUT=`${NM} ${OBJECTDIR}/QD/QD_wavefunction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_wavefunction_nomain.o QD/QD_wavefunction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/QD/QD_wavefunction.o ${OBJECTDIR}/QD/QD_wavefunction_nomain.o;\
	fi

${OBJECTDIR}/includes/lib_nomain.o: ${OBJECTDIR}/includes/lib.o includes/lib.cpp 
	${MKDIR} -p ${OBJECTDIR}/includes
	@NMOUTPUT=`${NM} ${OBJECTDIR}/includes/lib.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/includes/lib_nomain.o includes/lib.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/includes/lib.o ${OBJECTDIR}/includes/lib_nomain.o;\
	fi

${OBJECTDIR}/MC_Brute_Force_nomain.o: ${OBJECTDIR}/MC_Brute_Force.o MC_Brute_Force.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MC_Brute_Force.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/MC_Brute_Force_nomain.o MC_Brute_Force.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MC_Brute_Force.o ${OBJECTDIR}/MC_Brute_Force_nomain.o;\
	fi

${OBJECTDIR}/includes/minimization/vectormatrixclass_nomain.o: ${OBJECTDIR}/includes/minimization/vectormatrixclass.o includes/minimization/vectormatrixclass.cpp 
	${MKDIR} -p ${OBJECTDIR}/includes/minimization
	@NMOUTPUT=`${NM} ${OBJECTDIR}/includes/minimization/vectormatrixclass.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/includes/minimization/vectormatrixclass_nomain.o includes/minimization/vectormatrixclass.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/includes/minimization/vectormatrixclass.o ${OBJECTDIR}/includes/minimization/vectormatrixclass_nomain.o;\
	fi

${OBJECTDIR}/QD/QD_Harmonic_osc_nomain.o: ${OBJECTDIR}/QD/QD_Harmonic_osc.o QD/QD_Harmonic_osc.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	@NMOUTPUT=`${NM} ${OBJECTDIR}/QD/QD_Harmonic_osc.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_Harmonic_osc_nomain.o QD/QD_Harmonic_osc.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/QD/QD_Harmonic_osc.o ${OBJECTDIR}/QD/QD_Harmonic_osc_nomain.o;\
	fi

${OBJECTDIR}/DMC_nomain.o: ${OBJECTDIR}/DMC.o DMC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DMC.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/DMC_nomain.o DMC.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DMC.o ${OBJECTDIR}/DMC_nomain.o;\
	fi

${OBJECTDIR}/QD/QD_Orbital_nomain.o: ${OBJECTDIR}/QD/QD_Orbital.o QD/QD_Orbital.cpp 
	${MKDIR} -p ${OBJECTDIR}/QD
	@NMOUTPUT=`${NM} ${OBJECTDIR}/QD/QD_Orbital.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD/QD_Orbital_nomain.o QD/QD_Orbital.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/QD/QD_Orbital.o ${OBJECTDIR}/QD/QD_Orbital_nomain.o;\
	fi

${OBJECTDIR}/QVMC_nomain.o: ${OBJECTDIR}/QVMC.o QVMC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/QVMC.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/QVMC_nomain.o QVMC.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/QVMC.o ${OBJECTDIR}/QVMC_nomain.o;\
	fi

${OBJECTDIR}/Hermite_nomain.o: ${OBJECTDIR}/Hermite.o Hermite.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Hermite.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Hermite_nomain.o Hermite.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Hermite.o ${OBJECTDIR}/Hermite_nomain.o;\
	fi

${OBJECTDIR}/MC_Importance_Sampling_nomain.o: ${OBJECTDIR}/MC_Importance_Sampling.o MC_Importance_Sampling.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MC_Importance_Sampling.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/MC_Importance_Sampling_nomain.o MC_Importance_Sampling.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MC_Importance_Sampling.o ${OBJECTDIR}/MC_Importance_Sampling_nomain.o;\
	fi

${OBJECTDIR}/QD_electron_interaction_nomain.o: ${OBJECTDIR}/QD_electron_interaction.o QD_electron_interaction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/QD_electron_interaction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/QD_electron_interaction_nomain.o QD_electron_interaction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/QD_electron_interaction.o ${OBJECTDIR}/QD_electron_interaction_nomain.o;\
	fi

${OBJECTDIR}/electron_interaction_nomain.o: ${OBJECTDIR}/electron_interaction.o electron_interaction.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/electron_interaction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/electron_interaction_nomain.o electron_interaction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/electron_interaction.o ${OBJECTDIR}/electron_interaction_nomain.o;\
	fi

${OBJECTDIR}/LA_VMC_APP_nomain.o: ${OBJECTDIR}/LA_VMC_APP.o LA_VMC_APP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LA_VMC_APP.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/LA_VMC_APP_nomain.o LA_VMC_APP.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/LA_VMC_APP.o ${OBJECTDIR}/LA_VMC_APP_nomain.o;\
	fi

${OBJECTDIR}/Blocking/Blocking_nomain.o: ${OBJECTDIR}/Blocking/Blocking.o Blocking/Blocking.cpp 
	${MKDIR} -p ${OBJECTDIR}/Blocking
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Blocking/Blocking.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Blocking/Blocking_nomain.o Blocking/Blocking.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Blocking/Blocking.o ${OBJECTDIR}/Blocking/Blocking_nomain.o;\
	fi

${OBJECTDIR}/Jastrow_nomain.o: ${OBJECTDIR}/Jastrow.o Jastrow.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Jastrow.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Jastrow_nomain.o Jastrow.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Jastrow.o ${OBJECTDIR}/Jastrow_nomain.o;\
	fi

${OBJECTDIR}/includes/ini_nomain.o: ${OBJECTDIR}/includes/ini.o includes/ini.cpp 
	${MKDIR} -p ${OBJECTDIR}/includes
	@NMOUTPUT=`${NM} ${OBJECTDIR}/includes/ini.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/includes/ini_nomain.o includes/ini.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/includes/ini.o ${OBJECTDIR}/includes/ini_nomain.o;\
	fi

${OBJECTDIR}/Orbital_nomain.o: ${OBJECTDIR}/Orbital.o Orbital.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Orbital.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Orbital_nomain.o Orbital.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Orbital.o ${OBJECTDIR}/Orbital_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/vmc

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
