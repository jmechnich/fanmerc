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

#ifndef FANMERCDEFS_HH
#define FANMERCDEFS_HH

#include <string>

namespace fanmerc
{

#define ITEM_TYPES_NO 16

  static const std::string ItemTypes[ITEM_TYPES_NO] =
  {
      "OHAND",
      "THAND",
      "MISSILE",
      "HEAD",
      "AMULETT",
      "ARMOR",
      "BRACELETS",
      "BELT",
      "RRING",
      "LRING",
      "GLOVES",
      "CAPE",
      "BOOTS",
      "ACTIVE",
      "PASSIVE",
      "NOWEAR"
  };

#define ATTRIBUTES_NO 5

  static const std::string Attributes[ATTRIBUTES_NO] =
  {
      "Strength",
      "Dexterity",
      "Speed",
      "Constitution",
      "Magic"
  };
  
#define COMBAT_SKILLS_NO 12
#define CLOSE_SKILLS_MIN 0
#define CLOSE_SKILLS_MAX 3
#define MISSILE_SKILLS_MIN 4
#define MISSILE_SKILLS_MAX 7
#define DEFENCE_SKILLS_MIN 8
#define DEFENCE_SKILLS_MAX 11

  static const std::string CombatSkills[COMBAT_SKILLS_NO] =
  {
      "Blade",
      "Blunt",
      "Point",    
      "Staves",    
      "Bow",   
      "Crossbow",
      "Sling",
      "Throw",
      "Parry",
      "Dodge",
      "Armor",
      "Shield"
  };
  
#define MISC_SKILLS_NO 12
#define GENERAL_SKILLS_MIN 0
#define GENERAL_SKILLS_MAX 3
#define KNOWLEDGE_SKILLS_MIN 4
#define KNOWLEDGE_SKILLS_MAX 7
#define ACTION_SKILLS_MIN 8
#define ACTION_SKILLS_MAX 11

  static const std::string MiscSkills[MISC_SKILLS_NO] =
  {
      "Perception",
      "Swim",   
      "Climb",  
      "Stealth",
      "Ancient",
      "Nature",
      "Social",
      "Magic",
      "Disarm",
      "Healing",
      "Track",
      "Identify"
  };
    
#define MAGIC_SKILLS_NO 12
#define ELEMENTAL_SKILLS_MIN 0
#define ELEMENTAL_SKILLS_MAX 3
#define CONJURER_SKILLS_MIN 4
#define CONJURER_SKILLS_MAX 7
#define DIVINE_SKILLS_MIN 8
#define DIVINE_SKILLS_MAX 11

  static const std::string MagicSkills[MAGIC_SKILLS_NO] =
  {
      "Fire",
      "Air",
      "Water",
      "Earth",
      "Necromancer",
      "Mind",
      "Beneficial",
      "Nature",
      "Healing",
      "Offensive",
      "Create",
      "Prayers"
  };
  

}

#endif
