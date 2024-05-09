#pragma once
#include <stdint.h>
#include <time.h>

namespace DRand {
  // recommended 10/10
  unsigned int DRand32() {
      static unsigned long long seed = (unsigned long long)time(NULL);
  
      static const unsigned long long a = 43252145235;
      static const unsigned long long b = 134163156627;
  
      seed ^= a * (seed >> 2) + b * seed;
  
      return static_cast <unsigned int> (seed % UINT32_MAX);
  }
  
  // recommended 10/10
  unsigned int DRand32x() {
      static unsigned long long seed = static_cast <unsigned long long>(time(NULL));
      static unsigned long long special_seed = 0;

      static const unsigned long long a = 43252145235;
      static const unsigned long long b = 134163156627;

      special_seed ^= seed + b;
      seed ^= a * (seed >> 32) + special_seed;

      return static_cast <unsigned int> (seed % UINT32_MAX);
  }

  // recommended 8/10
  unsigned int DRand32o() {
      static unsigned long long seed = static_cast <unsigned long long>(time(NULL));

      static const unsigned long long a = 43252145235;
      static const unsigned long long b = 134163156627;

      seed ^= (seed >> 2) * seed + a;

      return static_cast <unsigned int> (seed % UINT16_MAX);
  }

  // recommended 8/10
  unsigned short DRand16() {
      static unsigned int seed = (unsigned int)time(NULL);

      static const unsigned int a = 2932355;
      static const unsigned int b = 5456263;

      seed ^= a * (seed >> 2) + b * seed;

      return static_cast <unsigned short> (seed % UINT16_MAX);
  }

  // recommended 10/10
  unsigned short DRand16x() {
      static unsigned int seed = (unsigned int)time(NULL);
      static unsigned int special_seed = 0;
  
      static const unsigned int a = 2932355;
      static const unsigned int b = 5456263;
  
      special_seed ^= seed + b;
      seed ^= a * (seed >> 16) + special_seed;
  
      return static_cast <unsigned short> (seed % UINT16_MAX);
  }

  // not recommended 6/10
  unsigned short DRand16o() {
      static unsigned int seed = static_cast <unsigned short> (time(NULL));
      static const unsigned int a = 2932355;
           
      seed ^= (seed >> 2) * seed + a;

      return static_cast <unsigned short> (seed % UINT16_MAX);
  }
}
