if (isServer && isDedicated && RR_enablePersistence) then {
	[] call rr_persistence_fnc_postinitServer;
};
RR_Persistence_LoadOnlyOnce = true
/*
["RR_persistence_SaveAllLoadouts", {
	if !(isServer) exitwith {};
	{
		_x call RR_Persistence_saveLoadout
	} foreach (allPlayers - entities "Headlessclient_F")
}] call CBA_fnc_addEventHandler;
*/
