//*******************************************************************
//
// OSSIM
//
// License:  See top level LICENSE.txt file.
// 
//*******************************************************************
// $Id$

#ifndef ossimCoreUtilityFactory_HEADER
#define ossimCoreUtilityFactory_HEADER 1

#include <ossim/util/ossimUtilityFactory.h>
#include <ossim/base/ossimString.h>

class ossimCoreUtility;
class ossimFilename;
class ossimKeywordlist;

class OSSIMDLLEXPORT ossimUtilityFactory : public ossimUtilityFactoryBase
{
public:
   virtual ~ossimUtilityFactory();
   static ossimUtilityFactory* instance();

   /**
    * @param openOverview If true image handler will attempt to open overview.
    * default = true
    */
   virtual ossimCoreUtility* open(const ossimFilename& fileName,
                                   bool openOverview=true)const;
   virtual ossimCoreUtility* open(const ossimKeywordlist& kwl,
                                   const char* prefix=0)const;

   /**
    * @brief Open overview that takes a file name.
    * 
    * @param file File to open.
    * 
    * @return ossimRefPtr to image handler on success or null on failure.
    */
   virtual ossimRefPtr<ossimCoreUtility> openOverview(
      const ossimFilename& file ) const;
   
   virtual ossimObject* createObject(const ossimString& typeName)const;
   
   /*!
    * Creates and object given a keyword list.
    */
   virtual ossimObject* createObject(const ossimKeywordlist& kwl,
                                     const char* prefix=0)const;
   
   /*!
    * This should return the type name of all objects in all factories.
    * This is the name used to construct the objects dynamially and this
    * name must be unique.
    */
   virtual void getTypeNameList(std::vector<ossimString>& typeList)const;

protected:

   /**
    * @brief Open method that looks at extension e.g. "tif", "jpg" to select
    * class to open.
    *
    * This is to be called by standard open before just going down the list
    * of classes the brute force hard way.
    * 
    * @param fileName The filename to open.
    * 
    * @return Pointer to image handler or null if nothing opened.
    */
//   virtual ossimCoreUtility* openFromExtension(
//      const ossimFilename& fileName) const;
  
   ossimUtilityFactory(){}
   ossimUtilityFactory(const ossimUtilityFactory&){}
   void operator = (const ossimUtilityFactory&){}

   static ossimUtilityFactory* theInstance;

TYPE_DATA
};

#endif
