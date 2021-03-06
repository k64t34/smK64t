#if defined _k_debug
	#endinput
#endif
#define _k_debug
#include "smk64t\k_player.inc"
#if !defined DEBUG_PLAYER
	#define DEBUG_PLAYER PLUGIN_AUTHOR
#endif
char DEBUGgPLUGIN_NAME[]=PLUGIN_NAME;
//*****************************************************************************
stock void DebugPrint(const char[] format, any:...){
//*****************************************************************************
//LogMessage("%s",msg);
//new client=1;
//decl String:sm_debug[4];
//GetClientInfo(client, "sm_debug", sm_debug, sizeof(sm_debug));
char buff[256];
VFormat(buff, sizeof(buff), format, 2);
#if defined DEBUG_PLAYER
char clientname[MAX_CLIENT_NAME];
for (int client=1;client<=MaxClients;client++)
	{
	if (IsValidClient(client))
		{
		if (GetClientName(client,clientname,MAX_CLIENT_NAME))
			{
			if (strcmp(DEBUG_PLAYER, clientname,false)==0)
				{
				PrintToChat(client,"[%s] %s",gPLUGIN_NAME,buff);	
				break;
				}
			}	
		}		
	}	
#else
PrintToChatAll("[%s] %s",DEBUGgPLUGIN_NAME,buff);
#endif
PrintToServer("[%s] %s",DEBUGgPLUGIN_NAME,buff);
LogMessage("[%s] %s",DEBUGgPLUGIN_NAME,buff);

//PrintHintTextToAll("%s",msg);
//PrintCenterTextAll("%s",msg);
}
//*****************************************************************************
//stock PrintToAllConsole(String:msg[]){
stock void PrintToAllConsole(const char[] format, any:...){ 
//*****************************************************************************
char buf[512];
VFormat(buf,sizeof(buf),format,2);
PrintToServer(buf);
#if defined _k_debuger_player
#else
#endif
PrintToChatAll(buf);
for (int client=1;client<=MaxClients;client++)
	if (IsValidClient (client))
		PrintToConsole(client,buf);
}

//*****************************************************************************
//kDEBUG(str[], any:...){	
//******************************************************************************
//#if defined DEBUG 
//PrintToChatAll("%s %s",PLUGIN_NAME,str);	
//#endif
//}
//*****************************************************************************

//*****************************************************************************
stock void PrintError(const char[] format, any:...){
//*****************************************************************************
char buff[256];
VFormat(buff, sizeof(buff), format, 2);
PrintToServer(buff);
LogMessage(buff);
LogError(buff);
#if defined DEBUG
DebugPrint(buff);
#endif
}