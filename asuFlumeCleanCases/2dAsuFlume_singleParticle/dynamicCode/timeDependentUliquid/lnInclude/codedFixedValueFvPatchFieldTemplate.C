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
    // SHA1 = eb3a1e91695fa9a503cd64628e18a5bd557ed492
    //
    // unique function name that can be checked if the correct library version
    // has been loaded
    void timeDependentUliquid_eb3a1e91695fa9a503cd64628e18a5bd557ed492(bool load)
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
    timeDependentUliquidFixedValueFvPatchVectorField
);


const char* const timeDependentUliquidFixedValueFvPatchVectorField::SHA1sum =
    "eb3a1e91695fa9a503cd64628e18a5bd557ed492";


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

timeDependentUliquidFixedValueFvPatchVectorField::
timeDependentUliquidFixedValueFvPatchVectorField
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
        Info<<"construct timeDependentUliquid sha1: eb3a1e91695fa9a503cd64628e18a5bd557ed492"
            " from patch/dictionary\n";
    }
}


timeDependentUliquidFixedValueFvPatchVectorField::
timeDependentUliquidFixedValueFvPatchVectorField
(
    const timeDependentUliquidFixedValueFvPatchVectorField& ptf,
    const fvPatch& p,
    const DimensionedField<vector, volMesh>& iF,
    const fieldMapper& mapper
)
:
    fixedValueFvPatchField<vector>(ptf, p, iF, mapper)
{
    if (false)
    {
        Info<<"construct timeDependentUliquid sha1: eb3a1e91695fa9a503cd64628e18a5bd557ed492"
            " from patch/DimensionedField/mapper\n";
    }
}


timeDependentUliquidFixedValueFvPatchVectorField::
timeDependentUliquidFixedValueFvPatchVectorField
(
    const timeDependentUliquidFixedValueFvPatchVectorField& ptf,
    const DimensionedField<vector, volMesh>& iF
)
:
    fixedValueFvPatchField<vector>(ptf, iF)
{
    if (false)
    {
        Info<<"construct timeDependentUliquid sha1: eb3a1e91695fa9a503cd64628e18a5bd557ed492 "
            "as copy/DimensionedField\n";
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

timeDependentUliquidFixedValueFvPatchVectorField::
~timeDependentUliquidFixedValueFvPatchVectorField()
{
    if (false)
    {
        Info<<"destroy timeDependentUliquid sha1: eb3a1e91695fa9a503cd64628e18a5bd557ed492\n";
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void timeDependentUliquidFixedValueFvPatchVectorField::updateCoeffs()
{
    if (this->updated())
    {
        return;
    }

    if (false)
    {
        Info<<"updateCoeffs timeDependentUliquid sha1: eb3a1e91695fa9a503cd64628e18a5bd557ed492\n";
    }

//{{{ begin code
    #line 54 "/home/OpenFOAM_PISA/OpenPDAC-12/run/ASU_Flume_Modeling/smallTankSingleParticlesWithInletConditions2D_run2/0/U.liquid/boundaryField/inlet"
scalar t = this->db().time().value();
	if (((t >= 0.0) && (t <= 4.0)))
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

