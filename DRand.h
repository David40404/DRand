#pragma once
#include <stdint.h>
#include <time.h>

namespace DRand {
    static const unsigned char pseudo_random_table[256] = {
      75, 96, 243, 133, 58, 144, 175, 156, 166, 188, 231, 154, 190, 67, 216, 117,
      19, 108, 48, 39, 101, 13, 180, 238, 46, 88, 204, 4, 27, 40, 173, 187, 240,
      78, 181, 20, 55, 225, 202, 152, 66, 157, 227, 226, 250, 140, 62, 44, 115, 251,
      229, 209, 148, 163, 128, 218, 184, 203, 114, 17, 137, 232, 95, 53, 79, 92, 14,
      206, 23, 196, 12, 205, 200, 221, 252, 127, 71, 246, 105, 228, 149, 97, 136,
      119, 42, 210, 89, 165, 9, 211, 24, 186, 151, 74, 18, 118, 147, 65, 124, 25, 217,
      161, 239, 212, 31, 85, 237, 242, 36, 104, 34, 185, 172, 201, 81, 176, 254, 22,
      63, 167, 41, 64, 255, 69, 223, 38, 15, 241, 26, 87, 109, 194, 179, 56, 5, 193,
      121, 106, 174, 138, 141, 93, 2, 236, 77, 111, 215, 199, 61, 249, 43, 33, 247,
      116, 57, 159, 224, 245, 153, 233, 192, 219, 90, 134, 164, 112, 207, 191, 91,
      125, 155, 98, 213, 244, 139, 113, 189, 235, 32, 8, 178, 182, 16, 183, 73, 253,
      158, 150, 168, 60, 30, 131, 37, 3, 248, 99, 76, 10, 130, 142, 72, 7, 86, 132,
      80, 82, 84, 68, 214, 146, 52, 70, 49, 28, 94, 110, 59, 162, 129, 208, 1, 169,
      29, 107, 220, 171, 54, 170, 197, 256, 21, 122, 11, 102, 126, 6, 123, 222, 0,
      50, 120, 234, 103, 83, 195, 143, 51, 45, 135, 198, 177, 160, 35, 47, 230, 100
  };

  // recomended 8/10
  unsigned char DRand8() {
      static unsigned short seed = (unsigned short)time(NULL);
      static const unsigned short a = 14556;
      static const unsigned short b = 25689;
  
      seed = a ^ seed + b;
  
      return pseudo_random_table[seed % UINT8_MAX];
  }

  //recomended 6/10
  inline unsigned char DRand8f() {
		static unsigned char seed = (unsigned char)time(NULL);
		seed = ((seed + 1) ^ 156) & 0xFF;
		return pseudo_random_table[seed];
	}

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
