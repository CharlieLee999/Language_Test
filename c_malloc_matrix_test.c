
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

double get_wall_time();

void main( int argc, char *argv[] )
{
  int N = atoi( argv[1] );
  
  //  int a[1000][1000] = {0};
  int *A = (int *) malloc( N * N * sizeof(int) );
  int *x = (int *) malloc( N * sizeof(int) );
  int *y = (int *) malloc( N * sizeof(int) );

  int i, j;
  double s_t = get_wall_time();

  for(i=0; i<N; i++)
    for(j=0; j<N; j++)
      {
	y[i] += A[i + j * N] * x[j];
      }
  
  double e_t = get_wall_time();
  printf("Raw*vector's running time of A[%d*%d] is %g ", N, N, e_t-s_t);

  double s_t_new = get_wall_time();
  for( i=0; i<N; i++)
    for( j=0; j<N; j++)
      y[i] += A[i*N + j] * x[j];
  double e_t_new = get_wall_time();
  printf("column*vector's running time of A[%d*%d] is %g ", N, N, e_t_new - s_t_new);
  
}

double get_wall_time(){
  struct timeval time;
  if (gettimeofday(&time,NULL)){
    //  Handle error
    return 0;
  }
  return (double)time.tv_sec + (double)time.tv_usec * .000001;
}
