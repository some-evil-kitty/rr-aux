// Loads a unit's saved loadout 
//
//
//
//

if !(isServer || RR_enablePersistence) exitwith {};

params ["_unit"];

private _id = getPlayerUID _unit;

private _loadouthashmap = profileNameSpace getVariable ["RR_Persistence_LoadoutsHashmap",createHashmap];

private _loadout = _loadouthashmap getOrDefault [_id,0];

if (_loadout isEqualTo 0) exitwith {};

[_unit,_loadout] call CBA_fnc_setLoadout;
