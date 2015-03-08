/**************************************************************************
**       Title: 
**    $RCSfile: $
**   $Revision: $$Name:  $
**       $Date: $
**   Copyright: GPL $Author: $
** Description:
**
**    
**
**-------------------------------------------------------------------------
**
**  $Log: $
**
**
**************************************************************************/

#ifndef XMLPARSER_HH
#define XMLPARSER_HH

namespace fanmerc
{

class XMLParser
{
public:
  static XMLParser* parser();
private:
  XMLParser();
  static XMLParser* _parser;
};
}

#endif
      
    
