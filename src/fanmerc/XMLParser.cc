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

#include "XMLParser.hh"

fanmerc::XMLParser* fanmerc::XMLParser::_parser = 0;

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::XMLParser::XMLParser()
{}

/*=========================================================================
 *  DESCRIPTION OF FUNCTION:
 *  ==> see headerfile
 *=======================================================================*/
fanmerc::XMLParser*
fanmerc::XMLParser::parser()
{
  if( _parser == 0)
  {
    _parser = new XMLParser;
  }
  return _parser;
}
