/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) YEAR OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "codedFixedValueFvPatchFieldTemplate.H"
#include "addToRunTimeSelectionTable.H"
#include "fieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"
#include "read.H"

//{{{ begin codeInclude

//}}} end codeInclude


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

extern "C"
{
    // dynamicCode:
    // SHA1 = 2820de8630da10ab96a6f3be598692f4fc25fc13
    //
    // unique function name that can be checked if the correct library version
    // has been loaded
    void timeDependentUparticles1_2820de8630da10ab96a6f3be598692f4fc25fc13(bool load)
    {
        if (load)
        {
            // code that can be explicitly executed after loading
        }
        else
        {
            // code that can be explicitly executed before unloading
        }
    }
}

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

makeRemovablePatchTypeField
(
    fvPatchVectorField,
    timeDependentUparticles1FixedValueFvPatchVectorField
);


const char* const timeDependentUparticles1FixedValueFvPatchVectorField::SHA1sum =
    "2820de8630da10ab96a6f3be598692f4fc25fc13";


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

timeDependentUparticles1FixedValueFvPatchVectorField::
timeDependentUparticles1FixedValueFvPatchVectorField
(
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const dictionary& dict
)
:
    fixedValueFvPatchField<vector>(p, iF, dict)
{
    if (false)
    {
        Info<<"construct timeDependentUparticles1 sha1: 2820de8630da10ab96a6f3be598692f4fc25fc13"
            " from patch/dictionary\n";
    }
}


timeDependentUparticles1FixedValueFvPatchVectorField::
timeDependentUparticles1FixedValueFvPatchVectorField
(
    const timeDependentUparticles1FixedValueFvPatchVectorField& ptf,
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const fieldMapper& mapper
)
:
    fixedValueFvPatchField<vector>(ptf, p, iF, mapper)
{
    if (false)
    {
        Info<<"construct timeDependentUparticles1 sha1: 2820de8630da10ab96a6f3be598692f4fc25fc13"
            " from patch/DimensionedField/mapper\n";
    }
}


timeDependentUparticles1FixedValueFvPatchVectorField::
timeDependentUparticles1FixedValueFvPatchVectorField
(
    const timeDependentUparticles1FixedValueFvPatchVectorField& ptf,
    const DimensionedField<vector, volMesh>& iF
)
:
    fixedValueFvPatchField<vector>(ptf, iF)
{
    if (false)
    {
        Info<<"construct timeDependentUparticles1 sha1: 2820de8630da10ab96a6f3be598692f4fc25fc13 "
            "as copy/DimensionedField\n";
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

timeDependentUparticles1FixedValueFvPatchVectorField::
~timeDependentUparticles1FixedValueFvPatchVectorField()
{
    if (false)
    {
        Info<<"destroy timeDependentUparticles1 sha1: 2820de8630da10ab96a6f3be598692f4fc25fc13\n";
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void timeDependentUparticles1FixedValueFvPatchVectorField::updateCoeffs()
{
    if (this->updated())
    {
        return;
    }

    if (false)
    {
        Info<<"updateCoeffs timeDependentUparticles1 sha1: 2820de8630da10ab96a6f3be598692f4fc25fc13\n";
    }

//{{{ begin code
    #line 54 "/home/OpenFOAM_PISA/OpenPDAC-12/run/ASU_Flume_Modeling/smallTankSingleParticlesWithInletConditions2D_run2/0/U.particles1/boundaryField/inlet"
scalar t = this->db().time().value();
       if ((t >= 0.0) && (t <= 4.0))
	  {
            vectorField& field = *this;
            field = vector(0.15, 0.0, 0.0);  // Set velocity to (1.0, 0.0, 0.0)
	  }
        else
	  {
            vectorField& field = *this;
            field = vector(0.0, 0.0, 0.0);  // Set velocity to zero
	  }
//}}} end code

    this->fixedValueFvPatchField<vector>::updateCoeffs();
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //

