#ifndef ossimUtilityFactory_HEADER
#define ossimUtilityFactory_HEADER
#include <ossim/base/ossimObjectFactory.h>
#include <ossim/elevation/ossimElevationDatabase.h>

class ossimUtility;

class OSSIM_DLL ossimUtilityFactoryBase : public ossimObjectFactory
{
public:
   /**
    * Creates an object given a type name.
    */
   virtual ossimObject* createObject(const ossimString& typeName)const
   {
      return createUtility(typeName);
   }

   /**
    * Creates and object given a keyword list.
    */
   virtual ossimObject* createObject(const ossimKeywordlist& kwl,
                                     const char* prefix=0)const
   {
      return createUtility(kwl, prefix);
   }

   virtual ossimUtility* createUtility(const ossimString& typeName) const=0;
   virtual ossimUtility* createUtility(const ossimKeywordlist& kwl, const char* prefix=0) const=0;
};

#endif
