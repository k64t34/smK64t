#if defined _k_cstrike
	#endinput
#endif
#define _k_cstrike

#pragma newdecls optional
#include <cstrike> 
// Common const from cstrike.inc
//#define CS_TEAM_NONE		0	/**< No team yet. */
//#define CS_TEAM_SPECTATOR	1	/**< Spectators. */
//#define CS_TEAM_T 			2	/**< Terrorists. */
//#define CS_TEAM_CT			3	/**< Counter-Terrorists. */
#pragma newdecls required
#define	HITGROUP_GENERIC   0
#define	HITGROUP_HEAD      1
#define	HITGROUP_CHEST     2
#define	HITGROUP_STOMACH   3
#define HITGROUP_LEFTARM   4
#define HITGROUP_RIGHTARM  5
#define HITGROUP_LEFTLEG   6
#define HITGROUP_RIGHTLEG  7
/*enum HitGroup
{    
    GENERIC             = 0,
    HEAD       = 1,
    HITGROUP_CHEST      = 2,
    HITGROUP_STOMACH    = 3,
    HITGROUP_LEFTARM	= 4,
	HITGROUP_RIGHTARM	= 5,
	HITGROUP_LEFTLEG    = 6,
	HITGROUP_RIGHTLEG   = 7
}
*/


#if defined USE_WEAPON // USE_WEAPON USE_WEAPON USE_WEAPON USE_WEAPON USE_WEAPON USE_WEAPON
#define MAX_WEAPON_NAME 16  //Maximum length of a weapon name string
#pragma newdecls optional
#include <smlib.inc> 
// Common const from smlib
//#define MAX_WEAPON_STRING		80
//#define MAX_WEAPONS				48	// Max number of weapons availabl
#if defined MAX_WEAPONS                 //Redefine MAX_WEAPONS from smlib to real weapon count in cstrike
	#undef MAX_WEAPONS
#endif
#define MAX_WEAPONS				35

#pragma newdecls required
//Entity Names for Weapons
char g_WeaponNames[MAX_WEAPONS][]={
	"primammo",     "secammo",  "vest",         "vesthelm",
    "defuser",      "nvgs",     "flashbang",    "hegrenade",
    "smokegrenade", "galil",    "ak47",         "scout",
    "sg552",        "awp",      "g3sg1",        "famas", 
    "m4a1",         "aug",      "sg550",        "glock",
    "usp",          "p228",     "deagle",       "elite",
    "fiveseven",    "m3",       "xm1014",       "mac10",
    "tmp",          "mp5navy",  "ump45",        "p90",
    "m249",         "c4",       "knife"};
#define WEAPONS_SLOTS_MAX 5	
//// Common const from cstrike.inc
//#define CS_SLOT_PRIMARY		0	/**< Primary weapon slot. */
//#define CS_SLOT_SECONDARY	1	/**< Secondary weapon slot. */
//#define CS_SLOT_KNIFE		2	/**< Knife slot. */
//#define CS_SLOT_GRENADE		3	/**< Grenade slot (will only return one grenade). */
//#define CS_SLOT_C4			4	/**< C4 slot. */
//
enum WeaponsSlot
{
    Slot_Invalid        = -1,   /** Invalid weapon (slot). */
    Slot_Primary        = 0,    /** Primary weapon slot. */
    Slot_Secondary      = 1,    /** Secondary weapon slot. */
    Slot_Melee          = 2,    /** Melee (knife) weapon slot. */
    Slot_Projectile     = 3,    /** Projectile (grenades, flashbangs, etc) weapon slot. */
    Slot_Explosive      = 4,    /** Explosive (c4) weapon slot. */
}

int f_WeaponSlots[MAX_WEAPONS] =    {
         -1, -1, -1, -1, -1, -1,
        CS_SLOT_GRENADE,    CS_SLOT_GRENADE,    CS_SLOT_GRENADE,    CS_SLOT_PRIMARY,
        CS_SLOT_PRIMARY,    CS_SLOT_PRIMARY,    CS_SLOT_PRIMARY,    CS_SLOT_PRIMARY,
        CS_SLOT_PRIMARY,    CS_SLOT_PRIMARY,    CS_SLOT_PRIMARY,    CS_SLOT_PRIMARY,
        CS_SLOT_PRIMARY,    CS_SLOT_SECONDARY,  CS_SLOT_SECONDARY,  CS_SLOT_SECONDARY,
        CS_SLOT_SECONDARY,  CS_SLOT_SECONDARY,  CS_SLOT_SECONDARY,  CS_SLOT_PRIMARY,
        CS_SLOT_PRIMARY,    CS_SLOT_PRIMARY,    CS_SLOT_PRIMARY,    CS_SLOT_PRIMARY,
        CS_SLOT_PRIMARY,    CS_SLOT_PRIMARY,    CS_SLOT_PRIMARY,    CS_SLOT_C4, 
        CS_SLOT_KNIFE};	
		
enum WeaponType
{
    Weapon_Glock = 0,
    weapon_USP,
    Weapon_P228,
    Weapon_Deagle,
    Weapon_Elite,
    Weapon_FiveSeven,
    Weapon_M3,
    Weapon_XM1014,
    Weapon_Galil,
    Weapon_AK47,
    Weapon_Scout,
    Weapon_SG552,
    Weapon_AWP,
    Weapon_G3SG1,
    Weapon_Famas,
    Weapon_M4A1,
    Weapon_Aug,
    Weapon_SG550,
    Weapon_Mac10,
    Weapon_TMP,
    Weapon_MP5Navy,
    Weapon_Ump45,
    Weapon_P90,
    Weapon_M249,
    Weapon_Vest,
    Weapon_VestHelm,
    Weapon_FlashBang,
    Weapon_HEGrenade,
    Weapon_SmokeGrenade,
    Weapon_Defuser,
    Weapon_NightVision,
    Weapon_C4,
    Weapon_Max
};
//Item Names for Weapons(GivePlayerItem)		
char g_WeaponItemNames[WeaponType][]={
"weapon_glock",
"weapon_usp",
"weapon_p228",
"weapon_deagle",
"weapon_elite",
"weapon_fiveseven",
"weapon_m3",
"weapon_xm1014",
"weapon_galil",
"weapon_ak47",
"weapon_scout",//10
"weapon_sg552",
"weapon_awp",
"weapon_g3sg1",
"weapon_famas",
"weapon_m4a1",
"weapon_aug",
"weapon_sg550",
"weapon_mac10",
"weapon_tmp",
"weapon_mp5navy",//20
"weapon_ump45",
"weapon_p90",
"weapon_m249",
"item_kevlar",
"item_assaultsuit",/*vest+helm */
"weapon_flashbang",//26
"weapon_hegrenade",//27
"weapon_smokegrenade",//28
"item_defuser",
"item_nvgs",//30
"weapon_c4",
""
};
#define i_vest 24
#define i_assaultsuit 25
#define i_flashbang 26
#define i_hegrenade 27
#define i_smokegrenade 28
#define i_defuser 29
#define i_nvgs 30

//Item type 0- Item, 1- weapon, -1-fail
int g_WeaponItemType[WeaponType]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,-1}; 

//**************************************************************
stock bool WeaponsClientHasWeapon(int client, const char[] weapon){
//**************************************************************
int WeaponsEntityIndex;
char classname[64];
for (int s = 0; s < WEAPONS_SLOTS_MAX; s++)
	{
	WeaponsEntityIndex=GetPlayerWeaponSlot(client,s);	
	if (WeaponsEntityIndex!=-1)
		{
		GetEdictClassname(WeaponsEntityIndex, classname, sizeof(classname));		
        ReplaceString(classname, sizeof(classname), "weapon_", "");
		#if defined DEBUG
		DebugPrint("WeaponsEntityIndex=%d classname=%s weapon=%s",WeaponsEntityIndex,classname,weapon);
		#endif
		
		if (strcmp(weapon, classname, false)==0)return true;        			
		}	
	}
return false;
}		

#endif // USE_WEAPON USE_WEAPON USE_WEAPON USE_WEAPON USE_WEAPON USE_WEAPON




#define iT 0
#define iCT 1

//**************************************************************
stock int iGetClientTeam(int client){
//**************************************************************
// IsClientInGame(client);  must be TRUE
#if defined DEBUG 
//PrintToChatAll("iGetClientTeam.start");	
#endif
int pteam;
pteam=GetClientTeam(client);
if (pteam==CS_TEAM_T) pteam=0;
else if (pteam==CS_TEAM_CT) pteam=1;
else pteam=-1;
#if defined DEBUG 
//PrintToChatAll("iGetClientTeam.end");	
#endif
return pteam;
}
//**************************************************************
stock int GetClientAgainstTeam(int client){
//**************************************************************
int pteam;
pteam=GetClientTeam(client);
if (pteam==CS_TEAM_T) pteam=CS_TEAM_CT;
else if (pteam==CS_TEAM_CT) pteam=CS_TEAM_T;
else pteam=-1;
return pteam;
}
//**************************************************************
stock int GetTeamClientNoBotCount(int[] teamscount){
//**************************************************************
for (int i=1; i<=MaxClients; i++)
	{
	if (IsClientConnected(i))
	if (IsClientInGame(i))
	if (!IsFakeClient(i))	
		teamscount[GetClientTeam(i)]++;
	}		
}


#endinput

/*-----------------------------------------------------------------*/


/**
 * General weapon API.
 */

/**
 * Maximum length of a weapon name string
 */
#define WEAPONS_MAX_LENGTH 32

/**
 * Number of weapon slots (For CS:S)
 */
#define WEAPONS_SLOTS_MAX 5

/**
 * Weapon slots.
 */
enum WeaponsSlot
{
    Slot_Invalid        = -1,   /** Invalid weapon (slot). */
    Slot_Primary        = 0,    /** Primary weapon slot. */
    Slot_Secondary      = 1,    /** Secondary weapon slot. */
    Slot_Melee          = 2,    /** Melee (knife) weapon slot. */
    Slot_Projectile     = 3,    /** Projectile (grenades, flashbangs, etc) weapon slot. */
    Slot_Explosive      = 4,    /** Explosive (c4) weapon slot. */
}

/**
 * Checks if a client has a specific weapon.
 * 
 * @param client    The client index.
 * @param weapon    The weapon classname.
 */
stock bool:WeaponsClientHasWeapon(client, const String:weapon[])
{
    // Get all of client's current weapons.
    new weapons[WeaponsSlot];
    WeaponsGetClientWeapons(client, weapons);
    
    decl String:classname[64];
    
    // x = slot index
    for (new x = 0; x < WEAPONS_SLOTS_MAX; x++)
    {
        // If slot is empty, then stop.
        if (weapons[x] == -1)
        {
            continue;
        }
        
        // If the weapon's classname matches, then return true.
        GetEdictClassname(weapons[x], classname, sizeof(classname));
        ReplaceString(classname, sizeof(classname), "weapon_", "");
        if (StrEqual(weapon, classname, false))
        {
            return true;
        }
    }
    
    return false;
}

/**
 * Return an array that contains all client's weapon indexes.
 * 
 * @param client    The client index.
 * @param weapons   The weapon index array.
 *                  -1 if no weapon in slot. 
 */
stock WeaponsGetClientWeapons(client, weapons[WeaponsSlot]){
    // x = Weapon slot.
    for (new x = 0; x < WEAPONS_SLOTS_MAX; x++)
    {
        weapons[x] = GetPlayerWeaponSlot(client, x);
    }
}

/**
 * Returns weapon index of the client's deployed weapon.
 * 
 * @param client    The client index.
 * @return          The weapon index of the deployed weapon.
 *                  -1 if no weapon is deployed. 
 */
stock WeaponsGetDeployedWeaponIndex(client)
{
    // Return the client's active weapon.
    return GetEntDataEnt2(client, offsActiveWeapon);
}

/**
 * Returns slot of client's deployed weapon.
 *
 * @param client    The client index.
 * @return          The slot number of deployed weapon.
 */
stock WeaponsSlot:WeaponsGetDeployedWeaponSlot(client)
{
    // Get all client's weapon indexes.
    new weapons[WeaponsSlot];
    WeaponsGetClientWeapons(client, weapons);
    
    // Get client's deployed weapon.
    new deployedweapon = WeaponsGetDeployedWeaponIndex(client);
    
    // If client has no deployed weapon, then stop.
    if (deployedweapon == -1)
    {
        return Type_Invalid;
    }
    
    // x = weapon slot.
    for (new x = 0; x < WEAPONS_SLOTS_MAX; x++)
    {
        if (weapons[x] == deployedweapon)
        {
            return WeaponsSlot:x;
        }
    }
    
    return Type_Invalid;
}







/**
 * Returns the weapon in a player's slot.  
 *
 * @param client		Client index.
 * @param slot			Slot index (mod specific).
 * @return				Entity index on success, -1 if no weapon existed.
 * @error				Invalid client or client not in game, or lack of mod support.
 */
native GetPlayerWeaponSlot(client, slot);
