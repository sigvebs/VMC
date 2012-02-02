#include <mpi.h>
#include "lib.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

// Begin main
int main(){

  // MPI
  int numproc, my_rank;
  MPI_Init( NULL, NULL );
  MPI_Comm_size( MPI_COMM_WORLD, &numproc );
  MPI_Comm_rank( MPI_COMM_WORLD, &my_rank );
  idum = -1*my_rank;


  MPI_Finalize();
  return 0;
}
