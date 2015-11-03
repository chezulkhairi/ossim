//----------------------------------------------------------------------------
//
// File: ossimHillshadeUtil.h
// 
// License:  LGPL
// 
// See LICENSE.txt file in the top level directory for more details.
//
// Author:  David Burken
//
// Description:
// 
// Utility class to for chipping out images. , orthorectifying imagery with an
// added slant toward doing digital elevation model(DEM) operations.
// 
//----------------------------------------------------------------------------
// $Id: ossimHillshadeUtil.h 23423 2015-07-13 19:07:38Z dburken $

#ifndef ossimHillshadeUtil_HEADER
#define ossimHillshadeUtil_HEADER 1

#include <ossim/base/ossimConstants.h>
#include <ossim/base/ossimReferenced.h>
#include <ossim/base/ossimRefPtr.h>
#include <ossim/imaging/ossimImageSource.h>
#include <ossim/imaging/ossimSingleImageChain.h>
#include <ossim/imaging/ossimImageFileWriter.h>
#include <ossim/projection/ossimMapProjection.h>
#include <ossim/util/ossimChipProcUtil.h>

// Forward class declarations:
class ossimArgumentParser;
class ossimDpt;
class ossimFilename;
class ossimGeoPolygon;
class ossimGpt;
class ossimImageData;
class ossimImageFileWriter;
class ossimImageGeometry;
class ossimImageViewAffineTransform;
class ossimIrect;
class ossimKeywordlist;

/**
 * @brief ossimHillshadeUtil class.
 *
 * This is a utility class to orthorectify imagery with an added slant toward
 * doing digital elevation model(DEM) operations.
 *
 * See the ossim-dem application for a code usage example.
 *
 * @note Almost all methods use throw for stack unwinding.  This is not in
 * method declarations to alleviate build errors on windows.  Sorry...
 *
 * @note "bumpshade" and "hillshade" intermixed throughout.  The class to do
 * a hillshade is the ossimBumpShadeTileSource.
 */
class OSSIM_DLL ossimHillshadeUtil : public ossimChipProcUtil
{
public:
   /** default constructor */
   ossimHillshadeUtil();

   /** virtual destructor */
   virtual ~ossimHillshadeUtil();

   virtual void setUsage(ossimArgumentParser& ap);

   /**
    * @brief Initial method to be ran prior to execute.
    * @param ap Arg parser to initialize from.
    * @note Throws ossimException on error.
    * @note A throw with an error message of "usage" is used to get out when
    * a usage is printed.
    */
   virtual bool initialize(ossimArgumentParser& ap);

protected:

   virtual void initializeChain();

   /** @brief Hidden from use copy constructor. */
   ossimHillshadeUtil( const ossimHillshadeUtil& obj );

   /** @brief Hidden from use assignment operator. */
   const ossimHillshadeUtil& operator=( const ossimHillshadeUtil& rhs );

};

#endif /* #ifndef ossimHillshadeUtil_HEADER */
