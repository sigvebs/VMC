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
 

ToDo:
- TODO: make comments more flexibel eg:
       whitespace whitespace ;
- TODO: the set and get functions should be splitted into some base functions like findSectionID, ..
	   instead of writing the code again and again
	   
*/

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "ini.h"
using namespace std;

ini::ini(const char _filename[])
{
  // init some variables
  this->Closed = false;
  this->withoutSections = true; // mode "without sections" by default
  this->sectionnames.push_back(INI_DEFAULT_SECTION); // for files without section
  this->buffer.push_back( vector<string>() ); // create a new dimension (the first dimension)
  this->filename = _filename;
  this->sections = 0;
  this->entries = 0;
  
  /* DON'T UNCOMMENT THIS
  this->buffer.resize(INI_MAX_SECTIONS);
  for(int i=0; i<INI_MAX_SECTIONS; i++)
    {
      this->buffer[i].resize(INI_MAX_LINES_PER_SEC);
    }
  // now I can access this array as 2d: this->buffer[0][1], meaning the second line of the first default section
  // the first line of every section (buffer[x][0]) contains the section name
  */
  /*
  add lines to a section with this->buffer[sectionidx].push_back
  but before add a new dimension if it doesn't exit:
  this->buffer.push_back( vector<string>() );
  To get the sectionidx, loop through this->sectionnames. the sectionidx will be the pos
  */
  
  //open the file
  ifstream inifile(_filename);
  string iniline("");
  int section_idx = 0; // counts the section, needed for the buffer vector
  string section_tmp_name;
  size_t pos1;
  size_t pos2;

  if(inifile.is_open())
    {
      this->InitGood = true;
      while(!inifile.eof())
	{
	  // Read section and insert them to the vector
	  getline(inifile, iniline);
	  if(iniline.length() > INI_MAX_LENGTH) // too large, avoid buffer overflows
	    iniline = iniline.substr(0, INI_MAX_LENGTH);


	  if(iniline[0] == '[' && iniline.find(']') != string::npos) // a section starts
	    {  
	      // change mode
	      if(this->withoutSections)
		this->withoutSections = false;
	      // statistics
	      this->sections++;
	      
	      // Remove [ and ]
	      pos1 = iniline.find("[");
	      pos2 = iniline.find("]", pos1+1);
	      section_tmp_name = iniline.substr(pos1+1, pos2-1);

	      // Overwrite default section
	      if(section_idx == 0)
		this->sectionnames[0] = section_tmp_name;
	      else
		this->sectionnames.push_back(section_tmp_name);
	      
	      this->buffer.push_back( vector<string>() ); // create a new dimension
	      
	      section_idx++;

	      // Reset pos1 and pos2
	      pos1 = 0;
	      pos2 = 0;
	    }
	  else
	    {
	      // statistics
	      if(iniline[0] != ';' && iniline.find('=') != string::npos)
		  this->entries++;
	      
	      if(section_idx > 0)
		this->buffer[section_idx-1].push_back(iniline);
	      else
		this->buffer[0].push_back(iniline);
	    }
	}
    }
  else this->InitGood = false;

  inifile.close();
}

ini::~ini()
{
  if(this->Closed == false)
    this->Close();
}

void ini::Close()
{
  int emptylines = 0;
  fstream inifile;
  
  inifile.open(this->filename.c_str(), ios::out);
  if(inifile.is_open())
    {
      this->InitGood = false; // file is closed, so false
      vector< vector <string> >::iterator section_it;
      vector<string>::iterator sectionnames_it;
      vector<string>::iterator line_it;
      
      for(section_it = this->buffer.begin(), sectionnames_it = this->sectionnames.begin(); section_it != this->buffer.end(); ++section_it, ++sectionnames_it)
	{
	    if(sectionnames_it != this->sectionnames.end())
	    {
	      if(!this->withoutSections) // only write the section if the section name isn't empty and if the mode "without Section" isn't true
		inifile << '[' << *sectionnames_it << ']' << endl;
	    }

	    // get all lines of the section
	    for(line_it = section_it->begin(); line_it != section_it->end(); ++line_it)
	      {
		// don't add a new line if the section and entry is the last one
		if((this->buffer.end()-section_it) == 2 && (section_it->end() - line_it) == 2) // = last entry of the last section
		  {
		    if(line_it->compare(INI_LINE_DONTSAVE)) // only write the line if it isn't marked as removed
		      inifile << *line_it;
		  }
		else
		  {
		    if(line_it->compare(INI_LINE_DONTSAVE)) // only write the line if it isn't marked as removed
		      inifile << *line_it << endl;
		  }
	      }
	}
      inifile.close();
      this->Closed = true;
    }
  else
  {
    this->InitGood = false;
    this->Closed = true;
  }
}

bool ini::Good()
{
  bool returnVal = this->InitGood;
  return returnVal;
}


int ini::GetInt(const char section[], const char key[])
{
  // Get the right dimension for accessing the buffer
  vector<string>::iterator sectionnames_it;
  vector<string>::iterator buffer_it;
  vector<string>::iterator buffer_end;
  bool lsection_found = false;
  int lsection = 0;
  
  string lkey;
  string lvalue;

  for(sectionnames_it = this->sectionnames.begin(); sectionnames_it < this->sectionnames.end(); ++sectionnames_it)
    {
      //if(sectionnames_it->at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	//{
	    if(!(*sectionnames_it).compare(section))
	      {
		lsection_found = true;
		break;
	      }
	//}
      lsection++;
    }
    
  if(!lsection_found  && !this->withoutSections) return 0;

  buffer_end = this->buffer[lsection].end();
  for(buffer_it = this->buffer[lsection].begin(); buffer_it < buffer_end; ++buffer_it)
    {
      lkey = this->getKeyFromString(*buffer_it);

      //if(lkey.at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	//{
	  if(!lkey.compare(key))
	    {
	      lvalue = this->getValueFromString(*buffer_it);
	      return (this->stringtonum<int>(lvalue));
	    }
	//}
    }
    
    // key not found
    return 0;
}

double ini::GetDouble(const char section[], const char key[])
{
  // Get the right dimension for accessing the buffer
  vector<string>::iterator sectionnames_it;
  vector<string>::iterator buffer_it;
  vector<string>::iterator buffer_end;
  bool lsection_found = false;
  int lsection = 0;
  
  string lkey;
  string lvalue;

  for(sectionnames_it = this->sectionnames.begin(); sectionnames_it < this->sectionnames.end(); ++sectionnames_it)
    {
      //if(sectionnames_it->at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	//{
	    if(!(*sectionnames_it).compare(section))
	      {
		lsection_found = true;
		break;
	      }
	//}
      lsection++;
    }
    
  if(!lsection_found  && !this->withoutSections) return 0;

  buffer_end = this->buffer[lsection].end();
  for(buffer_it = this->buffer[lsection].begin(); buffer_it < buffer_end; ++buffer_it)
    {
      lkey = this->getKeyFromString(*buffer_it);

      //if(lkey.at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	//{
	  if(!lkey.compare(key))
	    {
	      lvalue = this->getValueFromString(*buffer_it);
	      return (this->stringtonum<double>(lvalue));
	    }
	//}
    }
    
    // key not found
    return 0;
}


long ini::GetLong(const char section[], const char key[])
{
  // Get the right dimension for accessing the buffer
  vector<string>::iterator sectionnames_it;
  vector<string>::iterator buffer_it;
  vector<string>::iterator buffer_end;
  bool lsection_found = false;
  int lsection = 0;
  
  string lkey;
  string lvalue;

  for(sectionnames_it = this->sectionnames.begin(); sectionnames_it < this->sectionnames.end(); ++sectionnames_it)
    {
      //if(sectionnames_it->at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	//{
	    if(!(*sectionnames_it).compare(section))
	      {
		lsection_found = true;
		break;
	      }
	//}
      lsection++;
    }
    
  if(!lsection_found  && !this->withoutSections) return 0;

  buffer_end = this->buffer[lsection].end();
  for(buffer_it = this->buffer[lsection].begin(); buffer_it < buffer_end; ++buffer_it)
    {
      lkey = this->getKeyFromString(*buffer_it);

      //if(lkey.at(0) == section[0])// faster, since it will save a call (compare) if not even the first char is the same
	//{
	  if(!lkey.compare(key))
	    {
	      lvalue = this->getValueFromString(*buffer_it);
	      return (this->stringtonum<long>(lvalue));
	    }
	//}
    }
    
    // key not found
    return 0;
}


bool ini::GetBool(const char section[], const char key[])
{
  // Get the right dimension for accessing the buffer
  vector<string>::iterator sectionnames_it;
  vector<string>::iterator buffer_it;
  vector<string>::iterator buffer_end;
  bool lsection_found = false;
  int lsection = 0;
  
  string lkey;
  string lvalue;

  for(sectionnames_it = this->sectionnames.begin(); sectionnames_it < this->sectionnames.end(); ++sectionnames_it)
    { 
      //if(sectionnames_it->at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	//{
	    if(!(*sectionnames_it).compare(section))
	      {
		lsection_found = true;
		break;
	      }
	//}
      lsection++;
    }
    
  if(!lsection_found  && !this->withoutSections) return 0;

  buffer_end = this->buffer[lsection].end();
  for(buffer_it = this->buffer[lsection].begin(); buffer_it < buffer_end; ++buffer_it)
    {
      lkey = this->getKeyFromString(*buffer_it);

      //if(lkey.at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	//{
	  if(!lkey.compare(key))
	    {
	      int lretval;
	      lvalue = this->getValueFromString(*buffer_it);
	      lretval = (this->stringtonum<int>(lvalue));
	      if(lretval == 1)
		 return true;
	      else
		return false;
	    }
	//}
    }
    
    // key not found
    return 0;
}

string ini::Get(const char section[], const char key[])
{
  return this->GetString(section, key);
}

string ini::GetString(const char section[], const char key[])
{
  // Get the right dimension for accessing the buffer
  vector<string>::iterator sectionnames_it;
  vector<string>::iterator buffer_it;
  vector<string>::iterator buffer_end;
  bool lsection_found = false;
  int lsection = 0;
  
  string lkey;
  string lvalue;

  for(sectionnames_it = this->sectionnames.begin(); sectionnames_it < this->sectionnames.end(); sectionnames_it++)
    {
      //if(sectionnames_it->at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	//{	
	    if(!(*sectionnames_it).compare(section))
	      {
		lsection_found = true;
		break;
	      }
	//}
      lsection++;
    }
    
  if(!lsection_found  && !this->withoutSections) return "";

  buffer_end=this->buffer[lsection].end();
  for(buffer_it = this->buffer[lsection].begin(); buffer_it < buffer_end; ++buffer_it)
    {
      lkey = this->getKeyFromString(*buffer_it);

      //if(lkey.at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	//{
	  if(!lkey.compare(key))
	    {
	      string lstring = this->getValueFromString(*buffer_it);
	      return lstring;
	    }
	//}
    }
    
    // key not found
    return "";
}

void ini::Set(const char section[], const char key[], const char newval[])
{
  // Get the right dimension for accessing the buffer
  vector<string>::iterator sectionnames_it;
  vector<string>::iterator buffer_it;
  vector<string>::iterator buffer_end;
  bool lsection_found = false;
  bool lkey_found = false;
  int lsection = 0;
  int lkeyline = 0;
  
  string lkey;
  
  if(!this->withoutSections)
    {
      for(sectionnames_it = this->sectionnames.begin(); sectionnames_it < this->sectionnames.end(); ++sectionnames_it)
	{
	  //if(sectionnames_it->at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	    //{
		if(!(*sectionnames_it).compare(section))
		  {
		    lsection_found = true;
		    break;
		  }
	    //}
	  lsection++;
	}
    }
    
  if(!lsection_found && !this->withoutSections) 
      this->CreateSection(section);
  else
  {
    buffer_end = this->buffer[lsection].end();
    for(buffer_it = this->buffer[lsection].begin(); buffer_it < buffer_end; ++buffer_it)
      {
	lkey = this->getKeyFromString(*buffer_it);

	//if(lkey.at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	 // {
	    if(!lkey.compare(key))
	      {
		*buffer_it = lkey+'=';
		*buffer_it += newval;
		lkey_found = true;
		break;
	      }
	  //}
	lkeyline++;
      }
  }
  
  if(!lkey_found)
  {
     // statistics
    this->entries++;

    string lnewentry;
    lnewentry.append(key);
    lnewentry.append("=");
    lnewentry += newval;
    this->buffer[lsection].push_back(lnewentry);
  }
}

void ini::SetString(const char section[], const char key[], string newval)
{
  // Get the right dimension for accessing the buffer
  vector<string>::iterator sectionnames_it;
  vector<string>::iterator buffer_it;
  vector<string>::iterator buffer_end;
  bool lsection_found = false;
  bool lkey_found = false;
  int lsection = 0;
  int lkeyline = 0;
  
  string lkey;

  if(!this->withoutSections)
    {
      for(sectionnames_it = this->sectionnames.begin(); sectionnames_it < this->sectionnames.end(); ++sectionnames_it)
	{
	  //if(sectionnames_it->at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	    //{
		if(!(*sectionnames_it).compare(section))
		  {
		    lsection_found = true;
		    break;
		  }
	    //}
	  lsection++;
	}
    }
    
  if(!lsection_found  && !this->withoutSections) 
      this->CreateSection(section);
  else
  {
    buffer_end = this->buffer[lsection].end();
    for(buffer_it = this->buffer[lsection].begin(); buffer_it < buffer_end; ++buffer_it)
      {
	lkey = this->getKeyFromString(*buffer_it);

	//if(lkey.at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	 // {
	    if(!lkey.compare(key))
	      {
		*buffer_it = lkey+'=';
		*buffer_it += newval;
		lkey_found = true;
		break;
	      }
	 // }
	lkeyline++;
      }
  }
  
  if(!lkey_found)
  {
     // statistics
    this->entries++;
    
    string lnewentry;
    lnewentry.append(key);
    lnewentry.append("=");
    lnewentry+=newval;
    this->buffer[lsection].push_back(lnewentry);
  }
}

void ini::SetInt(const char section[], const char key[], int newval)
{
  // Get the right dimension for accessing the buffer
  vector<string>::iterator sectionnames_it;
  vector<string>::iterator buffer_it;
  vector<string>::iterator buffer_end;
  bool lsection_found = false;
  bool lkey_found = false;
  int lsection = 0;
  int lkeyline = 0;
  
  string lkey;

  if(!this->withoutSections)
    {
      for(sectionnames_it = this->sectionnames.begin(); sectionnames_it < this->sectionnames.end(); ++sectionnames_it)
	{
	  //if(sectionnames_it->at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	    //{
		if(!(*sectionnames_it).compare(section))
		  {
		    lsection_found = true;
		    break;
		  }
	    //}
	  lsection++;
	}
    }
    
  if(!lsection_found  && !this->withoutSections) 
      this->CreateSection(section);
  else
  {
    buffer_end = this->buffer[lsection].end();
    for(buffer_it = this->buffer[lsection].begin(); buffer_it < buffer_end; ++buffer_it)
      {
	lkey = this->getKeyFromString(*buffer_it);

	//if(lkey.at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	 // {
	    if(!lkey.compare(key))
	      {
		*buffer_it = lkey+'=';
		*buffer_it += newval;
		lkey_found = true;
		break;
	      }
	 // }
	lkeyline++;
      }
  }
  
  if(!lkey_found)
  {
     // statistics
    this->entries++;
    
    string lnewentry;
    lnewentry.append(key);
    lnewentry.append("=");
    lnewentry += newval;
    this->buffer[lsection].push_back(lnewentry);
  }
}

void ini::SetLong(const char section[], const char key[], long newval)
{
  // Get the right dimension for accessing the buffer
  vector<string>::iterator sectionnames_it;
  vector<string>::iterator buffer_it;
  vector<string>::iterator buffer_end;
  bool lsection_found = false;
  bool lkey_found = false;
  int lsection = 0;
  int lkeyline = 0;
  
  string lkey;

  if(!this->withoutSections)
    {
      for(sectionnames_it = this->sectionnames.begin(); sectionnames_it < this->sectionnames.end(); ++sectionnames_it)
	{
	  //if(sectionnames_it->at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	    //{
		if(!(*sectionnames_it).compare(section))
		  {
		    lsection_found = true;
		    break;
		  }
	    //}
	  lsection++;
	}
    }
    
  if(!lsection_found  && !this->withoutSections) 
      this->CreateSection(section);
  else
  {
    buffer_end = this->buffer[lsection].end();
    for(buffer_it = this->buffer[lsection].begin(); buffer_it < buffer_end; ++buffer_it)
      {
	lkey = this->getKeyFromString(*buffer_it);

	//if(lkey.at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	 // {
	    if(!lkey.compare(key))
	      {
		*buffer_it = lkey+'=';
		*buffer_it += newval;
		lkey_found = true;
		break;
	      }
	 // }
	lkeyline++;
      }
  }
  
  if(!lkey_found)
  {
     // statistics
    this->entries++;
    
    string lnewentry;
    lnewentry.append(key);
    lnewentry.append("=");
    lnewentry += newval;
    this->buffer[lsection].push_back(lnewentry);
  }
}

void ini::SetBool(const char section[], const char key[], const bool newval)
{
  // Get the right dimension for accessing the buffer
  vector<string>::iterator sectionnames_it;
  vector<string>::iterator buffer_it;
  vector<string>::iterator buffer_end;
  bool lsection_found = false;
  bool lkey_found = false;
  int lsection = 0;
  int lkeyline = 0;
  
  string lkey;

  if(!this->withoutSections)
    {
      for(sectionnames_it = this->sectionnames.begin(); sectionnames_it < this->sectionnames.end(); ++sectionnames_it)
	{
	  //if(sectionnames_it->at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	    //{
		if(!(*sectionnames_it).compare(section))
		  {
		    lsection_found = true;
		    break;
		  }
	    //}
	  lsection++;
	}
    }
    
  if(!lsection_found  && !this->withoutSections) 
      this->CreateSection(section);
  else
  {
    buffer_end = this->buffer[lsection].end();
    for(buffer_it = this->buffer[lsection].begin(); buffer_it < buffer_end; ++buffer_it)
      {
	lkey = this->getKeyFromString(*buffer_it);

	//if(lkey.at(0) == section[0])// faster, since it will save a call (compare) if not even the first char is the same
	 // {
	    if(!lkey.compare(key))
	      {
		*buffer_it = lkey+'=';
		*buffer_it += newval;
		lkey_found = true;
		break;
	      }
	  //}
	lkeyline++;
      }
  }
  
  if(!lkey_found)
  {
     // statistics
    this->entries++;
    
    string lnewentry;
    lnewentry.append(key);
    lnewentry.append("=");
    lnewentry += newval;
    this->buffer[lsection].push_back(lnewentry);
  }
}


void ini::CreateSection(const char section[])
{
  bool lsecfound = false;
  vector<string>::iterator sectionnames_it;
  // does the section already exist?
  for(sectionnames_it = this->sectionnames.begin(); sectionnames_it < this->sectionnames.end(); sectionnames_it++)
  {
    //if(sectionnames_it->at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
      //{
	  if(!(*sectionnames_it).compare(section))
	    lsecfound = true;
      //}
  }
  
  if(!lsecfound)
    {
      this->sectionnames.push_back(section);
      // Create new dimension
      this->buffer.push_back( vector<string>() );
      
      // statistics
      this->sections++;
    }
}

void ini::RemoveSection(const char section[])
{
    vector<string>::iterator sectionnames_it;
    int lpos = 0;
    
    for(sectionnames_it = this->sectionnames.begin(); sectionnames_it < this->sectionnames.end(); sectionnames_it++)
      {
	//if(sectionnames_it->at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	//{
	      if(!(*sectionnames_it).compare(section))
		{
		    this->buffer.erase(this->buffer.begin()+lpos);
		    sectionnames_it->clear();
		    
		     // statistics
		    this->sections--;
		    break;
		}
	//}
	lpos++;
      }
}

void ini::RemoveEntry(const char section[], const char key[])
{
  // Get the right dimension for accessing the buffer
  vector<string>::iterator sectionnames_it;
  vector<string>::iterator buffer_it;
  vector<string>::iterator buffer_end;
  bool lsection_found = false;
  int lsection = 0;
  
  string lkey;

  for(sectionnames_it = this->sectionnames.begin(); sectionnames_it < this->sectionnames.end(); ++sectionnames_it)
    {
      //if(sectionnames_it->at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
      //{
	    if(!(*sectionnames_it).compare(section))
	      {
		lsection_found = true;
		break;
	      }
      //}
      lsection++;
    }
    
  if(lsection_found)
    {
    buffer_end = this->buffer[lsection].end();
    for(buffer_it = this->buffer[lsection].begin(); buffer_it < buffer_end; ++buffer_it)
      {
	lkey = this->getKeyFromString(*buffer_it);

	//if(lkey.at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	 // {
	    if(!lkey.compare(key))
	      {
		 // statistics
		 this->entries--;
		  
		*buffer_it = INI_LINE_DONTSAVE;
		break;
	      }
	  //}
      }
  }
}

bool ini::ValidSection(const char section[])
{
  vector<string>::iterator sectionnames_it;
  
  for(sectionnames_it = this->sectionnames.begin(); sectionnames_it < this->sectionnames.end(); ++sectionnames_it)
    {
      //if(sectionnames_it->at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	//{
	    if(!sectionnames_it->compare(section))
	      return true;
	//}
    }
    
  return false;
}

bool ini::ValidEntry(const char section[], const char key[])
{
  // Get the right dimension for accessing the buffer
  vector<string>::iterator sectionnames_it;
  vector<string>::iterator buffer_it;
  vector<string>::iterator buffer_end;
  bool lsection_found = false;
  int lsection = 0;
  
  string lkey;

  for(sectionnames_it = this->sectionnames.begin(); sectionnames_it < this->sectionnames.end(); ++sectionnames_it)
    {
      //if(sectionnames_it->at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	//{
	    if(!(*sectionnames_it).compare(section))
	      {
		lsection_found = true;
		break;
	      }
      //}
      lsection++;
    }
    
  if(!lsection_found) 
      return false;
  else
  {
    buffer_end = this->buffer[lsection].end();
    for(buffer_it = this->buffer[lsection].begin(); buffer_it < buffer_end; ++buffer_it)
      {
	lkey = this->getKeyFromString(*buffer_it);

	//if(lkey.at(0) == section[0]) // faster, since it will save a call (compare) if not even the first char is the same
	//{
	    if(!lkey.compare(key))
	      return true;
	//}
      }
  }
   return false;
}

int ini::CountSections()
{
  int lsections = this->sections;
  return lsections;
}

int ini::CountEntries()
{
  int lentries = this->entries;
  return lentries;
}

void ini::Clear()
{
  // clear buffers
  this->sectionnames.clear();
  this->buffer.clear();
  
  //statistics
  this->entries = 0;
  this->sections = 0;
}

  
// Private functions
/*
Name: getKeyFromString
Function: Gets a key from a string, which is in the ini format
(key = value)
returns: The key as std:string
*/
string ini::getKeyFromString(string mystring)
{
    int i = mystring.find('=');
    if(i>=0)
    {
        return mystring.substr(0, i);
    }
    else return "";
}

/*
Name: getValueFromString
Function: Gets a value from a string, which is in the ini format
(key = value)
returns: The value as std:string
*/
string ini::getValueFromString(string mystring)
{
    int i = mystring.find_last_of('=');
    if(i>=0)
    {
        return mystring.substr(i+1);
    }
    else return "";
}

template <class T>
string ini::numtostring(T num)
{
	string mystring;  
	ostringstream convert;
	convert << num;    
	mystring = convert.str();
	return mystring;
}

template <class T>
T ini::stringtonum(string mystring)
{
	T num;
	istringstream convert(mystring);
	if( !(convert >> num) ) num = 0;
	return num;
}
