addMissionEventHandler ["EntityRespawned", {
	params ["_newEntity", "_oldEntity"];

	if (RR_Persistence_LoadOnlyOnce) exitWith {
		if (_newEntity getVariable ["RR_Persistence_firstSpawn", true]) then {
			[_newEntity] call RR_Persistence_fnc_loadUnit;
			_newEntity setVariable ["RR_Persistence_firstSpawn", false, true];
		};
	};
	[_newEntity] call RR_Persistence_fnc_loadUnit;
	_newEntity setVariable ["RR_Persistence_firstSpawn", false, true];
}];

addMissionEventHandler ["HandleDisconnect", {
	if !(allPlayers isEqualTo []) exitWith {false};
	params ["_unit"];
	deleteVehicle _unit;
	saveProfileNamespace;
}];

addMissionEventHandler ["MPEnded", {
	saveProfileNamespace;
}];