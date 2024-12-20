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
    // SHA1 = d413ae4eb37da0f5e89b06fb6f743efd3c8b9172
    //
    // unique function name that can be checked if the correct library version
    // has been loaded
    void timeDependentAlpha2_d413ae4eb37da0f5e89b06fb6f743efd3c8b9172(bool load)
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
    fvPatchScalarField,
    timeDependentAlpha2FixedValueFvPatchScalarField
);


const char* const timeDependentAlpha2FixedValueFvPatchScalarField::SHA1sum =
    "d413ae4eb37da0f5e89b06fb6f743efd3c8b9172";


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

timeDependentAlpha2FixedValueFvPatchScalarField::
timeDependentAlpha2FixedValueFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const dictionary& dict
)
:
    fixedValueFvPatchField<scalar>(p, iF, dict)
{
    if (false)
    {
        Info<<"construct timeDependentAlpha2 sha1: d413ae4eb37da0f5e89b06fb6f743efd3c8b9172"
            " from patch/dictionary\n";
    }
}


timeDependentAlpha2FixedValueFvPatchScalarField::
timeDependentAlpha2FixedValueFvPatchScalarField
(
    const timeDependentAlpha2FixedValueFvPatchScalarField& ptf,
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const fieldMapper& mapper
)
:
    fixedValueFvPatchField<scalar>(ptf, p, iF, mapper)
{
    if (false)
    {
        Info<<"construct timeDependentAlpha2 sha1: d413ae4eb37da0f5e89b06fb6f743efd3c8b9172"
            " from patch/DimensionedField/mapper\n";
    }
}


timeDependentAlpha2FixedValueFvPatchScalarField::
timeDependentAlpha2FixedValueFvPatchScalarField
(
    const timeDependentAlpha2FixedValueFvPatchScalarField& ptf,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchField<scalar>(ptf, iF)
{
    if (false)
    {
        Info<<"construct timeDependentAlpha2 sha1: d413ae4eb37da0f5e89b06fb6f743efd3c8b9172 "
            "as copy/DimensionedField\n";
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

timeDependentAlpha2FixedValueFvPatchScalarField::
~timeDependentAlpha2FixedValueFvPatchScalarField()
{
    if (false)
    {
        Info<<"destroy timeDependentAlpha2 sha1: d413ae4eb37da0f5e89b06fb6f743efd3c8b9172\n";
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void timeDependentAlpha2FixedValueFvPatchScalarField::updateCoeffs()
{
    if (this->updated())
    {
        return;
    }

    if (false)
    {
        Info<<"updateCoeffs timeDependentAlpha2 sha1: d413ae4eb37da0f5e89b06fb6f743efd3c8b9172\n";
    }

//{{{ begin code
    #line 31 "/home/OpenFOAM_PISA/OpenPDAC-12/run/ASU_Flume_Modeling/2particleCase3D/0/alpha.particles2/boundaryField/inlet"
scalar t = this->db().time().value();
        scalarField& field = *this;

        // Set alpha value based on time
        if (t >= 0.5 && t <= 1.0)
        {
            field = scalar(0.3);  // Set alpha value to 0.3
        }
        else
        {
            field = scalar(0.0);  // Set alpha value to 0.0
        }
//}}} end code

    this->fixedValueFvPatchField<scalar>::updateCoeffs();
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //

