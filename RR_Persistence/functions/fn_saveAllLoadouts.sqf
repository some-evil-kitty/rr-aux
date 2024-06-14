// Saves all loadouts 
//
//
//
//
//

if !(isServer) exitwith {};
{
	_x call RR_Persistence_fnc_saveLoadout
} foreach (allPlayers - entities "Headlessclient_F")