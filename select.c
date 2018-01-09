#include <sys/select.h>
#include <stddef.h>

int main(int argc, char **argv)
{
  fd_set empty, set;
  int i;
  struct timeval zero = {};
  FD_ZERO(&empty);
  for (i = 0; i < 10*1000*1000; i++)
  {
    set = empty;
    select(1, &set, NULL, NULL, &zero);
  }
  return 0;
}
