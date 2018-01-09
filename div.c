#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

int main(int argc, char **argv)
{
  volatile struct timeval timeout;
  volatile uint64_t usecs2 = 123456789;
  int i;
  for (i = 0; i < 10*1000*1000; i++)
  {
    uint64_t usecs = usecs2;
    timeout.tv_sec = usecs / (1000 * 1000);
    timeout.tv_usec = usecs - timeout.tv_sec * (1000ULL * 1000ULL);
  }
  printf("%lld %lld\n", (long long)timeout.tv_sec, (long long)timeout.tv_usec);
  return 0;
}
