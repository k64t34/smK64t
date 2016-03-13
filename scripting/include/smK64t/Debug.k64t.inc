#if defined _k_debug
	#endinput
#endif
#define _k_debug
//#include <player>
#if !defined DEBUG_PLAYER
	#define DEBUG_PLAYER PLUGIN_AUTHOR
#endif

//*****************************************************************************
stock DebugPrint(const String:format[], any:...){
//*****************************************************************************
//LogMessage("%s",msg);
//new client=1;
//decl String:sm_debug[4];
//GetClientInfo(client, "sm_debug", sm_debug, sizeof(sm_debug));
decl String:buff[256];
VFormat(buff, sizeof(buff), format, 2);
#if defined DEBUG_PLAYER
decl clientname[MAX_CLIENT_NAME];
for (new client=1;client<=MaxClients;client++)
	{
	if (IsValidClient (client))
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
PrintToChatAll("[%s] %s",gPLUGIN_NAME,buff);
#endif
PrintToServer("[%s] %s",gPLUGIN_NAME,buff);
LogMessage("[%s] %s",gPLUGIN_NAME,buff);

//PrintHintTextToAll("%s",msg);
//PrintCenterTextAll("%s",msg);
}
//*****************************************************************************
//stock PrintToAllConsole(String:msg[]){
stock PrintToAllConsole(const String:format[], any:...){ 
//*****************************************************************************
decl buf[512];
VFormat(buf,sizeof(buf),format,2);
PrintToServer(buf);
#if defined _k_debuger_player
#else
#endif
PrintToChatAll(buf);
for (new client=1;client<=MaxClients;client++)
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
stock PrintError(const String:format[], any:...){
//*****************************************************************************
decl String:buff[256];
VFormat(buff, sizeof(buff), format, 2);
PrintToServer(buff);
LogMessage(buff);
LogError(buff);
#if defined DEBUG
DebugPrint(buff);
#endif
}