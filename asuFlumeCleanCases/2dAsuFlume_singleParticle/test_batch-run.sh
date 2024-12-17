#!/bin/bash -l
#
#SBATCH --cluster=ub-hpc
#SBATCH --partition=general-compute
#SBATCH --qos=general-compute
#SBATCH --time=06:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=24
#SBATCH --ntasks=24
#SBATCH --mem=10000
#SBATCH --job-name="test_batch-run"
#SBATCH --output=5_seconds_3dtest.out
#SBATCH --mail-user=bykeim@buffalo.edu
#SBATCH --mail-type=all

module load gcc/11.2.0
module load openmpi/4.1.1
module load trilinos/13.4.1
module load scotch/7.0.2

#export LD_LIBRARY_PATH=/cvmfs/soft.ccr.buffalo.edu/versions/2023.01/easybuild/modules/avx512/Compiler/gcc/11.2.0/openmpi/4.1.1/lib:$LD_LIBRARY_PATH
#export OMPI_MCA_plm=slurm

#Let's start some work
#srun -n 4 ./mpi_hello

#srun -n 4 ../../mfixsolver_dmp -f vortex_shedding_fld_2d.mfx NODESI=4 NODESJ=1 NODESK=1
# decomposePar && sleep 60
# mpirun --mca btl vader,self -np 20 OpenPDAC -parallel
#echo "decomposed
#echo "running foamRun"

# Generate the time steps from 0.03 to 30 with a step of 0.01
times=()
for time in $(seq 5 5 30); do
    times+=($time)
done

fields="(alpha.particles1)"

# Launch the tasks in parallel
for time in "${times[@]}"; do
    srun reconstructPar -fields "$fields" -time "$time" -noLagrangian &
done

wait  # Ensure all processes finish

#srun -n 1 reconstructPar -fields '(U.particles1 alpha.particles1 U.liquid)' -newTimes
# reconstructPar -newTimes

# echo "hello from node: "`/usr/bin/uname -n`"
# echo “Hello world from node: “`/usr/bin/uname –n`”
