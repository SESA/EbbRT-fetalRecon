#!/bin/sh
set -x
export THREADS=${1:-1}
export ITERS=${2:-1}
export NODES=${3:-1}
export RUN_DEBUG=${DEBUG:-0}

./build/reconstruction -o 3TReconstruction.nii -i data/14_3T_nody_001.nii data/10_3T_nody_001.nii data/21_3T_nody_001.nii data/23_3T_nody_001.nii -m data/mask_10_3T_brain_smooth.nii --disableBiasCorrection --useAutoTemplate --useSINCPSF --resolution 2.0 --debug $RUN_DEBUG --numThreads $THREADS --useCPU --iterations $ITERS --numNodes $NODES


