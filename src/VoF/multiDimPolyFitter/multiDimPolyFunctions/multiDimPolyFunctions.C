/*---------------------------------------------------------------------------*\
            Copyright (c) 2017-2019, German Aerospace Center (DLR)
-------------------------------------------------------------------------------
License
    This file is part of the VoFLibrary source code library, which is an 
	unofficial extension to OpenFOAM.

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

#include "multiDimPolyFunctions.H"


namespace Foam
{
    defineTypeNameAndDebug(multiDimPolyFunctions, 0);
    defineRunTimeSelectionTable(multiDimPolyFunctions, word);
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

Foam::autoPtr<Foam::multiDimPolyFunctions> Foam::multiDimPolyFunctions::New
(
    const word& multiDimPolyFunctionsType,
    const Vector<label> dirs
)
{
    wordConstructorTable::iterator cstrIter =
        wordConstructorTablePtr_->find(multiDimPolyFunctionsType);

    if (!cstrIter.found())
    {
        FatalErrorInFunction
            << "Unknown multiDimPolyFunctions type " << multiDimPolyFunctionsType
            << endl << endl
            << "Valid multiDimPolyFunctions types : " << endl
            << wordConstructorTablePtr_->sortedToc()
            << exit(FatalError);
    }

    return autoPtr<multiDimPolyFunctions>(cstrIter()( dirs));
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::multiDimPolyFunctions::multiDimPolyFunctions(const Vector<label> dirs)
: 
nTerms_(-1),
coeffs_(scalarField(0)),
geomDir_(dirs),
geomCorrection_(pos0(dirs.x()),pos0(dirs.y()),pos0(dirs.z())),
termValues_(0)
{

}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::multiDimPolyFunctions::~multiDimPolyFunctions()
{}
