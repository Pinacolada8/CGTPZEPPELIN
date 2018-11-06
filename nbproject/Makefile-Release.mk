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
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Game-SRC/Cameras.o \
	${OBJECTDIR}/Game-SRC/Desenhos.o \
	${OBJECTDIR}/Game-SRC/GLM/glm.o \
	${OBJECTDIR}/Game-SRC/GLM/glm_util.o \
	${OBJECTDIR}/Game-SRC/GLM/glmimg.o \
	${OBJECTDIR}/Game-SRC/GameLogic.o \
	${OBJECTDIR}/Game-SRC/InGameMenu.o \
	${OBJECTDIR}/Game-SRC/Inputs.o \
	${OBJECTDIR}/Game-SRC/Lights.o \
	${OBJECTDIR}/Game-SRC/Models.o \
	${OBJECTDIR}/Game-SRC/Objects.o \
	${OBJECTDIR}/Game-SRC/Physics.o \
	${OBJECTDIR}/Game-SRC/Player.o \
	${OBJECTDIR}/Game-SRC/SOIL/SOIL.o \
	${OBJECTDIR}/Game-SRC/SOIL/image_DXT.o \
	${OBJECTDIR}/Game-SRC/SOIL/image_helper.o \
	${OBJECTDIR}/Game-SRC/SOIL/stb_image_aug.o \
	${OBJECTDIR}/Game-SRC/Sound.o \
	${OBJECTDIR}/Game-SRC/StateController.o \
	${OBJECTDIR}/Game-SRC/StateCredits.o \
	${OBJECTDIR}/Game-SRC/StateGame.o \
	${OBJECTDIR}/Game-SRC/StateInGameMenu.o \
	${OBJECTDIR}/Game-SRC/StateLoading.o \
	${OBJECTDIR}/Game-SRC/StateMenu.o \
	${OBJECTDIR}/Game-SRC/StateOption.o \
	${OBJECTDIR}/Game-SRC/Texto.o \
	${OBJECTDIR}/Game-SRC/Textures.o \
	${OBJECTDIR}/Game-SRC/Timer.o \
	${OBJECTDIR}/Game-SRC/Wait.o \
	${OBJECTDIR}/Game-SRC/Window.o \
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
LDLIBSOPTIONS=-LGameResources/Lib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/Start.exe

${CND_DISTDIR}/${CND_CONF}/Start.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/Start ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Game-SRC/Cameras.o: Game-SRC/Cameras.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Cameras.o Game-SRC/Cameras.c

${OBJECTDIR}/Game-SRC/Desenhos.o: Game-SRC/Desenhos.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Desenhos.o Game-SRC/Desenhos.c

${OBJECTDIR}/Game-SRC/GLM/glm.o: Game-SRC/GLM/glm.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC/GLM
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/GLM/glm.o Game-SRC/GLM/glm.c

${OBJECTDIR}/Game-SRC/GLM/glm_util.o: Game-SRC/GLM/glm_util.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC/GLM
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/GLM/glm_util.o Game-SRC/GLM/glm_util.c

${OBJECTDIR}/Game-SRC/GLM/glmimg.o: Game-SRC/GLM/glmimg.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC/GLM
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/GLM/glmimg.o Game-SRC/GLM/glmimg.c

${OBJECTDIR}/Game-SRC/GameLogic.o: Game-SRC/GameLogic.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/GameLogic.o Game-SRC/GameLogic.c

${OBJECTDIR}/Game-SRC/InGameMenu.o: Game-SRC/InGameMenu.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/InGameMenu.o Game-SRC/InGameMenu.c

${OBJECTDIR}/Game-SRC/Inputs.o: Game-SRC/Inputs.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Inputs.o Game-SRC/Inputs.c

${OBJECTDIR}/Game-SRC/Lights.o: Game-SRC/Lights.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Lights.o Game-SRC/Lights.c

${OBJECTDIR}/Game-SRC/Models.o: Game-SRC/Models.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Models.o Game-SRC/Models.c

${OBJECTDIR}/Game-SRC/Objects.o: Game-SRC/Objects.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Objects.o Game-SRC/Objects.c

${OBJECTDIR}/Game-SRC/Physics.o: Game-SRC/Physics.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Physics.o Game-SRC/Physics.c

${OBJECTDIR}/Game-SRC/Player.o: Game-SRC/Player.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Player.o Game-SRC/Player.c

${OBJECTDIR}/Game-SRC/SOIL/SOIL.o: Game-SRC/SOIL/SOIL.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC/SOIL
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/SOIL/SOIL.o Game-SRC/SOIL/SOIL.c

${OBJECTDIR}/Game-SRC/SOIL/image_DXT.o: Game-SRC/SOIL/image_DXT.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC/SOIL
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/SOIL/image_DXT.o Game-SRC/SOIL/image_DXT.c

${OBJECTDIR}/Game-SRC/SOIL/image_helper.o: Game-SRC/SOIL/image_helper.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC/SOIL
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/SOIL/image_helper.o Game-SRC/SOIL/image_helper.c

${OBJECTDIR}/Game-SRC/SOIL/stb_image_aug.o: Game-SRC/SOIL/stb_image_aug.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC/SOIL
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/SOIL/stb_image_aug.o Game-SRC/SOIL/stb_image_aug.c

${OBJECTDIR}/Game-SRC/Sound.o: Game-SRC/Sound.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Sound.o Game-SRC/Sound.c

${OBJECTDIR}/Game-SRC/StateController.o: Game-SRC/StateController.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/StateController.o Game-SRC/StateController.c

${OBJECTDIR}/Game-SRC/StateCredits.o: Game-SRC/StateCredits.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/StateCredits.o Game-SRC/StateCredits.c

${OBJECTDIR}/Game-SRC/StateGame.o: Game-SRC/StateGame.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/StateGame.o Game-SRC/StateGame.c

${OBJECTDIR}/Game-SRC/StateInGameMenu.o: Game-SRC/StateInGameMenu.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/StateInGameMenu.o Game-SRC/StateInGameMenu.c

${OBJECTDIR}/Game-SRC/StateLoading.o: Game-SRC/StateLoading.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/StateLoading.o Game-SRC/StateLoading.c

${OBJECTDIR}/Game-SRC/StateMenu.o: Game-SRC/StateMenu.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/StateMenu.o Game-SRC/StateMenu.c

${OBJECTDIR}/Game-SRC/StateOption.o: Game-SRC/StateOption.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/StateOption.o Game-SRC/StateOption.c

${OBJECTDIR}/Game-SRC/Texto.o: Game-SRC/Texto.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Texto.o Game-SRC/Texto.c

${OBJECTDIR}/Game-SRC/Textures.o: Game-SRC/Textures.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Textures.o Game-SRC/Textures.c

${OBJECTDIR}/Game-SRC/Timer.o: Game-SRC/Timer.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Timer.o Game-SRC/Timer.c

${OBJECTDIR}/Game-SRC/Wait.o: Game-SRC/Wait.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Wait.o Game-SRC/Wait.c

${OBJECTDIR}/Game-SRC/Window.o: Game-SRC/Window.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/Window.o Game-SRC/Window.c

${OBJECTDIR}/Game-SRC/main.o: Game-SRC/main.c
	${MKDIR} -p ${OBJECTDIR}/Game-SRC
	${RM} "$@.d"
	$(COMPILE.c) -O2 -IGameResources/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Game-SRC/main.o Game-SRC/main.c

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
