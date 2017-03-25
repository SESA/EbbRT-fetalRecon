//    Copyright Boston University SESA Group 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef UTILS_H
#define UTILS_H

#define PSF_SIZE 128

#define COEFF_INIT 0
#define GAUSSIAN_RECONSTRUCTION 1
#define SIMULATE_SLICES 2
#define INITIALIZE_ROBUST_STATISTICS 3
#define E_STEP_I 4
#define E_STEP_II 5
#define E_STEP_III 6
#define SCALE 7
#define SUPERRESOLUTION 8
#define M_STEP 9
#define RESTORE_SLICE_INTENSITIES 10
#define SCALE_VOLUME 11
#define SLICE_TO_VOLUME_REGISTRATION 12

#include <string>
#include <vector>

using namespace std;

typedef struct unsigned_three {
  unsigned int x, y, z;
} uint3;

struct POINT3D {
  short x;
  short y;
  short z;
  float value;

  template <typename Archive> void serialize(Archive& ar, 
      const unsigned int version) {
    ar & x & y & z & value;
  }  
};

struct SLICEINFO
{
  int x;        //pixel x
  int y;        //pixel y
  float value;  //value
};

typedef std::vector<POINT3D> VOXELCOEFFS;
typedef std::vector<std::vector<VOXELCOEFFS> > SLICECOEFFS;

// Struct for input arguments of reconstruction.cc
struct arguments {
  string outputName; 
  string maskName;
  string tFolder;
  string sFolder;

  vector<string> inputStacks;
  vector<string> inputTransformations;
  vector<double> thickness;
  vector<int> forceExcluded;

  int iterations; 
  int levels;
  int recIterationsFirst;
  int recIterationsLast;
  int numThreads;
  int numBackendNodes;
  int numFrontendCPUs;

  unsigned int numInputStacksTuner;
  unsigned int T1PackageSize;
  
  double sigma;
  double resolution;
  double averageValue;
  double delta;
  double lambda;
  double lastIterLambda;
  double smoothMask;
  double lowIntensityCutoff;

  bool globalBiasCorrection;
  bool intensityMatching;
  bool debug;
  bool disableBiasCorr;
};

// Initialization parameters
struct reconstructionParameters {
  bool globalBiasCorrection;
  bool adaptive;

  int sigmaBias;
  int numThreads;
  int start;
  int end;

  int directions[13][3];

  double step;
  double sigmaSCPU;
  double sigmaS2CPU;
  double mixSCPU;
  double mixCPU;
  double lowIntensityCutoff;
};

// CoeffInit() function parameters
struct coeffInitParameters {
  int stackFactor;
  int stackIndex;

  bool debug;

  double delta;
  double lambda;
  double alpha;
  double qualityFactor;
};

// EStep() function parameters
struct eStepParameters {
  double mCPU;
  double sigmaCPU;
  double meanSCPU;
  double meanS2CPU;
  double sigmaSCPU;
  double sigmaS2CPU;
  double mixSCPU;
  double mixCPU;
  double den;
};

struct eStepReturnParameters {
  double sum; 
  double den;
  double sum2;
  double den2; 
  double maxs; 
  double mins;
  double num;
};

// MStep() function parameters
struct mStepReturnParameters {
  double sigma;
  double mix;
  double num;
  double min; 
  double max; 
};

//ScaleVOlume() function parameters
struct scaleVolumeParameters {
  double num;
  double den;
};

#endif // end of UTILS_H
