CC = mpicxx -D MPICH_IGNORE_CXX_SEEK

PROG = vmc

# Making the executable file
${PROG} :	${PROG}.o 
		${CC}  ${PROG}.o  -o ${PROG}

# Creating the object file
${PROG}.o :	${PROG}.cpp 
		${CC} -c ${PROG}.cpp

# Compiling and running the application
run:    ${PROG}
	./${PROG} 
