// Saves all loadouts 
//
//
//
//
//

if !(isServer || RR_enablePersistence) exitwith {};
{
	_x call RR_Persistence_fnc_saveLoadout
} foreach (allPlayers - entities "Headlessclient_F");

private _inventory = [RR_Persistence_CommonBoxObject] call ace_common_fnc_getInventory;


profileNamespace setVariable ["RR_Persistence_CommonboxInventory",_inventory];

saveProfileNamespace;

