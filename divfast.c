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
    if (sizeof(size_t) < 8) {
      if (usecs <= UINT32_MAX) {
        timeout.tv_sec = ((uint32_t)usecs) / (1000 * 1000);
        timeout.tv_usec = usecs - timeout.tv_sec * (1000ULL * 1000ULL);
      } else {
        timeout.tv_sec = usecs / (1000 * 1000);
        timeout.tv_usec = usecs - timeout.tv_sec * (1000ULL * 1000ULL);
      }
    } else {
      timeout.tv_sec = usecs / (1000 * 1000);
      timeout.tv_usec = usecs - timeout.tv_sec * (1000ULL * 1000ULL);
    }
  }
  printf("%lld %lld\n", (long long)timeout.tv_sec, (long long)timeout.tv_usec);
  return 0;
}
