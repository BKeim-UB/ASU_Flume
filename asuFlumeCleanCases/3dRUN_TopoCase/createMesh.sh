foamCleanCase

blockMesh > log.blockMesh

# remove previous 0 folder and copy not-initialized fields
#rm -rf 0
#cp -r org.0 0


python3 createTopo.py 

decomposePar

# Grid deformation
mpirun -np 6 topoGridNew -parallel > log.topoGrid

mpirun -np 6 checkMesh -parallel -allGeometry -allTopology -writeSets > log.checkMesh

reconstructPar -withZero

#cp -r 0/polyMesh constant/
#rm -rf 0/polyMesh

# checkMesh -allGeometry -allTopology -writeSets
