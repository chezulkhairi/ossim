//*******************************************************************
//
// License:  See top level LICENSE.txt file.
//
//*************************************************************************
// $Id$

#ifndef ossimUtility_HEADER
#define ossimUtility_HEADER

#include <ossim/base/ossimObjectFactory.h>
#include <ossim/base/ossimFactoryListInterface.h>
#include <ossim/util/ossimUtilityFactoryBase.h>
#include <ossim/util/ossimUtilityFactoryBase.h>
#include <map>
#include <string>

class OSSIMDLLEXPORT ossimUtilityManager : public ossimUtilityFactory,
                                           public ossimFactoryListInterface<ossimUtilityFactory, ossimUtility>
{
public:
   ossimUtilityManager();
   ~ossimUtilityManager();

   static ossimUtilityManager* instance();

   /**
    * Initializes the utility factory. Returns TRUE if successful.
    * @note Throws ossimException on error.
    */
   virtual bool initialize();

   /**
    * Returns map of available utilities along with descriptions as <name, decription> pairs.
    */
   void getCapabilities(std::map<std::string, std::string>& capabilities);

   virtual ossimUtility* createUtility(const ossimString& typeName) const;
   virtual ossimUtility* createUtility(const ossimKeywordlist& kwl, const char* prefix=0) const;

   virtual ossimString getClassName() const { return "ossimUtilityManager"; }

private:
   static ossimUtilityManager* m_instance;
};

#endif
