rm -rf processor*
decomposePar
mpirun -np 6 foamRun -parallel > log.foamRun &
# reconstructPar -newTimes -fields '(U.liquid alpha.particles1 alpha.particles2)' -lagrangianFields '(none)'
