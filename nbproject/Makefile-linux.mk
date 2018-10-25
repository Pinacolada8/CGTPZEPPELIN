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
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=linux
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Game-SRC/Cannon.o \
	${OBJECTDIR}/Game-SRC/Desenhos.o \
	${OBJECTDIR}/Game-SRC/GameLogic.o \
	${OBJECTDIR}/Game-SRC/InGameMenu.o \
	${OBJECTDIR}/Game-SRC/Inputs.o \
	${OBJECTDIR}/Game-SRC/Objects.o \
	${OBJECTDIR}/Game-SRC/Obstacles.o \
	${OBJECTDIR}/Game-SRC/Physics.o \
	${OBJECTDIR}/Game-SRC/Player.o \
	${OBJECTDIR}/Game-SRC/PowerUp_invulnerability.o \
	${OBJECTDIR}/Game-SRC/Scenario.o \
	${OBJECTDIR}/Game-SRC/Scores.o \
	${OBJECTDIR}/Game-SRC/StateController.o \
	${OBJECTDIR}/Game-SRC/StateCredits.o \
	${OBJECTDIR}/Game-SRC/StateGame.o \
	${OBJECTDIR}/Game-SRC/StateInGameMenu.o \
	${OBJECTDIR}/Game-SRC/StateMenu.o \
	${OBJECTDIR}/Game-SRC/StateOption.o \
	${OBJECTDIR}/Game-SRC/Texto.o \
	${OBJECTDIR}/Game-SRC/Textures.o \
	${OBJECTDIR}/Game-SRC/Timer.o \
	${OBJECTDIR}/Game-SRC/Wait.o \
	${OBJECTDIR}/Game-SRC/main.o


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
LDLIBSOPTIONS=-LGameResources/Lib -lglut -lGLU -lGLEW -lSOIL -lGL -lm

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/Start

${CND_DISTDIR}/${CND_CONF}/Start: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/Start ${OBJECTFILES} ${LDLIBSOPTIONS} -g -Wall

${OBJECTDIR}/Game-SRC/Cannon.o: Game-SRC/Cannon.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Cannon.o Game-SRC/Cannon.c

${OBJECTDIR}/Game-SRC/Desenhos.o: Game-SRC/Desenhos.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Desenhos.o Game-SRC/Desenhos.c

${OBJECTDIR}/Game-SRC/GameLogic.o: Game-SRC/GameLogic.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/GameLogic.o Game-SRC/GameLogic.c

${OBJECTDIR}/Game-SRC/InGameMenu.o: Game-SRC/InGameMenu.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/InGameMenu.o Game-SRC/InGameMenu.c

${OBJECTDIR}/Game-SRC/Inputs.o: Game-SRC/Inputs.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Inputs.o Game-SRC/Inputs.c

${OBJECTDIR}/Game-SRC/Objects.o: Game-SRC/Objects.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Objects.o Game-SRC/Objects.c

${OBJECTDIR}/Game-SRC/Obstacles.o: Game-SRC/Obstacles.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Obstacles.o Game-SRC/Obstacles.c

${OBJECTDIR}/Game-SRC/Physics.o: Game-SRC/Physics.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Physics.o Game-SRC/Physics.c

${OBJECTDIR}/Game-SRC/Player.o: Game-SRC/Player.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Player.o Game-SRC/Player.c

${OBJECTDIR}/Game-SRC/PowerUp_invulnerability.o: Game-SRC/PowerUp_invulnerability.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/PowerUp_invulnerability.o Game-SRC/PowerUp_invulnerability.c

${OBJECTDIR}/Game-SRC/Scenario.o: Game-SRC/Scenario.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Scenario.o Game-SRC/Scenario.c

${OBJECTDIR}/Game-SRC/Scores.o: Game-SRC/Scores.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Scores.o Game-SRC/Scores.c

${OBJECTDIR}/Game-SRC/StateController.o: Game-SRC/StateController.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/StateController.o Game-SRC/StateController.c

${OBJECTDIR}/Game-SRC/StateCredits.o: Game-SRC/StateCredits.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/StateCredits.o Game-SRC/StateCredits.c

${OBJECTDIR}/Game-SRC/StateGame.o: Game-SRC/StateGame.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/StateGame.o Game-SRC/StateGame.c

${OBJECTDIR}/Game-SRC/StateInGameMenu.o: Game-SRC/StateInGameMenu.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/StateInGameMenu.o Game-SRC/StateInGameMenu.c

${OBJECTDIR}/Game-SRC/StateMenu.o: Game-SRC/StateMenu.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/StateMenu.o Game-SRC/StateMenu.c

${OBJECTDIR}/Game-SRC/StateOption.o: Game-SRC/StateOption.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/StateOption.o Game-SRC/StateOption.c

${OBJECTDIR}/Game-SRC/Texto.o: Game-SRC/Texto.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Texto.o Game-SRC/Texto.c

${OBJECTDIR}/Game-SRC/Textures.o: Game-SRC/Textures.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Textures.o Game-SRC/Textures.c

${OBJECTDIR}/Game-SRC/Timer.o: Game-SRC/Timer.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Timer.o Game-SRC/Timer.c

${OBJECTDIR}/Game-SRC/Wait.o: Game-SRC/Wait.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Wait.o Game-SRC/Wait.c

${OBJECTDIR}/Game-SRC/main.o: Game-SRC/main.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -g -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/main.o Game-SRC/main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
