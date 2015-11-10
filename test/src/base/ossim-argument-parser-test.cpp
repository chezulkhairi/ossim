//----------------------------------------------------------------------------
//
// License:  LGPL
// 
// See LICENSE.txt file in the top level directory for more details.
//
// Author:  David Burken
//
// Description: Test code for ossimGpt class.
// 
//----------------------------------------------------------------------------
// $Id: ossim-gpt-test.cpp 19751 2011-06-13 15:13:07Z dburken $

#include <ossim/base/ossimArgumentParser.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

template <typename T, size_t N> size_t SizeOfArray( const T(&)[ N ] ) { return N; }

void fail()
{
   cout<<"\nFAILED ossimArgumentParser TEST"<<endl;
   exit(-1);
}

int main(int argc, char *argv[])
{
   // define alternate command line:
   char* test_argv[]  = { argv[0],
                          "-a", "A1",
                          "-b", "B1", "B2",
                          "-a", "A2",
                          "-c", "C1", "C2", "C3",
                          "arg1", "arg2" };
   int test_argc = SizeOfArray(test_argv);

   ossimArgumentParser ap (&test_argc, test_argv);

   std::string ts1;
   ossimArgumentParser::ossimParameter sp1(ts1);
   std::string ts2;
   ossimArgumentParser::ossimParameter sp2(ts2);

   if ( !ap.read("-a", sp1) || (ts1 != "A1"))
      fail();

   if ( !ap.read("-a", sp1) || (ts1 != "A2"))
      fail();

   if ( !ap.read("-b", sp1, sp2) || (ts1 != "B1") || (ts2 != "B2"))
      fail();

   vector<ossimArgumentParser::ossimParameter> param_list;
   if ( !ap.read("-c", param_list) || (param_list.size() != 3) ||
         (param_list[0].getValue() != "C1") ||
         (param_list[1].getValue() != "C2") ||
         (param_list[2].getValue() != "C3"))
   {
      fail();
   }

   if (( ap.argc() != 3 ) || (strcmp(ap[1], "arg1") != 0) || (strcmp(ap[2], "arg2") != 0))
      fail();

   cout<<"\nPASSED ossimArgumentParser TEST"<<endl;
   exit(0);
}
