#include <stdio.h>
#include <time.h>


int collatz_stopping_time(unsigned int n) {

  int count = 0;
  int seqnumber = n;


  while(n != 1)
  {
    if(n % 2 == 0)
    {
      n /= 2;
    }
    else
    {
      n = (3 * n) + 1;
    }
    count++;
  }


  //printf ("%d has a stopping time of %d\n", seqnumber, count);

  return count;
}

int main(void)
{
  int maxstoppingtime = 0;
  int maxseqnumber = 0;
  int maxrationumber = 0;

  float maxstoppingratio = 0.0;
  float stoppingratio = 0.0;


  for(int i = 1; i <= 100000; i++)
  {
    int stoppingtime = collatz_stopping_time(i);
    stoppingratio = (float)stoppingtime/(float)i;

    //printf ("[CUR_RATIO_IS] %d has a current ratio of %2lf\n", i, stoppingratio);

    if(maxstoppingtime < stoppingtime)
    {
      maxstoppingtime = stoppingtime;
      maxseqnumber = i;

     //printf ("[CUR_MAX_STOPPING_TIME] %d has a stopping time of %d\n", maxseqnumber, maxstoppingtime);
    }

    if(maxstoppingratio < stoppingratio)
    {
      maxstoppingratio = stoppingratio;
      maxrationumber = i;

    //printf ("[CUR_MAX_RATIO] %d has a max ratio of %2lf\n", maxrationumber, maxstoppingratio);
    }
  }

  printf ("[MAX_STOPPING TIME] %d has a stopping time of %d\n", maxseqnumber, maxstoppingtime);

  printf ("[MAX_RATIO] %d has a max ratio of %2lf\n",  maxrationumber, maxstoppingratio);
}




