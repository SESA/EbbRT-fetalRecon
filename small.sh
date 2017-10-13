#!/bin/sh
set -x
export THREADS=${1:-1}
export ITERS=${2:-1}
export NODES=${3:-1}
export RUN_DEBUG=${DEBUG:-0}

./build/reconstruction -o 3TStackReconstruction.nii -i data/masked_stack-1.nii data/masked_stack-2.nii data/masked_stack-3.nii  data/masked_stack-4.nii --disableBiasCorrection --useAutoTemplate --useSINCPSF --resolution 2.0 --debug $RUN_DEBUG --numThreads $THREADS --useCPU --iterations $ITERS --numNodes $NODES
