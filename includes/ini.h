/*
 * Copyright (C) Jefferson 2010 <web@jeffersongta.de> / <remis80@gmx.net>
 * 
 http://creativecommons.org/licenses/by/3.0/de/deed.en_US
 
  You are free:

    * to Share — to copy, distribute and transmit the work
    * to Remix — to adapt the work
    *

Under the following conditions:

    *

      Attribution — You must attribute the work in the manner specified by the author or licensor (but not in any way that suggests that they endorse you or your use of the work).

      Attribute this work:
      Information
      What does "Attribute this work" mean?
      The page you came from contained embedded licensing metadata, including how the creator wishes to be attributed for re-use. You can use the HTML here to cite the work. Doing so will also include metadata on your page so that others can find the original work as well.

With the understanding that:

    * Waiver — Any of the above conditions can be waived if you get permission from the copyright holder.
    * Public Domain — Where the work or any of its elements is in the public domain under applicable law, that status is in no way affected by the license.
    * Other Rights — In no way are any of the following rights affected by the license:
          o Your fair dealing or fair use rights, or other applicable copyright exceptions and limitations;
          o The author's moral rights;
          o Rights other persons may have either in the work itself or in how the work is used, such as publicity or privacy rights.
    * Notice — For any reuse or distribution, you must make clear to others the license terms of this work. The best way to do this is with a link to this web page. 

 * Version: r9
 * Date (last edit): 11.09.2010
 * Function: This C++ include offers functions to read from a file in the
 *           INI format and write to a file in the INI format
 *           It is easy to use, stable and secure
*/

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream> // DEBUG only
using namespace std;

#define INI_DEFAULT_SECTION "main"

#define INI_MAX_LENGTH 300
#define INI_MAX_LINES_PER_SEC 50 // lines every section can have
#define INI_MAX_SECTIONS 20 // maximum amount of sections

#define INI_LINE_DONTSAVE "ini_dont_save123" // if a line contains this, it won't save


class ini {
 public:
  ini(const char _filename[]);
  ~ini();

  int GetInt(const char section[], const char key[]);
  double GetDouble(const char section[], const char key[]);
  long GetLong(const char section[], const char key[]);
  bool GetBool(const char section[], const char key[]);
  string GetString(const char section[], const char key[]);
  string Get(const char section[], const char key[]);
  
  void SetInt(const char section[],const char key[], int newval);
  void SetLong(const char section[], const char key[], long newval);
  void SetBool(const char section[], const char key[], bool newval);
  void SetString(const char section[], const char key[], string newval);
  void Set(const char section[], const char key[], const char newval[]);

  void CreateSection(const char section[]);
  void RemoveSection(const char section[]);
  void RemoveEntry(const char section[], const char key[]);
  bool ValidSection(const char section[]);
  bool ValidEntry(const char section[], const char key[]);
  int CountSections();
  int CountEntries();
  void Clear();
  void Close();
  bool Good();


 private:
  // internal functions
  string getKeyFromString(string mystring);
  string getValueFromString(string mystring);
  template <class T>
  string numtostring(T num);
  template <class T>
  T stringtonum(string mystring);


  // Variables
  string filename;
  vector<string> sectionnames;
  vector< vector<string> > buffer;
  bool InitGood; // no errors in constructor (could open the file ?)
  bool Closed;
  bool withoutSections; // mode without sections
  
  // cache for some statistics
  int sections;
  int entries;

};
