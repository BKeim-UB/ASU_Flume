#!/bin/bash -l
#
#SBATCH --cluster=ub-hpc
#SBATCH --partition=general-compute
#SBATCH --qos=general-compute
#SBATCH --time=06:00:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=24
#SBATCH --mem=10000
#SBATCH --job-name="Reconstruct2point5mm"
#SBATCH --output=reconstructionLog.foamRun
#SBATCH --mail-user=bykeim@buffalo.edu
#SBATCH --mail-type=all

module load gcc/11.2.0
module load openmpi/4.1.1
module load trilinos/13.4.1
module load scotch/7.0.2

#export LD_LIBRARY_PATH=/cvmfs/soft.ccr.buffalo.edu/versions/2023.01/easybuild/modules/avx512/Compiler/gcc/11.2.0/openmpi/4.1.1/lib:$LD_LIBRARY_PATH
#export OMPI_MCA_plm=slurm

#srun -n 4 ../../mfixsolver_dmp -f vortex_shedding_fld_2d.mfx NODESI=4 NODESJ=1 NODESK=1
#decomposePar



# srun -n 10 foamRun -parall
#reconstructPar -newTimes -fields "(U.particles1 U.liquid alpha.particles1 alpha.particles2 rho p)" -noLagrangian

rm -r processor*



# echo "hello from node: "`/usr/bin/uname -n`"
# echo “Hello world from node: “`/usr/bin/uname –n`”
