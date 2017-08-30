// ===================================================================================
// Copyright ScalFmm 2016 INRIA, Olivier Coulaud, Bérenger Bramas,
// Matthias Messner olivier.coulaud@inria.fr, berenger.bramas@inria.fr
// This software is a computer program whose purpose is to compute the
// FMM.
//
// This software is governed by the CeCILL-C and LGPL licenses and
// abiding by the rules of distribution of free software.
// An extension to the license is given to allow static linking of scalfmm
// inside a proprietary application (no matter its license).
// See the main license file for more details.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public and CeCILL-C Licenses for more details.
// "http://www.cecill.info".
// "http://www.gnu.org/licenses".
// ===================================================================================
#ifndef FABSTRACTCELL_HPP
#define FABSTRACTCELL_HPP


#include "../Utils/FGlobal.hpp"

/**
* @author Berenger Bramas (berenger.bramas@inria.fr)
* @class FAbstractCell
* @brief This class define the methods that every cell class has to implement to be insertable in the tree.
*
* In fact FOctree & FFmmAlgorithm need this functions to be implemented.
* But you cannot use this interface with the extension (as an example :
* because the compiler will faill to know if getMortonIndex is coming
* from this interface or from the extension)
*
* You can look to FBasicCell to have an idea of implementation.
*/
class FAbstractCell{
public:	
    /** Default destructor */
    virtual ~FAbstractCell(){
    }

    /**
     * Must be implemented by each user Cell class
     * @return the position of the current cell
     */
    virtual MortonIndex getMortonIndex() const = 0;


    /**
        * Must be implemented by each user Cell class
        * @param inIndex the position of the current cell
        */
    virtual void setMortonIndex(const MortonIndex inIndex) = 0;

    /**
        * Must be implemented by each user Cell class
        * @param inPosition the position of the current cell
        */
    virtual void setPosition(const FPoint<FReal>& inPosition) = 0;

    /**
    * Must be implemented by each user Cell class
    * @return the position in the tree coordinate
    */
    virtual const FTreeCoordinate& getCoordinate() const = 0;

    /**
    * Must be implemented by each user Cell class
    * @param the position in the tree coordinate
    */
    virtual void setCoordinate(const long inX, const long inY, const long inZ) = 0;

    /** Because the system can run in Tsm mode
          * a cell has to express if it has sources
          * @return true if there are sources particles inside
          */
    virtual bool hasSrcChild() const = 0;

    /** Because the system can run in Tsm mode
          * a cell has to express if it has targets
          * @return true if there are targets particles inside
          */
    virtual bool hasTargetsChild() const = 0;

    /**
          * This function make the cell containing sources
          */
    virtual void setSrcChildTrue() = 0;

    /**
          * This function make the cell containing targets
          */
    virtual void setTargetsChildTrue() = 0;

    /**
          * This function make the cell containing targets
          */
    virtual void resetToInitialState() = 0;
};


#endif //FABSTRACTCELL_HPP


