/* Taken from pq-crystals/kyber reference implementation:
 * https://github.com/pq-crystals/kyber
 */

#ifndef CPUCYCLES_H
#define CPUCYCLES_H

#include <stdint.h>

#if defined(__APPLE__) && (defined(__aarch64__) || defined(__arm64__))
#include <mach/mach_time.h>
#endif

#if defined(__aarch64__) || defined(__arm64__)

static inline uint64_t cpucycles(void) {
#if defined(__APPLE__)
  return mach_absolute_time();
#else
  uint64_t result;

  __asm__ volatile ("mrs %0, cntvct_el0" : "=r" (result));
  return result;
#endif
}

#elif defined(USE_RDPMC)  /* Needs echo 2 > /sys/devices/cpu/rdpmc */

static inline uint64_t cpucycles(void) {
  const uint32_t ecx = (1U << 30) + 1;
  uint64_t result;

  __asm__ volatile ("rdpmc; shlq $32,%%rdx; orq %%rdx,%%rax"
    : "=a" (result) : "c" (ecx) : "rdx");

  return result;
}

#else

static inline uint64_t cpucycles(void) {
  uint64_t result;

  __asm__ volatile ("rdtsc; shlq $32,%%rdx; orq %%rdx,%%rax"
    : "=a" (result) : : "%rdx");

  return result;
}

#endif

#endif /* CPUCYCLES_H */
